#include "stdafx.h"
#include <algorithm>
#include <string>
#include "SmallPolygons.h"

using namespace std;

int SmallPolygons::area(const Triangle &t) const {
	return (int) abs(y[t.a] * (x[t.b] - x[t.c]) + y[t.b] * (x[t.c] - x[t.a]) + y[t.c] * (x[t.a] - x[t.b]));
}

int SmallPolygons::dist(const Triangle &t) const {
	int x1 = x[t.a] - x[t.b], x2 = x[t.b] - x[t.c], x3 = x[t.c] - x[t.a];
	int y1 = y[t.a] - y[t.b], y2 = y[t.b] - y[t.c], y3 = y[t.c] - y[t.a];
	return (int)(sqrt(x1*x1 + y1*y1) + sqrt(x2*x2 + y2*y2) + sqrt(x3*x3 + y3*y3));
}

bool SmallPolygons::intersect(int a, int b, int c, int d) const {
	LL x1 = x[a], x2 = x[b], x3 = x[c], x4 = x[d];
	LL y1 = y[a], y2 = y[b], y3 = y[c], y4 = y[d];

	if (x1 >= x2) {
		if ((x1 < x3 && x1 < x4) || (x2 > x3 && x2 > x4)) {
			return false;
		}
	} else {
		if ((x2 < x3 && x2 < x4) || (x1 > x3 && x1 > x4)) {
			return false;
		}
	}
	if (y1 >= y2) {
		if ((y1 < y3 && y1 < y4) || (y2 > y3 && y2 > y4)) {
			return false;
		}
	} else {
		if ((y2 < y3 && y2 < y4) || (y1 > y3 && y1 > y4)) {
			return false;
		}
	}

	if (((x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)) * ((x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)) > 0) {
		return false;
	}
	if (((x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)) * ((x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2)) > 0) {
		return false;
	}
	return true;
}

void SmallPolygons::init(std::vector <int> points, int N) {
	MaxPolygons = N;
	Np = (int)points.size() / 2;
	x.resize(Np);
	y.resize(Np);
	cx.resize(Np);
	cy.resize(Np);
	used.resize(Np);
	double tx = 0, ty = 0;
	for (int i = 0; i < Np; ++i) {
		x[i] = points[i * 2], y[i] = points[i * 2 + 1];
		connection[i].next = -1;
		connection[i].previous = -1;
	}
}

vector<string> SmallPolygons::choosePolygons(vector<int> points, int N) {
	init(points, N);
	findTriangles();
	chooseFirstPolygon();
	while (chooseNextVertex()) {
		;
	}
	chooseRemainVertices();

	vector<string> ret;
	for (int start_node : polygons) {
		char w[64];
		sprintf(w, "%d", start_node);
		string ans = w;
		int node = connection[start_node].next;
		while (node != start_node) {
			sprintf(w, " %d", node);
			ans += w;
			node = connection[node].next;
		}
		ret.push_back(ans);
	}
	return ret;
}

void SmallPolygons::chooseFirstPolygon() {
	vector<pair<int, Triangle> > v;
	for (auto t : t_vec) {
		v.push_back(make_pair(t.s, t));
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	for (auto e : v) {
		Triangle t = e.second;
		if (!used[t.a] && !used[t.b] && !used[t.c]) {
			bool inter = false;
			for (int p = 0; p < Np; ++p) {
				int q = connection[p].next;
				if (q < 0) {
					continue;
				}
				if (intersect(t.a, t.b, p, q)) {
					inter = true;
					break;
				}
				if (intersect(t.b, t.c, p, q)) {
					inter = true;
					break;
				}
				if (intersect(t.c, t.a, p, q)) {
					inter = true;
					break;
				}
			}
			if (inter) {
				continue;
			}

			polygons.push_back(t.a);
			used[t.a] = 1, used[t.b] = 1, used[t.c] = 1;
			uf.unite(t.a, t.b);
			uf.unite(t.a, t.c);
			connection[t.a].next = t.b;
			connection[t.a].previous = t.c;
			connection[t.b].next = t.c;
			connection[t.b].previous = t.a;
			connection[t.c].next = t.a;
			connection[t.c].previous = t.b;
			++cnt;
			if (cnt >= MaxPolygons) {
				break;
			}
		}
	}
}

bool SmallPolygons::chooseNextVertex() {
	for (int i = 0; i < Np; ++i) {
		if (!used[i]) {
			continue;
		}
		int j = connection[i].next;

		IntSet &nn = edge_to_triangles[make_edge(i, j)];
		for (auto ti : nn) {
			Triangle &t = t_vec[ti];
			int k = t.a;
			if (i == k || j == k) {
				k = t.b;
				if (i == k || j == k) {
					k = t.c;
				}
			}
			if (!used[k]) {
				bool inter = false;
				for (int p = 0; p < Np; ++p) {
					int q = connection[p].next;
					if (q < 0) {
						continue;
					}
					if (i != p && i != q && intersect(i, k, p, q)) {
						inter = true;
						break;
					}
					if (j != p && j != q && intersect(j, k, p, q)) {
						inter = true;
						break;
					}
				}
				if (!inter) {
					used[k] = 1;
					connection[i].next = k;
					connection[k].previous = i;
					connection[k].next = j;
					connection[j].previous = k;
					uf.unite(i, k);
					return true;
				}
			}
		}
	}
	return false;
}

void SmallPolygons::chooseRemainVertices() {

	for (int i = 0; i < Np; ++i) {
		if (used[i]) {
			continue;
		}

		vector<pair<int, Triangle> > w;
		for (int p = 0; p < Np; ++p) {
			int q = connection[p].next;
			if (q < 0) {
				continue;
			}
			Triangle t = { i, p, q };
			t.s = area(t);
			w.push_back(make_pair(t.s, t));
		}

		sort(w.begin(), w.end());
		for (auto e : w) {
			Triangle &t = e.second;
			int j = t.b, k = t.c;
			if (!used[j] || !used[k]) {
				continue;
			}

			bool inter = false;
			for (int p = 0; p < Np; ++p) {
				int q = connection[p].next;
				if (q < 0) {
					continue;
				}

				if (j != p && j != q && intersect(i, j, p, q)) {
					inter = true;
					break;
				}
				if (k != p && k != q && intersect(i, k, p, q)) {
					inter = true;
					break;
				}
			}

			if (!inter) {
				used[i] = 1;
				if (connection[j].next != k) {
					swap(j, k);
				}
				if (connection[j].next != k) {
					continue;
				}

				connection[j].next = i;
				connection[i].previous = j;
				connection[i].next = k;
				connection[k].previous = i;
				uf.unite(i, j);
				break;
			}
		}

//		cerr << "not used: " << i << ", ap: " << ap.size() << ", v: " << v.size() << ", cnt: " << cnt << endl;
	}
}

void SmallPolygons::findTriangles() {
	int div = 1;
	for (div = 2; div <= 19; ++div) {
		if (Np / (div * div) < 5) {
			break;
		}
	}
	div *= 2;

	for (int i = 0; i < Np; ++i) {
		int xx = (x[i] * div) / MAX_COORDINATE;
		int yy = (y[i] * div) / MAX_COORDINATE;
		points[yy][xx].push_back(i);
	}
	int max_dist = MAX_COORDINATE * MAX_COORDINATE;
	if (div > 1) {
		max_dist /= (div * div / 4);
	}

	for (int i = 0; i < div; i += 2) {
		for (int j = 0; j < div; j += 2) {
			IntVec &cp = core_points[i / 2][j / 2];
			for (int k = i; k < i + 2; ++k) {
				for (int l = j; l < j + 2; ++l) {
					cp.insert(cp.end(), points[k][l].begin(), points[k][l].end());
				}
			}
			for (auto p : cp) {
				cx[p] = j / 2;
				cy[p] = i / 2;
			}
			IntVec &ap = all_points[i / 2][j / 2];
			ap = cp;
			int m = 1;
			int current_max_dist = max_dist;

retry:
			for (int k = 0; k <= m; ++k) {
				int l = m - k;
				int p = i - k;
				int q = j - l;
				if (p >= 0 && q >= 0) {
					ap.insert(ap.end(), points[p][q].begin(), points[p][q].end());
				}
				q = j + l + 1;
				if (p >= 0 && q < div) {
					ap.insert(ap.end(), points[p][q].begin(), points[p][q].end());
				}
				p = i + k + 1;
				if (p < div && q < div) {
					ap.insert(ap.end(), points[p][q].begin(), points[p][q].end());
				}
				q = j - l;
				if (p < div && q >= 0) {
					ap.insert(ap.end(), points[p][q].begin(), points[p][q].end());
				}
			}

			for (int k = 0; k < (int)cp.size(); ++k) {
				int p = cp[k];
				vector<pair<double, II> > v;
				for (int l = 0; l < (int)ap.size(); ++l) {
					int q = ap[l];
					if (p != q) {
						int dx = x[q] - x[p], dy = y[q] - y[p];
						int dist = dx*dx + dy*dy;
						if (dist <= current_max_dist) {
							double r = atan2(dy, dx);
							v.push_back(make_pair(r, II(dist, q)));
						}
					}
				}
				sort(v.begin(), v.end());
//				cerr << "i = " << i << ", j = " << j << ", k = " << k << ", points: " << v.size() << endl;
				if (v.size() < 3) {
//					cerr << "NO TRIANGLES: i = " << i << ", j = " << j << ", k = " << k << ", cp = " << cp.size() << ", ap = " << ap.size() << ", v = " << v.size() << endl;
#if 1
					if (m == 1) {
						m += 1;
						current_max_dist *= 3;
						goto retry;
					}
#endif
					continue;
				}

				v.push_back(make_pair(v[0].first + 2 * M_PI, v[0].second));
				int n;
				for (int m = 0; m < (int)v.size(); m = n) {
					for (n = m + 1; n < (int)v.size(); ++n) {
						if (v[n].first > v[m].first && (v[n].first - v[m].first) < M_PI) {
							break;
						}
					}
					if (n >= (int)v.size()) {
						break;
					}

					Triangle t = Triangle::gen(p, v[n].second.second, v[m].second.second);
					t.s = area(t);
//					t.s = dist(t);

					if (t_map.find(t) == t_map.end()) {
						int t_seq = t_vec.size();
						t_map[t] = t_seq;
						t_vec.push_back(t);
						p_triangles[t.a].push_back(t_seq);
						p_triangles[t.b].push_back(t_seq);
						p_triangles[t.c].push_back(t_seq);

						edge_to_triangles[make_edge(t.a, t.b)].insert(t_seq);
						edge_to_triangles[make_edge(t.b, t.c)].insert(t_seq);
						edge_to_triangles[make_edge(t.c, t.a)].insert(t_seq);
					}
				}
			}
		}
	}
}
