// BEGIN CUT HERE
/*
TCO 2017 R1A Easy (250)

問題
-何人かで卓球をする
-一列に並び、2人ずつ対戦する
-各自の実力が配列skillsで与えられる
-実力が高い方が必ず勝つ
-負けるか、連続でN回勝ったら列の最後に並ぶ
-Kゲーム目の対戦カードを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <list>

using namespace std;

class PingPongQueue {
public:
	vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
		list<int> q;
		for (int a : skills) {
			q.push_back(a);
		}
		int a = -1, b = -1, w = 0;
		for (int t = 1; ; ++t) {
			if (a < 0) {
				w = 0;
				a = q.front();
				q.pop_front();
			}
			b = q.front();
			q.pop_front();
			if (b > a) {
				w = 0;
				swap(a, b);
			}
			if (t == K) {
				break;
			}
			q.push_back(b);
			if (++w >= N) {
				q.push_back(a);
				a = -1;
			}
		}
		return { b, a };
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
			int Arr0[] = {1, 2, 3};
			int Arg1 = 2;
			int Arg2 = 2;
			int Arr3[] = {2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arg1 = 2;
			int Arg2 = 4;
			int Arr3[] = {1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
			int Arg1 = 10;
			int Arg2 = 399;
			int Arr3[] = {12, 50 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30, 12};
			int Arg1 = 34;
			int Arg2 = 80;
			int Arr3[] = {12, 30 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, whoPlaysNext(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PingPongQueue ___test;
	___test.run_test(-1);
}
// END CUT HERE
