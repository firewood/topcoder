// BEGIN CUT HERE
/*
SRM 567 Div1 Medium (500)

// PROBLEM STATEMENT
// Manao has invented a new unusual two-player game which he calls the String Game.
The game is played on a set of strings of the same length comprised of lowercase English letters.

In the beginning, the first player chooses a string X from the set and permutes its characters in any way he wants.
He also chooses a permutation of the English alphabet.
After that, the second player may permute the characters in each of the strings in the set, except for X.
Now X is lexicographically compared to each of the other strings in the set using the permuted English alphabet.
If X is strictly smaller than each of the other strings, the first player wins. Otherwise, the second player does.

In order to compare two different strings A and B, first it is necessary to find the first position at which these strings differ.
Let the characters at this position in A and B be a and b.
If a stands earlier than b in the permuted alphabet, then A is lexicographically smaller than B, otherwise B is lexicographically smaller than A.
For example, with alphabet {b, a, c, d, ..., z}, the string "aba" is lexicographically smaller than the string "aab" because 'b' stands earlier than 'a' in the alphabet.

You are given a vector <string> S, the set of strings on which the String Game is played.
Determine all strings which, when chosen by the first player, allow him to win if both he and his opponent play optimally.
That is, the first player always permutes the string X and the alphabet optimally, and then the second player permutes all the other strings optimally.
Return a vector <int> containing the sorted list of all 0-based indices of all such strings.


DEFINITION
Class:StringGame
Method:getWinningStrings
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getWinningStrings(vector <string> S)


NOTES
-The return value may sometimes be an empty vector <int>.


CONSTRAINTS
-S will contain between 2 and 50 elements, inclusive.
-Each element of S will be between 1 and 50 characters long, inclusive.
-All elements of S will be of equal length.
-Each element of S will consist of lowercase letters ('a'-'z') only.
-The elements of S will be distinct.


EXAMPLES

0)
{"a", "b", "c", "d"}

Returns: {0, 1, 2, 3 }

For each of the given strings, Manao can choose the alphabet which begins with the string's only character and his string will be lexicographically smallest.


1)
{"aabbcc", "aaabbb", "aaaccc"}

Returns: {1, 2 }

Manao can win if he chooses the string "aaabbb" or "aaaccc". For "aaabbb", he can choose permutation of the alphabet {b, a, c, ..., z} and make his string "bbbaaa". For "aaaccc", the permutation can be {c, a, b, d, ..., z} and the string itself can be "cccaaa". In both cases, regardless of which permutations the opponent chooses, the two other strings will always be lexicographically larger than Manao's string.


2)
{"ab", "ba"}

Returns: { }

Note that the first player's string should be strictly smaller than the opponent's strings.


3)
{"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}

Returns: {1, 3, 4 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class StringGame {
public:
	vector <int> getWinningStrings(vector <string> S) {
		vector <int> ans;
		int sz = (int)S.size();
		int cnt[50][26] = {};
		int i, j, k, l;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < (int)S[i].length(); ++j) {
				cnt[i][S[i][j]-'a'] += 1;
			}
		}

#if 1
		for (i = 0; i < sz; ++i) {
			int lc = 1;
			int lesser[50] = {};
			bool yes = false;
			for (l = 0; l < 26; ++l) {
				for (j = 0; j < 26; ++j) {
					for (k = 0; k < sz; ++k) {
						if (!lesser[k] && cnt[k][j] > cnt[i][j]) {
							break;
						}
					}
					if (k < sz) {
						continue;
					}
					for (k = 0; k < sz; ++k) {
						if (cnt[k][j] < cnt[i][j]) {
							if (!lesser[k]) {
								lesser[k] = 1;
								if (++lc >= sz) {
									yes = true;
								}
							}
						}
					}
				}
			}
			if (yes) {
				ans.push_back(i);
			}
		}
#else
		typedef long long LL;
		LL full = (1LL << sz) - 1;
		for (i = 0; i < sz; ++i) {
			LL lesser = 1LL << i;
			for (l = 0; l < 26; ++l) {
				for (j = 0; j < 26; ++j) {
					LL b = 0;
					for (k = 0; k < sz; ++k) {
						if (lesser & (1LL << k)) continue;
						if (cnt[k][j] > cnt[i][j]) {
							break;
						}
						if (cnt[k][j] < cnt[i][j]) {
							b |= 1LL << k;
						}
					}
					if (k < sz) continue;
					lesser |= b;
				}
			}
			if (lesser == full) {
				ans.push_back(i);
			}
		}
#endif

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
			string Arr0[] = {"a", "b", "c", "d"};
			int Arr1[] = {0, 1, 2, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aabbcc", "aaabbb", "aaaccc"};
			int Arr1[] = {1, 2 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab", "ba"};
			int Arr1[] = { 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
//			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
			int Arr1[] = {1, 3, 4 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;





		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaabbbcde", "aaabbbcdf", "eeeeeeeee"};
			int Arr1[] = {0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;







	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringGame ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
