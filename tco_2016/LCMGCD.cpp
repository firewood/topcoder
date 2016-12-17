// BEGIN CUT HERE
/*

TCO 2016 Round 2A Easy (400)

問題
-2^a×3^bの数からなる配列がある
-任意の2つの要素を選び、その要素を削除する
-2つの要素のGCDかLCMを求め、配列に追加する
-配列の要素が1つになるまで繰り返したとき、値をtにできるかどうかを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

class LCMGCD {
public:
	string isPossible(vector <int> x, int t) {
		LL tt = t;
		bool ans = false;
		LLVec xx(x.begin(), x.end());
		for (int i = 0; !ans && i < 100000; ++i) {
			random_shuffle(xx.begin(), xx.end());
			ans = possible(xx, tt);
		}
		return ans ? "Possible" : "Impossible";
	}

	bool possible(LLVec x, LL t) {
		for (size_t i = x.size(); i > 1; --i) {
			if (rand() % 2) {
				x[i - 2] = gcd(x[i - 2], x[i - 1]);
			} else {
				x[i - 2] = lcm(x[i - 2], x[i - 1]);
			}
			swap(x[i - 2], x[rand() % (i - 1)]);
		}
		return x[0] == t;
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
			int Arr0[] = { 2,3 };
			int Arg1 = 6;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 4,9 };
			int Arg1 = 6;
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 36, 54, 216 };
			int Arg1 = 36;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2187, 54, 18, 2187, 54, 59049, 2, 729, 19683, 6, 18, 729, 2, 59049, 2, 6, 2, 177147, 54, 6561, 18, 2, 2187, 6561, 18, 2, 729, 19683, 177147, 729, 54, 54, 54, 6, 19683, 2187, 729, 6561, 54, 2, 243, 2187, 2, 177147, 54, 54, 59049, 2187, 59049, 6 };
			int Arg1 = 162;
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LCMGCD ___test;
	___test.run_test(-1);
}
// END CUT HERE
