// BEGIN CUT HERE
/*
SRM 621 Div2 Medium (500)

PROBLEM STATEMENT
Your friend Lucas gave you a sequence S of positive integers.

For a while, you two played a simple game with S:
Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas.
For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.

Lucas now wants to trick you by choosing a number X such that there will be no valid answer.
For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.

You are given the vector <int> S.
Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.


DEFINITION
Class:NumbersChallenge
Method:MinNumber
Parameters:vector <int>
Returns:int
Method signature:int MinNumber(vector <int> S)


CONSTRAINTS
-S will contain between 1 and 20 elements, inclusive.
-Each element of S will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{5, 1, 2}

Returns: 4

These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8.
(We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.)
The smallest positive integer not present in the above list is 4.


1)
{2, 1, 4}

Returns: 8

We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.


2)
{2, 1, 2, 7}

Returns: 6

The example given in the problem statement.


3)
{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}

Returns: 1092


4)
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}

Returns: 56523

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class NumbersChallenge {
public:
	int MinNumber(vector <int> S) {
		int f[2][524288] = {};
		f[0][0] = 1;
		int a, b = 0;
		for (int i = 0; i < S.size(); ++i){
			a = i % 2, b = a ^ 1;
			memcpy(f[b], f[a], sizeof(f[0]));
			for (int j = 0; j < 524288; ++j) {
				if (f[a][j] && (j + S[i]) < 524288) {
					f[b][j + S[i]] = 1;
				}
			}
		}
		int ans;
		for (ans = 1;; ++ans){
			if (!f[b][ans]) {
				break;
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
			int Arr0[] = {5, 1, 2};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1, 4};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1, 2, 7};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
			int Arg1 = 1092;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
			int Arg1 = 56523;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinNumber(Arg0));
		}
		n++;


		// test_case_108
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 99941, 99967, 99934 };
			int Arg1 = 430914;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinNumber(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NumbersChallenge ___test;
	___test.run_test(-1);
}
// END CUT HERE
