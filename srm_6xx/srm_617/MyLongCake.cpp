// BEGIN CUT HERE
/*
SRM 617 Div1 Easy (250)

問題
-長さNのケーキがある
-何人かの友達が来るので、到着前にケーキを切っておく
-友達の数はN未満かつNの約数であり、何人到着するかは不明である
-友人の到着後、切っておいたケーキの連続するピースを渡す
-ただし各友人には同じ量だけ渡す
-分割数の最小値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MyLongCake {
public:
	int cut(int n) {
		int ans = 0;
		int x = n;
		for (int p = 2; x > 1 && p <= 100000; ++p) {
			if ((x % p) == 0) {
				while ((x % p) == 0) {
					x /= p;
				}
				ans += n / p;
				n -= n / p;
			}
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
			int Arg1 = 4;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 7;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 60000;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 3;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 4;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 27;
			int Arg1 = 9;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 9973;
			int Arg1 = 1;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 8;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MyLongCake ___test;
	___test.run_test(-1);
}
// END CUT HERE
