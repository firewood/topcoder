// BEGIN CUT HERE
/*
SRM 584 Div2 Medium (500)

PROBLEM STATEMENT
A kingdom has n citizens. Each one has some amount of money, a number of dollars denoted by a non-negative integer.

Citizens are numbered from 0 to n-1. Some citizens have friends. Their friendship network is described by a vector <string> called isFriend, such that if isFriend[i][j] == 'Y', the citizens numbered i and j are friends, and if isFriend[i][j] == 'N', these citizens are not friends.

The king decrees the following:

Each citizen's amount of money must be within d dollars of the amount of money belonging to any of his friends. In other words, a citizen with x dollars must not have any friends with less than x-d dollars or more than x+d dollars.

Given the number of citizens and their friendship network, what is the greatest possible money difference between any two people (not necessarily friends) in this kingdom? If there is a finite answer, return it. Otherwise, return -1.


DEFINITION
Class:Egalitarianism
Method:maxDifference
Parameters:vector <string>, int
Returns:int
Method signature:int maxDifference(vector <string> isFriend, int d)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-d will be between 0 and 1,000, inclusive.
-isFriend will contain exactly n elements.
-Each element of isFriend will contain exactly n characters, each of which is either 'Y' or 'N'.
-For any i, isFriend[i][i] = 'N'.
-For any i and j, isFriend[i][j] = isFriend[j][i].


EXAMPLES

0)
{"NYN",
 "YNY",
 "NYN"}
10

Returns: 20

The kingdom has three citizens. Citizens 0 and 1 are friends. Also, citizens 1 and 2 are friends. The greatest possible money difference between any two citizens is $20, as in the following configuration: citizen 0 has $100; citizen 1 has $110; citizen 2 has $120.


1)
{"NN",
 "NN"}
1

Returns: -1

Since citizens 0 and 1 are not friends, there are no constraints between them.


2)
{"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"}
1000

Returns: 3000


3)
{"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"}
584

Returns: -1


4)
{"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"}
5

Returns: 20


5)
{"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}

747

Returns: 2988


6)
{"NY",
 "YN"}
0

Returns: 0

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

using namespace std;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
*/
// END CUT HERE

#define INF 1000000000

class Egalitarianism {
public:
	int maxDifference(vector <string> isFriend, int d) {
		int dp[50][50];
		int i, j, k, N = (int)isFriend.size();
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				dp[i][j] = i == j ? 0 : (isFriend[i][j] == 'Y' ? 1 : INF);
			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		int ans = 0;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				ans = max(ans, dp[i][j]);
			}
		}
		return ans >= INF ? -1 : ans * d;
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
			string Arr0[] = {"NYN",
 "YNY",
 "NYN"};
			int Arg1 = 10;
			int Arg2 = 20;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NN",
 "NN"};
			int Arg1 = 1;
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"};
			int Arg1 = 1000;
			int Arg2 = 3000;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"};
			int Arg1 = 584;
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"};
			int Arg1 = 5;
			int Arg2 = 20;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}
;
			int Arg1 = 747;
			int Arg2 = 2988;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NY",
 "YN"};
			int Arg1 = 0;
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxDifference(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Egalitarianism ___test;
	___test.run_test(-1);
}
// END CUT HERE
