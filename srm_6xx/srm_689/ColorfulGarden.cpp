// BEGIN CUT HERE
/*
SRM 689 Div1 Easy (250)

PROBLEM STATEMENT
We have a garden that contains some flowers.
The flowers are arranged into a rectangle with 2 rows and n columns.
You are given a vector <string> garden that describes our garden.
The vector <string> garden has two elements, each with n characters.
Each character in garden represents one flower.
Different characters in garden represent different colors.

Two flowers are considered adjacent if they are in the same column, or if they are next to each other in the same row.
Your goal is to produce a garden in which no pair of adjacent flowers shares the same color.
You may rearrange the flowers in your garden arbitrarily (without changing its shape).
More precisely, you may swap any two flowers in your garden, and you may do so arbitrarily many times.

If the goal can be reached, return a vector <string> that will encode the resulting garden in the same format as was used for garden.
If there are multiple solutions, you may return any of them.
If there is no solution, return an empty vector <string>.


DEFINITION
Class:ColorfulGarden
Method:rearrange
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> rearrange(vector <string> garden)


CONSTRAINTS
-garden will contain exactly 2 elements, inclusive.
-Each element in garden will contain between 1 and 50 characters, inclusive.
-Each element in garden will contain the same number of characters.
-Each character in garden will be a lowercase letter ('a'-'z').


EXAMPLES

0)
{"aa",
 "bb"}

Returns: {"ab", "ba" }

Swapping garden[0][1] and garden[1][1] produces a valid garden.


1)
{"xxxx",
 "xxxx"}

Returns: { }

No matter what we do, we will end up with the same result, and that is not a valid solution.


2)
{"abcd",
 "abcd"}

Returns: {"abcd", "dcba" }


3)
{"abcdefghijklm",
 "nopqrstuvwxyz"}

Returns: {"abcdefghijklm", "nopqrstuvwxyz" }


4)
{"aaa",
 "aab"}

Returns: { }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class ColorfulGarden {
public:
	vector <string> rearrange(vector <string> garden) {
		vector <string> ans;
		int W = (int)garden[0].length();
		int cnt[256] = {};
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < W; ++j) {
				cnt[garden[i][j]] += 1;
			}
		}
		IIVec v;
		for (int i = 0; i < 256; ++i) {
			if (cnt[i] > W) {
				return ans;
			}
			if (cnt[i]) {
				v.push_back(II(-cnt[i], i));
			}
		}
		sort(v.begin(), v.end());
		ans = garden;
		int pos = 0;
		for (int i = 0; i < W * 2; ++i) {
			if (v[pos].first >= 0) {
				++pos;
			}
			int col = i % W, row = (col & 1) ^ (i >= W);
			ans[row][col] = (char)v[pos].second;
			v[pos].first += 1;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Source, const vector <string> &Expected, const vector <string> &Received) {
		cerr << "Test Case #" << Case << "...";
		bool valid = true;
		if (Expected.size() != Received.size()) {
			valid = false;
		}
		else if (Expected.size() > 0) {
			int W = (int)Source[0].length();
			int cnt[256] = {};
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < W; ++j) {
					cnt[Source[i][j]] += 1;
				}
			}
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < W; ++j) {
					cnt[Received[i][j]] -= 1;
					if (cnt[Received[i][j]] < 0) {
						valid = false;
					}
					if (Received[0][j] == Received[1][j]) {
						valid = false;
					}
					if (j > 0 && Received[i][j - 1] == Received[i][j]) {
						valid = false;
					}
				}
			}
			++W;
		}
		if (valid) {
			cerr << "PASSED" << endl;
		}
		else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: " << print_array(Expected) << endl;
			cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aa",
 "bb"};
			string Arr1[] = {"ab", "ba" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"xxxx",
 "xxxx"};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcd",
 "abcd"};
			string Arr1[] = {"abcd", "dcba" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcdefghijklm",
 "nopqrstuvwxyz"};
			string Arr1[] = {"abcdefghijklm", "nopqrstuvwxyz" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaa",
 "aab"};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac",
				"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbc" };
			string Arr1[] = { "abababababababababababababababababababababababacb", "babababababababababababababababababababababababac" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulGarden ___test;
	___test.run_test(-1);
}
// END CUT HERE
