// BEGIN CUT HERE
/*
SRM 699 Div2 Easy (250)

問題
-山でN日を過ごそうとしている
-1日目に高度0から歩き始める
-N日目には高度0に戻ってくる必要がある
-ある一日において、上りまたは下りのどちらかかが可能である
-一日で登れる高さの最大値はAである
-一日で下れる高さの最大値はBである
-登れる最大の高さを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class UpDownHiking {
public:
	int maxHeight(int N, int A, int B) {
		int ans = 0;
		for (int i = 1; i < N; ++i) {
			ans = max(ans, min(A * i, B * (N - i)));
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
			int Arg0 = 3;
			int Arg1 = 7;
			int Arg2 = 10;
			int Arg3 = 10;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 40;
			int Arg2 = 30;
			int Arg3 = 80;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 50;
			int Arg2 = 1;
			int Arg3 = 1;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 42;
			int Arg2 = 42;
			int Arg3 = 42;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 7;
			int Arg2 = 9;
			int Arg3 = 77;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UpDownHiking ___test;
	___test.run_test(-1);
}
// END CUT HERE
