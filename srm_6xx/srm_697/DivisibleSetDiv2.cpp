// BEGIN CUT HERE
/*
SRM 697 Div2 Medium

PROBLEM STATEMENT
You are given a vector <int> b containing a sequence of n positive integers: b[0], ..., b[n-1].
We are now looking for another sequence a[0], ..., a[n-1].
This sequence should have the following properties:

Each a[i] should be a number of the form 2^x[i] where x[i] is some positive integer. In other words, each a[i] is one of the numbers 2, 4, 8, 16, ...
For each i, the value a[i]^b[i] (that is, a[i] to the power b[i]) should be divisible by P, where P is the product of all a[i].

Determine whether there is at least one sequence with the desired properties.
Return "Possible" (quotes for clarity) if such a sequence exists and "Impossible" otherwise.

 
DEFINITION
Class:DivisibleSetDiv2
Method:isPossible
Parameters:vector <int>
Returns:string
Method signature:string isPossible(vector <int> b)


CONSTRAINTS
-b will contain between 1 and 50 elements, inclusive.  
-Each element in b will be between 1 and 10, inclusive.   


EXAMPLES

0)
{3,2}

Returns: "Possible"

One valid sequence is the sequence {2, 2}.
That is, a[0] = a[1] = 2.
Clearly, each a[i] is a power of two not smaller than 2.
The product of all a[i] is 2*2 = 4.
Both a[0]^b[0] = 2^3 = 8 and a[1]^b[1] = 2^2 = 4 are divisible by 4.


1)
{3,3,3}

Returns: "Possible"

Here, one valid sequence is {2, 2, 2}.


2)
{1,10}

Returns: "Impossible"

Suppose that a[0] = x and a[1] = y.
The value a[0]^b[0] = x^1 should be divisible by x*y.
This is only possible for y = 1.
However, 1 is not a positive power of two, so we cannot have a[1] = 1.


3)
{2, 3, 10}

Returns: "Possible"

One valid sequence is {8, 4, 2}.


4)
{7,10,4,6,3}

Returns: "Possible"


5)
{9,9,9,9,9,9,9,9,9}

Returns: "Possible"


6)
{3,4,5,6,7}

Returns: "Impossible"

*/
// END CUT HERE

#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class DivisibleSetDiv2 {
    bool possible(vector<int> b) {
        sort(b.rbegin(), b.rend());
        vector<int> a(b.size(), 1);
        int sum = accumulate(a.begin(), a.end(), 0);
        for (int t = 0; t < 1000000; ++t) {
            bool ok = true;
            for (int i = 0; i != a.size(); ++i) {
                while (a[i] * b[i] < sum) {
                    if (a[i] >= 1000000) {
                        return false;
                    }
                    ok = false;
                    ++a[i], ++sum;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
    
public:
    string isPossible(vector <int> b) {
        return possible(b) ? "Possible" : "Impossible";
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
			int Arr0[] = {3,2};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,10};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 10};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,10,4,6,3};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,9,9,9,9,9,9,9,9};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,4,5,6,7};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	DivisibleSetDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
