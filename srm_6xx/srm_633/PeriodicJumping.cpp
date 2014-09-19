// BEGIN CUT HERE
/*
SRM 633 Div1 Easy (250)

問題
-二次元平面上に蛙がいる
-ジャンプできる距離の配列が与えられる
-{2,5}が与えられたときは距離2,距離5,距離2,...のようにジャンプできる
-ジャンプする方向はx軸またはy軸に平行でなくてよい
-(x,0)に到達するために必要なジャンプの回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class PeriodicJumping {
public:
	int minimalTime(int x, vector <int> jumpLengths) {
		int ans = 0;
		LL X = abs(x);
		LL N = jumpLengths.size();

		LL sum = 0;
		for (int a : jumpLengths) {
			sum += a;
		}

		if (X >= sum * 2) {
			LL loops = X / sum;
			ans += (int)(loops * N);
			sum *= loops;
			for (LL i = 0; ; ++i) {
				if (sum >= X) {
					return ans;
				}
				++ans;
				sum += jumpLengths[i % N];
			}
		}

		sum = 0;
		LL m = 0;
		for (LL i = 0; ; ++i) {
			if (sum >= X && m <= (X + sum - m)) {
				break;
			}
			++ans;
			LL j = jumpLengths[i % N];
			sum += j;
			m = max(m, j);
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
			int Arg0 = 15;
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {5};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {10};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = -10;
			int Arr1[] = {2,3,4,500,6,7,8};
			int Arg2 = 11;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = -1000000000;
			int Arr1[] = {1};
			int Arg2 = 1000000000;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arr1[] = {19911120};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = { 1,10 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = { 1, 3 };
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = { 1, 5, 2 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 1, 8, 2, 2 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 1, 8, 2, 1 };
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 8, 2, 2, 1 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 4, 8 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 4, 8, 1 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 8, 16, 32 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = { 8, 16, 24 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 290;
			int Arr1[] = { 1,100 };
			int Arg2 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = { 1, 536870912, 536870912, 536870912, 536870912, 536870912, 536870912, 536870912, 536870912 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PeriodicJumping ___test;
	___test.run_test(-1);
}
// END CUT HERE
