// BEGIN CUT HERE
/*
SRM 646 Div2 Medium (500)

問題
-二次元の無限の升目がある
-単位時間に縦または横に1マス移動できる
-移動できないマスが与えられる
-単位時間k経過後に行けるx位置の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> Queue;

class TheGridDivTwo {
public:
	int find(vector <int> x, vector <int> y, int k) {
		int ans = 0;

		bool vis[2002][2002] = {};
		vis[1000][1000] = true;
		for (int i = 0; i < (int)x.size(); ++i) {
			vis[1000 + y[i]][1000 + x[i]] = true;
		}

		Queue q;
		q.push_back(II(1000, 1000));
		for (int t = 0; t < k; ++t) {
			Queue next;
			for (int i = 0; i < (int)q.size(); ++i) {
				const int dx[] = { -1, 1, 0, 0 };
				const int dy[] = { 0, 0, -1, 1 };
				int x = q[i].second, y = q[i].first;
				for (int d = 0; d < 4; ++d) {
					int nx = x + dx[d], ny = y + dy[d];
					if (nx >= 950 && nx <= 2000 && ny >= 950 && ny <= 1050) {
						if (!vis[ny][nx]) {
							next.push_back(II(ny, nx));
							vis[ny][nx] = true;
							ans = max(ans, nx - 1000);
						}
					}
				}
			}
			q = next;
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
			int Arr0[] = {1,1,1,1};
			int Arr1[] = {-2,-1,0,1};
			int Arg2 = 4;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 0, 0, 1};
			int Arr1[] = {0, -1, 1, 0};
			int Arg2 = 9;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			// int Arr0[] = {};
			// int Arr1[] = {};
			int Arg2 = 1000;
			int Arg3 = 1000;

			vector <int> Arg0;
			vector <int> Arg1;
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
			int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
			int Arg2 = 47;
			int Arg3 = 31;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheGridDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
