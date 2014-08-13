// BEGIN CUT HERE
/*
SRM 629 Div1 Easy (250)

問題
-地面に四角形の穴が開いている
-何枚かの四角形の板があり、それぞれの大きさが与えられる
-地面の穴を完全に覆いたい
-ただし板の四隅が穴の外側になるように置くこと
-最低何枚必要か求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class RectangleCovering {

	int check(int H, int W, IntVec &hh, IntVec &ww) {
		IntVec v;
		for (int i = 0; i < (int)hh.size(); ++i) {
			int a = min(hh[i], ww[i]);
			int b = max(hh[i], ww[i]);
			if (a > H) {
				v.push_back(b);
			} else if (b > H) {
				v.push_back(a);
			}
		}
		sort(v.rbegin(), v.rend());
		int sum = 0;
		for (int i = 0; i < (int)v.size(); ++i) {
			sum += v[i];
			if (sum >= W) {
				return i + 1;
			}
		}
		return 10000;
	}

public:
	int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
		int ans = min(check(holeH, holeW, boardH, boardW), check(holeW, holeH, boardW, boardH));
		return ans < 10000 ? ans : -1;
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
			int Arg0 = 5;
			int Arg1 = 5;
			int Arr2[] = {8,8,8};
			int Arr3[] = {2,3,4};
			int Arg4 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 10;
			int Arr2[] = {6,6,6,6};
			int Arr3[] = {6,6,6,6};
			int Arg4 = -1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arr2[] = {5};
			int Arr3[] = {5};
			int Arg4 = -1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = {6};
			int Arr3[] = {4};
			int Arg4 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10000;
			int Arg1 = 5000;
			int Arr2[] = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
			int Arr3[] = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
			int Arg4 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = { 5 };
			int Arr3[] = { 4 };
			int Arg4 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = { 5 };
			int Arr3[] = { 3 };
			int Arg4 = -1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arr2[] = { 1, 1 };
			int Arr3[] = { 2, 2 };
			int Arg4 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = { 1,2 };
			int Arr3[] = { 3,3 };
			int Arg4 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = { 1, 1 };
			int Arr3[] = { 3, 3 };
			int Arg4 = -1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = { 1,1,1 };
			int Arr3[] = { 3,3,3 };
			int Arg4 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minimumNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RectangleCovering ___test;
	___test.run_test(-1);
}
// END CUT HERE
