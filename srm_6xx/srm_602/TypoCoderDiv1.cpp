// BEGIN CUT HERE
/*
SRM 602 Div1 Easy (250)

PROBLEM STATEMENT
TypoCoder is a programming contest like TopCoder.
TypoCoder also has a rating system.
There are two types of coders in TypoCoder: brown coders and ciel coders.
A brown coder is a coder whose rating is greater than or equal to 2200.
A ciel coder is a coder whose rating is less than 2200.

Cat Lower competes in TypoCoder.
He is currently a ciel coder.
His rating at the end of the current year is X.

Next year there will be some contests.
In each of those contests, Cat Lower can either try his best or lose on purpose.
For each i, the i-th contest (0-based index) has weight D[i].
If Cat Lower tries his best in the i-th contest, his rating will increase by D[i].
If he decides to lose on purpose instead, his rating will decrease by D[i], but not below zero.
Formally, his rating will decrease by min(D[i],his rating before the contest).

Cat Lower loves being a ciel coder.
Therefore, he must never be a brown coder twice in a row.
That is, whenever Cat Lower becomes a brown coder, he must be ciel again after the next contest (if there are any contests left).

TypoCoder awards "Chameleon coder of the year" to the coder whose color changed the most times during the year.

You are given the vector <int> D and the int X.
Return the maximal number of color changes Cat Lower can have next year.


DEFINITION
Class:TypoCoderDiv1
Method:getmax
Parameters:vector <int>, int
Returns:int
Method signature:int getmax(vector <int> D, int X)


CONSTRAINTS
-D will contain between 1 and 50 elements, inclusive.
-Each element of D will be between 0 and 1,000,000,000 (10^9), inclusive.
-X will be between 0 and 2199, inclusive.


EXAMPLES

0)
{100,200,100,1,1}
2000

Returns: 3

When he increase at the second, the third and the last competition and decrease at the first and the fourth competition, he can change the color 3 times and this is the maximal.

1)
{0,0,0,0,0}
2199

Returns: 0

He cannot be a brown coder in this case.


2)
{90000,80000,70000,60000,50000,40000,30000,20000,10000}
0

Returns: 1

Note that Cat Lower always has at least one valid strategy: if he decides to lose in all contests, he will remain ciel forever.
In this test case, the optimal strategy for him is to lose in the first eight contests and then to win in the last one.
Note that before the last contest his rating will be 0.


3)
{1000000000,1000000000,10000,100000,2202,1}
1000

Returns: 4


4)
{2048,1024,5012,256,128,64,32,16,8,4,2,1,0}
2199

Returns: 0


5)
{61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272}
1223

Returns: 29


6)
{34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32}
1328

Returns: 20

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class TypoCoderDiv1 {
public:
	int getmax(vector <int> D, int X) {
		int N = (int)D.size();
		int dp[64][2200];
		memset(dp, -1, sizeof(dp));
		dp[0][X] = 0;
		for (int i = 0; i < N; ++i) {
			for (int r = 0; r < 2200; ++r) {
				if (dp[i][r] >= 0) {
					// win
					int next = r + D[i];
					if (next >= 2200) {
						if (i == N-1) {
							// any rating is OK
							dp[N][0] = max(dp[N][0], dp[i][r] + 1);
						} else {
							int nn = max(0, next - D[i+1]);
							if (nn < 2200) {
								dp[i+2][nn] = max(dp[i+2][nn], dp[i][r] + 2);
							}
						}
					} else {
						dp[i+1][next] = max(dp[i+1][next], dp[i][r]);
					}
					// lose
					next = max(0, r - D[i]);
					dp[i+1][next] = max(dp[i+1][next], dp[i][r]);
				}
			}
		}

		int ans = 0;
		for (int r = 0; r < 2200; ++r) {
			ans = max(ans, dp[N][r]);
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
			int Arr0[] = {100,200,100,1,1};
			int Arg1 = 2000;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0};
			int Arg1 = 2199;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
			int Arg1 = 0;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000,1000000000,10000,100000,2202,1};
			int Arg1 = 1000;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
			int Arg1 = 2199;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
			int Arg1 = 1223;
			int Arg2 = 29;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
			int Arg1 = 1328;
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TypoCoderDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
