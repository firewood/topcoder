// BEGIN CUT HERE
/*
SRM 610 Div2 Easy (250)

PROBLEM STATEMENT
Little John has a piece of paper with some distinct integers written on it.
You are given a vector <int> numbers.
The elements of numbers are the numbers written on John's paper.

John is now going to add some new numbers to his paper.
While doing so, he will be using integer division.
When doing integer division, we discard the fractional part of the result.
In this problem, we will use "div" to denote integer division.
For example, 15 div 5 = 3, and 24 div 5 = 4.

John will repeat the following process:
He will look at his paper and select two distinct numbers A and B such that A is greater than B.
He will compute C = A div B.
If C is not written on his paper yet, he will add it to the paper.

The process will stop once there is no way for John to add a new number to his paper.

Compute and return how many numbers will there be on John's paper at the end.

DEFINITION
Class:DivideByZero
Method:CountNumbers
Parameters:vector <int>
Returns:int
Method signature:int CountNumbers(vector <int> numbers)


NOTES
-The return value does not depend on the order in which John adds new numbers to his paper.


CONSTRAINTS
-numbers will contain between 1 and 100 elements, inclusive.
-Each element of numbers will be between 1 and 100, inclusive.
-The elements in numbers will be distinct.


EXAMPLES

0)
{9, 2}

Returns: 3

John starts with just 9 and 2 on his paper.
He can add the number 4, because 9 div 2 = 4.
After he adds the number 4, there will be no more numbers to add, because 9 div 4 = 2, and also 4 div 2 = 2.
Thus, at the end John's paper will contain 3 numbers: 9, 2, and 4.


1)
{8, 2}

Returns: 3


2)
{50}

Returns: 1

We only have one number. There isn't anything John can do.


3)
{1, 5, 8, 30, 15, 4}

Returns: 11


4)
{1, 2, 4, 8, 16, 32, 64}

Returns: 7


5)
{6, 2, 18}

Returns: 7

Once John has a number on his paper, he can use it when producing new numbers.
For example, in this case he can add 9 (computed as 18 div 2), and then add 1 (computed as 9 div 6).
The numbers he will have at the end are 1, 2, 3, 4, 6, 9, and 18.

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;

class DivideByZero {
public:
	int CountNumbers(vector <int> numbers) {
		IntSet s(numbers.begin(), numbers.end());
		bool f = true;
		while (f) {
			f = false;
			IntSet prev = s;
			IntSet::const_reverse_iterator a, b;
			for (a = prev.rbegin(); a != prev.rend(); ++a) {
				for (b = a, ++b; b != prev.rend(); ++b) {
					int c = *a / *b;
					if (s.find(c) == s.end()) {
						f = true;
						s.insert(c);
					}
				}
			}
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
			int Arr0[] = {9, 2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 8, 30, 15, 4};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 4, 8, 16, 32, 64};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6, 2, 18};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivideByZero ___test;
	___test.run_test(-1);
}
// END CUT HERE
