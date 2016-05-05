// BEGIN CUT HERE
/*
SRM 675 Div1 Easy (300)

問題
-頂点数500以下で長さ3のパスがs本の木を作成せよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TreeAndPathLength3 {
public:
	vector <int> construct(int s) {
		vector <int> ans;
		if (s <= 100) {
			for (int i = 0; i < s + 2; ++i) {
				ans.push_back(i);
				ans.push_back(i + 1);
			}
		} else {
			int r = sqrt(s);
			int n = 0;
			for (int i = 1; i <= r + 1; ++i) {
				ans.push_back(0);
				ans.push_back(++n);
			}
			for (int i = 1; i < r; ++i) {
				ans.push_back(1);
				ans.push_back(++n);
			}
			ans.push_back(2);
			ans.push_back(++n);
			int t = r * r;
			while (t < s) {
				ans.push_back(n);
				ans.push_back(++n);
				++t;
			}
		}
		return ans;
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
			int Arg0 = 1;
			int Arr1[] = {0, 1, 1, 2, 2, 3 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreeAndPathLength3 ___test;
	___test.run_test(-1);
}
// END CUT HERE
