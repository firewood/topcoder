// BEGIN CUT HERE
/*
TCO13 Algorithm Round2C Easy (250)

PROBLEM STATEMENT
Fox Ciel and Fox Jiro both went to spend an evening in the dancing room.
Together, there are N foxes in the room.
The foxes are numbered 0 through N-1.
In particular, Ciel is fox 0 and Jiro is fox 1.

You are given a vector <string> friendship that describes the initial friendship between the foxes in the room.
More precisely, friendship contains N elements with N characters each.
Character j of element i of friendship is 'Y' if foxes i and j are friends at the beginning of the evening, and 'N' otherwise.
Note that friendship is symmetric: whenever X is a friend of Y, Y is a friend of X.

During the evening, multiple songs will be played in succession.
During each song, some pairs of foxes will be dancing together.
Foxes are not allowed to change partners during the dance.
Thus in each dance each fox either dances with a single partner, or sits the dance out.

Foxes are not allowed to form the pairs for a dance arbitrarily.
It is only allowed for two foxes to dance together if they are friends, or if they have a common friend who can introduce them.
That is, if foxes A and B are not friends at the moment, they can only dance together if there is a fox C such that A and B are both friends with C.
After two foxes dance together, they become friends.

Fox Ciel wants to become friends with Fox Jiro.
Return the smallest number of dances in which this can be achieved (assuming that all other foxes cooperate and form pairs for the dances optimally).
If it's impossible to make Ciel and Jiro friends, return -1 instead.


DEFINITION
Class:DancingFoxes
Method:minimalDays
Parameters:vector <string>
Returns:int
Method signature:int minimalDays(vector <string> friendship)


NOTES
-Gender does not matter for the foxes when choosing their dance partners.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-friendship will contain exactly N elements.
-Each element of friendship will contain exactly N characters.
-Each character in friendship will be 'Y' or 'N'.
-For each i, friendship[i][i] = 'N'.
-For each i and j, friendship[i][j] = friendship[j][i].


EXAMPLES

0)
{"NNY",
 "NNY",
 "YYN"}

Returns: 1

There are 3 foxes. Ciel and Jiro are not friends, but they are both friends with fox 2. Thus, they may dance together in the first dance and become friends.


1)
{"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}

Returns: -1

Ciel does not know any other fox at the dance, so she cannot dance with anybody.


2)
{"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"}

Returns: 2


3)
{"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"}

Returns: 3


4)
{"NY",
 "YN"}

Returns: 0

Ciel and Jiro are already friends in the beginning, no dances are needed. In such a case, the correct return value is 0.

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

using namespace std;

#define INF 1000000000

class DancingFoxes {
public:
	int minimalDays(vector <string> friendship) {
		int N = (int)friendship.size();
		int d[50][50];
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				d[i][j] = friendship[i][j] == 'Y' ? 1 : INF;
			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		int dist = d[0][1] + 1;
		if (dist >= INF) {
			return -1;
		}

		int ans = 0;
		while (dist > 2) {
			dist -= dist / 3;
			++ans;
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
			string Arr0[] = {"NNY",
 "NNY",
 "YYN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalDays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalDays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalDays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalDays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NY",
 "YN"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalDays(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNYN", "NNNNY", "NNNYY", "YNYNN", "NYYNN"};
			int Arg1 = 3;
			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalDays(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DancingFoxes ___test;
	___test.run_test(-1);
}
// END CUT HERE
