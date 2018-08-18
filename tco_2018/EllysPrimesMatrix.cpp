// BEGIN CUT HERE
/*
TCC India 2018 Qualification Round Medium (500)

問題
-数値の行列が与えられる
-各行から数値を1桁ずつ選ぶとき、異なる素数が何個できるか求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysPrimesMatrix {
	int prime[10000000];
public:
	int getCount(vector <string> matrix) {
		memset(prime, -1, sizeof(prime));
		for (int i = 2; i < 10000000; ++i) {
			if (prime[i] < 0) {
				for (int j = i; j < 10000000; j += i) {
					prime[j] = i;
				}
			}
		}

		int rows = (int)matrix.size();
		int cols = (int)matrix[0].length();
		int index[8] = {};
		int ans = 0, i = 0;
		while (i < rows) {
			int v = 0;
			for (i = 0; i < rows; ++i) {
				v = (v * 10) + matrix[i][index[i]] - '0';
			}
			if (prime[v] == v) {
				++ans;
				prime[v] = -1;
			}

			for (i = 0; i < rows; ++i) {
				if (++index[i] < cols) {
					break;
				}
				index[i] = 0;
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
			string Arr0[] = {"5943",
 "1728",
 "3451"};
			int Arg1 = 11;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"123",
 "456",
 "789",
 "012",
 "248"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"11111",
 "11111",
 "11111",
 "11111",
 "13579"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"315509",
 "712846",
 "666371",
 "123456",
 "789012",
 "059437",
 "149573"};
			int Arg1 = 17575;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "01" };
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysPrimesMatrix ___test;
	___test.run_test(-1);
}
// END CUT HERE
