// BEGIN CUT HERE
/*
// SRM 533 Div2 Medium (500)

// PROBLEM STATEMENT
// The Casket of Star (sic) is a device in the Touhou universe. Its purpose is
to generate energy rapidly.
Initially it contains n stars in a row. The stars are labeled 0 through n-1
from the left to the right.
You are given a vector <int> weight, where weight[i] is the weight of star i.


The following operation can be repeatedly used to generate energy:

Choose a star x other than the very first star and the very last star.
The x-th star disappears.
This generates weight[x-1] * weight[x+1] units of energy.
We decrease n and relabel the stars 0 through n-1 from the left to the right.


Your task is to use the device to generate as many units of energy as possible.
Return the largest possible total amount of generated energy.

DEFINITION
Class:CasketOfStarEasy
Method:maxEnergy
Parameters:vector <int>
Returns:int
Method signature:int maxEnergy(vector <int> weight)


CONSTRAINTS
-weight will contain between 3 and 10 elements, inclusive.
-Each element in weight will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: 12

We have only 2 choices:

Make the "2" disappear first, and "3" next. The total energy is 1*3 + 1*4 = 7.
Make the "3" disappear first, and "2" next. The total energy is 2*4 + 1*4 = 12.

So the answer is 12.

1)
{100,2,1,3,100}

Returns: 10400

We proceed as follows:
{100,2,1,3,100} => {100,1,3,100} => {100,3,100} => {100,100}
The total energy is 100*1 + 100*3 + 100*100 = 10400.

2)
{2,2,7,6,90,5,9}

Returns: 1818


3)
{477,744,474,777,447,747,777,474}

Returns: 2937051


4)
{1,1,1,1,1,1,1,1,1,1}

Returns: 8

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef map<int, int> IntMap;

class CasketOfStarEasy {
	int len;
	IntMap m;
	int x[16];

	int rec(int mask) {
		if (m.find(mask) != m.end()) {
			return m[mask];
		}
		int &res = m[mask];

		res = 0;

		int i, prev, next;
		prev = 0;
		for (i = 1; i < (len-1); ++i) {
			int b = (1<<i);
			if (mask & b) {
				int a = mask ^ b;
				for (next = i+1; ; ++next) {
					if (mask & (1<<next)) {
						break;
					}
				}

				res = max(res, x[prev]*x[next]+rec(a));

				prev = i;
			}
		}
		return res;
	}

public:
	int maxEnergy(vector <int> weight) {
		m.clear();
		memset(x, 0, sizeof(x));
		len = weight.size();
		if (len < 3) {
			return 0;
		}
		if (len == 3) {
			return weight[0]*weight[2];
		}
		int i;
		for (i = 0; i < len; ++i) {
			x[i] = weight[i];
		}
		int all_mask = (1<<len)-1;
		int mid_mask = ((1<<(len-2))-1)*2;
		int end_mask = all_mask ^ mid_mask;
		m[end_mask] = 0;
		return rec(all_mask);
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
			int Arr0[] = {1,2,3,4};
			int Arg1 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,2,1,3,100};
			int Arg1 = 10400;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,7,6,90,5,9};
			int Arg1 = 1818;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {477,744,474,777,447,747,777,474};
			int Arg1 = 2937051;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;


		//
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {999,997,998,995,996,1,2,3,4,1000};
			int Arg1 = 4993966;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;
		//
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,5,5,5,5,5,100,1000,100,1};
			int Arg1 = 27001;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxEnergy(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CasketOfStarEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
