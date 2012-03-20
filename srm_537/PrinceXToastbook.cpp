// BEGIN CUT HERE
/*
// SRM 537 Div2 Hard (925)

// PROBLEM STATEMENT
// Prince Gogo is the charming prince of the Kingdom of Ducks, where slimes
and ducks live in peace and harmony.

Today, Prince Gogo purchased N toastbooks, numbered 0 through N-1. Each
toastbook contains some knowledge and grants it to the person who eats it.
It is known that no two toastbooks contain the same knowledge.

Initially, Gogo doesn't know any of the knowledge inside the toastbooks.
He intends to eat them all and gain as many pieces of knowledge as possible.
Furthermore, some of the books require a specific piece of knowledge in order
to understand its knowledge. This will be given as a vector <int> prerequisite.
If there is no required knowledge to understand the toastbook number i,
prerequisite[i] will be -1.
Otherwise, prerequisite[i] will be the number of the toastbook that contains
the knowledge necessary to understand book i. If Gogo eats some book x without
having the required knowledge, he will not gain the knowledge inside the book,
even if he later gains the knowledge from the book prerequisite[x].

Unfortunately, Gogo forgot to number the toastbooks when he purchased them.
Hence, he is forced to eat all N toastbooks in a random order. Return the
expected number of toastbooks that Gogo will understand.

DEFINITION
Class:PrinceXToastbook
Method:eat
Parameters:vector <int>
Returns:double
Method signature:double eat(vector <int> prerequisite)


NOTES
-The expected value of a random variable can be imagined as the average value of very many independent experiments.
-The returned value must have an absolute or relative error less than 10^-9.


CONSTRAINTS
-prerequisite will contain between 2 and 50 elements, inclusive.
-Each element of prerequisite will be between -1 and N-1, inclusive, where N is the number of elements in prerequisite.
-For all i, prerequisite[i] will not be i.


EXAMPLES

0)
{-1, 0}

Returns: 1.5

There are only two possible orders. If Gogo eats book 0 first, he
gains the knowledge in both books. If Gogo eats book 1 first, he
lacks the required knowledge to understand the book 1 when he read it. Hence, he will
only gain the knowledge in book 0. Therefore, the expected number
of books that Gogo will understand is the average of the two, which
is 1.5.


1)
{-1, 0, 1}

Returns: 1.6666666666666667

There are 6 possible orders. The number of books understood is as follows:
0, 1, 2: 3
0, 2, 1: 2
1, 0, 2: 1
1, 2, 0: 1
2, 0, 1: 2
2, 1, 0: 1

Hence, the expected number of books that Gogo will understand is their average, which is (3+2+1+1+2+1)/6 = 10/6.


2)
{1, -1, 1}

Returns: 2.0


3)
{1, 0}

Returns: 0.0

Each book has the other book as a prerequisite. Gogo will not be able to understand either one, regardless of the order in which he eats them.


4)
{-1, -1}

Returns: 2.0

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

class PrinceXToastbook {

	double factorial(double n) {
		if (n > 1) {
			n *= factorial(n-1);
		}
		return n;
	}

public:
	double eat(vector <int> prerequisite) {
		double result = 0;
		int i;
		for (i = 0; i < (int)prerequisite.size(); ++i) {
			int depth = 0;
			int parent = i;
			while (true) {
				++depth;
				if (depth > (int)prerequisite.size()) {
					break;
				}
				parent = prerequisite[parent];
				if (parent < 0) {
					result += 1.0 / factorial(depth);
					break;
				}
			}
		}
		return result;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 0};
			double Arg1 = 1.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 0, 1};
			double Arg1 = 1.6666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, -1, 1};
			double Arg1 = 2.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0};
			double Arg1 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, -1};
			double Arg1 = 2.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 5, 5, 7, 2, 3, 4, 1};
			double Arg1 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrinceXToastbook ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
