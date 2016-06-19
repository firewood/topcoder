// BEGIN CUT HERE
/*
TCO 2016 Round 2C Easy (250)

PROBLEM STATEMENT
N bears are playing a game.
For the purpose of this problem, each bear is just a single point in the plane.
You are given the coordinates of the bears: the vector <int>s x and y, each with N elements.
For each valid i there is a bear at (x[i], y[i]).

The game they play is played in rounds.
There is a single ball.
At the beginning of each round one of the bears holds the ball.
This bear chooses a direction and throws the ball in that direction.
The ball will travel along a straight line.
As soon as the ball hits another bear for the first time, that bear will catch the ball and the round will end.
It is not allowed to throw the ball in a direction where it won't hit any other bear.

At the beginning of the game, the bears choose two special roles: 
one bear will be the Startbear and another bear will be the Goalbear.
The Startbear has the ball at the beginning of the game.
The game ends when the Goalbear gets the ball.
Bears always play optimally ? they always finish the game in the smallest possible number of rounds.

There are exactly N*(N-1) ways to choose the Startbear and the Goalbear.
For each of those ways, determine the smallest possible number of rounds the game may take.
Return the sum of those N*(N-1) numbers.


DEFINITION
Class:BearBall
Method:countThrows
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countThrows(vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 1500, inclusive.
-x will contain exactly N elements.
-y will contain exactly N elements.
-Each element in x and in y will be between -20,000 and 20,000, inclusive.
-No two points will coincide.


EXAMPLES

0)
{1,4,2}
{1,10,7}

Returns: 6

There are three bears. They stand at (1,1), (4,10), and (2,7).

There are six ways to choose the Startbear and the Goalbear.
In each of those six cases the game will have a single round, because the Startbear can throw the ball directly at the Goalbear.
So, the answer is 6.


1)
{0,0,0,1,1}
{0,1,2,0,1}

Returns: 22

There are five bears. They stand at (0,0), (0,1), (0,2), (1,0), and (1,1).

There are 20 ways to choose the two special bears. In 18 of those 20 ways a single throw is enough. In each of the remaining two ways the bears need two rounds of the game.

Consider the situation when the Startbear is at (0,0) and the Goalbear is at (0,2). 
This game cannot be won in a single round:
if the Startbear throws a ball in the direction of the Goalbear, the ball will hit the bear at (0,1) and that bear will catch it.

There are multiple ways to win that game in two rounds.
For example, after the Startbear hits the bear at (0,1), that bear will throw the ball to the Goalbear.
Another optimal strategy is to start by throwing the ball from (0,0) to (1,1).
This is shown in the figure below; the bear with the ball is painted red.


2)
{5,7,9,11}
{4,3,2,1}

Returns: 20


3)
{10,10,50,50,90,90}
{5,17,5,17,5,17}

Returns: 34


4)
{-100, -90, -80, -70, -85, -90, 0, 20}
{-5, -8, -13, -21, -13, -13, -13, -69}

Returns: 68

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, LL> ILL;
typedef map<double, ILL> DILLMap;

class BearBall {

public:
	int countThrows(vector <int> x, vector <int> y) {
		int ans = 0;
		bool d[1500][1500] = {};
		int N = (int)x.size();
		for (int i = 0; i < N; ++i) {
			DILLMap m;
			int cnt = 0;
			for (int j = 0; j < N; ++j) {
				if (i != j) {
					LL dx = x[j] - x[i], dy = y[j] - y[i];
					LL dist = dx*dx + dy*dy;
					double r = atan2(dy, dx);
					if (m.find(r) != m.end()) {
						++cnt;
						ILL prev = m[r];
						if (prev.second < dist) {
							continue;
						}
						d[i][prev.first] = 0;
					}
					m[r] = ILL(j, dist);
					d[i][j] = 1;
				}
			}
			if (cnt >= N - 2) {
				return (LL)(N - 1) * N * (N + 1) / 6 * 2;
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				ans += d[i][j] ? 1 : 2;
			}
		}
		return ans * 2;
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
			int Arr0[] = {1,4,2};
			int Arr1[] = {1,10,7};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,1,1};
			int Arr1[] = {0,1,2,0,1};
			int Arg2 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,7,9,11};
			int Arr1[] = {4,3,2,1};
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,50,50,90,90};
			int Arr1[] = {5,17,5,17,5,17};
			int Arg2 = 34;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-100, -90, -80, -70, -85, -90, 0, 20};
			int Arr1[] = {-5, -8, -13, -21, -13, -13, -13, -69};
			int Arg2 = 68;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearBall ___test;
	___test.run_test(-1);
}
// END CUT HERE
