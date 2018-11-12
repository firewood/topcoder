// BEGIN CUT HERE
/*
SRM 740 Div2 Medium (500)

PROBLEM STATEMENT

You are a spectator at a long jump competition.
N contestants compete in the event.
The contestants wear bibs with numbers 0 through N-1.

The competition consists of three rounds.
In each round each contestant gets one attempt to jump as far as they can.
To make the competition more dramatic for spectators, the order in which the contestants jump may change from round to round.
More precisely, before each round the contestants are ordered from the currently-worst to the currently-best one, and that is the order in which they will jump.

In order to compare which contestant is better, we first compare their best jump.
In case of a tie, we look at their second best jump, and so on.
If two contestants have exactly the same collection of jump lengths, the one with the smaller bib number is better.
(Thus, before the first round of the competition contestant 0 is the best contestant. This means that in the first round they always jump in the order N-1, N-2, ..., 1, 0.)

You have observed the whole competition and you wrote down all 3*N jump lengths in the order in which the contestants made them.
You are given these lengths in the vector <int> jumpLengths.
You forgot to write down which contestant made which jump, but luckily this can be reconstructed from what we know about the contest.

What are the results of the competition?
Compute and return a vector <int> with N elements: the bib numbers of the contestants in the order in which they placed in the contest (starting with the winner).


DEFINITION
Class:LongJumpCompetition
Method:recoverStandings
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> recoverStandings(vector <int> jumpLengths)


NOTES
-The number N is not given explicitly. You can determine it by looking at the number of elements in jumpLengths and dividing it by 3.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-jumpLengths will have exactly 3*N elements.
-Each element of jumpLengths will be between 0 and 1000, inclusive.


EXAMPLES

0)
{847, 833, 829}

Returns: {0 }

This test case has N = 1.
In other words, there is a single competitor (with bib number 0).
That competitor makes three jumps and then wins the contest.


1)
{100, 120, 110, 130, 120, 111, 147, 92, 0}

Returns: {0, 2, 1 }


We see that jumpLengths contains nine jumps, so we have N = 3 contestants. Here's the full explanation of what happens during the contest:

Before the first round nobody has made any jumps yet.
Thus, the order from worst to best is determined purely by the contestants' bib numbers.
In the first round they are going to jump in the order {2, 1, 0}.

What this means is that contestant 2's jump had length 100, then contestant 1's jump had length 120, and finally contestant 0's jump measured 110.

Before the second round we determine a new order for the contestants.
Currently, contestant 2 is the worst, then 0, and contestant 1 leads the contest with the currently longest jump.
Thus, in the second round they will jump in the order {2, 0, 1}.

Second round results come in: contestant 2's second jump measures 130, then we see contestant 0's second jump to 120, and contestant 1 jumps only to the 111 mark.

Before the third round we again need to determine the current standings.
The clear leader is contestant 2, their longest jump length is 130.
Contestants 0 and 1 have the same longest jump: 120.
Thus, we look at their second longest jump to see that contestant 1 should be higher in the standings.
Hence, the order from worst to best in which they will jump in the third round is {0, 1, 2}.

In the third round, contestant 0 makes the longest jump of the contest. The other two jumps are then too short to change anything. Thus, in the end contestant 0 wins, contestant 2 is second, and contestant 1 is third. This order is what we return: {0, 2, 1}.


2)
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: {0, 1, 2, 3 }

There are four contestants, each makes three very unsuccessful jumps. As their jump lengths are exactly the same, their order is always determined only by the numbers they wear. Thus, in the end contestant 0 is the winner, followed by 1, 2, and 3.


3)
{850, 840, 841, 850, 850, 837}

Returns: {1, 0 }

The following happened during the contest:

Contestant 1 jumped 850.
Contestant 0 jumped 840.
Contestant 0 jumped 841.
Contestant 1 jumped 850.
Contestant 0 jumped 850.
Contestant 1 jumped 837.

In the end, contestant 1 is the winner.
Both contestants have the same length of the longest jump (850).
Contestant 1 has a better second-longest jump (also 850) than contestant 0 (only 841).

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<vector<int>, int> VII;

class LongJumpCompetition {
public:
	vector <int> recoverStandings(vector <int> jumpLengths) {
		int n = (int)jumpLengths.size() / 3;
		vector<VII> best(n);
		for (int i = 0; i < n; ++i) {
			best[i].second = -i;
		}
		for (int r = 0; r < 3; ++r) {
			for (int i = 0; i < n; ++i) {
				sort(best[i].first.rbegin(), best[i].first.rend());
			}
			sort(best.begin(), best.end());
			for (int i = 0; i < n; ++i) {
				best[i].first.push_back(jumpLengths[r * n + i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			sort(best[i].first.rbegin(), best[i].first.rend());
		}
		sort(best.rbegin(), best.rend());
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = -best[i].second;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {847, 833, 829};
			int Arr1[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 120, 110, 130, 120, 111, 147, 92, 0};
			int Arr1[] = {0, 2, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int Arr1[] = {0, 1, 2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {850, 840, 841, 850, 850, 837};
			int Arr1[] = {1, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongJumpCompetition ___test;
	___test.run_test(-1);
}
// END CUT HERE
