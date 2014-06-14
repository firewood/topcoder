// BEGIN CUT HERE
/*
SRM 622 Div1 Easy (250)

PROBLEM STATEMENT
In the Republic of Nlogonia there are N cities.
For convenience, the cities are numbered 0 through N-1.
For each two different cities i and j, there is a direct one-way road from i to j.
You are given the lengths of those roads as a vector <string> dist with N elements, each with N characters.
For each i and j, the character dist[i][j] represents the length of the road from i to j.

The lengths of roads are integers between 1 and 9, inclusive, and they are represented by digits '1' through '9'.
That is, for distinct i and j, dist[i][j] will be between '1' and '9'.
For each i, dist[i][i] will be '0'.
Note that the roads from i to j and from j to i may have different lengths.

Every year on Algorithms Day (the most important holiday in Nlogonia) people travel between the cities.
More precisely, for each pair of distinct cities i and j, one full bus of people travels from i to j.
Each of those buses drives along a shortest path from its origin to its destination.
If there are multiple shortest paths, the bus driver picks one of them arbitrarily.

The roads in Nlogonia are currently limited.
You are given an int T with the following meaning: 
each of the current roads is only safe if it is guaranteed that there will be strictly fewer than T buses driving along the road.
In other words, a road is unsafe if it is possible that T or more buses will use it.
The government wants to rebuild all unsafe roads before the next Algorithms Day.
Return the sum of lengths of all unsafe roads.


DEFINITION
Class:BuildingRoutes
Method:build
Parameters:vector <string>, int
Returns:int
Method signature:int build(vector <string> dist, int T)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-dist will contain exactly N elements.
-Each element of dist will contain exactly N characters.
-For each i, dist[i][i] will be '0'.
-For each pair of distinct i and j, dist[i][j] will be between '1' and '9', inclusive.
-T will be between 1 and 2500, inclusive.


EXAMPLES

0)
{"011",
 "101",
 "110"}
1

Returns: 6

As T=1, a road is unsafe as soon as it is possible that a bus will use it. 
Each of the six roads in this test case belongs to some shortest path, hence each of them is unsafe


1)
{"033",
 "309",
 "390"}
1

Returns: 12

The roads 1->2 and 2->1 (the two roads of length 9) will not be used by any bus.
Only the four remaining roads are unsafe in this case.


2)
{"0123",
 "1023",
 "1203",
 "1230"}
2

Returns: 5


3)
{"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"}
3

Returns: 40

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BuildingRoutes {
public:
	int build(vector <string> dist, int T) {
		int N = (int)dist.size();

		int d[50][50] = {};
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				d[i][j] = dist[i][j] - '0';
			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					if (i != j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
		}

		int ans = 0;

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (i != j) {
					int cnt = 0;
					for (int p = 0; p < N; ++p) {
						for (int q = 0; q < N; ++q) {
							if (p != q) {
								if (d[p][i] + (dist[i][j] - '0') + d[j][q] == d[p][q]) {
									++cnt;
								}
							}
						}
					}
					if (cnt >= T) {
						ans += dist[i][j] - '0';
					}
				}
			}
		}

		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"011",
 "101",
 "110"};
			int Arg1 = 1;
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"033",
 "309",
 "390"};
			int Arg1 = 1;
			int Arg2 = 12;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0123",
 "1023",
 "1203",
 "1230"};
			int Arg1 = 2;
			int Arg2 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"};
			int Arg1 = 3;
			int Arg2 = 40;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingRoutes ___test;
	___test.run_test(-1);
}
// END CUT HERE
