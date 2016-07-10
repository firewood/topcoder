// BEGIN CUT HERE
/*
SRM 694 Div1 Easy (250)

PROBLEM STATEMENT
There are N students in your class.
The strength of each student is a small nonnegative integer.
You are given these strengths in the vector <int> strength with N elements.

You are going to divide all students into three teams for the boat race "TrySail".
Each student must be assigned to exactly one of the three teams.
Teams cannot be empty.

Strangely enough, in this race the strength of a team is the bitwise xor of the strengths of its members.
You want to maximize the sum of strengths of the three teams.
Compute and return the largest possible sum of the teams' strengths.

DEFINITION
Class:TrySail
Method:get
Parameters:vector <int>
Returns:int
Method signature:int get(vector <int> strength)


CONSTRAINTS
-N will be between 3 and 50, inclusive.
-strength will contain exactly N elements.
-Each element of strength will be between 0 and 255, inclusive.


EXAMPLES

0)
{2,3,3}

Returns: 8

There are only three students.
The only way to create three nonempty teams is to put each student into a different team.
In that case the sum of teams' strengths will be 2+3+3 = 8.


1)
{7,3,5,2}

Returns: 17

There are 6 ways to make 3 teams:
・ {0},{1},{2,3}: sum of strengths is 7+3+(5 xor 2) = 17
・ {0},{2},{1,3}: sum of strengths is 7+5+(3 xor 2) = 13
・ {0},{3},{1,2}: sum of strengths is 7+2+(3 xor 5) = 15
・ {1},{2},{0,3}: sum of strengths is 3+5+(7 xor 2) = 13
・ {1},{3},{0,2}: sum of strengths is 3+2+(7 xor 5) = 7
・ {2},{3},{0,1}: sum of strengths is 5+2+(7 xor 3) = 11
Therefore, the answer is 17.


2)
{13,13,13,13,13,13,13,13}

Returns: 26


3)
{114,51,4,191,9,81,0,89,3}

Returns: 470


4)
{108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197}

Returns: 567

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TrySail {
public:
	int get(vector <int> strength) {
		int N = (int)strength.size();
		int dp[60][256][256] = {};
		dp[0][0][0] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 256; ++j) {
				for (int k = 0; k < 256; ++k) {
					if (dp[i][j][k]) {
						dp[i + 1][j][k] = 1;
						dp[i + 1][j ^ strength[i]][k] = 1;
						dp[i + 1][j][k ^ strength[i]] = 1;
					}
				}
			}
		}
		int tot = 0;
		for (int i = 0; i < N; ++i) {
			tot ^= strength[i];
		}
		int ans = 0;
		for (int j = 0; j < 256; ++j) {
			for (int k = 0; k < 256; ++k) {
				if (dp[N][j][k]) {
					ans = max(ans, j + k + (tot ^ j ^ k));
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
			int Arr0[] = {2,3,3};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,3,5,2};
			int Arg1 = 17;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13,13,13,13,13,13,13,13};
			int Arg1 = 26;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {114,51,4,191,9,81,0,89,3};
			int Arg1 = 470;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
			int Arg1 = 567;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrySail ___test;
	___test.run_test(-1);
}
// END CUT HERE
