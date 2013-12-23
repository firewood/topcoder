// BEGIN CUT HERE
/*
SRM 592 Div2 Medium (500)

問題
-1からNまでのN個の数列AとBがある
-それぞれの要素を並べ替えて、max(Ai,Bi)の和を求める
-和がK以上になるのは何通りか求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class LittleElephantAndPermutationDiv2 {
public:
	long long getNumber(int N, int K) {
		LL ans = 0;
		int b[10] = {1,2,3,4,5,6,7,8,9,10};
		int i;
		LL k = 1;
		for (i = 1; i <= N; ++i) {
			k *= i;
		}
		do {
			int sum = 0;
			for (i = 0; i < N; ++i) {
				sum += max(i+1, b[i]);
			}
			if (sum >= K) {
				ans += k;
			}
		} while(next_permutation(b, b + N));
		return ans;
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
			int Arg0 = 1;
			int Arg1 = 1;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			long long Arg2 = 4LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 8;
			long long Arg2 = 18LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 47;
			long long Arg2 = 13168189440000LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndPermutationDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
