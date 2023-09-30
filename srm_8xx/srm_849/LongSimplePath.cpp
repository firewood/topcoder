// BEGIN CUT HERE
/*
SRM 849 Div1 Easy (250)

PROBLEM STATEMENT

A robot is placed on an infinite plane that is divided into a grid of unit squares.
The robot's starting square has coordinates (0, 0).
Your goal is to move the robot to the square with coordinates (R, C).

The robot understands only two types of commands:

The commands labeled using lowercase English letters (a, b, c, ...) instruct the robot to walk into higher-numbered rows.
The commands labeled using uppercase English letters (A, B, C, ...) instruct the robot to walk into higher-numbered columns.

More precisely:

For i=0 to 25, the command 'a'+i instructs the robot to walk from its current square (r,c) to the square (r+2^i,c).
For i=0 to 25, the command 'A'+i instructs the robot to walk from its current square (r,c) to the square (r,c+2^i).

For example, the program "bDa" will cause the robot to do the following:

'b': Walk from (0,0) via (1,0) to (2,0).
'D': Walk from (2,0) via (2,1), ..., (2,7) to (2,8).
'a': Walk from (2,8) to (3,8).

Some squares in the robot's plane may be blocked.
You are given the coordinates of all these obstacles:
for each valid i, the square (obsR[i], obsC[i]) is blocked.
The robot may not enter these squares.
This includes entering them during the execution of a command. E.g., in the above example, if there were an obstacle at (2,5), the instruction 'D' would cause the robot to collide with the obstacle.

If the target square cannot be reached, return an empty string.

It can be shown that whenever the target square can be reached, there is always a program of 3,000 or fewer instructions that gets the robot exactly to the target square.
Find and return any one such program.


DEFINITION
Class:LongSimplePath
Method:traverse
Parameters:int, int, vector <int>, vector <int>
Returns:string
Method signature:string traverse(int R, int C, vector <int> obsR, vector <int> obsC)


NOTES
-Any valid solution will be accepted. In particular, you are not required to minimize the number of instructions in your program.


CONSTRAINTS
-R will be between 0 and 10^9, inclusive.
-C will be between 0 and 10^9, inclusive.
-R+C will be positive.
-obsR will contain between 0 and 50 elements, inclusive.
-obsC will contain the same number of elements as obsR.
-Each element of obsR will be between 0 and R, inclusive.
-Each element of obsC will be between 0 and C, inclusive.
-All obstacles described by obsR and obsC will be in mutually distinct squares.
-The cells (0, 0) and (R, C) will not contain an obstacle.


EXAMPLES

0)
0
6
{}
{}

Returns: "CB"

We just need to tell the robot to take six steps "to the right" (from column 0 to column 6).


1)
0
6
{0}
{4}

Returns: ""

Same as the previous example, but now the obstacle is preventing us from reaching the goal.


2)
2
2
{0, 2}
{2, 0}

Returns: "AaAa"

The board looks as follows (with 'R' being the robot, '.' being empty squares, 'X' being obstacles, and '*' being the target square):

     X.*
     ...
     R.X

The correct solutions for this test case are precisely the following strings: "aBa", "aAAa", "aAaA", "AbA", "AaaA", and "AaAa". You may return any of these six strings.


3)
123
456
{0, 122}
{1, 456}

Returns: "gfedaIHGCBAbA"

Here the two obstacles limit the directions in which we can leave the start and reach the goal.


4)
3
1234
{0, 1, 2, 3}
{7, 7, 111, 111}

Returns: ""

Remember that our robot can only go "up" and "right". These four obstacles are enough to prevent it from being able to reach the goal.

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

typedef pair<int, int> II;

class LongSimplePath {
public:
	string traverse(int R, int C, vector <int> obsR, vector <int> obsC) {
		map<II, string> m;
		map<int, set<int>> ors, ocs;
		set<int> rs, cs;
		set<II> os;
		for (int i = 0; i < int(obsR.size()); ++i) {
			ors[obsR[i]].insert(obsC[i]);
			ocs[obsC[i]].insert(obsR[i]);
			rs.insert(obsR[i] - 1);
			rs.insert(obsR[i]);
			cs.insert(obsC[i] - 1);
			cs.insert(obsC[i]);
			os.insert(II(obsR[i], obsC[i]));
		}
		rs.insert(R);
		cs.insert(C);
		vector<II> q;
		q.emplace_back(II(0, 0));
		m[II(0, 0)] = "";
		while (!q.empty()) {
			vector<II> nq;
			for (auto kv : q) {
				int r = kv.first, c = kv.second;
				string s = m[II(r, c)];
				for (int y : rs) {
					if (y < r) continue;
					II key(y, c);
					if (os.find(key) != os.end()) break;
					if (m.find(key) != m.end()) continue;
					int d = y - r;
					string ns = s;
					for (int c = 0; c < 26; ++c) {
						if (d & (1 << c)) {
							ns += char('a' + c);
							d -= 1 << c;
						}
					}
					while (d > 0) {
						d -= 1 << 25;
						ns += 'z';
					}
					m[key] = ns;
					nq.emplace_back(key);
				}
				for (int x : cs) {
					if (x < c) continue;
					II key(r, x);
					if (os.find(key) != os.end()) break;
					if (m.find(key) != m.end()) continue;
					int d = x - c;
					string ns = s;
					for (int c = 0; c < 26; ++c) {
						if (d & (1 << c)) {
							ns += char('A' + c);
							d -= 1 << c;
						}
					}
					while (d > 0) {
						d -= 1 << 25;
						ns += 'Z';
					}
					m[key] = ns;
					nq.emplace_back(key);
				}
			}
			q = nq;
		}
		return m[II(R, C)];
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 6;
			// int Arr2[] = {};
			// int Arr3[] = {};
			string Arg4 = "CB";

			vector <int> Arg2;
			vector <int> Arg3;
			verify_case(n, Arg4, traverse(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 6;
			int Arr2[] = {0};
			int Arr3[] = {4};
			string Arg4 = "";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, traverse(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {0, 2};
			int Arr3[] = {2, 0};
			string Arg4 = "AaAa";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, traverse(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123;
			int Arg1 = 456;
			int Arr2[] = {0, 122};
			int Arr3[] = {1, 456};
			string Arg4 = "gfedaIHGCBAbA";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, traverse(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1234;
			int Arr2[] = {0, 1, 2, 3};
			int Arr3[] = {7, 7, 111, 111};
			string Arg4 = "";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, traverse(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongSimplePath ___test;
	___test.run_test(-1);
}
// END CUT HERE
