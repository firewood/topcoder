#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct Map {
	int x;
	int y;
	vector<string> b;
	Map() {
		x = -1;
		y = -1;
		b = vector<string>(50, string(50, '#'));
	}
};

struct History {
	int score;
	vector<int> cmds;
	vector<bitset<2500> > vis;
	vector<int> x;
	vector<int> y;
	bool operator <(const History &h) const {
		return score > h.score;
	}
};

int n;
int k;
int h;
int w;
int t;

int main()
{
	cin >> n >> k >> h >> w >> t;
	vector<Map> maps(n);
	History org;
	org.x = vector<int>(n);
	org.y = vector<int>(n);
	org.vis.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < h; ++j) {
			string s;
			cin >> s;
			s += string(50, '#');
			Map &m = maps[i];
			m.b[j] = s.substr(0, 50);
			if (m.x < 0) {
				m.x = s.find('@');
				if (m.x >= 0) {
					m.y = j;
					org.x[i] = m.x;
					org.y[i] = m.y;
				}
			}
			
		}
	}

	vector<History> hists;
	hists.push_back(org);

	static const string cc = "UDLR";
	static const int dx[] = { 0,0,-1,1 };
	static const int dy[] = { -1,1,0,0 };
#ifdef _DEBUG
	static const int max_hists = 5;
	static const int max_cmd_length = 10;
#else
	static const int max_hists = 30;
	static const int max_cmd_length = 2500;
#endif
	while (hists[0].cmds.size() < max_cmd_length) {
		vector<History> next;
		for (int h = 0; h != hists.size(); ++h) {
			++h;
			--h;
			for (int d = 0; d < 4; ++d) {
				History hist = hists[h];
				int score = hist.score;
				for (int i = 0; i < n; ++i) {
					if (hist.x[i] >= 0) {
						int nx = hist.x[i] + dx[d], ny = hist.y[i] + dy[d];
						switch (maps[i].b[ny][nx]) {
						case 'x':
							nx = -1;
							score -= 10;
							break;
						case '#':
							nx = hist.x[i], ny = hist.y[i];
							break;
						case 'o':
							if (!hist.vis[i][ny * 50 + nx]) {
								++score;
								hist.vis[i][ny * 50 + nx] = true;
							}
							break;
						}
						hist.x[i] = nx, hist.y[i] = ny;
					}
				}
				hist.cmds.push_back(d);
				hist.score = score;
				next.push_back(hist);
			}
			sort(next.begin(), next.end());
			if (next.size() > max_hists) {
				next.resize(max_hists);
			}
		}
		hists = next;
	}

	int besth, bests = -1;
	vector<int> bestm(k);
	for (int h = 0; h != hists.size(); ++h) {
		vector<pair<int, int> > sv;
		for (int i = 0; i < n; ++i) {
			int score = 0;
			int x = maps[i].x, y = maps[i].y;
			bool vis[50][50] = {};
			for (int d : hists[h].cmds) {
				int nx = x + dx[d], ny = y + dy[d];
				switch (maps[i].b[ny][nx]) {
				case 'x':
					nx = -1;
					break;
				case '#':
					nx = x, ny = y;
					break;
				case 'o':
					if (!vis[ny][nx]) {
						vis[ny][nx] = true;
						++score;
					}
					break;
				}
				if (nx < 0) {
					break;
				}
				x = nx, y = ny;
			}
			sv.push_back(make_pair(-score, i));
		}
		sort(sv.begin(), sv.end());
		int tot = 0;
		for (int i = 0; i < k; ++i) {
			tot -= sv[i].first;
		}
//		for (int i = 0; i != sv.size(); ++i) {
//			cout << " " << -sv[i].first;
//		}
//		cout << " " << tot << endl;
		if (tot > bests) {
			besth = h;
			bests = tot;
			for (int i = 0; i < k; ++i) {
				bestm[i] = sv[i].second;
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		if (i) {
			cout << " ";
		}
		cout << bestm[i];
	}
	cout << endl;
	for (int d : hists[besth].cmds) {
		cout << cc[d];
	}
	cout << endl;
    return 0;
}

