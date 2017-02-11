// BEGIN CUT HERE
/*
SRM 708 Div1 Easy (250)

PROBLEM STATEMENT
The instability of a string is the number of pairs of consecutive characters that are distinct.
For example, the instability of "aafcccca" is 3 and the instability of "aaaaaaaaa" is 0.

The total instability of a sequence of strings is the sum of instabilities of the individual strings.

The similarity between two strings s1 and s2 is the number of pairs of equal characters.
In other words, it is the number of pairs of indices (i,j) such that s1[i] = s2[j].
For example, the similarity between "aaaabc" and "xba" is 5 and the similarity between "xxx" and "xxxx" is 12.

The total similarity of a sequence of M strings is computed as follows:
For each of the M*(M-1)/2 possible pairs of strings you compute the similarity between them, and then you sum those M*(M-1)/2 numbers.

Limak needs some balance in his life.
He asked you to find a sequence of exactly N strings satisfying the following conditions:

The total instability of the sequence is equal to the total similarity of the sequence.
Each string contains between 1 and 100 characters, inclusive.
Each string contains only lowercase English letters ('a' - 'z').

For the given constraints a solution always exists.
If there are many solutions, you may return any one of them.


DEFINITION
Class:BalancedStrings
Method:findAny
Parameters:int
Returns:vector <string>
Method signature:vector <string> findAny(int N)


CONSTRAINTS
-N will be between 1 and 100, inclusive.


EXAMPLES

0)
3

Returns: {"eertree", "topcoder", "arena" }

We have:

instability("eertree") = 4
instability("topcoder") = 7
instability("arena") = 4

Thus, the total instability is 4 + 7 + 4 = 15.


We also have:

similarity("eertree","topcoder") = 7
similarity("eertree","arena") = 6
similarity("topcoder","arena") = 2

Thus, the total similarity is 7 + 6 + 2 = 15, which is the same as the total instability.


1)
4

Returns: {"hello", "little", "polar", "bear" }

In the provided answer, the total instability and the total similarity are both equal to 14.


2)
5

Returns: {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" }

Note that the returned sequence may contain multiple copies of the same string.
Each of those is counted separately.


3)
1

Returns: {"kkkkkkkkkkkkkkkkkkk" }


4)
10

Returns: {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;
typedef map<int, int> IntMap;

static int instability(StrVec &v) {
	int cnt = 0;
	for (string &s : v) {
		for (int i = 1; i < (int)s.length(); ++i) {
			cnt += s[i - 1] != s[i];
		}
	}
	return cnt;
}

int similarity(StrVec &v) {
	int r = 0;
	IntMap cnt[100];
	for (int i = 0; i != v.size(); ++i) {
		for (char c : v[i]) {
			++cnt[i][c - 'a'];
		}
	}
	for (int i = 0; i != v.size(); ++i) {
		for (auto &kv : cnt[i]) {
			for (int j = i + 1; j != v.size(); ++j) {
				r += kv.second * cnt[j][kv.first];
			}
		}
	}
	return r;
}

class BalancedStrings {
	public:
	vector <string> findAny(int N) {
		StrVec ans(N);
		if (N <= 26) {
			for (int i = 0; i < N; ++i) {
				ans[i] = string(1, 'a' + i);
			}
		} else {
			ans[0] = "abababababababababababababababababababababababababababababababababababababababababababababababababab";
			ans[1] = "cdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcd";
			for (int i = 2; i < N; ++i) {
				ans[i] = "e";
			}
			int p = instability(ans);
			int q = similarity(ans);
			for (int i = N - 1; q > p && i >= 2; --i) {
				ans[i] = string(1, 'e' + (i % 22));
				q = similarity(ans);
			}
			while (p > q) {
				for (int i = 1; i >= 0; --i) {
					if (ans[i].length() > 1) {
						ans[i] = ans[i].substr(0, ans[i].length() - 1);
						break;
					}
				}
				p = instability(ans);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arr1[] = {"eertree", "topcoder", "arena" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			string Arr1[] = {"hello", "little", "polar", "bear" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			string Arr1[] = {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arr1[] = {"kkkkkkkkkkkkkkkkkkk" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			string Arr1[] = {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BalancedStrings ___test;
	___test.run_test(-1);

	for (int t = 1; t <= 100; ++t) {
		StrVec ans = ___test.findAny(t);
		int p = instability(ans);
		int q = similarity(ans);
		if (ans.empty() || ans[0].empty() || p != q) {
			printf("ERROR: %d\n", t);
		}
	}
}
// END CUT HERE
