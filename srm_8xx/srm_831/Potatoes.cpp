// BEGIN CUT HERE
/*
SRM 831 Div1 Medium (500)

PROBLEM STATEMENT

You have a small rectangular field. The field is somewhere in the mountains. The soil isn't that good and there's a lot of rocks in the soil.

The only thing that will grow in these conditions are potatoes. You now want to plant some.

For this purpose, you divided the field into a grid of unit squares. Some contain soil ('.'), others contain rocks ('#').
You are given the map of the field in the vector <string> field.
You can only plant potatoes into soil. 

Potatoes need some room to grow. Thus, no two potatoes can share the same square and no two potatoes can share squares that have a common side (i.e., horizontally and vertically adjacent squares).

Plant exactly N potatoes. Return the field with 'P' used for cells that now contain potatoes. Any valid solution will be accepted. If there is no valid solution, return an empty vector <string> instead. (That is, a vector <string> with zero elements.)


DEFINITION
Class:Potatoes
Method:plant
Parameters:vector <string>, int
Returns:vector <string>
Method signature:vector <string> plant(vector <string> field, int N)


NOTES
-You are not allowed to (re)move any of the rocks on the field. That is, each '#' must remain a '#', you may only change some '.'s into 'P's.


CONSTRAINTS
-field will have between 1 and 50 elements, inclusive.
-Each element of field will have between 1 and 50 characters, inclusive.
-Each element of field will have the same number of characters.
-Each character in field will be '.' or '#'.
-N will be between 0 and 2,500, inclusive.


EXAMPLES

0)
{"........",
 "........",
 "........",
 "........"}
3

Returns: {"P.P.P...", "........", "........", "........" }

A nice field with no rocks. We want to plant three potatoes. There are plenty of ways to do it.


1)
{"####.###",
 "##.#####",
 "######.#",
 "###.####"}
3

Returns: {"####P###", "##P#####", "######P#", "###.####" }

A field almost full of rocks, there is only room for at most four potatoes.


2)
{"####.###",
 "##.#####",
 "######.#",
 "##..####"}
5

Returns: { }

There are five soil squares, but planting potatoes on all five of them is not a valid solution. (Two potatoes would be in horizontally adjacent squares.)


3)
{".........",
 ".........",
 ".........",
 ".........",
 "........."}
23

Returns: {"P.P.P.P.P", ".P.P.P.P.", "P.P.P.P.P", ".P.P.P.P.", "P.P.P.P.P" }

The maximum number of potatoes one can plant onto an empty 5 x 9 field.


4)
{".........",
 ".........",
 ".........",
 ".........",
 "........."}
24

Returns: { }

The minimum number of potatoes that doesn't fit into this field.


5)
{".........",
 "#########",
 ".#......#",
 ".########",
 ".#.....##"}
13

Returns: {"P.P.P.P.P", "#########", "P#P.P.P.#", ".########", "P#P.P.P##" }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>
#include <limits>
#include <queue>

using namespace std;

// https://github.com/atcoder/ac-library/blob/master/atcoder/maxflow.hpp
template <class Cap> struct mf_graph {
public:
	mf_graph() : _n(0) {}
	explicit mf_graph(int n) : _n(n), g(n) {}

	int add_edge(int from, int to, Cap cap) {
		assert(0 <= from && from < _n);
		assert(0 <= to && to < _n);
		assert(0 <= cap);
		int m = int(pos.size());
		pos.push_back({ from, int(g[from].size()) });
		int from_id = int(g[from].size());
		int to_id = int(g[to].size());
		if (from == to) to_id++;
		g[from].push_back(_edge{ to, to_id, cap });
		g[to].push_back(_edge{ from, from_id, 0 });
		return m;
	}

	struct edge {
		int from, to;
		Cap cap, flow;
	};

	edge get_edge(int i) {
		int m = int(pos.size());
		assert(0 <= i && i < m);
		auto _e = g[pos[i].first][pos[i].second];
		auto _re = g[_e.to][_e.rev];
		return edge{ pos[i].first, _e.to, _e.cap + _re.cap, _re.cap };
	}
	std::vector<edge> edges() {
		int m = int(pos.size());
		std::vector<edge> result;
		for (int i = 0; i < m; i++) {
			result.push_back(get_edge(i));
		}
		return result;
	}
	void change_edge(int i, Cap new_cap, Cap new_flow) {
		int m = int(pos.size());
		assert(0 <= i && i < m);
		assert(0 <= new_flow && new_flow <= new_cap);
		auto& _e = g[pos[i].first][pos[i].second];
		auto& _re = g[_e.to][_e.rev];
		_e.cap = new_cap - new_flow;
		_re.cap = new_flow;
	}

	Cap flow(int s, int t) {
		return flow(s, t, std::numeric_limits<Cap>::max());
	}

	void bfs(int s, int t, vector<int>& level, deque<int>& que) {
		std::fill(level.begin(), level.end(), -1);
		level[s] = 0;
		que.clear();
		que.push_back(s);
		while (!que.empty()) {
			int v = que.front();
			que.pop_front();
			for (auto e : g[v]) {
				if (e.cap == 0 || level[e.to] >= 0) continue;
				level[e.to] = level[v] + 1;
				if (e.to == t) return;
				que.push_back(e.to);
			}
		}
	};

	Cap dfs(int s, vector<int> &level, vector<int>&iter, int v, Cap up) {
		if (v == s) return up;
		Cap res = 0;
		int level_v = level[v];
		for (int& i = iter[v]; i < int(g[v].size()); i++) {
			_edge& e = g[v][i];
			if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
			Cap d = dfs(s, level, iter, e.to, std::min(up - res, g[e.to][e.rev].cap));
			if (d <= 0) continue;
			g[v][i].cap += d;
			g[e.to][e.rev].cap -= d;
			res += d;
			if (res == up) return res;
		}
		level[v] = _n;
		return res;
	};

	Cap flow(int s, int t, Cap flow_limit) {
		assert(0 <= s && s < _n);
		assert(0 <= t && t < _n);
		assert(s != t);

		std::vector<int> level(_n), iter(_n);
		deque<int> que;

		Cap flow = 0;
		while (flow < flow_limit) {
			bfs(s, t, level, que);
			if (level[t] == -1) break;
			std::fill(iter.begin(), iter.end(), 0);
			Cap f = dfs(s, level, iter, t, flow_limit - flow);
			if (!f) break;
			flow += f;
		}
		return flow;
	}

	std::vector<bool> min_cut(int s) {
		std::vector<bool> visited(_n);
		deque<int> que;
		que.push_back(s);
		while (!que.empty()) {
			int p = que.front();
			que.pop_front();
			visited[p] = true;
			for (auto e : g[p]) {
				if (e.cap && !visited[e.to]) {
					visited[e.to] = true;
					que.push_back(e.to);
				}
			}
		}
		return visited;
	}

private:
	int _n;
	struct _edge {
		int to, rev;
		Cap cap;
	};
	std::vector<std::pair<int, int>> pos;
	std::vector<std::vector<_edge>> g;
};

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

class Potatoes {

public:
	vector <string> plant(vector <string> field, int N) {
		int H = field.size(), W = field[0].length(), st = H * W * 2, ed = H * W * 2 + 1;

		// フローによる二部マッチング
		mf_graph<int> g(H * W * 2 + 2);
		for (int y = 0; y < H; ++y) {
			for (int x = 0; N > 0 && x < W; ++x) {
				if (field[y][x] == '.') {
					if (((x + y) % 2) == 0) {
						// 左側
						g.add_edge(st, y * W + x, 1);
						for (int dir = 0; dir < 4; ++dir) {
							int ny = y + dy[dir], nx = x + dx[dir];
							if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
								g.add_edge(y * W + x, ny * W + nx, 1);
							}
						}
					} else {
						// 右側
						g.add_edge(y * W + x, ed, 1);
					}
				}
			}
		}
		g.flow(st, ed);

		// 最小点被覆を求めるための補助グラフを作る
		vector<vector<int>> edges(H * W);
		vector<int> visited(H * W), q;
		for (auto edge : g.edges()) {
			if (edge.from != st && edge.to != ed) {
				if (edge.flow > 0) {
					// マッチ端点は逆方向に貼る
					edges[edge.to].emplace_back(edge.from);
					visited[edge.from] = -1;
				} else {
					edges[edge.from].emplace_back(edge.to);
				}
			}
		}
		// 非マッチ端点を始点にする
		for (auto edge : g.edges()) {
			if (edge.from != st && edge.to != ed) {
				if (!visited[edge.from]) {
					q.emplace_back(edge.from);
				}
			}
		}
		// 非マッチ端点から到達可能点を求める
		while (!q.empty()) {
			int n = q.back();
			q.pop_back();
			visited[n] = 1;
			for (auto e : edges[n]) {
				if (visited[e] != 1) {
					q.emplace_back(e);
				}
			}
		}

		// 最大独立集合(どの2頂点も辺で結ばれていない)を求める
		auto place = [&](int y, int x) {
			if (N > 0 && field[y][x] == '.') {
				field[y][x] = 'P';
				--N;
			}
		};
		for (auto edge : g.edges()) {
			if (edge.from == st && visited[edge.to] == 1) {
				// 左側かつ到達可能点
				place(edge.to / W, edge.to % W);
			}
			if (edge.to == ed && !visited[edge.from]) {
				// 右側かつ到達不可能点
				place(edge.from / W, edge.from % W);
			}
		}

		return N == 0 ? field : vector<string>();
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) {
		ostringstream os; os << "{\n";
		for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) {
			os << "          \"" << *iter << "\",\n";
		}
		os << "        }";
		return os.str();
	}

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) {
		cerr << "Test Case #" << Case << "...";
		if (Expected == Received) {
			cerr << "PASSED" << endl;
		} else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: " << print_array(Expected) << endl;
			cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"........",
 "........",
 "........",
 "........"};
			int Arg1 = 3;
			string Arr2[] = {"P.P.P...", "........", "........", "........" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"####.###",
				"##.#####",
				"######.#",
				"###.####"};
			int Arg1 = 3;
			string Arr2[] = {"####P###", "##P#####", "######P#", "###.####" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"####.###",
				"##.#####",
				"######.#",
				"##..####"};
			int Arg1 = 5;
//			string Arr2[] = { };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
//			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg2;
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".........",
 ".........",
 ".........",
 ".........",
 "........."};
			int Arg1 = 23;
			string Arr2[] = {"P.P.P.P.P", ".P.P.P.P.", "P.P.P.P.P", ".P.P.P.P.", "P.P.P.P.P" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".........",
 ".........",
 ".........",
 ".........",
 "........."};
			int Arg1 = 24;
//			string Arr2[] = { };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			//vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg2;
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".........",
 "#########",
 ".#......#",
 ".########",
 ".#.....##"};
			int Arg1 = 13;
			string Arr2[] = {"P.P.P.P.P", "#########", "P#P.P.P.#", ".########", "P#P.P.P##" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;







		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"#..#"
			};
			int Arg1 = 2;
			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2;
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"#.",
				".."
			};
			int Arg1 = 2;
			string Arr2[] = {
				"#P",
				"P."
			};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"##.",
				".##"
			};
			int Arg1 = 2;
			string Arr2[] = {
				"##P",
				"P##"
			};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Potatoes ___test;
	___test.run_test(-1);
}
// END CUT HERE
