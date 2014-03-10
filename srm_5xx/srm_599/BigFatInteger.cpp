// BEGIN CUT HERE
/*
SRM 599 Div1 Easy (250)

問題
-LunはAのB乗のような巨大な数が大好きである
-Xの初期値を1とする
-Xには素数か、または、Xの約数をかけることができる
-AのB乗にするための最小の手数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class BigFatInteger {
public:
	int minOperations(int A, int B) {
		LL mul = 0;
		int primes = 0;
		for (int n = 2; n < 1000; ++n) {
			if ((A % n) == 0) {
				++primes;
				LL c = 0;
				while ((A % n) == 0) {
					++c;
					A /= n;
				}
				mul = max(mul, c);
			}
		}
		if (A > 1) {
			++primes;
			mul = max(mul, 1LL);
		}
		mul *= B;
		int ans = primes;
		LL n = 1;
		while (mul > n) {
			n *= 2;
			++ans;
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
			int Arg0 = 6;
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 162;
			int Arg1 = 1;
			int Arg2 = 4;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 999983;
			int Arg1 = 9;
			int Arg2 = 5;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 360;
			int Arg1 = 8;
			int Arg2 = 8;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 36;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 216;
			int Arg1 = 5;
			int Arg2 = 6;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 5;
			int Arg2 = 5;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BigFatInteger ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
