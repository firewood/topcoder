// BEGIN CUT HERE
/*
SRM 596 Div1 Easy (250)

問題
-要素数がNの配列が与えられる
-どれかの要素を+1するか、全ての要素を2倍にすることができる
-初期値を0として、その配列と同じにするまでの最小の手数を求める

*/
// END CUT HERE
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class IncrementAndDoubling {
public:
	int getMin(vector <int> desiredArray) {
		int ans = 1000000000;
		int c = 0;
		while (true) {
			int sum = accumulate(desiredArray.begin(), desiredArray.end(), 0);
			ans = min(ans, c + sum);
			if (sum <= 0) {
				break;
			}
			for (int i = 0; i < (int)desiredArray.size(); ++i) {
				c += desiredArray[i] % 2;
				desiredArray[i] /= 2;
			}
			++c;
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
			int Arr0[] = {2, 1};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {16, 16, 16};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 1, 0, 1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 234, 345, 456, 567, 789};
			int Arg1 = 40;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7};
			int Arg1 = 84;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncrementAndDoubling ___test;
	___test.run_test(-1);
}
// END CUT HERE
