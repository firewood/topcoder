// BEGIN CUT HERE
/*
// SRM 560 Div2 Medium (500)

// PROBLEM STATEMENT
// 
Tomek thinks that smartphones are overrated.
He plans to release a new cellphone with an old-school keyboard, which may require you to tap a key multiple times to type a single letter.
For example, if the keyboard has two keys, one with the letters "adef" and the other one with the letters "zyx", then typing 'a' requires one keystroke, typing 'f' requires four keystrokes, typing 'y' requires two keystrokes, and so on.

Tomek has already designed the keyboard's layout.
That is, he already knows the number of keys on the keyboard, and for each key he knows the maximum number of letters it may hold.
He now wants to create a specific keyboard for a language that uses N different letters.
He has a large body of text in this language, and he already analyzed it to find the frequencies of all N letters of its alphabet.

You are given a vector <int> frequencies with N elements.
Each element of frequencies is the number of times one of the letters in Tomek's alphabet appears in the text he has.
Each element of frequencies will be strictly positive.
(I.e., each of the N letters occurs at least once in Tomek's text.)

You are also given a vector <int> keySize.
The number of elements of keySize is the number of keys on Tomek's keyboard.
Each element of keySize gives the maximal number of letters on one of the keys.

Find an assignment of letters to keys that minimizes the number of keystrokes needed to type Tomek's entire text.
Return that minimum number of keystrokes.
If there is not enough room on the keys and some letters of the alphabet won't fit, return -1 instead.


DEFINITION
Class:TomekPhone
Method:minKeystrokes
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minKeystrokes(vector <int> frequencies, vector <int> keySizes)


CONSTRAINTS
-frequencies will contain between 1 and 50 elements, inclusive.
-Each element of frequencies will be between 1 and 1,000, inclusive.
-keySizes will contain between 1 and 50 elements, inclusive.
-Each element of keySizes will be between 1 and 50, inclusive.


EXAMPLES

0)
{7,3,4,1}
{2,2}

Returns: 19

Tomek's language has four letters.
Let us call them A, B, C, and D.
Tomek's text contains seven As, three Bs, four Cs, and one D.
The keyboard has two keys, each of them may contain at most two letters.
One optimal solution is to use the keys "AD" and "CB".
We can then type each A and each C using a single keystroke, and we need two keystrokes for each B and each D.
Therefore, the total number of keystrokes when typing the entire text will be 7*1 + 3*2 + 4*1 + 1*2 = 19.


1)
{13,7,4,20}
{2,1}

Returns: -1

There is not enough space on the keys to fit all four letters.


2)
{11,23,4,50,1000,7,18}
{3,1,4}

Returns: 1164


3)
{100,1000,1,10}
{50}

Returns: 1234


4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}
{10,10,10,10,10,10,10,10}

Returns: 3353

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TomekPhone {

public:
	int minKeystrokes(vector <int> frequencies, vector <int> keySizes) {
		int res = 0;
		int sz = (int)frequencies.size();
		sort(frequencies.rbegin(), frequencies.rend());
		int i = 0, j, k;
		for (j = 1; j <= 50; ++j) {
			for (k = 0; k < (int)keySizes.size(); ++k) {
				if (keySizes[k] >= j) {
					res += j * frequencies[i];
					if (++i >= sz) {
						return res;
					}
				}
			}
		}
		return -1;
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
			int Arr0[] = {7,3,4,1};
			int Arr1[] = {2,2};
			int Arg2 = 19;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13,7,4,20};
			int Arr1[] = {2,1};
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11,23,4,50,1000,7,18};
			int Arr1[] = {3,1,4};
			int Arg2 = 1164;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,1000,1,10};
			int Arr1[] = {50};
			int Arg2 = 1234;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			int Arr1[] = {10,10,10,10,10,10,10,10};
			int Arg2 = 3353;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TomekPhone ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
