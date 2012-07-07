// BEGIN CUT HERE
/*
// SRM 533 Div2 Hard (1000)

問題
魔法少女がN人の悪い魔女と戦う。
ライフの初期値はMで、毎日1ずつ減る。
魔女はday[i]の日に出現する。
魔女に勝つ確率はwin[i]%で、勝つとライフがgain[i]増える。
ただしライフの最大値はMである。
魔法少女の生存日数の期待値を求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX_M 100000

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<double> DoubleVec;
typedef vector<II> IIVec;

static double memo[50][MAX_M+1];

class MagicalGirl {
	int Max;
	IntVec _day;
	DoubleVec _win;
	IntVec _gain;

	double rec(int i, int M) {
		if (memo[i][M] > 0) {
			return memo[i][M];
		}
		double &res = memo[i][M];
		int G = min(Max, M+_gain[i]);
		int d = G+1;
		if ((i+1) < (int)_day.size()) {
			d = _day[i+1] - _day[i];
		}
		if (M > d) {
			res = rec(i+1, M-d);
		} else {
			res = _day[i]+M;
		}
		if (G > d) {
			res = max(res, (1.0-_win[i])*_day[i] + _win[i]*rec(i+1, G-d));
		} else {
			res = max(res, (1.0-_win[i])*_day[i] + _win[i]*(_day[i]+G));
		}
		return res;
	}

public:
	double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
		Max = M;
		IIVec Days;
		int i;
		for (i = 0; i < (int)day.size(); ++i) {
			if (win[i] > 0 && gain[i] > 0) {
				Days.push_back(II(day[i], i));
			}
		}
		sort(Days.begin(), Days.end());

		_day.clear();
		_win.clear();
		_gain.clear();
		memset(memo, 0, sizeof(memo));
		for (i = 0; i < (int)Days.size(); ++i) {
			_day.push_back(Days[i].first);
			_win.push_back(win[Days[i].second] * 0.01);
			_gain.push_back(gain[Days[i].second]);
		}

		if (Days.size() <= 0 || M <= _day[0]) {
			return M;
		}
		return rec(0, M - _day[0]);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) {
		cerr << "Test Case #" << Case << "...";
		if (fabs(Expected-Received) <= 0.000000001) {
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
			int Arg0 = 2;
			int Arr1[] = {1};
			int Arr2[] = {75};
			int Arr3[] = {1};
			double Arg4 = 2.5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {5,5,5,5};
			int Arr2[] = {100,100,100,100};
			int Arr3[] = {1,1,1,1};
			double Arg4 = 14.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {5,5,5,5,5};
			int Arr2[] = {40,80,60,20,0};
			int Arr3[] = {10,10,10,10,10};
			double Arg4 = 13.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {2};
			int Arr2[] = {100};
			int Arr3[] = {2};
			double Arg4 = 2.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {2,13,8,7,9,4,6,21};
			int Arr2[] = {18,83,75,23,45,23,10,98};
			int Arr3[] = {10,9,8,10,7,16,13,20};
			double Arg4 = 35.908;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arr1[] = {10,20,30,40,50,60,70,80,90};
			int Arr2[] = {100,100,100,100,100,100,100,100,100};
			int Arr3[] = {10,10,10,10,10,10,10,10,10};
			double Arg4 = 101.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arr1[] = {1000000};
			int Arr2[] = {100};
			int Arr3[] = {100000};
			double Arg4 = 100000.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 93517;
			int Arr1[] = {23367, 28352, 35810, 56704, 70640, 72846, 102511, 126139, 131873, 134114, 153463, 169313, 170673, 192244, 222101, 238198, 249439, 273685, 285007, 291936, 317025, 342469, 364205, 396535, 400369, 419257, 451777, 472468, 495584, 495756, 512473, 533952, 545218, 562027, 586917, 590552, 595048, 598203, 617573, 619711, 650602, 655028, 678908, 701805, 729220, 729381, 760892};
			int Arr2[] = {99, 89, 32, 69, 6, 61, 93, 36, 83, 72, 50, 54, 22, 13, 7, 42, 68, 6, 75, 95, 59, 23, 40, 35, 85, 72, 96, 32, 18, 83, 76, 82, 86, 67, 53, 18, 43, 36, 86, 78, 97, 32, 80, 78, 29, 55, 26};
			int Arr3[] = {26643, 7324, 19962, 15331, 4069, 11738, 5333, 15520, 31748, 9842, 17345, 6945, 21114, 11715, 5659, 3753, 11671, 8594, 20675, 17438, 27243, 22662, 6304, 26761, 1871, 29866, 22808, 17304, 4700, 17902, 15000, 25116, 10226, 15525, 10514, 20620, 307, 27656, 27258, 25983, 4742, 7346, 17736, 7222, 14869, 28451, 14073};
			double Arg4 = 127853.2025625;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 92987;
			int Arr1[] = {17746, 48848, 73459, 74570, 105311, 112902, 132635, 148605, 158429, 167479, 183842, 201695, 211681, 227264, 246255, 274217, 290694, 301114, 303991, 313239, 336000, 362118, 364366, 369141, 399782, 414434, 436789, 438452, 443784, 443892, 448684, 460789, 475642, 498142, 508034, 519070, 548521, 552267, 578660, 604005, 607654, 635010, 665965, 680164, 691707, 707701, 710329, 742314, 751674, 771024};
			int Arr2[] = {29, 16, 15, 80, 86, 38, 3, 12, 89, 32, 70, 28, 88, 7, 8, 28, 94, 87, 13, 24, 17, 74, 63, 45, 83, 60, 45, 10, 25, 37, 91, 95, 35, 13, 56, 73, 79, 68, 54, 28, 2, 42, 58, 20, 69, 9, 54, 1, 34, 50};
			int Arr3[] = {13016, 29845, 26927, 946, 21697, 16624, 14040, 19199, 4040, 29183, 26311, 24049, 17407, 31083, 4322, 29840, 21182, 29760, 29585, 16780, 3358, 3437, 27200, 7349, 12927, 28741, 29665, 15745, 32514, 19201, 18791, 1417, 18960, 24892, 1100, 23308, 13522, 11893, 21772, 4971, 26806, 6289, 18856, 28075, 26096, 12886, 9252, 7415, 25079, 3569};
			double Arg4 = 92987.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	cout.precision(16);
	MagicalGirl ___test;
	___test.run_test(8);
//	___test.run_test(-1);
	return 0;
}
// END CUT HERE
