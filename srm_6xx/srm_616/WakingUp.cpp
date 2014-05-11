// BEGIN CUT HERE
/*
SRM 616 Div1 Easy (250)

問題
-Alexの眠さをSとする
-毎分眠さはD増加する
-N個のアラームがあり、開始時刻、間隔、ボリュームが与えられる
-アラームが鳴ると眠さがボリュームのぶんだけ減る
-眠さが0以下になると起きる
-初期値Sのうち、起きることができる最大値を求める
-任意のSで起きることができるなら-1

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

class WakingUp {
public:
	int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
		int m = 1;
		for (int i = 1; i <= 10; ++i) {
			m = lcm(m, i);
		}
		int low = 0;
		int c = 0;
		int t;
		for (t = 1; t <= m; ++t) {
			c += D;
			for (int i = 0; i < (int)period.size(); ++i) {
				if (t >= start[i] && ((t - start[i]) % period[i]) == 0) {
					c -= volume[i];
				}
			}
			low = min(low, c);
		}
		int low2 = 0;
		for (; t <= 2*m; ++t) {
			c += D;
			for (int i = 0; i < (int)period.size(); ++i) {
				if (t >= start[i] && ((t - start[i]) % period[i]) == 0) {
					c -= volume[i];
				}
			}
			low2 = min(low2, c);
		}
		if (low2 < low) {
			return -1;
		}
		return -low;
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
			int Arr0[] = {2, 3};
			int Arr1[] = {1, 2};
			int Arr2[] = {3, 4};
			int Arg3 = 3;
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arr2[] = {17};
			int Arg3 = 17;
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arr2[] = {23};
			int Arg3 = 17;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9, 2, 5, 5, 7};
			int Arr1[] = {6, 1, 4, 1, 6};
			int Arr2[] = {71, 66, 7, 34, 6};
			int Arg3 = 50;
			int Arg4 = 78;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 6, 5, 3, 8, 3, 4};
			int Arr1[] = {1, 1, 3, 2, 6, 3, 3};
			int Arr2[] = {42, 85, 10, 86, 21, 78, 38};
			int Arg3 = 88;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int Arr1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int Arr2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int Arg3 = 100;
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WakingUp ___test;
	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
