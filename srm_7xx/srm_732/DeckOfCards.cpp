// BEGIN CUT HERE
/*
SRM 732 Div2 Easy (250)

PROBLEM STATEMENT

You found a deck of slightly non-traditional playing cards.
Each card has a value and a suit.
The value of each card is a positive integer, and the suit is a lowercase English letter ('a'-'z').
We will use (v, s) to denote a card with value v and suit s.

You want to know whether the deck is perfect.
A perfect deck has two properties:

All cards in the deck are distinct. (I.e., no two cards share both value and suit.)
For any two cards (v1, s1) and (v2, s2) in the deck, the deck also contains the cards (v1, s2) and (v2, s1).

You are given the following data:

an int n: the number of cards in the deck
a vector <int> value with n elements: the values of the cards in the deck
a string suit  with n elements: the suits of the cards in the deck

More precisely, for each valid i, (value[i], suit[i]) is one of the cards in the deck.

Return "Perfect" if the deck is perfect and "Not perfect" otherwise.
Note that the quotes are only for clarity and that the return value is case-sensitive.


DEFINITION
Class:DeckOfCards
Method:IsValid
Parameters:int, vector <int>, string
Returns:string
Method signature:string IsValid(int n, vector <int> value, string suit)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-value will contain exactly n elements.
-Each element of value will be between 1 and 1,000,000,000, inclusive.
-suit will be of length n exactly.
-Suit will only contain lower-case alphabets ('a'-'z').


EXAMPLES

0)
1
{10}
"z"

Returns: "Perfect"

There is only one card in the deck: (10, 'z').
The deck is obviously perfect.


1)
3
{1,2,3}
"hhh"

Returns: "Perfect"


2)
4
{2,3,2,3}
"hcch"

Returns: "Perfect"


3)
3
{1,1,1}
"hch"

Returns: "Not perfect"

This deck is not perfect because it contains two copies of the card (1, 'h').


4)
4
{1,2,3,4}
"hhcc"

Returns: "Not perfect"

This deck is not perfect. For example, the presence of cards (1, 'h') and (3, 'c') implies that the cards (3, 'h') and (1, 'c') should also be in the deck, but both of them are missing.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
#define MOD 1000000007LL
#define MOD 1000000009LL
*/
// END CUT HERE

class DeckOfCards {

	bool check(int n, vector <int> value, string suit) {
		if (n == 1) {
			return true;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (value[i] == value[j] && suit[i] == suit[j]) {
					return false;
				}
				if (value[i] != value[j] && suit[i] != suit[j]) {
					bool a = false, b = false;
					for (int k = 0; k < n; ++k) {
						if (k != i && k != j) {
							if (value[i] == value[k] && suit[j] == suit[k]) {
								a = true;
							}
							if (value[j] == value[k] && suit[i] == suit[k]) {
								b = true;
							}
						}
					}
					if (!a || !b) {
						return false;
					}
				}
			}
		}
		return true;
	}

public:
	string IsValid(int n, vector <int> value, string suit) {
		return check(n, value, suit) ? "Perfect" : "Not perfect";
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
			int Arg0 = 1;
			int Arr1[] = {10};
			string Arg2 = "z";
			string Arg3 = "Perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,2,3};
			string Arg2 = "hhh";
			string Arg3 = "Perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {2,3,2,3};
			string Arg2 = "hcch";
			string Arg3 = "Perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,1,1};
			string Arg2 = "hch";
			string Arg3 = "Not perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,2,3,4};
			string Arg2 = "hhcc";
			string Arg3 = "Not perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DeckOfCards ___test;
	___test.run_test(-1);
}
// END CUT HERE
