// BEGIN CUT HERE
/*
SRM 570 Div2 Hard (1000)

// PROBLEM STATEMENT
// The Centaur company has N servers, numbered 1 through N.
These servers are currently connected into a network.
The topology of the network is a tree.
In other words, there are exactly N-1 bidirectional cables, each connecting some two servers in such a way that the entire network is connected.

The Centaur company is about to split into two new companies: the Human company and the Horse company.
When this happens, the companies will divide the servers somehow.
Once they divide their servers, they will cut each cable that connects a server of the Horse company and a server of the Human company.

While the Horse company has a lot of cables, the Human company does not have any.
Therefore, when dividing the servers, the Human company must get a set of servers that will remain connected after the cables are cut.

You are given two vector <int>s a and b, each containing N-1 elements.
These two arrays describe the original cables:
for each i, there is a cable that connects the servers a[i] and b[i].

Compute and return the number of different ways in which the two companies may divide the servers.
(It is possible that one of the companies will get no servers at all.)

DEFINITION
Class:CentaurCompanyDiv2
Method:count
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long count(vector <int> a, vector <int> b)


NOTES
-N can be determined as (1 + the length of a).


CONSTRAINTS
-N will be between 2 and 51, inclusive.
-a and b will contain exactly N-1 elements.
-Each element of a and b will be between 1 and N, inclusive.
-The network defined by a and b will be a tree (as explained in the problem statement).


EXAMPLES

0)
{1}
{2}

Returns: 4

There are 2^2 = 4 ways to divide the servers between two companies. For any division, the Human company's servers will remain connected.

1)
{2,2}
{1,3}

Returns: 7

There are 2^3 = 8 ways to divide the servers between two companies. However, if the Human company gets server 1 and server 3, and the Horse company gets server 2, the Human company's servers will not be connected. Therefore the number of valid ways is 8 - 1 = 7.

2)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}

Returns: 56



3)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51}

Returns: 1125899906842675

The answer overflows a 32-bit integer data type.

4)
{10, 7, 2, 5, 6, 2, 4, 9, 7}
{8, 10, 10, 4, 1, 6, 2, 2, 3}

Returns: 144



*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;

class CentaurCompanyDiv2 {

	IntVec _a;
	IntVec _b;
	LL dp[51];

	LL dfs(int parent, int node) {
		LL res = 1;
		for (int i = 0; i < (int)_a.size(); ++i) {
			if (_a[i] == node) {
				if (_b[i] != parent) {
					res *= (dfs(node, _b[i]) + 1);
				}
			}
			if (_b[i] == node) {
				if (_a[i] != parent) {
					res *= (dfs(node, _a[i]) + 1);
				}
			}
		}
		return dp[node - 1] = res;
	}

public:
	long long count(vector <int> a, vector <int> b) {
		_a = a, _b = b;
		dfs(-1, 1);
		LL ans = 1;
		for (int i = 0; i <= (int)a.size(); ++i) {
			ans += dp[i];
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
			int Arr0[] = {1};
			int Arr1[] = {2};
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2};
			int Arr1[] = {1,3};
			long long Arg2 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9};
			int Arr1[] = {2,3,4,5,6,7,8,9,10};
			long long Arg2 = 56LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
			long long Arg2 = 1125899906842675LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7};
			int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3};
			long long Arg2 = 144LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CentaurCompanyDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
