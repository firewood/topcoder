// BEGIN CUT HERE
/*
SRM 737 Div1 Easy (300)

問題
-二人でNIMゲームを行う
-いくつかの石からなるいくつかの山がある
-プレイヤーは一つの山を選び、一つ以上の石を取る
-最後の石を取ったプレイヤーが勝つ
-先手が勝利し、かつ、最適な手数が最大となるようにN個の山を構成せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AliceAndBobEasy {
public:
	vector <int> make(int N) {
		vector <int> ans(N, 1 << 20);
		if (N % 2 == 0) {
			ans[0] = 0;
		}
		for (int i = 0; i < N; ++i) {
			ans[i] += i + 1;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {737 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, make(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {737, 373 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, make(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {3337, 3373, 3733 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, make(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceAndBobEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
