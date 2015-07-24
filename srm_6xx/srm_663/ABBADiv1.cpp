// BEGIN CUT HERE
/*
SRM 663 Div1 Easy (250)

PROBLEM STATEMENT
One day, Jamie noticed that many English words only use the letters A and B.
Examples of such words include "AB" (short for abdominal), "BAA" (the noise a sheep makes), "AA" (a type of lava), and "ABBA" (a Swedish pop sensation).

Inspired by this observation, Jamie created a simple game.
You are given two strings: initial and target.
The goal of the game is to find a sequence of valid moves that will change initial into target.
There are two types of valid moves:

Add the letter A to the end of the string.
Add the letter B to the end of the string and then reverse the entire string. (After the reversal the newly-added B becomes the first character of the string).

Return "Possible" (quotes for clarity) if there is a sequence of valid moves that will change initial into target.
Otherwise, return "Impossible".


DEFINITION
Class:ABBADiv1
Method:canObtain
Parameters:string, string
Returns:string
Method signature:string canObtain(string initial, string target)


CONSTRAINTS
-The length of initial will be between 1 and 49, inclusive.
-The length of target will be between 2 and 50, inclusive.
-target will be longer than initial.
-Each character in initial and each character in target will be either 'A' or 'B'.


EXAMPLES

0)
"A"
"BABA"

Returns: "Possible"

Jamie can perform the following moves:

Initially, the string is "A".
Jamie adds a 'B' to the end of the string and then reverses the string. Now the string is "BA".
Jamie adds a 'B' to the end of the string and then reverses the string. Now the string is "BAB".
Jamie adds an 'A' to the end of the string. Now the string is "BABA".

Since there is a sequence of moves which starts with "A" and creates the string "BABA", the answer is "Possible".


1)
"BAAAAABAA"
"BAABAAAAAB"

Returns: "Possible"

Jamie can add a 'B' to the end of the string and then reverse the string.


2)
"A"
"ABBA"

Returns: "Impossible"


3)
"AAABBAABB"
"BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"

Returns: "Possible"


4)
"AAABAAABB"
"BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ABBADiv1 {

	string init;
	string t;
	int init_len;
	int target_len;

	bool dfs(int dir, int st, int ed) {
		int len = ed - st;
		if (len == init_len) {
			string s = t.substr(st, init_len);
			if (dir) {
				reverse(s.begin(), s.end());
			}
			return init == s;
		}
		bool result = false;
		if (len > init_len) {
			if (!dir) {
				if (t[st] == 'B') {
					result |= dfs(1, st + 1, ed);
				}
				if (t[ed - 1] == 'A') {
					result |= dfs(0, st, ed - 1);
				}
			} else {
				if (t[ed - 1] == 'B') {
					result |= dfs(0, st, ed - 1);
				}
				if (t[st] == 'A') {
					result |= dfs(1, st + 1, ed);
				}
			}
		}
		return result;
	}

public:
	string canObtain(string initial, string target) {
		init = initial;
		t = target;
		init_len = initial.length();
		target_len = target.length();
		return dfs(0, 0, target_len) ? "Possible" : "Impossible";
	}


	bool dfs2(string a) {
		if (a.length() < target_len) {
			if (dfs2(a + 'A')) {
				return true;
			}
			reverse(a.begin(), a.end());
			if (dfs2('B' + a)) {
				return true;
			}
			return false;
		}
		return a == t;
	}

	string canObtain2(string initial, string target) {
		t = target;
		target_len = t.length();
		return dfs2(initial) ? "Possible" : "Impossible";
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
			string Arg0 = "A";
			string Arg1 = "BABA";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAAAAABAA";
			string Arg1 = "BAABAAAAAB";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "ABBA";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAABBAABB";
			string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAABAAABB";
			string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "B";
			string Arg1 = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
/*
struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; }
		else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};
*/
// END CUT HERE

// BEGIN CUT HERE
int main() {
	ABBADiv1 ___test;
	___test.run_test(0);
	___test.run_test(1);
	___test.run_test(2);
	___test.run_test(3);
	___test.run_test(4);
	___test.run_test(5);
//	___test.run_test(-1);


	int cnt = 0;
	for (int t = 0; t < 10000; ++t) {
		int alen = (rand() * 4) / (RAND_MAX + 1) + 1;
		int blen = alen + (rand() * 4) / (RAND_MAX + 1) + 1;
		string a, b;
		for (int i = 0; i < alen; ++i) {
			a += (rand() * 2) / (RAND_MAX + 1) ? 'A' : 'B';
		}
		for (int i = 0; i < blen; ++i) {
			b += (rand() * 2) / (RAND_MAX + 1) ? 'A' : 'B';
		}

		string p = ___test.canObtain(a, b);
		string q = ___test.canObtain2(a, b);
		if (p != q) {
			printf("a: %s, b: %s, 1: %s, 2: %s\n", a.c_str(), b.c_str(), p.c_str(), q.c_str());
			if (++cnt >= 3) {
				break;
			}
		}
	}




}
// END CUT HERE
