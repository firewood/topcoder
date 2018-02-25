#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

#ifdef _DEBUG
static const int pre_max_hists = 10;
static const int pre_max_cmd_length = 10;
static const int max_hists = 20;
static const int max_cmd_length = 20;
#else
static const int pre_max_hists = 200;
static const int pre_max_cmd_length = 5;
static const int max_hists = 80;
static const int max_cmd_length = 2500;
#endif
static const int pre_penalty = -100;
static const int penalty = -100;

static const string cc = "UDLR";
static const int dx[] = { 0,0,-1,1 };
static const int dy[] = { -1,1,0,0 };

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

vector<History> gen_command(const vector<Map> &maps, int max_hists, int max_cmd_length, int stack_penalty) {
	int n = (int)maps.size();
	int h = maps[0].b.size();
	History org;
	org.x = vector<int>(n);
	org.y = vector<int>(n);
	org.vis.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < h; ++j) {
			org.x[i] = maps[i].x;
			org.y[i] = maps[i].y;
		}
	}

	vector<History> hists;
	hists.push_back(org);
	while (hists[0].cmds.size() < max_cmd_length) {
		vector<History> next;
		for (int h = 0; h != hists.size(); ++h) {
			for (int d = 0; d < 4; ++d) {
				History hist = hists[h];
				int score = hist.score;
				for (int i = 0; i < n; ++i) {
					if (hist.x[i] >= 0) {
						int nx = hist.x[i] + dx[d], ny = hist.y[i] + dy[d];
						switch (maps[i].b[ny][nx]) {
						case 'x':
							nx = -1;
							score += stack_penalty;
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

	return hists;
}

int main()
{
	int n, k, h, w, t;
	cin >> n >> k >> h >> w >> t;
	vector<Map> maps(n);
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
				}
			}

		}
	}

	vector<History> hists = gen_command(maps, pre_max_hists, pre_max_cmd_length, pre_penalty);

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
		if (tot > bests) {
			besth = h;
			bests = tot;
			for (int i = 0; i < k; ++i) {
				bestm[i] = sv[i].second;
			}
		}
	}

	vector<Map> selected;
	for (int i = 0; i < k; ++i) {
		selected.push_back(maps[bestm[i]]);
	}
	hists = gen_command(selected, max_hists, min(t, max_cmd_length), penalty);

	for (int i = 0; i < k; ++i) {
		if (i) {
			cout << " ";
		}
		cout << bestm[i];
	}
	cout << endl;
	for (int d : hists[0].cmds) {
		cout << cc[d];
	}
	cout << endl;

	return 0;
}
