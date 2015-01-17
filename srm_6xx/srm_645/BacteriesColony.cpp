// BEGIN CUT HERE
/*
SRM 645 Div2 Easy (250)

問題
-バクテリアを育てている
-いくつかのコロニーがある
-隣り合うコロニーの大きさにより、次の日のコロニーの状態が変わる
-両隣が自分より大きければ大きさが1増える
-両隣が自分より小さければ大きさが1減る
-最終的なコロニーの大きさを求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BacteriesColony {
public:
	vector <int> performTheExperiment(vector <int> colonies) {
		int N = (int)colonies.size();
		vector <int> c[2];
		c[0] = colonies;
		int x = 0;
		while (c[0] != c[1]) {
			c[x ^ 1] = c[x];
			for (int i = 1; i < N - 1; ++i) {
				if (c[x][i - 1] < c[x][i] && c[x][i] > c[x][i + 1]) {
					c[x ^ 1][i]--;
				}
				if (c[x][i - 1] > c[x][i] && c[x][i] < c[x][i + 1]) {
					c[x ^ 1][i]++;
				}
			}
			x ^= 1;
		}
		return c[x];
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
			int Arr0[] = {5, 3, 4, 6, 1 };
			int Arr1[] = {5, 4, 4, 4, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 4, 9 };
			int Arr1[] = {1, 4, 5, 9 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {78, 34, 3, 54, 44, 99 };
			int Arr1[] = {78, 34, 34, 49, 49, 99 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 };
			int Arr1[] = {32, 59, 59, 59, 47, 47, 47, 47, 47, 18, 18, 19, 53, 53, 91 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BacteriesColony ___test;
	___test.run_test(-1);
}
// END CUT HERE
