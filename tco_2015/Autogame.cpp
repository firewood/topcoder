// BEGIN CUT HERE
/*
TCO 2015 Round 1A Medium (500)

PROBLEM STATEMENT
Hero is playing a game with tokens.
There are N places for tokens.
The places are numbered 1 through N.
There are also N arrows, each pointing from some place to some place.
No two arrows start at the same place.
It is possible that multiple arrows point to the same place.
Also, an arrow may start and end at the same place.

You are given the description of the game board: a vector <int> a with N elements.
For each i between 1 and N, inclusive, the arrow that starts at the place i points to the place a[i-1].

At the beginning of the game, Hero will take an arbitrary number of tokens between 0 and N, inclusive, and he will place them onto distinct places.
He will then play K rounds of the game.
In each round each token moves from its current place along the arrow to the new place.
After each round, Hero checks whether all tokens are still in distinct places.
If two or more tokens are in the same place, Hero loses the game.
Hero wins the game if he does not lose it during the K rounds he plays.

There may be multiple ways how Hero can win the game.
Two ways are different if there is some i such that at the beginning of the game place i did contain a token in one case but not in the other.
Count those ways and return their count modulo 1,000,000,007.


DEFINITION
Class:Autogame
Method:wayscnt
Parameters:vector <int>, int
Returns:int
Method signature:int wayscnt(vector <int> a, int K)


CONSTRAINTS
-a will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element in a will be between 1 and N, inclusive.
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,3}
5

Returns: 8

There are 2^3 = 8 valid ways to place the tokens. In each round each token will stay in the same place. Hence, Hero will win the game for each initial placement of tokens.


1)
{1,1,1}
1

Returns: 4

If Hero starts the game with two or three tokens, after the first round there will be multiple tokens in the same place (place 1) and Hero will lose the game. He will only win the game if he starts with 0 tokens (1 possibility) or with 1 token (3 possibilities).


2)
{2,1}	
42

Returns: 4


3)
{2,3,4,3}
3

Returns: 9


4)
{4,4,3,2,1}
3

Returns: 18

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class Autogame {
public:
	int wayscnt(vector <int> a, int K) {
		int N = (int)a.size();
		UnionFind g(64);
		int dp[2][64] = {};
		for (int i = 0; i < N; ++i) {
			dp[0][i] = i + 1;
		}
		int t = min(K, N);
		for (int i = 1; i <= t; ++i) {
			int current = i % 2;
			int previous = current ^ 1;
			for (int i = 0; i < N; ++i) {
				dp[current][i] = 0;
			}
			for (int i = 0; i < N; ++i) {
				if (dp[previous][i]) {
					int next = a[i] - 1;
					if (dp[current][next]) {
						g.unite(dp[current][next], dp[previous][i]);
					} else {
						dp[current][next] = dp[previous][i];
					}
				}
			}
		}

		LL ans = 1;
		for (int i = 1; i <= N; ++i) {
			if (g.root(i) == i) {
				LL sz = g.size(i);
				ans = (ans * (sz + 1)) % MOD;
			}
		}
		return (int)ans;
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
			int Arr0[] = {1,2,3};
			int Arg1 = 5;
			int Arg2 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arg1 = 1;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1}	;
			int Arg1 = 42;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,4,3};
			int Arg1 = 3;
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4,3,2,1};
			int Arg1 = 3;
			int Arg2 = 18;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Autogame ___test;
	___test.run_test(-1);
}
// END CUT HERE
