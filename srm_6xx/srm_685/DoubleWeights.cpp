// BEGIN CUT HERE
/*
SRM 685 Div2 Medium (500)

問題
-N個の頂点からなる無向グラフがある
-辺が存在するとき、各辺はweight1[i][j]とweight2[i][j]の二種類のコストを持つ
-移動コストはweight1の合計W1とweight2の合計W2の積である
-頂点0から1への移動コストの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;
typedef vector<string> StrVec;

class DoubleWeights {

public:
	int minimalCost(vector <string> weight1, vector <string> weight2) {
		int N = (int)weight1.size();
		int mx[2][20];
		memset(mx, 0x3f, sizeof(mx));
		mx[0][0] = 0, mx[1][0] = 0;
		priority_queue<IIII> Queue;
		Queue.push(IIII(II(0, 0), II(0, 0)));
		unsigned int ans = -1;
		while (Queue.size() > 0) {
			IIII top = Queue.top();
			Queue.pop();
			int n = top.first.second;
			int first = top.second.first;
			int second = top.second.second;
			for (int i = 0; i < N; ++i) {
				if (weight1[n][i] != '.') {
					int a = first + weight1[n][i] - '0';
					int b = second + weight2[n][i] - '0';
					 int nc = a * b;
					if (i == 1) {
						ans = min(ans, (unsigned int)nc);
					} else if (a <= mx[0][i] || b <= mx[1][i]) {
						mx[0][i] = min(mx[0][i], a);
						mx[1][i] = min(mx[1][i], b);
						Queue.push(IIII(II(-nc, i), II(a, b)));
					}
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
			string Arr0[] = {"..14",
 "..94",
 "19..",
 "44.."};
			string Arr1[] = {"..94",
 "..14",
 "91..",
 "44.."};
			int Arg2 = 64;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..14",
 "..14",
 "11..",
 "44.."};
			string Arr1[] = {"..94",
 "..94",
 "99..",
 "44.."};
			int Arg2 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..",
 ".."};
			string Arr1[] = {"..",
 ".."};
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."};
			string Arr1[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."};
			int Arg2 = 2025;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."};
			string Arr1[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."};
			int Arg2 = 16;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleWeights ___test;
	___test.run_test(-1);
}
// END CUT HERE
