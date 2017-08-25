// BEGIN CUT HERE
/*
SRM 720 Div2 Easy (250)

問題
-N行N列のマス目がある
-各行および各桁がK個の異なる数からなるかどうかを判定せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DistinctGridEasy {
public:
	string checkGrid(int n, int k, vector <int> grid) {
		for (int i = 0; i < n; ++i) {
			set<int> a, b;
			for (int j = 0; j < n; ++j) {
				a.insert(grid[i*n + j]);
				b.insert(grid[j*n + i]);
			}
			if (a.size() != k || b.size() != k) {
				return "Bad";
			}
		}
		return "Good";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arr2[] = {
0,1,2,
1,2,0,
2,0,1
};
			string Arg3 = "Good";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arr2[] = {
0,1,2,
1,2,0,
2,0,0
};
			string Arg3 = "Bad";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arr2[] = {
0,0,0,0,1,
0,1,0,0,0,
0,0,1,0,0,
1,0,0,0,0,
0,0,0,1,0
};
			string Arg3 = "Good";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 3;
			int Arr2[] = {
2,2,0,0,1,
0,1,2,2,0,
0,2,1,0,0,
1,0,0,0,2,
0,0,2,1,0
};
			string Arg3 = "Good";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			int Arr2[] = {
3,2,1,0,3,2,1,
3,2,1,3,2,1,2,
2,0,3,1,1,0,3,
1,3,0,2,0,3,0,
0,3,1,2,3,2,1,
1,1,1,2,1,0,3,
3,1,2,0,3,2,3
};
			string Arg3 = "Bad";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DistinctGridEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
