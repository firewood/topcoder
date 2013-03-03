// BEGIN CUT HERE
/*
TCO13 Round 1B Easy (250)

PROBLEM STATEMENT
In one of her subjects at the university, Elly and her classmates have to prepare projects.
The professor wants the students to work in pairs (groups of two).
Each student must belong to exactly one pair and each pair should produce one project.
You may assume that the number of people in the class is even.

You are given a vector <int> knowledge.
Each element of knowledge is the amount of knowledge of one of the students.
The quality of a project is the total knowledge of the students that work on it.
That is, if students i and j form one of the pairs, the quality of their project will be knowledge[i] + knowledge[j].

This creates some problems.
If there is a really strong group, their project will be of really high quality.
The professor will then compare the other projects to it and will be disappointed by them,
giving low grades to the other pairs.
Thus, the students want to form the groups in such way that the difference
between the quality of the best project and the quality of the worst project is as small as possible.

Return that minimal difference in the quality between the best and the worst project
if the students split into pairs in the best possible way.


DEFINITION
Class:EllysPairs
Method:getDifference
Parameters:vector <int>
Returns:int
Method signature:int getDifference(vector <int> knowledge)


CONSTRAINTS
-knowledge will contain between 2 and 50 elements, inclusive.
-The number of elements of knowledge will be even.
-Each element of knowledge will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2, 6, 4, 3}

Returns: 1

Here obviously grouping the two best people in the class (with knowledge 6 and 4) doesn't make sense.
If 6 pairs with 3 and 4 pairs with 2 they will get qualities of 9 and 6, respectively, leading to difference 3.
However, there is an even better grouping: 2 with 6 and 4 with 3 for qualities of 8 and 7, respectively. The difference then would be only 1.


1)
{1, 1, 1, 1, 1, 1}

Returns: 0

Some or even all students can have the same knowledge.


2)
{4, 2, 4, 2, 1, 3, 3, 7}

Returns: 2


3)
{5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4}

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysPairs {
public:
	int getDifference(vector <int> knowledge) {
		sort(knowledge.begin(), knowledge.end());
		int Min = 2000000000, Max = 0;
		int sz = (int)knowledge.size();
		for (int i = 0; i < sz/2; ++i) {
			int sum = knowledge[i] + knowledge[sz - 1 - i];
			Min = min(Min, sum);
			Max = max(Max, sum);
		}
		return Max - Min;
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
			int Arr0[] = {2, 6, 4, 3};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getDifference(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getDifference(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 2, 4, 2, 1, 3, 3, 7};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getDifference(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getDifference(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 4, 5};
			int Arg1 = 1;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getDifference(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 4, 5, 6, 9};
			int Arg1 = 2;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getDifference(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysPairs ___test;
	___test.run_test(-1);
}
// END CUT HERE
