// BEGIN CUT HERE
/*
TCO 2013 Round 2B Easy (250)

問題
-一直線な道路に3種類の木を植える
-種類ごとに植える間隔が指定される
-異なる種類の間隔が大きくなるように植えていく
-間隔の最大値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class FruitTrees {
public:
	int maxDist(int apple, int kiwi, int grape) {
		int a = gcd(apple, kiwi);
		int b = gcd(kiwi, grape);
		int c = gcd(grape, apple);
		int ans = min(a, min(b, c)) / 2;
		if (a == b && b == c) {
			ans = a / 3;
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
			int Arg0 = 1;
			int Arg1 = 5;
			int Arg2 = 8;
			int Arg3 = 0;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 6;
			int Arg3 = 1;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			int Arg1 = 30;
			int Arg2 = 20;
			int Arg3 = 5;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 899;
			int Arg1 = 1073;
			int Arg2 = 1147;
			int Arg3 = 14;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2000;
			int Arg1 = 2000;
			int Arg2 = 2000;
			int Arg3 = 666;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 10;
			int Arg2 = 10;
			int Arg3 = 1;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 77;
			int Arg1 = 42;
			int Arg2 = 21;
			int Arg3 = 3;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 6;
			int Arg3 = 1;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 444;
			int Arg1 = 1480;
			int Arg2 = 1110;
			int Arg3 = 74;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 5*7*11;
			int Arg1 = 5*7*13;
			int Arg2 = 7*11*13*17;
			int Arg3 = 17;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FruitTrees ___test;
	___test.run_test(-1);
}
// END CUT HERE
