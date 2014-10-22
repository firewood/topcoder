// BEGIN CUT HERE
/*
SRM 625 Div2 Medium (500)

問題
-N個の数値からなる配列が与えられる
-任意の要素をkずつ増加させることができる
-1からNまで一個ずつ存在するように変更できるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class IncrementingSequence {
public:
	string canItBeDone(int k, vector <int> A) {
		int cnt[64] = {};
		for (int i = 0; i < (int)A.size(); ++i) {
			cnt[A[i]] += 1;
		}
		for (int i = (int)A.size(); i > 0; --i) {
			int j;
			for (j = i; j > 0; j -= k) {
				if (cnt[j] > 0) {
					break;
				}
			}
			if (j <= 0) {
				return "IMPOSSIBLE";
			}
			cnt[j] -= 1;
		}
		return "POSSIBLE";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,2,4,3};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {2,2};
			string Arg2 = "IMPOSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1,1,1,1,1,1,1,1};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {5,3,3,2,1};
			string Arg2 = "IMPOSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arr1[] = {1,2,3,1,4,5,6,7,9,8};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,1,1,1,1,1,2,2,2,2,2,2};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncrementingSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
