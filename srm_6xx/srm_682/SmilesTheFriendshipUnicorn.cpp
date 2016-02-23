// BEGIN CUT HERE
/*
SRM 682 Div1 Easy (300)

PROBLEM STATEMENT
Smiles the Friendship Unicorn lives in the Friendship Kingdom. There are N people in the Friendship Kingdom, numbered from 0 to N-1. Some of them are friends with each other: you are given these pairs in the vector <int> A and the vector <int> B. For each valid i, the person numbered A[i] is friends with the person numbered B[i]. Friendship is two-way, so the person numbered B[i] is also friends with the person numbered A[i]. For every group containing between 1 and N-1 people (inclusive), at least one person in the group is friends with someone outside the group.

Smiles would like to know whether there exists a friendship chain. A friendship chain is a sequence of 5 distinct people A, B, C, D, and E such that:

A is friends with B.
B is friends with C.
C is friends with D.
D is friends with E.

(In the language of graph theory: a friendship chain is a simple path of length 4.)

If a friendship chain exists, output "Yay!". Otherwise, output ":(". (All quotes are for clarity only.)

DEFINITION
Class:SmilesTheFriendshipUnicorn
Method:hasFriendshipChain
Parameters:int, vector <int>, vector <int>
Returns:string
Method signature:string hasFriendshipChain(int N, vector <int> A, vector <int> B)


CONSTRAINTS
-N will be between 5 and 2000, inclusive.
-A will contain between 1 and 2000 elements, inclusive.
-A and B will contain the same number of elements.
-Each element of A and B will be between 0 and N-1, inclusive.
-No one will be friends with themselves.
-The same friendship will not be given twice in the input.
-For every group containing between 1 and N-1 people (inclusive), at least one person in the group is friends with someone outside the group.


EXAMPLES

0)
5
{0, 1, 2, 3}
{1, 2, 3, 4}

Returns: "Yay!"

A friendship chain is formed by:

Person 0
Person 1
Person 2
Person 3
Person 4

in that order. (The reverse order 4-3-2-1-0 is also a valid friendship chain.)


1)
5
{0, 1, 2, 3, 1}
{1, 2, 3, 0, 4}

Returns: "Yay!"

One example of a valid friendship chain is:

Person 4
Person 1
Person 2
Person 3
Person 0


2)
6
{0, 0, 0, 0, 0}
{1, 2, 3, 4, 5}

Returns: ":("


3)
8
{1, 3, 4, 3, 4, 3, 0, 2}
{7, 7, 7, 4, 6, 5, 4, 7}

Returns: "Yay!"


4)
7
{0, 1, 1, 5, 4, 5}
{5, 2, 3, 6, 1, 1}

Returns: ":("


5)
42
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}

{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0}

Returns: "Yay!"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class SmilesTheFriendshipUnicorn {

	bool check(int N, IntVec &A, IntVec &B) {
		IntVec edge[2000];
		for (int i = 0; i != A.size(); ++i) {
			edge[A[i]].push_back(B[i]);
			edge[B[i]].push_back(A[i]);
		}
		for (int a = 0; a < N; ++a) {
			const IntVec &p = edge[a];
			for (int j = 0; j != p.size(); ++j) {
				int b = p[j];
				for (int k = j + 1; k != p.size(); ++k) {
					int c = p[k];
					for (int d : edge[b]) {
						if (a == d || c == d) {
							continue;
						}
						for (int e : edge[c]) {
							if (a != e && b != e && d != e) {
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}

public:
	string hasFriendshipChain(int N, vector <int> A, vector <int> B) {
		return check(N, A, B) ? "Yay!" : ":(";
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
			int Arg0 = 5;
			int Arr1[] = {0, 1, 2, 3};
			int Arr2[] = {1, 2, 3, 4};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {0, 1, 2, 3, 1};
			int Arr2[] = {1, 2, 3, 0, 4};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0, 0, 0, 0, 0};
			int Arr2[] = {1, 2, 3, 4, 5};
			string Arg3 = ":(";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arr1[] = {1, 3, 4, 3, 4, 3, 0, 2};
			int Arr2[] = {7, 7, 7, 4, 6, 5, 4, 7};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = {0, 1, 1, 5, 4, 5};
			int Arr2[] = {5, 2, 3, 6, 1, 1};
			string Arg3 = ":(";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 42;
			int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}
;
			int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SmilesTheFriendshipUnicorn ___test;
	___test.run_test(-1);
}
// END CUT HERE
