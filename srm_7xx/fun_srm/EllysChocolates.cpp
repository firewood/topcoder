// BEGIN CUT HERE
/*
2017 TCO Algorithm Warsaw Regional Round
Fun SRM Easy (250)

問題
-Nユーロ持っている
-チョコレートが一つPユーロで売っている
-食べ終わったチョコレートの包み紙K個でチョコレートが一つもらえる
-手に入るチョコレートの個数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysChocolates {
public:
	int getCount(int P, int K, int N) {
		int ans = N / P;
		int w = ans;
		while (w >= K) {
			int g = w / K;
			ans += g;
			w %= K;
			w += g;
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
			int Arg1 = 3;
			int Arg2 = 15;
			int Arg3 = 22;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 41;
			int Arg1 = 4;
			int Arg2 = 1337;
			int Arg3 = 42;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 666;
			int Arg1 = 13;
			int Arg2 = 823172;
			int Arg3 = 1337;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 666;
			int Arg1 = 222;
			int Arg2 = 444;
			int Arg3 = 0;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysChocolates ___test;
	___test.run_test(-1);
}
// END CUT HERE
