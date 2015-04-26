// BEGIN CUT HERE
/*
SRM 656 Div2 Medium (500)

問題
-N枚のパンケーキがある
-それぞれの大きさは1からNで、それぞれのおいしさが与えられる
-1枚ずつランダムに選んで積んでいく
-ただし、一つ前に積んだものより大きければ、それを積まないで終了
-詰まれたパンケーキのおいしさの合計の期待値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RandomPancakeStackDiv2 {
public:
	double expectedDeliciousness(vector <int> d) {
		int N = (int)d.size();
		int seq[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		double a = 0, b = 0;
		do {
			b += 1;
			for (int i = 0; i < N; ++i) {
				if (i > 0 && seq[i] >= seq[i - 1]) {
					break;
				}
				a += d[seq[i]];
			}
		} while (next_permutation(seq, seq + N));
		return a / b;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			double Arg1 = 1.6666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,20};
			double Arg1 = 20.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,10,9,2};
			double Arg1 = 9.891666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,8,7,6,5,4,3,2,1};
			double Arg1 = 10.999999724426809;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			double Arg1 = 7.901100088183421;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
			double Arg1 = 1.7182818011463845;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomPancakeStackDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
