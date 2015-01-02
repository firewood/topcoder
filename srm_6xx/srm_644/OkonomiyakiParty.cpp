// BEGIN CUT HERE
/*
SRM 644 Div1 Easy (250)

PROBLEM STATEMENT
Wolf Sothe is planning a party for his M friends.
He wants to give them some okonomiyaki at the party.
(Okonomiyaki is a Japanese pancake.)

Sothe just came to an okonomiyaki restaurant.
The restaurant makes several types of okonomiyaki.
Each type of okonomiyaki has its specific size.
You are given the sizes of all okonomiyaki types as a vector <int> osize.

Sothe would like to buy exactly M okonomiyaki.
They must all have different types, so that the people at the party have the most options to choose from.
Additionally, they must all have roughly the same sizes, so that nobody feels disappointed.
More precisely, the difference between the size of the largest and smallest okonomiyaki ordered by Sothe must be K or less.

You are given the vector <int> osize and the ints M and K.
Compute and return the number of different orders Sothe could place at the restaurant, modulo 1,000,000,007.

DEFINITION
Class:OkonomiyakiParty
Method:count
Parameters:vector <int>, int, int
Returns:int
Method signature:int count(vector <int> osize, int M, int K)


CONSTRAINTS
-osize will contain between 2 and 50 elements, inclusive.
-Each element in osize will be between 1 and 10,000, inclusive.
-M will be between 2 and the number of elements in osize, inclusive.
-K will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,4,6,7,9}
2
3

Returns: 6

There are five types of okonomiyaki.
Let's call them types A, B, C, D, and E.
(Type A has size 1, type B has size 4, and so on.)
Sothe wants to buy M=2 different okonomiyaki and their sizes must differ by K=3 or less.
There are 6 valid orders: A+B, B+C, B+D, C+D, C+E, and D+E.

Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.


1)
{1,6,2,7,4,2,6,1,5,2,4}
4
3

Returns: 60

Different types of okonomiyaki may have equal sizes.
An order may contain multiple okonomiyaki of the same size, they are only required to have different types.


2)
{1,4,5,7,10,11,13,16,18}
4
5

Returns: 0

In this test case there is no valid order: regardless of which 4 pancakes Sothe wants, the difference between their sizes will be too large.


3)
{55,2,7,232,52,5,5332,623,52,6,532,5147}
6
10000

Returns: 924


4)
{5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
5682,7775,4356,5140,8923,9801,3729}
15
4003

Returns: 114514

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

#define COMBSZ 64
#define MOD 1000000007LL

class OkonomiyakiParty {
public:
	int count(vector <int> osize, int M, int K) {
		LL ans = 0, i, j;
		LL C[COMBSZ][COMBSZ] = {1};		// should be static for larger size
		for (i = 1; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (j = 1; j <= i; ++j) {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			}
		}
		sort(osize.begin(), osize.end());
		LL N = osize.size();
		for (i = 0; i < N; ++i) {
			// osize[j] is greater than osize[i] + K
			j = upper_bound(osize.begin() + i + 1, osize.end(), osize[i] + K) - osize.begin();
			ans = (ans + C[j - i - 1][M - 1]) % MOD;
		}
		return (int)(ans % MOD);
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
			int Arr0[] = {1,4,6,7,9};
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,6,2,7,4,2,6,1,5,2,4};
			int Arg1 = 4;
			int Arg2 = 3;
			int Arg3 = 60;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,4,5,7,10,11,13,16,18};
			int Arg1 = 4;
			int Arg2 = 5;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {55,2,7,232,52,5,5332,623,52,6,532,5147};
			int Arg1 = 6;
			int Arg2 = 10000;
			int Arg3 = 924;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
5682,7775,4356,5140,8923,9801,3729};
			int Arg1 = 15;
			int Arg2 = 4003;
			int Arg3 = 114514;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OkonomiyakiParty ___test;
	___test.run_test(-1);





	LL i, j;

	LL C[COMBSZ][COMBSZ] = {};
	for (i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
	}
	for (i = 1; i < COMBSZ; ++i) {
		for (j = 1; j < COMBSZ; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}


	LL X[COMBSZ][COMBSZ] = {1};
	for (i = 1; i < COMBSZ; ++i) {
		X[i][0] = 1;
		for (j = 1; j <= i; ++j) {
			X[i][j] = (X[i - 1][j - 1] + X[i - 1][j]) % MOD;
		}
	}


	for (i = 0; i < COMBSZ; ++i) {
		for (j = 0; j < COMBSZ; ++j) {
			if (C[i][j] != X[i][j]) {
				cout << i << "," << j << endl;
				break;
			}
		}
	}














}
// END CUT HERE
