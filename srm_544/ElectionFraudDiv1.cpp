// BEGIN CUT HERE
/*
// SRM 544 Div1 Easy (275)

// PROBLEM STATEMENT
// In a normal election, one expects the percentages received by each of
the candidates to sum to exactly 100 percent.  There are two ways this
might not be the case: if the election is fraudulent, or if the reported
percentages are rounded.
For example, in an election with 3 voters and 3 candidates, if each voter
chooses a different candidate the final percentages would be reported as
33, 33, 33, which only sum to 99.  Conversely, in an election with 7 voters
and 3 candidates, if the candidates receive 2, 2, and 3 votes, respectively,
the final percentages would be reported as 29, 29, and 43, which sum to 101.
The ministry of voting wants you to help them determine if an election was
run fairly or not.  You'll be given a vector <int> percentages, giving the
percentage of the vote that went to each candidate, rounded to the nearest
whole number (in the case a number lies halfway between 2 consecutive
integers, it will be rounded up).  If the election could be legitimate,
return the minimum number of voters that could have participated in this
election.  If the election is definitely fraudulent, return -1.


DEFINITION
Class:ElectionFraudDiv1
Method:MinimumVoters
Parameters:vector <int>
Returns:int
Method signature:int MinimumVoters(vector <int> percentages)


NOTES
-You may assume that whenever the election may be legitimate, the smallest
 possible number of voters will fit into a int.


CONSTRAINTS
-percentages will contain between 1 and 50 elements, inclusive.
-Each element of percentages will be between 0 and 100, inclusive.


EXAMPLES

0)
{33, 33, 33}

Returns: 3

The first example from the problem statement.


1)
{29, 29, 43}

Returns: 7

The second example from the problem statement.


2)
{12, 12, 12, 12, 12, 12, 12, 12}

Returns: -1

These results are impossible.


3)
{13, 13, 13, 13, 13, 13, 13, 13}

Returns: 8


4)
{0, 1, 100}

Returns: 200

The only possibility is that the candidates received 0, 1, and 199 votes, respectively.


5)
{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}

Returns: 97

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ElectionFraudDiv1 {

public:
	int MinimumVoters(vector <int> percentages) {
		int sz = percentages.size();
		int votes, i;
		for (votes = 1; votes < 10000; ++votes) {
			int MinSum = 0;
			int margin = 0;
			for (i = 0; i < sz; ++i) {
				bool f = false;
				int per = percentages[i];
				int Min = (per*votes - votes/2)/100;
				int t;
				for (t = max(0, Min); ; ++t) {
					int n = (t*100 + votes/2) / votes;
					if (n == per) {
						if (!f) {
							f = true;
							MinSum += t;
						} else {
							++margin;
						}
					} else if (n > per) {
						break;
					}
				}
				if (!f) {
					break;
				}
			}
			if (i >= sz && MinSum <= votes && (MinSum + margin) >= votes) {
				return votes;
			}
		}
		return -1;
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
			int Arr0[] = {33, 33, 33};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {29, 29, 43};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12, 12, 12, 12, 12, 12, 12, 12};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 100};
			int Arg1 = 200;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
			int Arg1 = 97;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 99, 0};
			int Arg1 = 67;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 4, 3, 10, 3, 3, 4, 3, 3, 3, 3, 5, 1, 6, 4, 3, 3, 3, 3, 7, 4, 4, 4, 3, 0, 3};
			int Arg1 = 115;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 34, 34, 34};
			int Arg1 = -1;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ElectionFraudDiv1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
