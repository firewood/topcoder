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

class BipartiteMatching {
	int _size;
	vector<int> _left;
	vector<int> _right;
	vector<vector<int>> _edges;
	vector<int> _match;
	vector<int> _visited;
public:
	BipartiteMatching(int size) : _size(size) {
		_left.resize(size);
		_right.resize(size);
		_edges = vector<vector<int>>(size);
	}

	void set_left(int n) { _left[n] = 1; }

	void set_right(int n) { _right[n] = 1; }

	void add_edge(int left, int right) {
		_edges[left].emplace_back(right);
		_edges[right].emplace_back(left);
	}

	int match() {
		int matched = 0;
		_match = vector<int>(_size, -1);
		for (int i = 0; i < _size; ++i) {
			if (_left[i] && _match[i] < 0) {
				_visited = vector<int>(_size);
				matched += dfs(i);
			}
		}
		return matched;
	}

	bool dfs(int n) {
		_visited[n] = 1;
		for (auto x : _edges[n]) {
			auto& w = _match[x];
			if (w < 0 || (!_visited[w] && dfs(w))) {
				_match[n] = x;
				w = n;
				return true;
			}
		}
		return false;
	}

	vector<int> getMaximumIndependentSet() {
		match();
		vector<vector<int>> edges(_size);
		vector<int> visited(_size);
		vector<int> q;
		for (int i = 0; i < _size; ++i) {
			if (_left[i]) {
				for (auto x : _edges[i]) {
					if (_match[i] == x) {
						edges[x].emplace_back(i);
					} else {
						edges[i].emplace_back(x);
					}
				}
				if (_match[i] < 0) {
					q.emplace_back(i);
				}
			}
		}
		while (!q.empty()) {
			auto n = q.back();
			q.pop_back();
			visited[n] = 1;
			for (auto x : edges[n]) {
				if (!visited[x]) {
					q.emplace_back(x);
				}
			}
		}
		vector<int> s;
		for (int i = 0; i < _size; ++i) {
			if ((_left[i] && visited[i]) || (_right[i] && !visited[i])) {
				s.emplace_back(i);
			}
		}
		return s;
	}
};

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

class Potatoes {

public:
	vector <string> plant(vector <string> field, int N) {
		int H = field.size(), W = field[0].length();
		auto yx = [&](int y, int x) { return y * W + x; };
		BipartiteMatching bm(H * W);
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				if (field[y][x] == '.') {
					if ((y + x) % 2 == 0) {
						bm.set_left(yx(y, x));
						for (int dir = 0; dir < 4; ++dir) {
							int ny = y + dy[dir], nx = x + dx[dir];
							if (ny >= 0 && ny < H && nx >= 0 && nx < W && field[ny][nx] == '.') {
								bm.add_edge(yx(y, x), yx(ny, nx));
							}
						}
					} else {
						bm.set_right(yx(y, x));
					}
				}
			}
		}
		vector<int> mis = bm.getMaximumIndependentSet();
		if (mis.size() < N) {
			return {};
		}
		for (int i = 0; i < N; ++i) {
			field[mis[i] / W][mis[i] % W] = 'P';
		}
		return field;
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
			string Arr0[] = {
				"........",
				 "........",
				 "........",
				 "........"
			};
			int Arg1 = 3;
			string Arr2[] = {
				".P.P.P..",
				"........",
				"........",
				"........"
			};

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
				"###.####"
			};
			int Arg1 = 3;
			string Arr2[] = {
				"####P###",
				"##P#####",
				"######P#",
				"###.####"
			};

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

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2;
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				".........",
				".........",
				".........",
				".........",
				"........."
			};
			int Arg1 = 23;
			string Arr2[] = {
				"P.P.P.P.P",
				".P.P.P.P.",
				"P.P.P.P.P",
				".P.P.P.P.",
				"P.P.P.P.P"
			};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				".........",
				".........",
				".........",
				".........",
				"........."
			};
			int Arg1 = 24;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg2;
			verify_case(n, Arg2, plant(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				".........",
				"#########",
				".#......#",
				".########",
				".#.....##"
			};
			int Arg1 = 13;
			string Arr2[] = {
				"P.P.P.P.P",
				"#########",
				"P#.P.P.P#",
				".########",
				"P#P.P.P##"
			};

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
