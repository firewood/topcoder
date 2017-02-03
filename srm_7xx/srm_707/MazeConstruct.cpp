// BEGIN CUT HERE
/*
SRM 707 Div1 Easy (250)

問題
-N×Mマスの盤面がある
-左上から右下までの最短距離がちょうどKステップとなるように障害物を配置せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MazeConstruct {
public:
	vector <string> construct(int k) {
		vector <string> ans;
		if (k <= 49) {
			ans.push_back(string(k + 1, '.'));
			return ans;
		}

		for (int h = 8; h <= 50; ++h) {
			for (int w = 2; w <= 12; ++w) {
				int cnt = h * 2 * w + w * 2 + h - 1;
				if (k >= (cnt - (h - 4)) && k <= cnt) {
					for (int i = 0; i < w; ++i) {
						ans.push_back(string(h, '.'));
						ans.push_back(string(h - 1, '#') + ".");
						ans.push_back(string(h, '.'));
						ans.push_back("." + string(h - 1, '#'));
					}
					ans.push_back(string(h, '.'));
					int pos = h - 2;
					while ((cnt - k) >= 1) {
						ans[1][pos--] = '.';
						cnt -= 2;
					}
					if (cnt < k) {
						ans.push_back(string(h - 1, '#') + ".");
					}
/*
					for (string s : ans) {
						cout << s << endl;
					}
					cout << cnt << endl;
//*/
					return ans;
				}
			}
		}

		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arr1[] = {"...." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			string Arr1[] = {"...", "...", "..." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			string Arr1[] = {
				"..#..",
				"#.#..",
				"..#..",
				".#...",
				"....." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			string Arr1[] = {
				"..........",
				"#######...",
				"..........",
				".#########",
				"..........",
				"#########.",
				"..........",
				".#########",
				"..........",
				"#########." };
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MazeConstruct ___test;
	___test.run_test(-1);
}
// END CUT HERE
