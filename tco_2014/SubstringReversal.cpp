// BEGIN CUT HERE
/*
TCO 2014 Round 2C Easy (300)

PROBLEM STATEMENT

You are given a string S. The string can have up to 2500 characters.
You have to reverse exactly one substring of S. Formally, you have to choose two 0-based indices {x,y} such that x <= y, and then you have to reverse the order of the letters with indices x through y, inclusive. That is, S[x]S[x+1]...S[y] becomes S[y]...S[x+1]S[x].

For example, if S="abcdefg", you can choose the indices {2,5} to obtain "abfedcg", the indices {0,1} to obtain "bacdefg", or the indices {3,3} to obtain "abcdefg". (In the last example, only one letter was selected, so the string did not change.)

Your goal is to produce the lexicographically smallest string possible. Return a vector <int> containing two elements: the optimal indices x and y.
If there are multiple optimal choices, find the one with the smallest x.
If there are still multiple optimal choices, find the one with the smallest y.


DEFINITION
Class:SubstringReversal
Method:solve
Parameters:string
Returns:vector <int>
Method signature:vector <int> solve(string S)


NOTES
-Given two strings A and B of equal length, we say that A is lexicographically smaller than B if A has a smaller character than B at the first position where they differ.


CONSTRAINTS
-S will contain between 1 and 2500 elements, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"abdc"

Returns: {2, 3 }

Reverse "dc" to "cd".


1)
"aabbcc"

Returns: {0, 0 }

Nothing to reverse here, you cannot produce a lexicographically smaller string.


2)
"misof"

Returns: {0, 4 }

Reverse the entire string.


3)
"ivan"

Returns: {0, 2 }

Reverse "iva" to bring 'a' to the beginning.


4)
"thisseemstobeaneasyproblem"

Returns: {0, 13 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

typedef vector<int> IntVec;

class SubstringReversal {

public:
	vector <int> solve(string S) {
		vector <int> ans(2);
		int len = S.length();
		string x = S;
		sort(x.begin(), x.end());
		for (int i = 0; i < len; ++i) {
			if (S[i] != x[i]) {
				string sm = S;
				for (int j = i + 1; j < len; ++j) {
					if (S[j] < S[i]) {
						string t = S;
						reverse(t.begin() + i, t.begin() + j + 1);
						if (t < sm) {
							sm = t;
							ans[0] = i;
							ans[1] = j;
						}
					}
				}
				break;
			}
		}
		return ans;
	}

	vector <int> solve2(string S) {
		vector <int> ans(2);
		int len = S.length();
		string m = S;
		string r = S;
		reverse(r.begin(), r.end());
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {
				string y = S.substr(0, i) + r.substr(len - j - 1, j - i + 1) + S.substr(j + 1);
				if (y < m) {
					ans[0] = i;
					ans[1] = j;
					m = y;
				}
			}
		}
		return ans;
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
			string Arg0 = "abdc";
			int Arr1[] = {2, 3 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabbcc";
			int Arr1[] = {0, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "misof";
			int Arr1[] = {0, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ivan";
			int Arr1[] = {0, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "thisseemstobeaneasyproblem";
			int Arr1[] = {0, 13 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 =
  				"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			int Arr1[] = { 0, 2499 };
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubstringReversal ___test;
	___test.run_test(-1);

/*
	for (int i = 0; i < 1000; ++i) {
		int len = (rand() * 5) / (RAND_MAX + 1) + 1;
		char w[2560] = {};
		for (int j = 0; j < len; ++j) {
			w[j] = 'a' + (rand() * 5) / (RAND_MAX + 1);
		}
		IntVec p = ___test.solve2(w);
		DWORD t = GetTickCount();
		IntVec q = ___test.solve(w);
		DWORD passed = GetTickCount() - t;

		if (passed > 2000 || p[0] != q[0] || p[1] != q[1]) {
			ofstream out("challenge.txt");
			out << w << endl;

			cout << "str:" << endl << w << endl;
			cout << "mine:" << p[0] << "/" << p[1] << ", target:" << q[0] << "/" << q[1] << endl;
			return 0;
		}
	}
	printf("PASSED\n");
*/
}
// END CUT HERE
