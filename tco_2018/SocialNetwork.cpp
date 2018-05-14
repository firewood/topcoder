// BEGIN CUT HERE
/*
TCO18 Fun Round Poland Easy (250)

PROBLEM STATEMENT
A new social network automatically matches people together based upon a shared interest. A list of interests for each member of the social network is given in the vector <string> interests. Each element represents the interests of a single member: each character ('A'-'Z') represents a different interest. Two individuals become friends if they have at least one interest in common. Return the average number of friends each member has.


DEFINITION
Class:SocialNetwork
Method:averageFriends
Parameters:vector <string>
Returns:double
Method signature:double averageFriends(vector <string> interests)


NOTES
-Your return value must have an absolute or a relative error at most 10^(-9).


CONSTRAINTS
-interests will contain between 2 and 50 elements, inclusive.
-Each character in each element of interests will be an uppercase English letter ('A'-'Z').
-The characters in each element of interests will be distinct.


EXAMPLES

0)
{"A", "A"}

Returns: 1.0

Two people who share a common interest. Thus, they each have one friend, and the average number of
friends is therefore also 1.


1)
{"ABC", "DE", "FGHIJ"}

Returns: 0.0

Three people with no common interests.


2)
{"ABC", "DE", "FGHIJA"}

Returns: 0.6666666666666666

This is almost the same situation as Example #1 but now two of the people share a common interests.
Now these three people have 1, 0, and 1 friends, respectively. The average number of friends is
(1+0+1)/3 = 2/3 = 0.6666666667.


3)
{"AB", "AC", "AD", "AE", "BCDE"}

Returns: 4.0

All of these people are friends with each other, even though there is no single topic they would all
be interested in.


4)
{"ABCDE", "BCDEF"}

Returns: 1.0

Even if people share multiple common interests, they are only friends once.


5)
{"", "", "", ""}

Returns: 0.0

Four grumpy people who are not interested in anything.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SocialNetwork {
public:
	double averageFriends(vector <string> interests) {
		int n = (int)interests.size();
		long long f[64] = {};
		for (int i = 0; i < n; ++i) {
			for (char c : interests[i]) {
				f[i] |= 1LL << (c - 'A');
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (i != j && (f[i] & f[j]) != 0) {
					++cnt;
				}
			}
		}
		return 2.0 * cnt / n;
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
			string Arr0[] = {"A", "A"};
			double Arg1 = 1.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ABC", "DE", "FGHIJ"};
			double Arg1 = 0.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ABC", "DE", "FGHIJA"};
			double Arg1 = 0.6666666666666666;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AB", "AC", "AD", "AE", "BCDE"};
			double Arg1 = 4.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ABCDE", "BCDEF"};
			double Arg1 = 1.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"", "", "", ""};
			double Arg1 = 0.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SocialNetwork ___test;
	___test.run_test(-1);
}
// END CUT HERE
