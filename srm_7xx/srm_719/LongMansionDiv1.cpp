// BEGIN CUT HERE
/*
SRM 719 Div1 Easy (250)

PROBLEM STATEMENT
LYC is the pet dog of Emperor Zhangzj of Yali Empire. Zhangzj has a huge affluence. Besides his palace, he has multiple estates. One of them is the Long Mansion, a famous site in Yali. LYC loves to play. One day, he accidentally enters the labyrinthine Long Mansion.

The mansion can be seen as a grid of unit square cells. There are N rows, indexed from 0 to (N - 1). The number of columns is infinite in one direction. The columns are indexed by nonnegative integers, starting from 0. You are given ints sX, sY, eX, eY. Initially LYC is standing on the cell on the sXth row, and the sYth column. The exit is at the cell on the eXth row, and the eYth column. LYC can walk to a cell that shares an edge with the cell he is at. He wished to reach the exit as soon as possible.

Unfortunately, each cell contains some obstacles that slow LYC down. For each cell we know the time LYC needs to spend there while passing through the cell. LYC also needs to spend that amount of time in the initial cell and in the exit cell as well. There is a pattern to the obstacles: each column of the mansion looks the same. In other words, all cells within any given row contain the same obstacle type, and therefore they delay LYC by the same amount of time. For example, the entire first row are some bushes, the entire second row contains some walls, and so on. You are given the times in the vector <int> t. More precisely, LYC will spend t[i] time in each cell he visits in row i.

You are given one vector <int> t and 4 ints sX, sY, eX, eY. Return the minimal time LYC needs to spend to reach the exit.


DEFINITION
Class:LongMansionDiv1
Method:minimalTime
Parameters:vector <int>, int, int, int, int
Returns:long long
Method signature:long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-t will contain exactly N elements.
-Each element of t will be between 1 and 1,000, inclusive.
-sX and eX will be between 0 and (N - 1), inclusive.
-sY and eY will be between 0 and 1,000,000,000 inclusive.


EXAMPLES

0)
{5, 3, 10}
2
0
2
2

Returns: 29

The optimal path would be (2, 0) &rarr (1, 0) &rarr (1, 1) &rarr (1, 2) &rarr (2, 2). The total time would be 10 + 3 + 3 + 3 + 10 = 29. Note that you should count the time LYC spends on the inital cell and the cell of the exit as well.


1)
{5, 3, 10}
0
2
0
0

Returns: 15

This time the optimal path would be (0, 2) &rarr (0, 1) &rarr (0, 0).


2)
{137, 200, 184, 243, 252, 113, 162}
0
2
4
2

Returns: 1016


3)
{995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999}
18
433156521
28
138238863

Returns: 293443080673


4)
{1}
0
0
0
0

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class LongMansionDiv1 {
public:
	long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY) {
		LL ans = 1LL << 60;
		int n = (int)t.size();
		for (int c = 0; c < n; ++c) {
			LL cost = 0;
			for (int x = sX; x < c; ++x) {
				cost += t[x];
			}
			for (int x = sX; x > c; --x) {
				cost += t[x];
			}
			for (int x = eX; x < c; ++x) {
				cost += t[x];
			}
			for (int x = eX; x > c; --x) {
				cost += t[x];
			}
			cost += (abs(eY - sY) + 1) * (LL)t[c];
			ans = min(ans, cost);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 3, 10};
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 2;
			long long Arg5 = 29LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 3, 10};
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 0;
			long long Arg5 = 15LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {137, 200, 184, 243, 252, 113, 162};
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = 2;
			long long Arg5 = 1016LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999};
			int Arg1 = 18;
			int Arg2 = 433156521;
			int Arg3 = 28;
			int Arg4 = 138238863;
			long long Arg5 = 293443080673LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 0;
			long long Arg5 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongMansionDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
