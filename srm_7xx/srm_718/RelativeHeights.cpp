// BEGIN CUT HERE
/*
SRM 718 Div2 Easy (250)

PROBLEM STATEMENT
The city of Byteland has plans to give the city a new skyline by building n new skyscrapers in a row.
The skyscrapers will be numbered 0 through n-1 from left to right.
The height of skyscraper i will be h[i].
It is guaranteed that all the heights are distinct.

The height profile of a skyline is a sequence of integers that is produced by writing down the numbers of the skyscrapers in the order of their height, starting from the tallest one.
For example, if the heights of the skyscrapers were {50,20,10,40,30}, the height profile would be {0,3,4,1,2}:
skyscraper 0 is the tallest one, skyscraper 3 is the second tallest, and so on.

Unfortunately, due to some budget constraints, Byteland can only afford to build n-1 of the planned n skyscrapers.
A committee is going to choose which one of the n skyscrapers they won't build.
The remaining n-1 skyscrapers will then receive new numbers: 0 through n-2, again going from left to right.

Different choices by the committee may lead to skylines with different height profiles.
Compute and return the number of distinct height profiles that can be produced.


DEFINITION
Class:RelativeHeights
Method:countWays
Parameters:vector <int>
Returns:int
Method signature:int countWays(vector <int> h)


CONSTRAINTS
-h will contain between 2 and 50 elements, inclusive.
-Each element of h will be between 1 and 1,000, inclusive.
-Elements of h will be distinct.


EXAMPLES

0)
{1,3,6,10,15,21}

Returns: 1

The committee can choose one of six different skylines:

{3,5,10,15,21}
{1,5,10,15,21}
{1,3,10,15,21}
{1,3,5,15,21}
{1,3,5,10,21}
{1,3,5,10,15}

However, all of these skylines have the same height profile: {4,3,2,1,0}.


1)
{4,2,1,3}

Returns: 3

Here, the committee can choose one of four possible skylines: {2,1,3}, {4,1,3}, {4,2,3}, or {4,2,1}.
The height profiles of these skylines are {2,0,1}, {0,2,1}, {0,2,1}, and {0,1,2}, respectively.
As the second and the third skyline share the same height profile, there are only three distinct height profiles.


2)
{6,2,352,43,5,44}

Returns: 6


3)
{4,5,6,1,2,3}

Returns: 2


4)
{10,9,7,5,3,1,8,6,4,2}

Returns: 9

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

IntVec getOrder(vector<int> v) {
	IntVec r;
	IIVec a;
	for (int i = 0; i != v.size(); ++i) {
		a.push_back(II(v[i], i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i != v.size(); ++i) {
		r.push_back(a[i].second);
	}
	return r;
}

class RelativeHeights {
	public:
	int countWays(vector <int> h) {
		set<IntVec> s;
		for (int i = 0; i != h.size(); ++i) {
			IntVec a = h;
			a.erase(a.begin() + i);
			s.insert(getOrder(a));
		}
		return s.size();
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
			int Arr0[] = {1,3,6,10,15,21};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2,1,3};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,2,352,43,5,44};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,5,6,1,2,3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,7,5,3,1,8,6,4,2};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RelativeHeights ___test;
	___test.run_test(-1);
}
// END CUT HERE
