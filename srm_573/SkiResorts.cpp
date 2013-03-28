// BEGIN CUT HERE
/*
SRM 573 Div1 Medium (450)

PROBLEM STATEMENT
Fox Ciel is the owner of a ski resort. The ski resort has N places numbered 0 through N-1.
There are some bidirectional roads between pairs of places. You are given a vector <string> roads.
If the j-th character of the i-th element of roads is 'Y', there is a bidirectional road that connects place i and place j.
If it is 'N', there's no road between them. You are also given a vector <int> altitude.
The i-th element of altitude is the altitude of the place i.

You can go directly from the place i to the place j by skiing if there is a bidirectional road
between them and the altitude of the place i is higher than or equal to the altitude of the place j.
Ciel wants to reconstruct the ski resort so that place N-1 is reachable (not necessarily directly) from place 0 by skiing.
In the reconstruction, Ciel can change the altitude of some places.
The cost of changing the altitude of a place from x to y is |x - y| units of money, where || denotes the absolute value.

Return the minimal cost required for the reconstruction.
If it is impossible to reach place N-1 from place 0 even after the reconstruction, return -1.


DEFINITION
Class:SkiResorts
Method:minCost
Parameters:vector <string>, vector <int>
Returns:long long
Method signature:long long minCost(vector <string> road, vector <int> altitude)


CONSTRAINTS
-road will contain between 2 and 50 elements, inclusive.
-Each element of road will contain exactly N characters, where N is the number of elements of road.
-Each character in road will be either 'Y' or 'N'.
-For each valid i, the i-th character of the i-th element of road will be 'N'.
-For each valid pair (i, j), the i-th character of the j-th element of road and the j-th character of the i-th element of road will be equal.
-altitude will contain exactly N elements.
-Each element of altitude will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{"NYN",
 "YNY",
 "NYN"}
{30, 20, 10}

Returns: 0

It is possible to reach place 2 from place 0 even without the reconstruction by following the path (place 0) -> (place 1) -> (place 2).


1)
{"NY",
 "YN"}
{10, 20}

Returns: 10

For example, Ciel can change the altitude of both places to 15. The cost is |10 - 15| + |20 - 15| = 10.


2)
{"NYN",
 "YNN",
 "NNN"}
{573, 573, 573}

Returns: -1

Place 2 is not reachable from place 0.


3)
{"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"}
{7, 4, 13, 2, 8, 1, 8, 15, 5, 15}

Returns: 12

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
typedef pair<LL, II> LII;
typedef priority_queue<LII> LIIQueue;
typedef vector<int> IntVec;

class SkiResorts {

public:
	long long minCost(vector <string> road, vector <int> altitude) {
		int sz = (int)road.size();

		// generate alt table
		IntVec alt = altitude;
		sort(alt.begin(), alt.end());
		unique(alt.begin(), alt.end());

		LL mincost[64][64];
		memset(mincost, 0x3f, sizeof(mincost));

		LIIQueue q;
		int i, j;
		for (i = 0; i < (int)alt.size(); ++i) {
			LL cost = abs(alt[i] - altitude[0]);
			mincost[0][i] = cost;
			q.push(LII(-cost, II(0, alt[i])));
		}

		// dijkstra
		while (q.size() > 0) {
			LII current = q.top();
			q.pop();
			int from = current.second.first;
			if (from == (sz-1)) {
				return -current.first;
			}
			for (i = 0; i < (int)alt.size(); ++i) {
				if (alt[i] > current.second.second) {
					break;
				}
				for (j = 0; j < sz; ++j) {
					if (road[from][j] == 'Y') {
						LL cost = -current.first + abs(alt[i] - altitude[j]);
						if (cost < mincost[j][i]) {
							mincost[j][i] = cost;
							q.push(LII(-cost, II(j, alt[i])));
						}
					}
				}
			}
		}

		return -1;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN",
 "YNY",
 "NYN"};
			int Arr1[] = {30, 20, 10};
			long long Arg2 = 0LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NY",
 "YN"};
			int Arr1[] = {10, 20};
			long long Arg2 = 10LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN",
 "YNN",
 "NNN"};
			int Arr1[] = {573, 573, 573};
			long long Arg2 = -1LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"};
			int Arr1[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
			long long Arg2 = 12LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minCost(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SkiResorts ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
