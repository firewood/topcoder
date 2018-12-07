// BEGIN CUT HERE
/*
SRM 742 Div1 Easy (250)

問題
- 1Ωの抵抗(製品ゼロ)を製造できる工場がある
- 新しい製品iは、製品xと製品yを直列につなぐ(操作0)か、並列につなぐ(操作1)ことで定義できる
- nanoOhms(単位ナノΩ)の抵抗を構成せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class ResistorFactory {
public:
	vector <int> construct(long long nanoOhms) {
		LL upper = nanoOhms / 1000000000LL;
		long double lower = (long double)(nanoOhms - upper * 1000000000LL);
		vector <int> ans;
		for (int i = 0; i < 30; ++i) {
			ans.push_back(i);
			ans.push_back(i);
			ans.push_back(0);
		}
		ans.push_back(0);
		ans.push_back(0);
		ans.push_back(1);
		for (int i = 0; i < 60; ++i) {
			ans.push_back(31 + i);
			ans.push_back(31 + i);
			ans.push_back(1);
		}
		for (int i = 30; i >= 0; --i) {
			LL x = 1LL << i;
			if (x <= upper) {
				ans.push_back((int)ans.size() / 3);
				ans.push_back(i);
				ans.push_back(0);
				upper -= x;
			}
		}
		long double y = 500000000;
		for (int i = 0; i < 60; ++i) {
			if (y <= lower) {
				ans.push_back((int)ans.size() / 3);
				ans.push_back(i + 31);
				ans.push_back(0);
				lower -= y;
			}
			y *= 0.5;
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
			long long Arg0 = 3000000000LL;
			int Arr1[] = {0, 0, 0, 0, 1, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1200000000LL;
			int Arr1[] = {0, 0, 0, 1, 0, 0, 1, 2, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1428571428LL;
			int Arr1[] = {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 12000000001LL;
			int Arr1[] = {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 333333333LL;
			int Arr1[] = {0, 0, 1, 0, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ResistorFactory ___test;
	___test.run_test(-1);
}
// END CUT HERE
