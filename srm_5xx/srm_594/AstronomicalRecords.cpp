// BEGIN CUT HERE
/*
SRM 594 Div1 Easy (250)

問題
-惑星系に関する記録がAとBの二つある
-各要素は太陽からの距離順に並んでおり、数値が相対的な大きさを表す
-AとBは同じ惑星系の記録だが、倍率は異なる可能性がある
-全ての惑星が記録されているとは限らない
-少なくともいくつの惑星があるか求める

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
