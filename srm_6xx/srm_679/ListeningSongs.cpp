// BEGIN CUT HERE
/*
SRM 679 Div2 Easy (250)

問題
-二つのバンドがある
-それぞれ何曲かあり、長さが秒で与えられる
-両方のバンドからT曲聴いた上で、余った時間で聴けるだけ曲を聴く
-ただし同じ曲は二度聴かない
-minutes分の間に何曲聴けるか求める

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

class ListeningSongs {
public:
	int listen(vector <int> durations1, vector <int> durations2, int minutes, int T) {
		if (durations1.size() < T || durations2.size() < T) {
			return -1;
		}
		sort(durations1.begin(), durations1.end());
		sort(durations2.begin(), durations2.end());
		int sec = minutes * 60;
		int tot = 0;
		for (int i = 0; i < T; ++i) {
			tot += durations1[0];
			tot += durations2[0];
			durations1.erase(durations1.begin());
			durations2.erase(durations2.begin());
		}
		if (tot > sec) {
			return -1;
		}
		for (int d : durations2) {
			durations1.push_back(d);
		}
		sort(durations1.begin(), durations1.end());
		int ans = T * 2;
		for (int d : durations1) {
			tot += d;
			if (tot > sec) {
				break;
			}
			++ans;
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
			int Arr0[] = {300,200,100};
			int Arr1[] = {400,500,600};
			int Arg2 = 17;
			int Arg3 = 1;
			int Arg4 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {300,200,100};
			int Arr1[] = {400,500,600};
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {60,60,60};
			int Arr1[] = {60,60,60};
			int Arg2 = 5;
			int Arg3 = 2;
			int Arg4 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {120,120,120,120,120};
			int Arr1[] = {60,60,60,60,60,60};
			int Arg2 = 10;
			int Arg3 = 3;
			int Arg4 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {196,147,201,106,239,332,165,130,205,221,248,108,60};
			int Arr1[] = {280,164,206,95,81,383,96,255,260,244,60,313,101};
			int Arg2 = 60;
			int Arg3 = 3;
			int Arg4 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,200,300};
			int Arr1[] = {100,200,300};
			int Arg2 = 2;
			int Arg3 = 1;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,200,300,400,500,600};
			int Arr1[] = {100,200};
			int Arg2 = 1000;
			int Arg3 = 3;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ListeningSongs ___test;
	___test.run_test(-1);
}
// END CUT HERE
