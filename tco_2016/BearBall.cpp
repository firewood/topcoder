// BEGIN CUT HERE
/*
TCO 2016 Round 2C Easy (250)

問題
-2次元平面上にN匹の熊がいて、それぞれの座標が与えられる
-1ターン毎に熊から熊へボールを投げるゲームを行う
-ボールの軌跡は直線である
-ボールの軌跡上にいて、ボールをさわったことのない熊がキャッチする
-熊iからはじめて、熊jがボールをキャッチするまで行う
-iとjの全ての組み合わせについて、最短ターン数の合計を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, LL> ILL;
typedef map<double, ILL> DILLMap;

class BearBall {

public:
	int countThrows(vector <int> x, vector <int> y) {
		int ans = 0;
		bool d[1500][1500] = {};
		int N = (int)x.size();
		for (int i = 0; i < N; ++i) {
			DILLMap m;
			int cnt = 0;
			for (int j = 0; j < N; ++j) {
				if (i != j) {
					LL dx = x[j] - x[i], dy = y[j] - y[i];
					LL dist = dx*dx + dy*dy;
					double r = atan2(dy, dx);
					if (m.find(r) != m.end()) {
						++cnt;
						ILL prev = m[r];
						if (prev.second < dist) {
							continue;
						}
						d[i][prev.first] = 0;
					}
					m[r] = ILL(j, dist);
					d[i][j] = 1;
				}
			}
			if (cnt >= N - 2) {
				return (LL)(N - 1) * N * (N + 1) / 6 * 2;
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				ans += d[i][j] ? 1 : 2;
			}
		}
		return ans * 2;
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
			int Arr0[] = {1,4,2};
			int Arr1[] = {1,10,7};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,1,1};
			int Arr1[] = {0,1,2,0,1};
			int Arg2 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,7,9,11};
			int Arr1[] = {4,3,2,1};
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,50,50,90,90};
			int Arr1[] = {5,17,5,17,5,17};
			int Arg2 = 34;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-100, -90, -80, -70, -85, -90, 0, 20};
			int Arr1[] = {-5, -8, -13, -21, -13, -13, -13, -69};
			int Arg2 = 68;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countThrows(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearBall ___test;
	___test.run_test(-1);
}
// END CUT HERE
