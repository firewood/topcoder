// BEGIN CUT HERE
/*
TCO 2017 R1A Easy (250)

PROBLEM STATEMENT
This task is about a group of people who like to play ping pong.
All games of ping pong mentioned in this task are one-on-one games.

You are given a vector <int> skills.
Each element of skills is the skill level of one person in the group.
The skill levels are all distinct.
Whenever two people play a game of ping pong, the one with the higher skill level always wins.

All people in the group would like to play but they only have a single table.
Therefore, only two people can play at any given time.

There will be a sequence of games, numbered starting from 1.
Game 1 will be played by the players who correspond to skills[0] and skills[1].
All the remaining people will form a queue, in the order in which they are given in skills.
After each game the following things will happen, in order:

The person who lost the game leaves the table and goes to the end of the queue.
If the person who won the game has already won N games in a row, they also leave the table and they go to the end of the queue (behind the person who lost the last game).
While there are fewer than two people at the table, the first person in the queue leaves the queue and goes to the table.
The two people at the table play the next game.


You are given the vector <int> skills, the int N, and an int K.
Return the two-element vector <int> { L, W }, where L and W are the skills of the loser and the winner of game K, in this order.

DEFINITION
Class:PingPongQueue
Method:whoPlaysNext
Parameters:vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> whoPlaysNext(vector <int> skills, int N, int K)


CONSTRAINTS
-skills will contain between 2 and 50 elements, inclusive.
-Each element of skills will be between 1 and 50, inclusive.
-All elements of skills will be distinct.
-N will be between 1 and 100, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1, 2, 3}
2
2

Returns: {2, 3 }

In all annotations, we call people by their skill. For example, "player 7" means "the player whose skill level is 7".

In this example players 1 and 2 play the first game, and player 2 wins.
For the second game, player 3 joins player 2, so we return { 2, 3 }.


1)
{1, 2, 3}
2
4

Returns: {1, 2 }

The sequence of games is as follows:

Player 1 loses to player 2.
Player 2 loses to player 3.
Player 1 loses to player 3. After this player 1 joins the queue, player 3 also steps down because he just won 2 games in a row and joins the queue.
Player 1 loses to player 2.


2)
{49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50}
10
399

Returns: {12, 50 }


3)
{30, 12}
34
80

Returns: {12, 30 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <list>

using namespace std;

class PingPongQueue {
public:
	vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
		list<int> q;
		for (int a : skills) {
			q.push_back(a);
		}
		int a = -1, b = -1, w = 0;
		for (int t = 1; ; ++t) {
			if (a < 0) {
				w = 0;
				a = q.front();
				q.pop_front();
			}
			b = q.front();
			q.pop_front();
			if (b > a) {
				w = 0;
				swap(a, b);
			}
			if (t == K) {
				break;
			}
			q.push_back(b);
			if (++w >= N) {
				q.push_back(a);
				a = -1;
			}
		}
		return { b, a };
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
			int Arr0[] = {1, 2, 3};
			int Arg1 = 2;
			int Arg2 = 2;
			int Arr3[] = {2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arg1 = 2;
			int Arg2 = 4;
			int Arr3[] = {1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
			int Arg1 = 10;
			int Arg2 = 399;
			int Arr3[] = {12, 50 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30, 12};
			int Arg1 = 34;
			int Arg2 = 80;
			int Arr3[] = {12, 30 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PingPongQueue ___test;
	___test.run_test(-1);
}
// END CUT HERE
