// BEGIN CUT HERE
/*
SRM 660 Div2 Medium (500)

PROBLEM STATEMENT
Hero is inviting his friends to the party.
He has n friends, numbered 0 through n-1.
For each of his friends there is at most one other person the friend dislikes.
You are given this information as a vector <int> a with n elements.
For each i, a[i] is either the number of the person disliked by friend i, we have a[i]=i if friend i likes everybody else.

Hero is inviting his friends one at a time.
Whenever he invites friend i, they will accept if and only if the friend a[i] didn't accept an earlier invitation.
(That includes two cases: either Hero didn't invite friend a[i] yet, or he did but the friend rejected the invitation.)

Hero noticed that the order in which he invites his friends matters: different orders may produce different numbers of accepted invitations.

Find an order that will produce the most accepted invitations, and return their number.


DEFINITION
Class:PrivateD2party
Method:getsz
Parameters:vector <int>
Returns:int
Method signature:int getsz(vector <int> a)


CONSTRAINTS
-a will contain exactly n elements.
-n will be between 1 and 50, inclusive.
-Each element of a will be between 0 and n - 1, inclusive.


EXAMPLES

0)
{0,1}

Returns: 2

Each of the friends likes the other. Regardless of the order in which Hero asks them, they will both accept the invitation.


1)
{1,0}

Returns: 1

Friend 0 dislikes friend 1 and vice versa. The first friend Hero asks will accept the invitation but then the other friend will certainly reject it.


2)
{1,0,3,2}

Returns: 2


3)
{5,2,2,4,5,0}

Returns: 5

Here is what would happen if Hero invited the friends in the order (0,1,2,3,4,5):

Friend 5 didn't accept yet, so friend 0 would accept.
Friend 2 didn't accept yet, so friend 1 would accept.
Friend 2 likes everybody and therefore they would accept.
Friend 4 didn't accept yet, so friend 3 would accept.
Friend 5 didn't accept yet, so friend 4 would accept.
Friend 0 did already accept, therefore friend 5 would reject.

It turns out that this solution happens to be optimal: there is no order such that all six friends would accept the invitations.


4)
{3,2,1,0,5,4}

Returns: 3

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

class PrivateD2party {

	int N;
	int Visited[100];
	int Loops;
	vector <int> h;
	vector <int> v[100];

	int dfs(int a) {
		if (Visited[a]) {
			return 0;
		}
		Visited[a] = 1;
		int r = 1;
		for (int n : v[a]) {
			if (Visited[n]) {
				Loops += 1;
			}
			r += dfs(n);
		}
		return r;
	}

public:
	int getsz(vector <int> a) {
		N = (int)a.size();
		h = a;
		for (int i = 0; i < N; ++i) {
			v[i].clear();
		}
		UnionFind uf(N);
		for (int i = 0; i < N; ++i) {
			if (i != a[i]) {
				v[a[i]].push_back(i);
				uf.unite(i, a[i]);
			}
		}
		int Max[100] = {};
		for (int i = 0; i < N; ++i) {
			memset(Visited, 0, sizeof(Visited));
			Loops = 0;
			int r = uf.root(i);
			int s = dfs(i);
			Max[r] = max(Max[r], s - Loops);
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			if (i == uf.root(i)) {
				ans += Max[i];
			}
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
			int Arr0[] = {0,1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getsz(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getsz(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,3,2};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getsz(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,2,2,4,5,0};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getsz(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,2,1,0,5,4};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getsz(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 13, 1, 2, 6, 17, 17, 2, 18, 14, 14, 15, 7, 14, 15, 6, 8, 5, 5, 4, 2 };
			int Arg1 = 19;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getsz(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrivateD2party ___test;
	___test.run_test(-1);
}
// END CUT HERE
