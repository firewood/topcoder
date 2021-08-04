// BEGIN CUT HERE
/*
TCO21 Regional Qualification (250)

PROBLEM STATEMENT

Olympic shooting competitions are done in rounds of 25 shots.
Obviously, whoever hits more targets wins.
Ties are broken in an interesting way: using the Countback Rule.
Below we quote this rule from the official rulebook.

9.15.1.2 Countback Rule

Any ties to be broken by this method must be decided as follows:

The scores of the last round of 25 targets must be compared.
The winner is the athlete with the highest score in that round.

In a case where the tie is still not broken, the round before last must be compared and if still not broken, the round before that and so on; and

If the results of all the rounds are still equal, ties must be decided by counting backward,  target  by  target,  from  the  last  target  of  the  last  round  (and  if  necessary, the next to the last round etc.) until a tie-breaking zero (0) is found.  If  the  tied  athletes  have  zeroes  (0)  on  the  same  target,  the  countback  shall  continue until the tie is broken.

If two shooters have exactly the same shooting record, the above rule will conclude that they are still tied.
If the tie still needs to be broken (e.g., to decide who gets a medal), the shooters who are still tied after the Countback Rule is applied have a shoot-off.

In this problem we will assume that all ties left after the Countback Rule is applied must be resolved via a shoot-off.
We will also assume that whenever a shoot-off takes place, the shooter with the smaller number performs better.

You are given the shooting records of N shooters in the vector <string> results.
For each i, results[i] is the shooting record of shooter number i.
Each '1' represents a hit, each '0' is a miss.

Determine the final standings of this shooting competition and return it as a vector <int> with the competitor numbers ordered from best to worst.
All ties need to be broken: first by using the Countback Rule, and the ones that remain by a shoot-off.


DEFINITION
Class:OlympicShooting
Method:sort
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> sort(vector <string> results)


CONSTRAINTS
-results will have between 1 and 30 elements, inclusive.
-Each element of results will have the same length.
-That length will be 25, 50, 75, 100, or 125.
-Each character in results will be '1' or '0'.


EXAMPLES

0)
{"1111111111101111111111111",
 "1111111111111111111111100",
 "1111111111111111111110111",
 "1111111111111111111111111",
 "1111111111111111111110111"}

Returns: {3, 0, 2, 4, 1 }

Five participants, one round of 25 shots.
Participant 3 hit all 25 targets and won. Participants 0, 2, and 4 hit 24 targets each. The Countback Rule tells us that participant 0 should be second (as they are the only one among the three who hit target #22). A shoot-off decides that participant 2 is before participant 4 in the final standings. Participant 1 is last with just 23 hit targets.


1)
{"11111111111011111111111110000000000000000000010000",
 "11111111111111111111111000000000000000000000001000",
 "11111111111111111111101110000000000000000000000100",
 "11111111111111111111111110000000000000000000000010",
 "11111111111111111111101110000000000000000000000001"}

Returns: {3, 4, 2, 0, 1 }

Here we also have a second round of shooting. In the second round each shooter only hit one target. These hits change the order produced by the Countback Rule.

E.g., when comparing shooters 2 and 4, we see that they both have score 1 for the last round, they both have score 24 for the first round, and then we see that on the very last shot of the competition shooter 4 succeeded while shooter 2 failed.


2)
{"11111111111011111111111110000000000000000000000100",
 "11111111111111111111111000000000000000000000011000",
 "11111111111111111111101110000000000000000000000100",
 "11111111111111111111111110000000000000000000000010",
 "11111111111111111111101110000000000000000000000001"}

Returns: {3, 1, 4, 0, 2 }

A similar but different situation. Note that participant 1 now has a total of 25 hits, just like almost everyone else in this example. The Countback Rule places them in second place, as their last round is better (two hits) than the others (one hit each).


3)
{"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000"}

Returns: {0, 1, 2, 3, 4, 5 }

A larger tie that is only decided by a shoot-off involving all six people.


4)
{"10000000000000000000000000000000000000000000000000",
 "01000000000000000000000000000000000000000000000000"}

Returns: {1, 0 }

Both shooters have the same grand totals and also the same round totals. As we are going back through their shooting history shot by shot, we see 48 shots where the results match and then finally we get to the second shot of the competition. There the tie is finally broken.

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

class OlympicShooting {
public:
	vector <int> sort(vector <string> results) {
		int N = results.size();
		vector <int> ans(N);
		vector<tuple<int, vector<int>, string, int>> v;
		for (int i = 0; i < N; ++i) {
			int score = 0;
			vector<int> round_score(results[0].size() / 25);
			string& s = results[i];
			reverse(s.begin(), s.end());
			for (int j = 0; j < s.length(); ++j) {
				s[j] ^= 1;
				score += s[j] - '0';
				round_score[j / 25] += s[j] - '0';
			}
			v.emplace_back(make_tuple(score, round_score, s, i));
		}
		std::sort(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			ans[i] = get<3>(v[i]);
		}
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int>& Expected, const vector <int>& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"1111111111101111111111111",
				"1111111111111111111111100",
				"1111111111111111111110111",
				"1111111111111111111111111",
				"1111111111111111111110111" };
			int Arr1[] = { 3, 0, 2, 4, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sort(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"11111111111011111111111110000000000000000000010000",
				"11111111111111111111111000000000000000000000001000",
				"11111111111111111111101110000000000000000000000100",
				"11111111111111111111111110000000000000000000000010",
				"11111111111111111111101110000000000000000000000001" };
			int Arr1[] = { 3, 4, 2, 0, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sort(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"11111111111011111111111110000000000000000000000100",
				"11111111111111111111111000000000000000000000011000",
				"11111111111111111111101110000000000000000000000100",
				"11111111111111111111111110000000000000000000000010",
				"11111111111111111111101110000000000000000000000001" };
			int Arr1[] = { 3, 1, 4, 0, 2 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sort(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"00000000000000000000000000000000000000000000000000",
				"00000000000000000000000000000000000000000000000000",
				"00000000000000000000000000000000000000000000000000",
				"00000000000000000000000000000000000000000000000000",
				"00000000000000000000000000000000000000000000000000",
				"00000000000000000000000000000000000000000000000000" };
			int Arr1[] = { 0, 1, 2, 3, 4, 5 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sort(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"10000000000000000000000000000000000000000000000000",
				"01000000000000000000000000000000000000000000000000" };
			int Arr1[] = { 1, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sort(Arg0));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OlympicShooting ___test;
	___test.run_test(-1);
}
// END CUT HERE
