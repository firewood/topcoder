// BEGIN CUT HERE
/*
SRM 645 Div2 Medium (500)

問題
-直線上に何台かの貨車がある
-それぞれの位置と長さが与えられる
-コスト1で左右どちらかに1移動できる
-全ての貨車が連続するような位置に移動するための総コストの最小値を求める

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
typedef pair<LL, LL> LLLL;
typedef vector<LLLL> LLLLVec;

class ConnectingCars {

public:
	long long minimizeCost(vector <int> positions, vector <int> lengths) {
		LL N = positions.size();
		LLLLVec v;
		for (LL i = 0; i < N; ++i) {
			v.push_back(LLLL(positions[i], lengths[i]));
		}
		sort(v.begin(), v.end());
		LL offset[60] = {};
		for (LL i = 1; i < N; ++i) {
			offset[i] = offset[i-1] + v[i-1].second;
		}
		LL ans = 0;
		for (LL i = 0; i < N; ++i) {
			LL pos = v[N / 2].first - offset[N / 2] + offset[i];
			ans += abs(v[i].first - pos);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 10, 20};
			int Arr1[] = {2, 2, 5, 3};
			long long Arg2 = 15LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 50, 1}
;
			int Arr1[] = {10, 2, 1};
			long long Arg2 = 96LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 10, 100, 13, 80};
			int Arr1[] = {5, 3, 42, 40, 9};
			long long Arg2 = 66LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427};
			int Arr1[] = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540};
			long long Arg2 = 1009957100LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConnectingCars ___test;
	___test.run_test(-1);
}
// END CUT HERE
