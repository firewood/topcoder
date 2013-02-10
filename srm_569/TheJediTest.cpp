// BEGIN CUT HERE
/*
SRM 569 Div1 Medium (500)

PROBLEM STATEMENT
A long time ago in a galaxy far, far away the Jedi Academy conducted a test
to detect children with high Force sensitivy which would then be trained to become Jedi.
The test was conducted in the Jedi Temple which had several floors.
For each i, students[i] children have initially gathered at floor i (0-based).
A Jedi could only manage to cope with at most K children located at the same floor.
So, if there were between K+1 and 2K children at a floor, two Jedi would be required there;
if there were between 2K+1 and 3K children, three Jedi were neccessary and so on.

To minimize the number of Jedi needed to supervise the test, it was decided to relocate some children.
However, to avoid the mess, each child was only allowed to be relocated by at most one floor,
i.e. he or she could stay on the same floor, go one floor down or go one floor up.
Note that it is not possible to go a floor down from the first floor or a floor up from the last floor.

Determine and return the minimum number of Jedi supervisors needed after the relocation.


DEFINITION
Class:TheJediTest
Method:minimumSupervisors
Parameters:vector <int>, int
Returns:int
Method signature:int minimumSupervisors(vector <int> students, int K)


CONSTRAINTS
-students will contain between 1 and 20 elements, inclusive.
-Each element of students will be between 0 and 100,000,000, inclusive.
-K will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
{3, 6, 3}
4

Returns: 3

If the children stay the way they are, 4 Jedi will be required.
A possible solution with only 3 observers needed is to send all the children to floor 1.
Another optimal solution is to send one child from floor 1 to floor 0 and the others to floor 2.


1)
{1, 1, 1, 1}
4

Returns: 2

A single observer can watch four children. However, to gather at the same floor,
at least one child would have to move more than one floor away from his or her initial location.


2)
{0, 0, 0, 0}
12345

Returns: 0

For the Jedi Academy, a bad day it was.


3)
{15, 0, 13, 4, 29, 6, 2}
7

Returns: 10

An optimal solution is to gather the children from floor 0 and floor 2 at floor 1,
move the children from floor 3 and one child from floor 5 to floor 4 and move the children from the last floor 6 down to floor 5. The quantities of students at each floor will be {0, 28, 0, 0, 34, 7, 0}.


4)
{1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68}
114

Returns: 102138

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

class TheJediTest {
public:
	int minimumSupervisors(vector <int> students, int K) {
		int ans = 0, sz = (int)students.size();
		int i, j, k, l;
		students.push_back(0);
		students.push_back(0);
		for (i = 1; i <= sz; ++i) {
			j = students[i-1];
			ans += j / K;
			j %= K;
			if (j) {
				++ans;
				k = min(K - j, students[i]);
				students[i] -= k;
				l = min(K - j - k, students[i+1]);
				students[i+1] -= l;
			}
		}
		return ans;
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
			int Arr0[] = {3, 6, 3};
			int Arg1 = 4;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1};
			int Arg1 = 4;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0};
			int Arg1 = 12345;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {15, 0, 13, 4, 29, 6, 2};
			int Arg1 = 7;
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
			int Arg1 = 114;
			int Arg2 = 102138;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {29541663, 85732198, 69829763, 77760462, 32153432, 79240058, 13641353, 50236888, 83780217, 82884996, 5909451, 68242201, 64320036, 82420030, 16758585, 12089161, 92006984, 90761986};
			int Arg1 = 67854681;
			int Arg2 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {99203485, 17324730, 5410737, 11860563, 34237187, 11126721, 56157622, 48960271, 3684793};
			int Arg1 = 1725617;
			int Arg2 = 167;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheJediTest ___test;
	___test.run_test(-1);
}
// END CUT HERE
