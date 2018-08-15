// BEGIN CUT HERE
/*
TCO18 R1B Medium (600)

問題
-1からNまでの数がある
-以下の条件でK個のペア(x1, y1), (x2, y2), ... (xk, yk)を作る
-1 <= xi < yi <= n
-yi < xi+1
-(xi+1 + yi+1) - (xi + yi) = C
-N, C, Kが与えられるとき、K個のペアを構築せよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class StablePairsDiv1 {
public:
	vector <int> findMaxStablePairs(int n, int c, int k) {
		vector <int> ans;
		for (int sum = 3; sum <= 200; ++sum) {
			vector <int> temp;
			int prev = 0;
			for (int i = 0; i < k; ++i) {
				int s = sum + c * i;
				int p = -1, q = -1;
				for (int j = prev + 1; j <= s / 2; ++j) {
					int k = s - j;
					if (j < k && k <= n) {
						if (p < 0 || k < q) {
							p = j, q = k;
						}
					}
				}
				if (p < 0) {
					break;
				}
				temp.push_back(p);
				temp.push_back(q);
				prev = q;
			}
			if (temp.size() == k * 2) {
				ans = temp;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arr3[] = {2, 3, 4, 5 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arr3[] = {1, 2, 3, 4 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100;
			int Arg2 = 1;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 100;
			int Arg2 = 1;
			int Arr3[] = {2, 3 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 6;
			int Arg2 = 3;
			int Arr3[] = {2, 5, 6, 7, 9, 10 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 7;
			int Arg2 = 3;
			int Arr3[] = {4, 5, 6, 10, 11, 12 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 100;
			int Arg2 = 5;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 8;
			int Arg2 = 1;
			int Arr3[] = { 99,100 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 97;
			int Arg1 = 8;
			int Arg2 = 25;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 3;
			int Arg2 = 3;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StablePairsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
