// BEGIN CUT HERE
/*
SRM 628 Div1 Medium (500)

問題
-いくつかの抵抗がある
-抵抗は組み合わせAまたはBで結合する
-Aは和、Bは最大値
-組み合わせ方と使用可能な抵抗値の一覧が与えられる
-構成可能な抵抗値の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CircuitsConstruction {
	string c;
	vector <int> con;

	int dfs(const char *&s) {
		switch (*s++) {
		case 'A':
			return dfs(s) + dfs(s);
		case 'B':
			return max(dfs(s), dfs(s));
		case 'X':
			return 1;
		}
		return 0;
	}

public:
	int maximizeResistance(string circuit, vector <int> conductors) {
		const char *s = circuit.c_str();
		int cnt = dfs(s);
		sort(conductors.rbegin(), conductors.rend());
		return accumulate(conductors.begin(), conductors.begin() + cnt, 0);
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
			string Arg0 = "BXBXX";
			int Arr1[] = {8, 2, 3};
			int Arg2 = 8;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAXXAXAXX";
			int Arr1[] = {1, 1, 2, 8, 10};
			int Arg2 = 22;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AXBXX";
			int Arr1[] = {8, 2, 3};
			int Arg2 = 11;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX";
			int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
			int Arg2 = 454;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBABBXXXAXXBAAXXXBBXXAAXXXBBBXAXXBAXXXBBAAXXXBXXXBAABBBXXXABXBXXBAXXXAXBXAXXXBBABXXAXXABBXXAXAXXXX";
			int Arr1[] = { 323, 647, 195, 94, 682, 35, 723, 252, 143, 261, 106, 832, 450, 894, 669, 569, 484, 429, 246, 514, 516, 899, 238, 940, 915, 963, 708, 157, 242, 454, 47, 3, 578, 285, 753, 908, 795, 489, 12, 840, 370, 184, 273, 721, 925, 592, 695, 681, 81, 793 };
			int Arg2 = 8911;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maximizeResistance(Arg0, Arg1));
		}
		n++;




	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CircuitsConstruction ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
