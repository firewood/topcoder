// BEGIN CUT HERE
/*
SRM 756 Div2 Easy (250)

PROBLEM STATEMENT
There are N girls auditioning for an idol competition. You are a junior producer of the competition. During the auditions you have evaluated the talent and the skill of each candidate. The results of these evaluations are given in the vector <int>s talent and skill: for each valid i, talent[i] is the amount of talent and skill[i] the amount of skill candidate i has shown.
Your task is to decide which girls advance to the second stage of the selection process. In order to do this, you came up with a simple rule: girl A will advance if and only if there is no other girl B such that B has both strictly more talent and strictly more skill than A.
Please calculate and return the number of girls who advance to the second stage.


DEFINITION
Class:CinderellaGirls
Method:count
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int count(vector <int> talent, vector <int> skill)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-talent will contain exactly N elements.
-skill will contain exactly N elements.
-Each element in talent will be between 1 and 10,000, inclusive.
-Each element in skill will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{10,20,30}

{30,20,10}

Returns: 3

Every girl will be accepted.


1)
{10,20,30}

{10,20,30}

Returns: 1

In this case, girls 0 and 1 will not be accepted because girl 2 has more talent and more skill than each of the other two.


2)
{10,10,10}

{1,100,10000}

Returns: 3

Their skill scores differ significantly but their talent scores are the same so every girl will be invited to the second stage.


3)
{46,70,39,53,10,47,73,95,95,27}

{81,47,64,65,34,55,75,16,80,69}

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CinderellaGirls {
public:
	int count(vector <int> talent, vector <int> skill) {
		int ans = 0, n = (int)talent.size();
		for (int i = 0; i < n; ++i) {
			bool ok = true;
			for (int j = 0; j < n; ++j) {
				if (talent[i] < talent[j] && skill[i] < skill[j]) {
					ok = false;
				}
			}
			ans += ok;
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
			int Arr0[] = {10,20,30}
;
			int Arr1[] = {30,20,10}
;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,20,30}
;
			int Arr1[] = {10,20,30}
;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,10}
;
			int Arr1[] = {1,100,10000}
;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {46,70,39,53,10,47,73,95,95,27}
;
			int Arr1[] = {81,47,64,65,34,55,75,16,80,69}
;
			int Arg2 = 3;

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
	CinderellaGirls ___test;
	___test.run_test(-1);
}
// END CUT HERE
