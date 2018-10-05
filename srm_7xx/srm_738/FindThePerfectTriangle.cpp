// BEGIN CUT HERE
/*
SRM 738 Div1 Easy (250)

問題
-三角形の辺の長さの合計perimeterと面積areaが与えられる
-3点の座標(x1, y1), (x2, y2), (x3, y3)すべてが0以上3000以下の整数にできるとき、それを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FindThePerfectTriangle {
public:
	vector <int> constructTriangle(int area, int perimeter) {
		vector<int> xv, yv;
		for (int x = -1000; x <= 1000; ++x) {
			for (int y = -1000; y <= 1000; ++y) {
				int rr = x * x + y * y;
				int r = (int)(sqrt(rr) + 1.0e-10);
				if (rr == r * r) {
					xv.push_back(x);
					yv.push_back(y);
				}
			}
		}
		int sz = (int)xv.size();
		for (int i = 0; i < sz; ++i) {
			int ax = xv[i], ay = yv[i];
			for (int j = 0; j < sz; ++j) {
				int bx = xv[j], by = yv[j];
				if (abs(ax * by - bx * ay) == area * 2) {
					int cx = ax - bx, cy = ay - by;
					double p = sqrt(ax * ax + ay * ay) + sqrt(bx * bx + by * by) + sqrt(cx * cx + cy * cy);
					if (fabs(p - perimeter) <= 1.0e-10) {
						return vector<int>({ 1000, 1000, ax + 1000, ay + 1000, bx + 1000, by + 1000 });
					}
				}
			}
		}
		return vector<int>();
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
			int Arg0 = 6;
			int Arg1 = 11;

			vector <int> Arg2;
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 12;
			int Arr2[] = {1, 1, 1, 4, 5, 4 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 37128;
			int Arg1 = 882;
			int Arr2[] = {137, 137, 273, 410, 1, 410 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 18;
			int Arr2[] = {1, 1, 4, 5, 1, 9 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18096;
			int Arg1 = 928;
			int Arr2[] = {1, 1, 1, 88, 417, 88 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000;

			vector <int> Arg2;
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 420;
			int Arg1 = 150;
			int Arr2[] = { 0,1000,0,1008,21,980 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FindThePerfectTriangle ___test;
	___test.run_test(-1);
}
// END CUT HERE
