// BEGIN CUT HERE
/*
SRM 605 Div1 Easy (250)

PROBLEM STATEMENT

Alien Fred wants to destroy the Earth.
But before he does that, he wants to eat some hamburgers.

You are given two vector <int>s: type and taste.
They describe all hamburgers available in the shop he found.
Each hamburger has a type (some positive integer) and a taste (some, possibly negative, integer).
For each i, type[i] represents the type of i-th hamburger (0-based index), and taste[i] represents the taste of i-th hamburger.
It is possible that different hamburgers have the same type but a different taste.

Fred wants to eat some subset of those hamburgers (possibly none or all of them).
Eating the chosen hamburgers will give him some amount of joy.
This amount can be computed as Y * A, where Y is the number of different types of hamburgers eaten, and A is their total taste.

Return the largest possible amount of joy he can get.


DEFINITION
Class:AlienAndHamburgers
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getNumber(vector <int> type, vector <int> taste)


CONSTRAINTS
-type will contain between 1 and 50 elements, inclusive.
-type and taste will contain the same number of elements.
-Each element of type will be between 1 and 100, inclusive.
-Each element of taste will be between -100,000 and 100,000, inclusive.


EXAMPLES

0)
{1, 2}
{4, 7}

Returns: 22

In this case, the best choice is to choose both hamburgers. The number of different types is 2, and the total taste is 11. Thus, the answer is 2*11 = 22.


1)
{1, 1}
{-1, -1}

Returns: 0

Note that sometimes the best choice is not to eat any hamburgers. In such a case the amount of joy is 0.


2)
{1, 2, 3}
{7, 4, -1}

Returns: 30


3)
{1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1}
{1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0}

Returns: 54


4)
{30, 20, 10}
{100000, -100000, 100000}

Returns: 400000

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class AlienAndHamburgers {
public:
	int getNumber(vector <int> type, vector <int> taste) {
		IIVec v, w;
		for (int i = 0; i < (int)type.size(); ++i) {
			v.push_back(II(type[i], taste[i]));
		}
		sort(v.rbegin(), v.rend());

		for (auto p : v) {
			if (w.size() > 0 && w.back().second == p.first) {
				w.back().first += max(0, p.second);
			} else {
				w.push_back(II(p.second, p.first));
			}
		}
		sort(w.rbegin(), w.rend());

		int t = 0, cnt = 0;
		for (auto p : w) {
			int a = t + p.first;
			int b = a * (cnt + 1);
			if (b < t * cnt) {
				break;
			}
			t = a;
			++cnt;
		}
		return t * cnt;
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
			int Arr0[] = {1, 2};
			int Arr1[] = {4, 7};
			int Arg2 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1};
			int Arr1[] = {-1, -1};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arr1[] = {7, 4, -1};
			int Arg2 = 30;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
			int Arr1[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
			int Arg2 = 54;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30, 20, 10};
			int Arr1[] = {100000, -100000, 100000};
			int Arg2 = 400000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 1, 2};
			int Arr1[] = {4, 7, 4, 7};
			int Arg2 = 44;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlienAndHamburgers ___test;
	___test.run_test(-1);

}
// END CUT HERE
