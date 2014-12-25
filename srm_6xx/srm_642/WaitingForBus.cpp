// BEGIN CUT HERE
/*
SRM 642 Div1 Easy (250)

問題
-N台のバスがある
-ランダムでどれかのバスが出発する
-戻ってきたら次のバスがランダムで選ばれる
-バスが選ばれる確率と、戻ってくるまでの時間の配列が与えられる
-時刻sでの平均待ち時間を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WaitingForBus {
public:
	double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
		long double a[200002] = {}; 
		a[0] = 1.0; 
		int N = (int)time.size(); 
		for (int t = 0; t < s; ++t) {
			if (a[t] > 0) {
				for (int i = 0; i < N; ++i) { 
					long double p = prob[i] * a[t]; 
					a[t + time[i]] += p * 0.01;
				}
			}
		}
		long double ans = 0;
		for (int t = 1; t <= 100000; ++t) {
			ans += a[s + t] * (long double)t;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) <= 1.0e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,100};
			int Arr1[] = {90,10};
			int Arg2 = 5;
			double Arg3 = 9.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arr1[] = {100};
			int Arg2 = 101;
			double Arg3 = 4.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,10};
			int Arr1[] = {50,50};
			int Arg2 = 88888;
			double Arg3 = 3.666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {10,20,30,40};
			int Arg2 = 1000;
			double Arg3 = 1.166666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,100,1000,10000,100000};
			int Arr1[] = {90,4,3,2,1};
			int Arg2 = 100000;
			double Arg3 = 21148.147303578935;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WaitingForBus ___test;
	___test.run_test(-1);
}
// END CUT HERE
