// BEGIN CUT HERE
/*
SRM 594 Div1 Easy (250)

PROBLEM STATEMENT
Fox Ciel found two astronomical records.
They both describe the same solar system.
Each planet in the system can be characterized by two parameters each being a positive number: planet's size and the distance at which it orbits the sun.
All orbital distances are pairwise distinct, but sizes of some planets may be the same.

The first record is a vector <int> A with x elements.
These elements give the relative sizes of some x planets in the solar system.
Formally, the sizes of those planets have the ratio A[0] : A[1] : ... : A[x-1].
The planets described by A are ordered by their distance from the sun.
(That is, earlier elements of A correspond to planets that are closer to the sun.)

The second record is a vector <int> B with y elements.
These elements give the relative sizes of some y planets in the solar system.
Formally, the sizes of those planets have the ratio B[0] : B[1] : ... : B[y-1].
The planets described by B are ordered by their distance from the sun.

Note that the planets considered by a record do not have to be consecutive.
For example, if a solar system contains the planets P, Q, R, S, T, and U, it is possible that the first record compares P, R, and S, and the second record compares Q, R, T, and U.

We assume that both records are correct.
Return the smallest possible total number of planets in the solar system.


DEFINITION
Class:AstronomicalRecords
Method:minimalPlanets
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimalPlanets(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-B will contain between 2 and 50 elements, inclusive.
-Each element in A will be between 1 and 1,000,000,000, inclusive.
-Each element in B will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,1,2,1}
{2,1,2,1,2}

Returns: 6

There have to be at least 5 planets, because each record compares 5 of them.
There cannot be exactly 5 planets, because the first one would have to be both smaller than and larger than the second one.
(Their ratio would have to be both 1:2 and 2:1, which is impossible.)
There can be exactly 6 planets with relative sizes 1,2,1,2,1,2.


1)
{1,2,3,4}
{2,4,6,8}

Returns: 4

There can be only 4 planets because 1:2:3:4 = 2:4:6:8.


2)
{2,3,2,3,2,3,2}
{600,700,600,700,600,700,600}

Returns: 10


3)
{1,2,3,4,5,6,7,8,9}
{6,7,8,9,10,11,12}

Returns: 12


4)
{100000000,200000000}
{200000000,100000000}

Returns: 3

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class AstronomicalRecords {

	int lcs(LLVec A, LLVec B) {
		int dp[52][52] = {};
		for (int i = 0; i < (int)A.size(); ++i) {
			for (int j = 0; j < (int)B.size(); ++j) {
				if (A[i] == B[j]) {
					dp[i+1][j+1] = 1 + dp[i][j];
				} else {
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}
		return dp[A.size()][B.size()];
	}

public:
	int minimalPlanets(vector <int> A, vector <int> B) {
		int ans = (int)(A.size() + B.size());
		for (int i = 0; i < (int)A.size(); ++i) {
			for (int j = 0; j < (int)B.size(); ++j) {
				LL p = A[i], q = B[j];
				LLVec a, b;
				for (int k = 0; k < (int)A.size(); ++k) {
					a.push_back(A[k] * q);
				}
				for (int k = 0; k < (int)B.size(); ++k) {
					b.push_back(B[k] * p);
				}
				ans = min(ans, (int)(A.size() + B.size() - lcs(a, b)));
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
			int Arr0[] = {1,2,1,2,1};
			int Arr1[] = {2,1,2,1,2};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {2,4,6,8};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,2,3,2,3,2};
			int Arr1[] = {600,700,600,700,600,700,600};
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9};
			int Arr1[] = {6,7,8,9,10,11,12};
			int Arg2 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100000000,200000000};
			int Arr1[] = {200000000,100000000};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {524288, 262144, 32768, 128, 8388608, 32, 128, 4, 8192, 16777216, 8192, 4, 256, 262144, 2097152, 2097152, 2097152, 16777216, 1, 8, 1024, 4096, 2097152, 4, 268435456, 65536, 2, 8, 33554432, 2, 67108864, 4, 268435456, 128, 16384, 1024, 16, 4, 134217728, 536870912, 131072, 64, 268435456, 8, 8192, 64, 128, 8, 33554432, 8192};
			int Arr1[] = {131072, 16384, 1, 512, 2097152, 67108864, 64, 16, 131072, 16, 256, 128, 32, 4096, 4194304, 1024, 134217728, 1, 1, 134217728, 512, 64, 65536, 131072, 16384, 8192, 4, 268435456, 256, 1024, 8, 32768, 16777216, 512, 32768, 512, 64, 8192, 512, 524288, 65536, 512, 1048576, 1024, 512, 262144, 131072, 65536, 33554432, 64};
			int Arg2 = 83;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AstronomicalRecords ___test;
	___test.run_test(-1);
}
// END CUT HERE
