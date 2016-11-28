// BEGIN CUT HERE
/*
SRM 696 Div2 Medium (500)

PROBLEM STATEMENT
Hero has two arrays, A and B, each containing the same number of integers.
He wants to change A into an array that will resemble B as closely as possible.
More precisely, the difference between two arrays of equal length is the number of indices where the two arrays differ.
Hero wants to minimize the distance between the modified array A and the original array B.

Hero can only modify A by using stickers.
He has a collection of stickers.
Each sticker contains a single integer.
Each sticker can be used to cover a single element of A.
Hero must use each sticker exactly once, and he cannot use multiple stickers on the same element of A.

You are given the original arrays in the vector <int>s A and B, and the collection of stickers in the vector <int> F.
Return the smallest possible difference between A and B after all stickers from F have been used to replace some elements of A.


DEFINITION
Class:Arrfix
Method:mindiff
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int mindiff(vector <int> A, vector <int> B, vector <int> F)


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-A and B will contain the same number of elements.
-Size of F won't be larger than size of A.
-Each element in A, B and F will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,1}
{2,2,2}
{2}

Returns: 2


1)
{1,1,1}
{2,2,1}
{2,2}

Returns: 0


2)
{1,2,3}
{3,2,1}
{}

Returns: 2

Hero has no stickers. The given arrays A and B differ on two positions: on 0-based indices 0 and 2.


3)
{2,2,2}
{2,2,2}
{1,2,3}

Returns: 2

Note that Hero must use all the stickers. Originally the two arrays are the same, but applying all the stickers creates two differences, regardless of the order in which you use them.


4)
{1,3,3,3}
{2,3,3,3}
{2,2}

Returns: 1

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Arrfix {
public:
	int mindiff(vector <int> A, vector <int> B, vector <int> F) {
		int ua[64] = {}, uf[64] = {};
		for (int stage = 0; stage != 4; ++stage) {
			for (int i = 0; i != F.size(); ++i) {
				for (int j = 0; !uf[i] && j != A.size(); ++j) {
					if (!ua[j]) {
						switch (stage) {
						case 0:
							if (A[j] != F[i] && B[j] == F[i]) {
								ua[j] = 1, uf[i] = 1, A[j] = F[i];
							}
							break;
						case 1:
							if (A[j] == F[i] && B[j] == F[i]) {
								ua[j] = 1, uf[i] = 1, A[j] = F[i];
							}
							break;
						case 2:
							if (A[j] != B[j]) {
								ua[j] = 1, uf[i] = 1, A[j] = F[i];
							}
							break;
						case 3:
							ua[j] = 1, uf[i] = 1, A[j] = F[i];
							break;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i != A.size(); ++i) {
			ans += A[i] != B[i];
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
			int Arr0[] = {1,1,1};
			int Arr1[] = {2,2,2};
			int Arr2[] = {2};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arr1[] = {2,2,1};
			int Arr2[] = {2,2};
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {3,2,1};
			// int Arr2[] = {};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2;
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2};
			int Arr1[] = {2,2,2};
			int Arr2[] = {1,2,3};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,3,3};
			int Arr1[] = {2,3,3,3};
			int Arr2[] = {2,2};
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Arrfix ___test;
	___test.run_test(-1);
}
// END CUT HERE
