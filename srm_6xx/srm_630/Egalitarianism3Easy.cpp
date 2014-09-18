// BEGIN CUT HERE
/*
SRM 630 Div2 Medium (500)

問題
-N個の都市がある
-それぞれの都市はN-1本の道路で接続されておりそれぞれの長さが与えられる
-どの2都市の距離も全て等しいという条件を満たす最大の都市数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef set<int> IntSet;

class Egalitarianism3Easy {
public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		if (n <= 2) {
			return n;
		}
		int d[50][50];
		memset(d, 0x3f, sizeof(d));
		for (int i = 0; i < (int)a.size(); ++i) {
			d[a[i] - 1][b[i] - 1] = len[i];
			d[b[i] - 1][a[i] - 1] = len[i];
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		int ans = 2;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int r = d[i][j];
				if (r < 1e6) {
					IntSet s;
					s.insert(i);
					s.insert(j);
					for (int k = 0; k < n; ++k) {
						if (i != k && j != k) {
							IntSet::const_iterator it;
							for (it = s.begin(); it != s.end(); ++it){
								if (d[k][*it] != r) {
									break;
								}
							}
							if (it == s.end()){
								s.insert(k);
							}
						}
					}
					ans = max(ans, (int)s.size());
				}
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
			int Arg0 = 4;
			int Arr1[] = {1,1,1};
			int Arr2[] = {2,3,4};
			int Arr3[] = {1,1,1};
			int Arg4 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {1,2,3,2,3};
			int Arr2[] = {2,3,4,5,6};
			int Arr3[] = {2,1,3,2,3};
			int Arg4 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {1,1,1,1,1,1,1,1,1};
			int Arr2[] = {2,3,4,5,6,7,8,9,10};
			int Arr3[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int Arg4 = 9;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1};
			int Arr2[] = {2};
			int Arr3[] = {3};
			int Arg4 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			// int Arr1[] = {};
			// int Arr2[] = {};
			// int Arr3[] = {};
			int Arg4 = 1;

			vector <int> Arg1;
			vector <int> Arg2;
			vector <int> Arg3;
			verify_case(n, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Egalitarianism3Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
