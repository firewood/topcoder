// BEGIN CUT HERE
/*
SRM 572 Div1 Easy (250)

// PROBLEM STATEMENT
// You are a huge fan of an online programming contest called SRM (Special Round Match). To participate in an SRM contest, you must first download an applet called Arena, log in to the Arena by entering your username and password, and start competing.

Recently, to avoid hackers' attacks on the Arena, SRM imposes a new rule for the users' passwords. From now on, the first K characters of each user's password must match its last K characters. In this way, if someone enters a password with different first and last K characters repeatedly, it can be considered an attack from hackers.

However, you love your old password and do not want to change many characters from it. You are given a string oldPassword representing your old password, and an int K. Return the minimum number of characters of oldPassword that must be changed so that the string containing the first K characters of oldPassword is equal to the string containing the last K characters of oldPassword.

DEFINITION
Class:NewArenaPassword
Method:minChange
Parameters:string, int
Returns:int
Method signature:int minChange(string oldPassword, int K)


CONSTRAINTS
-oldPassword will contain between 1 and 50 characters, inclusive.
-Each character of oldPassword will be a lowercase letter 'a' - 'z'.
-K will be between 1 and the number of characters of oldPassword, inclusive.


EXAMPLES

0)
"topcoderopen"
5

Returns: 3

A possible solution is changing your password into "topcndetopcn". To do this, you must change the 4th, 7th, and 10th characters (0-based) of "topcoderopen".

1)
"puyopuyo"
4

Returns: 0

Your old password already satisfies the new rule.

2)
"loool"
3

Returns: 1

The first and the last K characters can overlap. In this case, the only optimal solution is to change your password into "lolol".

3)
"arena"
5

Returns: 0



4)
"amavckdkz"
7

Returns: 5



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
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

class NewArenaPassword {
public:
	int minChange(string oldPassword, int K) {
		int sz = (int)oldPassword.length();
		int ans = 0;
		int i, j, k;
		if (K*2 <= sz) {
			for (i = 0; i < K; ++i) {
				ans += oldPassword[i] != oldPassword[sz-K+i];
			}
		} else {
			int T = sz - K;
			for (i = 0; i < T; ++i) {
				int f[256] = {};
				for (j = 0; (k=i+j*T) < sz; ++j) {
					f[(int)oldPassword[k]] += 1;
				}
				sort(f, f+256, greater<int>());
				ans += j - f[0];
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
			string Arg0 = "topcoderopen";
			int Arg1 = 5;
			int Arg2 = 3;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "puyopuyo";
			int Arg1 = 4;
			int Arg2 = 0;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "loool";
			int Arg1 = 3;
			int Arg2 = 1;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "arena";
			int Arg1 = 5;
			int Arg2 = 0;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "amavckdkz";
			int Arg1 = 7;
			int Arg2 = 5;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NewArenaPassword ___test;
//	___test.run_test(0);
//	___test.run_test(1);
	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
