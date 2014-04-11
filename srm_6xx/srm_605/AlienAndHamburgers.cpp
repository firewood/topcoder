// BEGIN CUT HERE
/*
SRM 605 Div1 Easy (250)

問題
-エイリアンのFredは地球を滅ぼす前にハンバーガーを食べておくことにした
-種類と味の配列が与えられる
-満足度は種類の数×味の合計である
-満足度の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class AlienAndHamburgers {
public:
	int getNumber(vector <int> type, vector <int> taste) {
		IIVec v, w;
		for (int i = 0; i < (int)type.size(); ++i) {
			v.push_back(II(type[i], taste[i]));
		}
		sort(v.rbegin(), v.rend());

		for (auto p : v) {
			if (w.size() > 0 && w.back().second == p.first) {
				w.back().first += max(0, p.second);
			} else {
				w.push_back(II(p.second, p.first));
			}
		}
		sort(w.rbegin(), w.rend());

		int t = 0, cnt = 0;
		for (auto p : w) {
			int a = t + p.first;
			int b = a * (cnt + 1);
			if (b < t * cnt) {
				break;
			}
			t = a;
			++cnt;
		}
		return t * cnt;
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
			int Arr0[] = {1, 2};
			int Arr1[] = {4, 7};
			int Arg2 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1};
			int Arr1[] = {-1, -1};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arr1[] = {7, 4, -1};
			int Arg2 = 30;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
			int Arr1[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
			int Arg2 = 54;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30, 20, 10};
			int Arr1[] = {100000, -100000, 100000};
			int Arg2 = 400000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 1, 2};
			int Arr1[] = {4, 7, 4, 7};
			int Arg2 = 44;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlienAndHamburgers ___test;
	___test.run_test(-1);

}
// END CUT HERE
