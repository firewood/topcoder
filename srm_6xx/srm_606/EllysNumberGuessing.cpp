// BEGIN CUT HERE
/*
SRM 606 Div1 Easy (250)

PROBLEM STATEMENT
Elly and Kris play the following game. In the beginning Kristina thinks of a number between 1 and 1,000,000,000, inclusive. After that Elly starts trying to guess it. In each round she says a number and Kristina says what is the absolute difference between the number she has thought of, and the number Elly guessed. Now Elly wonders if the guesses she has already made are sufficient to uniquely determine Kristina's number.

You are given a vector <int> guesses and a vector <int> answers of the same length. For each valid i, in round i of the game (0-based index) Elly guessed the number guesses[i] and Kristina answered answers[i]. If Kristina's number can be uniquely determined, return that number. If there are multiple possibilities that are consistent with the current set of guesses and answers, return -1. If it can be shown that at some point Kristina has lied (some of her answers were inconsistent), return -2.

DEFINITION
Class:EllysNumberGuessing
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getNumber(vector <int> guesses, vector <int> answers)


CONSTRAINTS
-guesses and answers will each contain between 1 and 50 elements, inclusive.
-guesses and answers will contain the same number of elements.
-Each element of guesses will be between 1 and 1,000,000,000, inclusive.
-Each element of answers will be between 1 and 999,999,999, inclusive.


EXAMPLES

0)
{600, 594}
{6, 12}

Returns: 606

Apparently Kristina has thought of the number of this SRM.


1)
{100, 50, 34, 40}
{58, 8, 8, 2}

Returns: 42

It is not guaranteed that Elly has used a perfect strategy so far.


2)
{500000, 600000, 700000}
{120013, 220013, 79987}

Returns: -2

The answers here are inconsistent. After the second guess we can conclude that the answer is below 500000. But the third one indicates that it is above 500000. Thus, Kristina is a liar and you should return -2.


3)
{500000000}
{133742666}

Returns: -1

There are multiple possibilities here, thus you should return -1.


4)
{76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879}
{466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466}

Returns: 543212345


5)
{42}
{42}

Returns: 84

Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.


6)
{999900000}
{100001}

Returns: 999799999

Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysNumberGuessing {
public:
	int getNumber(vector <int> guesses, vector <int> answers) {
		int a = -1, b = -1, ac = 0, bc = 0;
		int N = (int)guesses.size();
		for (int i = 0; i < N; ++i) {
			for (int j = -1; j <= 1; j += 2) {
				int n = guesses[i] + answers[i] * j;
				if (n >= 1 && n <= 1000000000) {
					if (a < 0) {
						a = n;
					} else if (b < 0 && a != n) {
						b = n;
					}
					if (n == a) {
						++ac;
					}
					if (n == b) {
						++bc;
					}
				}
			}
		}
		if (ac >= N) {
			if (bc >= N) {
				return -1;
			}
			return a;
		}
		if (bc >= N) {
			return b;
		}
		return -2;
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
			int Arr0[] = {600, 594};
			int Arr1[] = {6, 12};
			int Arg2 = 606;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 50, 34, 40};
			int Arr1[] = {58, 8, 8, 2};
			int Arg2 = 42;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {500000, 600000, 700000};
			int Arr1[] = {120013, 220013, 79987};
			int Arg2 = -2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {500000000};
			int Arr1[] = {133742666};
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879};
			int Arr1[] = {466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466};
			int Arg2 = 543212345;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42};
			int Arr1[] = {42};
			int Arg2 = 84;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {999900000};
			int Arr1[] = {100001};
			int Arg2 = 999799999;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysNumberGuessing ___test;
	___test.run_test(-1);
}
// END CUT HERE
