// BEGIN CUT HERE
/*
SRM 699 Div1 Easy (250)

PROBLEM STATEMENT
N wolves are going to challenge bear Limak.
Each wolf chooses an integer between 0 and 2^30-1, inclusive, and shows it to all other wolves.
No wolf is going to reveal their own number to Limak.
Some wolves may remain completely silent, some may give Limak some information.
The only information a wolf will tell Limak is the bitwise xor of the numbers of all N-1 other wolves (i.e., all wolves except for the wolf who gives this particular information).

Limak's goal is to find the sum of the numbers chosen by the wolves.
If there are multiple sums that are consistent with the information Limak was given, he wants to find the smallest of them.

You are given a vector <int> x with N elements.
Each element of x represents one of the wolves.
If x[i] equals -1, wolf i remained silent.
Otherwise, wolf i announced that the bitwise xor of the other wolves' numbers is x[i].

If there is at least one set of integers 0 and 2^30-1, inclusive, that is consistent with the information given by the wolves, return the smallest possible sum of such a set of numbers. Otherwise, return -1.


DEFINITION
Class:OthersXor
Method:minSum
Parameters:vector <int>
Returns:long long
Method signature:long long minSum(vector <int> x)


CONSTRAINTS
-N will be between 2 and 40, inclusive.
-x will contain exactly N elements.
-Each element in x will be between -1 and 1073741823 (i.e. 2^30-1), inclusive.


EXAMPLES

0)
{1,-1,3}

Returns: 3

There are many scenarios that are consistent with this information.
For example, it is possible that the wolves chose the numbers {15, 12, 13}.
Wolf 0 announces (12 xor 13) = 1, and wolf 2 announces (15 xor 12) = 3.
In this case, the sum of the wolves' numbers would be 15+12+13 = 40.

However, the sum 40 is not the smallest sum possible.
The optimal solution looks as follows:
The wolves chose the numbers {2, 1, 0}.
Wolf 0 announces (1 xor 0) = 1, and wolf 2 announces (2 xor 1) = 3.
The sum in this case is only 2+1+0 = 3, and it can be shown that this is the smallest sum that can be obtained.

1)
{0,0,1}

Returns: -1


2)
{70,100}

Returns: 170

In the only possible scenario wolves choose numbers 100 and 70, resulting in xors 70 and 100.

3)
{-1,0,-1,100,36}

Returns: 164


4)
{0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
1073741823,1073741823,1073741823,123456789,987654321,804289383}

Returns: 11992352010


5)
{1287325,424244444,92759185,812358213,1000000000,825833522,749092703}

Returns: -1


6)
{-1,-1}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class OthersXor {
public:
	long long minSum(vector <int> x) {
		LL zc = count(x.begin(), x.end(), -1);
		LL ans = 0;
		for (LL b = 1 << 29; b > 0; b >>= 1) {
			LL cnt[2] = {};
			for (int a : x) {
				if (a >= 0) {
					cnt[a & b ? 1 : 0] += 1;
				}
			}
			if (cnt[1] <= 0) {
				continue;
			}
			LL m = 1 << 30;
			if (cnt[0] & 1) {
				m = min(m, cnt[0]);
			} else if (zc) {
				m = min(m, cnt[0] + 1);
			}
			if ((cnt[1] & 1) == 0) {
				m = min(m, cnt[1]);
			} else if (zc) {
				m = min(m, cnt[1] + 1);
			}
			if (m == 1 << 30) {
				return -1;
			}
			ans += m * b;
		}
		return ans;
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
			int Arr0[] = {1,-1,3};
			long long Arg1 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1};
			long long Arg1 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {70,100};
			long long Arg1 = 170LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,0,-1,100,36};
			long long Arg1 = 164LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
1073741823,1073741823,1073741823,123456789,987654321,804289383};
			long long Arg1 = 11992352010LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
			long long Arg1 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1};
			long long Arg1 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OthersXor ___test;
	___test.run_test(-1);
}
// END CUT HERE
