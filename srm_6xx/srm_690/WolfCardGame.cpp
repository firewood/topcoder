// BEGIN CUT HERE
/*
SRM 690 Div1 Easy (250)

問題
-1から100までの100毎のカードのうち、K枚選ぶ
-選んだカードに正負どちらかの符号をつける
-合計がNにならないような選び方を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WolfCardGame {
public:
	vector <int> createAnswer(int N, int K) {
		vector <int> ans;
		int d;
		for (d = 2; d < 7; ++d) {
			if (N % d) {
				break;
			}
		}
		for (int i = 1; i <= K; ++i) {
			ans.push_back(min(100, i * d));
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
			int Arg0 = 20;
			int Arg1 = 4;
			int Arr2[] = {1, 2, 3, 4 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			int Arg1 = 1;
			int Arr2[] = {39 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 97;
			int Arg1 = 6;
			int Arr2[] = {7, 68, 9, 10, 62, 58 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 12;
			int Arr2[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 15;
			int Arr2[] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 15;
			int Arr2[] = { 3,6,9,12,15,18,21,24,27,30,33,36,39,42,45 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 6;
			int Arg1 = 15;
			int Arr2[] = { 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 30;
			int Arg1 = 15;
			int Arr2[] = { 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 60;
			int Arg1 = 15;
			int Arr2[] = { 7,14,21,28,35,42,49,56,63,70,77,84,91,98,100 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 90;
			int Arg1 = 15;
			int Arr2[] = { 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, createAnswer(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WolfCardGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
