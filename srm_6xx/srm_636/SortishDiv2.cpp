// BEGIN CUT HERE
/*
SRM 636 Div2 Medium (500)

問題
-配列が与えられる
-いくつかの値は未知である
-任意の2つの値について昇順なものがsortedness個あるとき、配列の組み合わせの総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;
typedef vector<int> IntVec;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
//		++i;
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
//		++i;
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

class SortishDiv2 {
public:
	int ways(int sortedness, vector <int> seq) {
		int ans = 0;
		int N = (int)seq.size();
		int zi[128] = {};
		int zc = 0;
		IntSet r;
		for (int i = 1; i <= N; ++i) {
			r.insert(i);
		}
		for (int i = 0; i < N; ++i) {
			r.erase(seq[i]);
			if (!seq[i]) {
				zi[zc++] = i;
			}
		}
		IntVec v(r.begin(), r.end());
		do {
			BIT b(128);
			for (int i = 0; i < zc; ++i) {
				seq[zi[i]] = v[i];
			}
			int cnt = 0;
			for (int i = 0; i < N; ++i) {
				cnt += b.sum(seq[i]);
				b.add(seq[i], 1);
			}
			ans += cnt == sortedness;
		} while (zc && next_permutation(v.begin(), v.end()));
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
			int Arg0 = 5;
			int Arr1[] = {4, 0, 0, 2, 0};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {0, 0, 0, 0};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 3, 2};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 2, 0, 5, 0, 0};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SortishDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
