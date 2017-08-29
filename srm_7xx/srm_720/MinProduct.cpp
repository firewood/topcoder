// BEGIN CUT HERE
/*
SRM 720 Div2 Medium (500)

問題
-0から9まで、各桁に使える数値の個数が与えられる
-総数がその個数を超えないように、blank1桁の数Aとblank2桁の数Bを作る
-A×Bの最小値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class MinProduct {
public:
	long long findMin(vector <int> amount, int blank1, int blank2) {
		if (blank1 > blank2) {
			swap(blank1, blank2);
		}
		LL a = 0, b = 0, d = 0;
		while (blank1 && amount[d]) {
			--amount[d];
			--blank1;
		}
		while (blank1 || blank2) {
			if (blank1) {
				while (!amount[d]) {
					++d;
				}
				a = a * 10 + d;
				amount[d]--;
				--blank1;
			}
			if (blank2) {
				while (!amount[d]) {
					++d;
				}
				b = b * 10 + d;
				amount[d]--;
				--blank2;
			}
		}
		return a * b;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,1,2,1,1,0,0,0,0};
			int Arg1 = 2;
			int Arg2 = 3;
			long long Arg3 = 3042LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
			int Arg1 = 1;
			int Arg2 = 8;
			long long Arg3 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,0,0,0,0,0,0,0,0};
			int Arg1 = 2;
			int Arg2 = 2;
			long long Arg3 = 11LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,20,20,20,20,20,20,20,20,20};
			int Arg1 = 9;
			int Arg2 = 9;
			long long Arg3 = 12345678987654321LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,0,0,1,0,0,5,3,2};
			int Arg1 = 9;
			int Arg2 = 3;
			long long Arg3 = 36556078253LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,0,0,0,18};
			int Arg1 = 9;
			int Arg2 = 8;
			long long Arg3 = 99999998900000001LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinProduct ___test;
	___test.run_test(-1);
}
// END CUT HERE
