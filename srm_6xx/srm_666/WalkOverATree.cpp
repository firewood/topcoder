// BEGIN CUT HERE
/*
SRM 666 Div1 Easy (222)

問題
-N個の頂点からなる木が与えられる
-1ステップで辺を一つ移動できる
-Lステップで訪問できる異なる頂点の最大数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WalkOverATree {
public:
	int maxNodesVisited(vector <int> parent, int L) {
		int dist[100] = {};
		int N = (int)parent.size() + 1;
		int ans = 0;
		for (int i = 0; i < N - 1; ++i) {
			int d = 1;
			int n = i + 1;
			while (n != 0) {
				++d;
				n = parent[n - 1];
			}
			ans = max(ans, d);
		}
		ans = min(ans, L + 1);
		int remain_nodes = N - ans;
		int remain_time = max(0, L - ans + 1);
		ans += min(remain_nodes, remain_time / 2);
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
			int Arr0[] = {0, 0};
			int Arg1 = 2;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0};
			int Arg1 = 3;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 3};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,2,4,2,3,1};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
			int Arg1 = 4;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
			int Arg1 = 26;
			int Arg2 = 17;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 2, 0}
;
			int Arg1 = 100;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 2};
			int Arg1 = 4;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxNodesVisited(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WalkOverATree ___test;
	___test.run_test(-1);
}
// END CUT HERE
