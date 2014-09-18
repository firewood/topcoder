// BEGIN CUT HERE
/*
SRM 631 Div2 Medium (500)

問題
-左から右の直線上に猫が何匹かいる
-位置と匹数が与えられる
-時間timeだけ左右のどちらかに移動できる
-同じ座標に2匹以上が存在しないように移動可能かどうか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
typedef vector<II> IIVec;

class CatsOnTheLineDiv2 {
public:
	string getAnswer(vector <int> position, vector <int> count, int time) {
		int N = (int)position.size();
		IIVec v;
		for (int i = 0; i < N; ++i) {
			v.push_back(II(position[i], count[i]));
		}
		sort(v.begin(), v.end());

		LL prev = -1LL << 60;
		for (int i = 0; i < N; ++i) {
			LL left = max(prev + 1, v[i].first - time);
			LL right = left + v[i].second - 1;
			if (right > v[i].first + time) {
				return "Impossible";
			}
			prev = right;
		}
		return "Possible";
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
			int Arr0[] = {0};
			int Arr1[] = {7};
			int Arg2 = 3;
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {8};
			int Arg2 = 2;
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1};
			int Arr1[] = {3, 1};
			int Arg2 = 0;
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 0, 2};
			int Arr1[] = {2, 3, 5};
			int Arg2 = 2;
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 1, -10, 7, 12, 2, 10, 20};
			int Arr1[] = {3, 4, 2, 7, 1, 4, 3, 4};
			int Arg2 = 6;
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatsOnTheLineDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
