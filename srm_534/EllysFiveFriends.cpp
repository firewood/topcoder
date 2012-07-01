// BEGIN CUT HERE
/*
// SRM 534 Div2 Hard (1000)

// PROBLEM STATEMENT
// During the girl sleepovers, Elly and her friends happen to play games
that involve the consumption of fluids. For the purpose of this problem,
we will assume that the fluids consumed are apple juice and orange juice.
(This does not necessarily correspond to reality.)

One of these games is the following:
Five girls sit down in a circle. We will label the girls 0 through 4 in the
order in which they sit. Note that the girls 0 and 4 sit next to each other.
At the beginning of the game, each girl i picks a positive integer numbers[i]
between one and ten thousand.

The game then proceeds in rounds.
Each round involves two girls that sit next to each other.
Both girls must have positive integers at the beginning of the round.
There are two possible actions they may perform:

If both their integers are odd, they may perform the "apple action":
they subtract 1 from each of their integers, and they share a glass of apple juice.
They may always perform the "orange action": They divide both their integers by 2
(rounding down, if the result is not an integer) and share a glass of orange juice.

The girls win the game if all of their numbers reach zero.


Elly once observed five of her friends playing this game. Elly recorded the
game on a piece of paper:
For each round, she wrote down the pair of girls that played in that round and
the drink they chose. (The order in which she wrote down the two girls does not matter.)
If the girls won the game, Elly gives the paper to you, otherwise she throws it away.

You are given the vector <int> numbers containing the integers the girls selected
at the beginning of the game. Let X be the count of different ways in which
the girls could have won the game. In other words, X is the number of different
papers Elly could have written down and given to you.
Your method must return this value modulo 1,000,000,007.

DEFINITION
Class:EllysFiveFriends
Method:getZero
Parameters:vector <int>
Returns:int
Method signature:int getZero(vector <int> numbers)


CONSTRAINTS
-numbers will contain exactly 5 elements.
-Each element of numbers will be between 1 and 10000, inclusive.


EXAMPLES

0)
{5, 1, 1, 2, 3}

Returns: 10

One of the ways in which the girls can win the game:

Girls 0 and 1 drink orange juice. New integers: {2, 0, 1, 2, 3}.
Girls 2 and 3 drink orange juice. New integers: {2, 0, 0, 1, 3}.
Girls 3 and 4 drink apple juice.  New integers: {2, 0, 0, 0, 2}.
Girls 0 and 4 drink orange juice. New integers: {1, 0, 0, 0, 1}.
Girls 0 and 4 drink apple juice.  New integers: {0, 0, 0, 0, 0}.

A different way of winning the game has the same first four steps, and then in step 5 girls 0 and 4
drink orange juice. Note that in step 2 girls 2 and 3 are not allowed to choose apple juice, as at
that time at least one of their integers is even.


1)
{2, 1, 1, 1, 2}

Returns: 0

Here the girls cannot win the game at all.


2)
{3, 4, 1, 4, 5}

Returns: 520

Even with small numbers the answer can be rather big.


3)
{42, 666, 1337, 666, 42}

Returns: 549119981

Don't forget to use modular arithmetics.


4)
{8792, 9483, 6787, 9856, 6205}

Returns: 165501353

An almost maximal test case.


5)
{10000, 10000, 10000, 10000, 10000}

Returns: 952019520

The maximal test case.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 1000000007

typedef vector<int> IntVec;

static int memo[26][26][26][26][26];

class EllysFiveFriends {
	int val2key[5][10001];
	int key2val[5][10001];

	int rec(IntVec &state) {
		int &res = memo[state[0]][state[1]][state[2]][state[3]][state[4]];
		if (res >= 0) {
			return res;
		}
		res = 0;
		int i, j;
		for (i = 0; i < 5; ++i) {
			j = (i+1) % 5;
			int si = state[i], sj = state[j];
			if (si == 0 || sj == 0) {
				continue;
			}
			IntVec next = state;
			int ni = key2val[i][si], nj = key2val[j][sj];
			if ((ni & 1) & (nj & 1)) {
				next[i] -= 1;
				next[j] -= 1;
				res = (res + rec(next)) % MOD;
			}
			next[i] = val2key[i][ni / 2];
			next[j] = val2key[j][nj / 2];
			res = (res + rec(next)) % MOD;
		}
		return res;
	}

public:
	int getZero(vector <int> numbers) {
		IntVec state(5);
		int i, j;
		for (i = 0; i < 5; ++i) {
			IntVec vars(1);
			j = numbers[i];
			while (j > 0) {
				vars.push_back(j);
				if (j & 1) {
					j &= ~1;
				} else {
					j >>= 1;
				}
			}
			sort(vars.begin(), vars.end());
			for (j = 0; j < (int)vars.size(); ++j) {
				val2key[i][vars[j]] = j;
				key2val[i][j] = vars[j];
			}
			state[i] = (int)vars.size() - 1;
		}
		memset(memo, -1, sizeof(memo));
		memo[0][0][0][0][0] = 1;
		int res = rec(state);
		return res;
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
			int Arr0[] = {5, 1, 1, 2, 3};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1, 1, 1, 2};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 4, 1, 4, 5};
			int Arg1 = 520;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 666, 1337, 666, 42};
			int Arg1 = 549119981;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8792, 9483, 6787, 9856, 6205};
			int Arg1 = 165501353;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000, 10000, 10000, 10000, 10000};
			int Arg1 = 952019520;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8191, 8191, 8191, 8191, 8191};
			int Arg1 = 996154957;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysFiveFriends ___test;
//	___test.run_test(6);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
