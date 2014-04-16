// BEGIN CUT HERE
/*
SRM 608 Div1 Easy (300)

問題
-N個の箱がある
-それぞれの箱にはキャンディーがlow[i]～high[i]個入っている
-キャンディーは全部でC個
-X個以上食べるには何箱あければよいか

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MysticAndCandies {
public:
	int minBoxes(int C, int X, vector <int> low, vector <int> high) {
		int N = (int)low.size();
		int ans = N;

		sort(low.rbegin(), low.rend());
		int t = 0;
		for (int i = 0; i < N - 1; ++i) {
			t += low[i];
			if (t >= X) {
				ans = i + 1;
				break;
			}
		}

		sort(high.begin(), high.end());
		t = C;
		for (int i = 0; i < N; ++i) {
			t -= high[i];
			if (t >= X) {
				ans = min(ans, N - i - 1);
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
			int Arg0 = 15;
			int Arg1 = 12;
			int Arr2[] = {1, 2, 3, 4, 5};
			int Arr3[] = {1, 2, 3, 4, 5};
			int Arg4 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 60;
			int Arg1 = 8;
			int Arr2[] = {5, 2, 3};
			int Arr3[] = {49, 48, 47};
			int Arg4 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 58;
			int Arg1 = 30;
			int Arr2[] = {3, 9, 12, 6, 15};
			int Arr3[] = {8, 12, 20, 8, 15};
			int Arg4 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 207581165;
			int Arg1 = 172146543;
			int Arr2[] = {4725448, 2753824, 6019698, 4199708, 4070001, 3589497, 5358499, 3637585, 5393667, 2837466,
2747807, 2918199, 3638042, 5199002, 3072044, 3858909, 3762101, 3657754, 3218704, 3888861,
3195689, 4768935, 3137633, 4124272, 4125056, 6087486, 3632970, 3620489, 2748765, 5917493,
3958996, 3335021, 3517186, 5543440, 2951006, 3403270, 3299481, 3093204, 4092331};
			int Arr3[] = {5702812, 6805664, 6823687, 5337687, 4286533, 4999849, 6567411, 4563235, 6618139, 6260135,
6249469, 3821449, 5963157, 6385012, 4255959, 5786920, 6112817, 4103918, 6371537, 4231698,
3409172, 6806782, 5623563, 4511221, 6407338, 6491490, 5209517, 6076093, 6530132, 6111464,
5833839, 6253088, 5595160, 6236805, 5772388, 5285713, 5617002, 4650978, 5234740};
			int Arg4 = 31;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 43873566;
			int Arg1 = 32789748;
			int Arr2[] = {2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477};
			int Arr3[] = {2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628};
			int Arg4 = 7;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 12709967;
			int Arg1 = 12628670;
			int Arr2[] = { 6812036, 5720267 };
			int Arr3[] = { 7060872, 6299029 };
			int Arg4 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



	}


// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MysticAndCandies ___test;
	___test.run_test(-1);
}
// END CUT HERE
