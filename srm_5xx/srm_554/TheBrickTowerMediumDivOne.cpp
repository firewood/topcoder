// BEGIN CUT HERE
/*
// SRM 554 Div1 Medium (500)

問題
0からN-1までのN本の塔があり、高さはばらばらである。
塔と塔の間を、それらの高いほうだけ離して一直線上に並べる。
全体の距離が最小で、塔の番号が辞書順最小の並べ方を求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

class TheBrickTowerMediumDivOne {

public:
	vector <int> find(vector <int> heights) {
		int sz = (int)heights.size();
		IIVec x, y;
		int i, j;
		for (i = 0; i < sz; ++i) {
			x.push_back(II(heights[i], i));
		}
		y.push_back(x[0]);
		x.erase(x.begin());
		while (!x.empty()) {
			i = 0;
			int mincost = max(y.back().first, x[i].first);
			for (j = 1; j < (int)x.size(); ++j) {
				int cost = max(y.back().first, x[j].first);
				if (cost < mincost) {
					i = j;
					mincost = cost;
				}
			}
			y.push_back(x[i]);
			x.erase(x.begin() + i);
		}
		IntVec res(sz);
		for (i = 0; i < sz; ++i) {
			res[i] = y[i].second;
		}
		return res;
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
			int Arr0[] = {4, 7, 5};
			int Arr1[] = {0, 2, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 4, 4, 4, 4, 4};
			int Arr1[] = {0, 1, 2, 3, 4, 5, 6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 3, 2};
			int Arr1[] = {0, 3, 1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 32, 38, 25, 43, 47, 6};
			int Arr1[] = {0, 6, 3, 1, 2, 4, 5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {0};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,3,4,7,1,2,6};
			int Arr1[] = {0,1,4,5,2,6,3};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheBrickTowerMediumDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
