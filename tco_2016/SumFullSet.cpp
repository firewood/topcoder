// BEGIN CUT HERE
/*
TCO 2016 Round 1C Easy (250)

PROBLEM STATEMENT

Let S be a sequence of (not necessarily distinct) integers.
We say that S is closed under addition if it has the following property:
For any pair of valid and distinct indices i and j, the number S[i]+S[j] does also occur in the sequence S (one or more times).

Note that the numbers S[i] and S[j] may be equal, only the indices i and j are required to be distinct.
Also note that from the definition it follows that any 0-element or 1-element sequence is closed under addition,
 as there are no valid pairs of distinct indices into such a sequence.

You are given a sequence of integers in a vector <int> elements.
Return "closed" (quotes for clarity) if the given sequence is closed under addition.
Otherwise, return "not closed".


DEFINITION
Class:SumFullSet
Method:isSumFullSet
Parameters:vector <int>
Returns:string
Method signature:string isSumFullSet(vector <int> elements)


CONSTRAINTS
-Number of elements in elements will be between 1 and 50, both inclusive.
-Each element of elements will be between -50 and 50, both inclusive.


EXAMPLES

0)
{-1,0,1}

Returns: "closed"


(-1) + 0 = (-1), which does appear in our sequence
(-1) + 1 = 0, which does appear in our sequence
0 + 1 = 1, which does appear in our sequence
hence, our sequence is closed under addition


1)
{-1,1}

Returns: "not closed"


2)
{0,1}

Returns: "closed"


3)
{0,1,1}

Returns: "not closed"

This sequence is not closed under addition because 1+1 = 2, which is not an element of our sequence.


4)
{16,0,43,43,-36,-49,-46,-16,40,34,-43,-24,13,-48,45,19,12,0,43,6,26,-23,50,28,-3,21,46,45,-32,-41,0,-27,42,19,47,-36,-21,-1,5,-21,-28,-43,23,-26,-5,21,-41,16,-37,38}

Returns: "not closed"


5)
{10}

Returns: "closed"

A 1-element sequence is closed under addition by definition.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SumFullSet {
public:
	string isSumFullSet(vector <int> elements) {
		set<int> s(elements.begin(), elements.end());
		for (int i = 0; i != elements.size(); ++i) {
			for (int j = i + 1; j != elements.size(); ++j) {
				if (s.find(elements[i] + elements[j]) == s.end()) {
					return "not closed";
				}
			}
		}
		return "closed";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,0,1};
			string Arg1 = "closed";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isSumFullSet(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,1};
			string Arg1 = "not closed";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isSumFullSet(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1};
			string Arg1 = "closed";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isSumFullSet(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,1};
			string Arg1 = "not closed";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isSumFullSet(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {16,0,43,43,-36,-49,-46,-16,40,34,-43,-24,13,-48,45,19,12,0,43,6,26,-23,50,28,-3,21,46,45,-32,-41,0,-27,42,19,47,-36,-21,-1,5,-21,-28,-43,23,-26,-5,21,-41,16,-37,38};
			string Arg1 = "not closed";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isSumFullSet(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			string Arg1 = "closed";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isSumFullSet(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SumFullSet ___test;
	___test.run_test(-1);
}
// END CUT HERE
