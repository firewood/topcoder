// BEGIN CUT HERE
/*
SRM 715 Div2 Easy (250)

問題
-N×Mのマス目がある
-K×Kマスごとに区切ったとき、それぞれのK×Kマスが全て同じ色かどうかを求める

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

class ImageCompression {
public:
	string isPossible(vector <string> image, int k) {
		int H = (int)image.size(), W = (int)image[0].length();
		bool ans = (H % k) == 0 && (W % k) == 0;
		if (ans) {
			for (int i = 0; i < H; i += k) {
				for (int j = 0; j < W; j += k) {
					int sum = 0;
					for (int a = 0; a < k; ++a) {
						sum += accumulate(image[i + a].begin() + j, image[i + a].begin() + j + k, 0);
					}
					if (sum != (k * k * '0') && sum != (k * k * '1')) {
						ans = false;
					}
				}
			}
		}
		return ans ? "Possible" : "Impossible";
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
			string Arr0[] = {
"0011",
"0011",
"1100",
"1100",
"0000",
"0000"
};
			int Arg1 = 2;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"0011",
"0011",
"1100",
"1100",
"0010",
"0000"
};
			int Arg1 = 2;
			string Arg2 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"111000111",
"111000111",
"111000111"
};
			int Arg1 = 3;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"001100",
"001100",
"110011",
"110011",
"001100",
"001100"
};
			int Arg1 = 6;
			string Arg2 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"001100",
"001100",
"110011",
"110011",
"001100",
"001100"
};
			int Arg1 = 2;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"11111111",
"11111111",
"11111111",
"11111111",
"11111111",
"11111111",
"11111111",
"11111111"
};
			int Arg1 = 4;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ImageCompression ___test;
	___test.run_test(-1);
}
// END CUT HERE
