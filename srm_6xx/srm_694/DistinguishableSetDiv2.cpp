// BEGIN CUT HERE
/*
SRM 694 Div2 Medium (500)

PROBLEM STATEMENT
There are N people.
Each of them was given the same survey that consisted of M questions.
The people were numbered 0 through N-1, and the questions were numbered 0 through M-1.
Each person answered each question by choosing one of the provided options.
For each question, the options were labeled using distinct uppercase letters ('A'-'Z').

You are given the responses to the survey: a vector <string> answer with N elements, each consisting of M characters.
For each i and j, answer[i][j] is the answer person i chose for question j.

A set of questions is called a distinguishable set if we can use it to distinguish between any two of our N people.
Formally, a distinguishable set of questions has the property that no two people have the same sequence of responses to those questions.

The set of questions used in the survey has exactly 2^M subsets.
Count how many of those subsets are distinguishable sets, and return that count.


DEFINITION
Class:DistinguishableSetDiv2
Method:count
Parameters:vector <string>
Returns:int
Method signature:int count(vector <string> answer)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-M will be between 1 and 10, inclusive.
-answer will contain exactly N elements, inclusive.
-Each element in answer will contain exactly M characters, inclusive.
-Each character in answer will be a uppercase letter ('A'-'Z').


EXAMPLES

0)
{"AA","AB","CC"}

Returns: 2

There are 4 subsets of questions: {}, {0}, {1}, and {0,1}.
Let's look at each of them separately.

For the empty subset {} each person gave the same sequence of answers (an empty sequence).
For the subset {0} the answers given by the three people were "A", "A", and "C". Note that two of the people gave the same response.
For the subset {1} the answers given by the three people were "A", "B", and "C". Note that all three responses are distinct.
For the subset {0,1} the answers given by the three people were "AA", "AB", and "CC". Again, note that all three responses are distinct.

Thus, there are 2 distinguishable sets: {1} and {0,1}.


1)
{"XYZ","XYZ","XYZ"}

Returns: 0

Each person gave exactly the same sequence of answers.
Thus, no subset of questions is a distinguishable set.
The correct return value in such a case is 0.


2)
{"AAAA","BACA","CDCE"}

Returns: 11

Among the 16 possible subsets of these questions there are 11 distinguishable sets.
The five subsets of questions that are not distinguishable sets are {}, {1}, {2}, {3}, and {1,3}. 


3)
{"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"}

Returns: 1017


4)
{"XYZ","XAB","YAC"}

Returns: 5

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<string> StrVec;

class DistinguishableSetDiv2 {
public:
	int count(vector <string> answer) {
		int ans = 0;
		int N = (int)answer.size(), M = (int)answer[0].length();
		for (int b = 0; b < (1 << M); ++b) {
			StrVec v = answer;
			for (int i = 0; i < M; ++i) {
				if ((1 << i) & b) {
					for (int j = 0; j < N; ++j) {
						v[j][i] = ' ';
					}
				}
			}
			sort(v.begin(), v.end());
			int i;
			for (i = 1; i < N; ++i) {
				if (v[i - 1].compare(v[i]) == 0) {
					break;
				}
			}
			ans += i >= N;
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
			string Arr0[] = {"AA","AB","CC"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XYZ","XYZ","XYZ"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AAAA","BACA","CDCE"};
			int Arg1 = 11;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"};
			int Arg1 = 1017;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XYZ","XAB","YAC"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DistinguishableSetDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
