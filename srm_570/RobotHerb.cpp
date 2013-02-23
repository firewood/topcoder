// BEGIN CUT HERE
/*
// SRM 570 Div1 Easy (250)

問題
-ロボットがXY平面上を移動する
-命令が数値の配列で与えられる
-各命令では数値nだけ直進し、n回90度右回転する
-命令列全体をT回実行後、スタート地点からのマンハッタン距離を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class RobotHerb {

public:
	long long getdist(int T, vector <int> a) {
		int sz = (int)a.size();
		int d = 0;
		int dx[] = {1,0,-1,0};
		int dy[] = {0,-1,0,1};
		LL i, j, x = 0, y = 0;
		for (i = 1; i <= T; ++i) {
			for (j = 0; j < sz; ++j) {
				x += dx[d] * a[j];
				y += dy[d] * a[j];
				d = (d + a[j]) % 4;
			}
			if (i == 4) {
				i = T - (T%4);
				x *= (T/4);
				y *= (T/4);
			}
		}
		return abs(x) + abs(y);
	}

	long long getdist_affine_trans(int T, vector <int> a) {
		int sz = (int)a.size();
		int d = 0;
		int aa[] = {1, 0,-1, 0};
		int bb[] = {0,-1, 0, 1};
		int cc[] = {0, 1, 0,-1};
		int dd[] = {1, 0,-1, 0};
		LL i, j, x = 0, y = 0;
		for (j = 0; j < sz; ++j) {
			x += aa[d] * a[j];
			y += bb[d] * a[j];
			d = (d + a[j]) % 4;
		}
		int e = d;
		LL tx = x;
		LL ty = y;
		for (i = 2; i <= T; ++i) {
			LL p = aa[d] * x + bb[d] * y + tx;
			LL q = cc[d] * x + dd[d] * y + ty;
			d = (d + e) % 4;
			x = p;
			y = q;
		}
		return abs(x) + abs(y);
	}

	long long getdist_ref(int T, vector <int> a) {
		int sz = (int)a.size();
		int c = 0;
		int dx[] = {1,0,-1,0};
		int dy[] = {0,-1,0,1};
		LL i, j, x = 0, y = 0;
		for (i = 0; i < T; ++i) {
			for (j = 0; j < sz; ++j) {
				x += dx[c] * a[j];
				y += dy[c] * a[j];
				c = (c + a[j]) % 4;
			}
		}
		return abs(x) + abs(y);
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received, const long long &Received2) {
		cerr << "Test Case #" << Case << "...";
		if (Received != Received2) {
			cerr << "FAILED" << endl;
			cerr << "\1: \"" << Received << '\"' << endl;
			cerr << "\2: \"" << Received2 << '\"' << endl;
		} else if (Expected == Received) {
			cerr << "PASSED" << endl;
		} else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: \"" << Expected << '\"' << endl;
			cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1,2,3};
			long long Arg2 = 2LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist_ref(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {1};
			long long Arg2 = 0LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist_ref(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {1,1,2};
			long long Arg2 = 10LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist_ref(Arg0, Arg1));
		}
		n++;

/*
		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arr1[] = {100};
			long long Arg2 = 100000000000LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist_ref(Arg0, Arg1));
		}
		n++;
*/

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 570;
			int Arr1[] = {2013,2,13,314,271,1414,1732};
			long long Arg2 = 4112LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist_ref(Arg0, Arg1));
		}
		n++;


		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,2,3,4,5};
			long long Arg2 = 9LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist_ref(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RobotHerb ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
