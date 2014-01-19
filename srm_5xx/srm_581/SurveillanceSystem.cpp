// BEGIN CUT HERE
/*
SRM 581 Div1 Easy (250)

問題
-N個の区画に分割された倉庫があり、そこからコンテナを盗み出したい
-何台かの監視カメラが設置されている
-コンテナがある位置と、監視カメラが監視しているコンテナの数が与えられる
-カメラの位置は全て異なる
-各区画の監視状態を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef map<int, int> IntMap;

class SurveillanceSystem {

public:
	string getContainerInfo(string containers, vector <int> reports, int L) {
		char ans[64] = {};
		int N = (int)containers.length();
		int i, j;
		IntMap m;
		for (i = 0; i < reports.size(); ++i) {
			m[reports[i]] += 1;
		}
		IntMap::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			int w[64] = {};
			int tot = 0;
			for (i = 0; i <= N-L; ++i) {
				int c = 0;
				for (j = 0; j < L; ++j) {
					c += containers[i+j] == 'X';
				}
				if (c == it->first) {
					++tot;
					for (j = 0; j < L; ++j) {
						w[i+j] += 1;
					}
				}
			}
			for (i = 0; i < N; ++i) {
				if (w[i]) {
					if (tot == it->second || w[i] > tot - it->second) {
						ans[i] = '+';
					} else if (ans[i] != '+') {
						ans[i] = '?';
					}
				}
			}
		}
		for (i = 0; i < N; ++i) {
			if (!ans[i]) {
				ans[i] = '-';
			}
		}
		return ans;
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
			string Arg0 = "-X--XX";
			int Arr1[] = {1, 2};
			int Arg2 = 3;
			string Arg3 = "??++++";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getContainerInfo(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-XXXXX-";
			int Arr1[] = {2};
			int Arg2 = 3;
			string Arg3 = "???-???";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getContainerInfo(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "------X-XX-";
			int Arr1[] = {3, 0, 2, 0};
			int Arg2 = 5;
			string Arg3 = "++++++++++?";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getContainerInfo(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-XXXXX---X--";
			int Arr1[] = {2, 1, 0, 1};
			int Arg2 = 3;
			string Arg3 = "???-??++++??";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getContainerInfo(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X";
			int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
			int Arg2 = 7;
			string Arg3 = "???++++?++++++++++++++++++++??????--";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getContainerInfo(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "XX------X";
			int Arr1[] = {2,1};
			int Arg2 = 3;
			string Arg3 = "+++?--???";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getContainerInfo(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SurveillanceSystem ___test;
	___test.run_test(-1);
}
// END CUT HERE
