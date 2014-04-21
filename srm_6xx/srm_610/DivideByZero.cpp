// BEGIN CUT HERE
/*
SRM 610 Div2 Easy (250)

問題
-何枚かの紙に数字が書いてある
-任意の2枚を取り出して、大きいほうの数÷小さいほうの数を計算する
-商が紙にない数なら追加する
-最終的に紙が何枚か求める

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;

class DivideByZero {
public:
	int CountNumbers(vector <int> numbers) {
		IntSet s(numbers.begin(), numbers.end());
		bool f = true;
		while (f) {
			f = false;
			IntSet prev = s;
			IntSet::const_reverse_iterator a, b;
			for (a = prev.rbegin(); a != prev.rend(); ++a) {
				for (b = a, ++b; b != prev.rend(); ++b) {
					int c = *a / *b;
					if (s.find(c) == s.end()) {
						f = true;
						s.insert(c);
					}
				}
			}
		}
		return s.size();
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
			int Arr0[] = {9, 2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 8, 30, 15, 4};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 4, 8, 16, 32, 64};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6, 2, 18};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, CountNumbers(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivideByZero ___test;
	___test.run_test(-1);
}
// END CUT HERE
