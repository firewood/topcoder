// BEGIN CUT HERE
/*
SRM 620 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel wants to hire a new maid.
There are n candidates for the position.
There are m different skills a maid should have, such as cooking, cleaning, or discreetness.
Ciel numbered the candidates 0 through n-1 and the skills 0 through m-1.

Ciel evaluated the level each candidate has in each of the skills.
You are given this information encoded in a vector <string> score with n elements, each consisting of m characters.
For each i and j, the character score[i][j] represents the level candidate i has in skill j.
Said character will always be between 'A' and 'Z', inclusive, where 'A' means the best possible and 'Z' the worst possible candidate.

You are also given an int x.
Ciel thinks that skill x is the most important skill a maid should have.

Return a vector <int> with n elements: the numbers of all candidates, ordered according to their level in skill x from the best to the worst.
Candidates who have the same level in skill x should be ordered by their number in ascending order.


DEFINITION
Class:CandidatesSelectionEasy
Method:sort
Parameters:vector <string>, int
Returns:vector <int>
Method signature:vector <int> sort(vector <string> score, int x)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-m will be between 1 and 50, inclusive.
-score will contain exactly n elements.
-Each element of score will contain exactly m characters.
-Each character in each element of score will be an uppercase English letter ('A'-'Z').
-x will be between 0 and m-1, inclusive.


EXAMPLES

0)
{"ACB", "BAC", "CBA"}
1

Returns: {1, 2, 0 }

The output should be {1, 2, 0}, because the level of candidate 1 in skill 1 is 'A', the level of candidate 2 in this skill is 'B', and the level of candidate 0 is 'C'.


1)
{"A", "C", "B", "C", "A"}
0

Returns: {0, 4, 2, 1, 3 }

Note that when 2 candidates have same level, they will remain in the original order.


2)
{"LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC"}
2

Returns: {5, 3, 8, 7, 4, 6, 1, 2, 0 }


3)
{"BBCBABAC","BCBACABA","CCCBAACB","CACABABB","AABBBBCC"}
6

Returns: {0, 1, 3, 2, 4 }


4)
{"XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY"}
3

Returns: {0, 3, 4, 5, 7, 8, 9, 6, 1, 2 }


5)
{"X"}
0

Returns: {0 }

Note that we may have only one candidate as well as only 1 skill.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CandidatesSelectionEasy {
public:
	vector <int> sort(vector <string> score, int x) {
		vector<pair<int, int> > v;
		for (int i = 0; i < (int)score.size(); ++i) {
			v.push_back(make_pair(score[i][x], i));
		}
		std::sort(v.begin(), v.end());
		vector<int> ans;
		for (int i = 0; i < (int)score.size(); ++i) {
			ans.push_back(v[i].second);
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
			string Arr0[] = {"ACB", "BAC", "CBA"};
			int Arg1 = 1;
			int Arr2[] = {1, 2, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"A", "C", "B", "C", "A"};
			int Arg1 = 0;
			int Arr2[] = {0, 4, 2, 1, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC"};
			int Arg1 = 2;
			int Arr2[] = {5, 3, 8, 7, 4, 6, 1, 2, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BBCBABAC","BCBACABA","CCCBAACB","CACABABB","AABBBBCC"};
			int Arg1 = 6;
			int Arr2[] = {0, 1, 3, 2, 4 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY"};
			int Arg1 = 3;
			int Arr2[] = {0, 3, 4, 5, 7, 8, 9, 6, 1, 2 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"X"};
			int Arg1 = 0;
			int Arr2[] = {0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CandidatesSelectionEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
