// BEGIN CUT HERE
/*
SRM 688 Div1 Easy (250)

PROBLEM STATEMENT
Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.

Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".

You have a string s.
You want to change it into a correct parentheses sequence.

You can only change the string using magic flips.
In order to do a magic flip, you specify two 0-based indices L and R such that L <= R.
The operation modifies the characters on indices from L to R, inclusive.
First, the order of these characters is reversed.
Then, each character is toggled to the opposite one.
That is, each '(' in the specified range changes to a ')' and vice versa.

For example, suppose you have the string "((()".
If you do a magic flip on the entire string (i.e., choosing L=0 and R=3), it first gets reversed to ")(((" and then all parentheses are toggled. Thus, flipping the string "((()" produces the string "()))".

Given s, find and report any sequence of at most 10 magic flips that changes s into a correct parentheses sequence.
If there is no such sequence of magic flips, return the vector <int> {-1}.
If there are multiple such sequences, you may return any of them.
In particular, you are not required to find the shortest possible sequence of flips.
The returned vector <int> should contain 2*F elements, where F is the number of flips you want to perform:
for each flip, in order, first its L and then its R.


DEFINITION
Class:ParenthesesDiv1Easy
Method:correct
Parameters:string
Returns:vector <int>
Method signature:vector <int> correct(string s)


CONSTRAINTS
-s will contain between 1 and 1,000 characters, inclusive.
-Each character in s will be '(' or ')'.


EXAMPLES

0)
")("

Returns: {0, 0, 1, 1 }

The first flip has L=R=0.
It changes the string to "((".
The second flip has L=R=1.
It changes that string to "()", which is a correct parentheses sequence.


1)
"))))))(((((("

Returns: {0, 5, 6, 11 }

Here, the first flip changes the string to "((((((((((((" and then the second flip changes it to "(((((())))))".

Note that {0,0,1,1,2,2,...,11,11} is not a valid solution.
This sequence of flips produces a correct parentheses sequence (by flipping each character separately).
However, this sequence consists of 12 flips and we are only allowed to perform at most 10 flips.


2)
"))()())()"

Returns: {-1 }

This s has length 9.
There is no correct parentheses sequence of length 9, so there can be no good sequence of flips.


3)
")()((("

Returns: {0, 0, 3, 3, 5, 5 }


4)
"()"

Returns: { }

This time we don't need to do anything.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ParenthesesDiv1Easy {
public:
	vector <int> correct(string s) {
		vector <int> ans;
		int len = (int)s.length();
		if (len % 2) {
			ans.push_back(-1);	
		} else {
			vector<int> deleted(len);
			int closed_cnt = 0, closed_pos = -1, opened_cnt = 0;
			for (int i = 0; i < len; ++i) {
				if (s[i] == '(') {
					++opened_cnt;
				} else if (opened_cnt) {
					--opened_cnt;
					deleted[i] = 1;
					for (int j = i - 1; j >= 0; --j) {
						if (!deleted[j]) {
							deleted[j] = 1;
							break;
						}
					}
				} else {
					++closed_cnt;
					closed_pos = i;
				}
			}

			if (closed_pos >= 0) {
				ans.push_back(0);
				ans.push_back(closed_pos);
				for (int i = 0; i <= (closed_pos / 2); ++i) {
					swap(deleted[i], deleted[closed_pos - i]);
					char a = s[i] == '(' ? ')' : '(';
					char b = s[closed_pos - i] == '(' ? ')' : '(';
					s[i] = b, s[closed_pos - i] = a;
				}
			}

			int total_cnt = closed_cnt + opened_cnt;
			opened_cnt = 0;
			for (int i = 0; i < len; ++i) {
				if (!deleted[i] && s[i] == '(') {
					++opened_cnt;
					if (opened_cnt > (total_cnt / 2)) {
						ans.push_back(i);
						ans.push_back(len - 1);
						break;
					}
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
		if ((Case == -1) || (Case == n)) {
			string Arg0 = ")(";
			int Arr1[] = { 0, 0, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "))))))((((((";
			int Arr1[] = { 0, 5, 6, 11 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "))()())()";
			int Arr1[] = { -1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			string Arg0 = ")()(((";
			//			int Arr1[] = {0, 0, 3, 3, 5, 5 };
			int Arr1[] = { 0, 0, 4, 5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "()";

			vector <int> Arg1;
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "))()()()())())))))))))((((((((()()()()()()))(()()())";
			//             ))()()()())()))))))))) ((((((((()()()()()()))(()()())";
			int Arr1[] = { 0, 21, 11, 51 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "(()))()))(((((()()))((())(()))((((((((()))))((((((()))))))()(((()(((()(()())())(())())))((((((()))((())))))()(()((()((()))()(()(()(()()))))))(((())()())(())()(((()(((()()()()()())((()(((())((()()))((((()(()()(())))())))))())((()()((((())())(()()())(((()(((((((()()))()()((((())()(((()(()))(()((())))(())))(()))))()((()(()(()()())))))())))))())()))(((()((()()()(((((())))))))(((())((()(()()))((()))))())))))))(()))(()(()(()((()())((()())()())()())((((()((())))))(()((())(()()()))((()()(()))(()((((())()()()()())(()()()))(()())(((()()()))(((()))())()((())(())()(())()()))((((()))()(()))((()()(()(()()()((((())(()())))())))(((()(((((((())((()(((()((((((()(())(((()(())))()((()(((((((())()()()()()())))())))())()))((()()()()((()((()((()()()(()()))()((())(()))()()(((()))((()))((()()()(()()))(((())()((())()()(((())))(()()()())(((())))())((()(()(()))(((((()())))))()(()(()(()((())((()(()()))()()))()(()))(())()))(()(()(())()()()((()(()((())))))())(((()))()))))))()()((())(()())()(((((())(())(()()(()()(())";
			int Arr1[] = { 0, 8, 625, 999 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv1Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
