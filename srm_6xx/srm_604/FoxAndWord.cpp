// BEGIN CUT HERE
/*
SRM 604 Div2 Easy (250)

PROBLEM STATEMENT
One day, Fox Ciel looked at the words "tokyo" and "kyoto" and noticed an unusual property:
We can split "tokyo" into "to"+"kyo", and then swap those two parts to obtain "kyo"+"to" = "kyoto".

Formally, let S and T be two different strings.
We call the pair (S,T) interesting if there are two non-empty strings A and B such that S = A+B and T = B+A.
For example, according to this definition, if S="tokyo" and T="kyoto", then the pair (S,T) is interesting, because we can find A="to" and B="kyo".

You are given a vector <string> words.
Return the number of interesting pairs we can find among the elements of words.
Only count each pair once.
E.g., ("tokyo","kyoto") and ("kyoto","tokyo") is the same interesting pair.


DEFINITION
Class:FoxAndWord
Method:howManyPairs
Parameters:vector <string>
Returns:int
Method signature:int howManyPairs(vector <string> words)


CONSTRAINTS
-words will contain between 2 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each character in each element of words will be a lowercase letter ('a'-'z').
-All the elements in words will be pairwise distinct.


EXAMPLES

0)
{"tokyo", "kyoto"}

Returns: 1

As mentioned in the problem statement, ("tokyo", "kyoto") is an interesting pair.


1)
{"aaaaa", "bbbbb"}

Returns: 0

("aaaaa", "bbbbb") is not an interesting pair.


2)
{"ababab","bababa","aaabbb"}

Returns: 1

There is one interesting pair: ("ababab","bababa").
Note that for this interesting pair there is more than one way to choose the strings A and B.


3)
{"eel", "ele", "lee"}

Returns: 3


4)
{"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}

Returns: 6


5)
{"top","coder"}

Returns: 0

Different elements of words may have different lengths.

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndWord {
public:
	int howManyPairs(vector <string> words) {
		int ans = 0;
		int N = (int)words.size();
		for (int i = 0; i < N; ++i) {
			string a = words[i];
			for (int j = i+1; j < N; ++j) {
				if (a.length() == words[j].length()) {
					string b = words[j] + words[j];
					int pos = (int)b.find(a);
					if (pos > 0) {
						++ans;
					}
				}
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
			string Arr0[] = {"tokyo", "kyoto"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManyPairs(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaaaa", "bbbbb"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManyPairs(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ababab","bababa","aaabbb"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManyPairs(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"eel", "ele", "lee"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManyPairs(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManyPairs(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"top","coder"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManyPairs(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndWord ___test;
	___test.run_test(-1);
}
// END CUT HERE
