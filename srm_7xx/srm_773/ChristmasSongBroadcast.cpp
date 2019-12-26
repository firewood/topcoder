// BEGIN CUT HERE
/*
SRM 773 Div1 Easy (300)

PROBLEM STATEMENT

"All I want for Christmas is for everyone to be forced to listen to 'All I Want For Christmas' and all other Christmas songs for the whole December!" exclaimed Santa.

You are the elf in charge of broadcasting Christmas songs to all the households in one specific village.
The village contains N households, and we'll number them 0 to N-1.

You have the whole Elf Broadcasting Network at your disposal.
The network consists of T directional broadcast towers, numbered 0 to T-1.
Each tower can be used arbitrarily many times.
When used, the tower will broadcast the whole Mariah Carey Christmas album to any one household.
The cost of doing so depends both on the household and on the tower used, in a very specific way:
broadcasting from tower x to household y costs ((A[y] * x + B[y]) modulo 1,000,000,007) elf dollars.
Note that all the values in A are small (see Constraints).

Once a household has been "infected" by Christmas music, they are under your control and you can use them to spread the "love" to their neighbors.
Each household that has already heard the album can call any other household and play them the album.
The costs of doing so are given in the vector <string> directCost.
More precisely, the cost of having household i call household j is the ASCII value of the character directCost[i][j].
These costs are symmetric: i calling j costs the same as j calling i.

Return the minimum total cost of spreading the Christmas joy to everyone in the village.


DEFINITION
Class:ChristmasSongBroadcast
Method:minimizeCost
Parameters:int, vector <int>, vector <int>, vector <string>
Returns:int
Method signature:int minimizeCost(int T, vector <int> A, vector <int> B, vector <string> directCost)


NOTES
-It can be shown that the optimal answer will always fit into a signed 32-bit integer.


CONSTRAINTS
-T will be between 1 and 10^9 + 7, inclusive.
-N will be between 1 and 50, inclusive.
-A, B and directCost will have N elements each.
-Each element of A will be between 1 and 100, inclusive.
-Each element of B will be between 0 and 10^9 + 6, inclusive.
-Each element of directCost will have N characters.
-For each i, directCost[i][i] will be '-' (and should be ignored).
-For each distinct i and j, directCost[i][j] will be one of [0-9A-Za-z] (i.e., a digit, an uppercase letter, or a lowercase letter).
-For each distinct i and j, directCost[i][j] will be equal to directCost[j][i].


EXAMPLES

0)
1000000007
{1, 10, 100}
{7, 7, 7}
{"-AA",
 "A-A",
 "AA-"}

Returns: 0

There are three households in this village. The direct broadcast from any house to any other house costs 65 elf dollars (65 is the ASCII value of 'A'). However, we will not use this option because for each household there is a broadcasting tower that can broadcast the song to the house for free.

The optimal solution is to broadcast from tower 1,000,000,000 to house 0, from tower 100,000,000 to house 1, and from tower 10,000,000 to house 2.


1)
1
{1, 1, 1}
{1600, 1500, 1700}
{"-01",
 "0-A",
 "1A-"}

Returns: 1597

There is only a single tower. Broadcasting from the tower to household 0 costs 1600, doing so to household 1 costs 1500, and for household 2 we would pay 1700 elf dollars.

The optimal solution is to use the tower to send Christmas music to household 1, then have household 1 call household 0 (cost 48) and then have the now-infected household 0 call household 2 (cost 49).


2)
2
{100, 100, 100, 100}
{0, 35, 999999910, 123456789}
{"-01z",
 "0-Az",
 "1A-z",
 "zzz-"}

Returns: 160

This time, one cheapest solution is to broadcast from tower 0 to household 0 (cost 0), then from tower 0 to household 1 (cost 35), then from tower 1 to household 2 (cost 3), and finally from any of those households to household 3 (cost 122, which is the ASCII value of 'z').


3)
1
{47}
{1000000006}
{"-"}

Returns: 1000000006

Sometimes broadcasting can be pretty expensive.

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

static const LL MOD = 1000000007LL;

class ChristmasSongBroadcast {
public:
	int minimizeCost(int T, vector <int> A, vector <int> B, vector <string> directCost) {
		int n = (int)A.size();
		static const int INF = 1 << 30;
		vector<int> mc(n, INF);
		priority_queue<II, vector<II>, greater<II> > q;
		for (int i = 0; i < n; ++i) {
			LL cost = B[i];
			for (LL j = (MOD - B[i]) / A[i]; j < T; ++j) {
				LL k = (j * A[i] + B[i]) % MOD;
				cost = min(cost, k);
				if (k < (MOD - k)) {
					j += (MOD / A[i] - 1);
				}
			}
			q.push({ (int)cost, i });
		}
		while (!q.empty()) {
			II t = q.top();
			q.pop();
			if (mc[t.second] != INF) continue;
			mc[t.second] = t.first;
			for (int i = 0; i < n; ++i) {
				if (i != t.second && mc[i] == INF) {
					q.push({ directCost[i][t.second], i });
				}
			}
		}
		return accumulate(mc.begin(), mc.end(), 0);
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
			int Arg0 = 1000000007;
			int Arr1[] = {1, 10, 100};
			int Arr2[] = {7, 7, 7};
			string Arr3[] = {"-AA",
 "A-A",
 "AA-"};
			int Arg4 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1, 1, 1};
			int Arr2[] = {1600, 1500, 1700};
			string Arr3[] = {"-01",
 "0-A",
 "1A-"};
			int Arg4 = 1597;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {100, 100, 100, 100};
			int Arr2[] = {0, 35, 999999910, 123456789};
			string Arr3[] = {"-01z",
 "0-Az",
 "1A-z",
 "zzz-"};
			int Arg4 = 160;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {47};
			int Arr2[] = {1000000006};
			string Arr3[] = {"-"};
			int Arg4 = 1000000006;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 123456789;
			int Arr1[] = { 47 };
			int Arr2[] = { 1000000006 };
			string Arr3[] = { "-" };
			int Arg4 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 9999334;
			int Arr1[] = { 100 };
			int Arr2[] = { 66666 };
			string Arr3[] = { "-" };
			int Arg4 = 66666;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChristmasSongBroadcast ___test;
	___test.run_test(-1);
}
// END CUT HERE
