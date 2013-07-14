// BEGIN CUT HERE
/*
SRM 584 Div2 Hard (1000)

PROBLEM STATEMENT
Once upon a time, there was a civilization called Ruritania. It had n building sites numbered from 0 to n-1. There were various types of buildings such as libraries, markets, and palaces. Each building type was assigned an integer from 1 to 50. The building at site i (0-based index) was of type kind[i].

With the passing of millennia, Ruritania declined and its building sites were covered in sand, concealing all the buildings. Recently, an intrepid archeologist excavated K building sites.

You are given vector <int>s kind and found as well as the int K. The types of buildings discovered by the excavation are described by the vector <int> found, which contains at most one value for each building type even if several buildings of a type were excavated.

Return the number of K-tuples of sites that could have been excavated to arrive at the given values. The answer is guaranteed to be at least one.


DEFINITION
Class:Excavations2
Method:count
Parameters:vector <int>, vector <int>, int
Returns:long long
Method signature:long long count(vector <int> kind, vector <int> found, int K)


CONSTRAINTS
-kind will contain N elements, where N is between 1 and 50, inclusive.
-Each element of kind will be between 1 and 50, inclusive.
-found will contain between 1 and 50 elements, inclusive.
-Each element of found will occur in kind at least once.
-The elements of found will be distinct.
-K will be between the number of elements in found and N, inclusive.
-There will exist at least one K-tuple of sites consistent with the given information.


EXAMPLES

0)
{1, 2, 2, 1}
{1}
2

Returns: 1

There are four building sites. Two contain a building of type 1 and two contain a building of type 2. The archeologist excavated two sites and only found buildings of type 1. The only possible scenario is that the archeologist excavated sites 0 and 3.


1)
{1, 2, 2, 1}
{1, 2}
2

Returns: 4

The building sites are the same as before, but in this case buildings of type 1 and type 2 have been discovered. The archeologist must have excavated one of four possible pairs of sites: (0, 1), (0, 2), (1, 3), or (2, 3).


2)
{1, 2, 1, 1, 2, 3, 4, 3, 2, 2}
{4, 2}
3

Returns: 6

The archeologist excavated one of six possible triples of building sites:

(1, 4, 6)
(1, 6, 8)
(1, 6, 9)
(4, 6, 8)
(4, 6, 9)
(6, 8, 9)


3)
{50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}
{50}
21

Returns: 5567902560

*/
// END CUT HERE
#include <string.h>
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
typedef map<II, LL> IILLMap;

#define COMBSZ 100

class Excavations2 {
	int N;
	int F;
	int cnt[51];
	LL C[COMBSZ][COMBSZ];
	IntVec fnd;
	IILLMap memo;

	LL rec(int i, int k) {
		if (i >= F || k <= 0) {
			return 0;
		}
		II key(i, k);
		if (memo.find(key) != memo.end()) {
			return memo[key];
		}
		int c = cnt[fnd[i]];
		LL &r = memo[key];
		if (i == (F-1)) {
			r = c >= k ? C[c][k] : 0;
		} else {
			int j;
			for (j = 1; j < k; ++j) {
				r += C[c][j] * rec(i+1, k-j);
			}
		}
		return r;
	}

public:
	long long count(vector <int> kind, vector <int> found, int K) {
		memset(cnt, 0, sizeof(cnt));
		memset(C, 0, sizeof(C));
		memo.clear();
		N = (int)kind.size();
		F = (int)found.size();
		fnd = found;
		int i, j;
		for (i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
		}
		for (i = 1; i < COMBSZ; ++i) {
			for (j = 1; j < COMBSZ; ++j) {
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
		for (i = 0; i < N; ++i) {
			cnt[kind[i]] += 1;
		}
		return rec(0, K);
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
			int Arr0[] = {1, 2, 2, 1};
			int Arr1[] = {1};
			int Arg2 = 2;
			long long Arg3 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 2, 1};
			int Arr1[] = {1, 2};
			int Arg2 = 2;
			long long Arg3 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2};
			int Arr1[] = {4, 2};
			int Arg2 = 3;
			long long Arg3 = 6LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
			int Arr1[] = {50};
			int Arg2 = 21;
			long long Arg3 = 5567902560LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Excavations2 ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
