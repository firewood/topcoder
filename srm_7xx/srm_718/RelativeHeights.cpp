// BEGIN CUT HERE
/*
SRM 718 Div2 Easy (250)

問題
-N個のビルの高さが与えられる
-そのうちの一つだけ、予算の都合で建てられないことになった
-高さ順に順位をつけたとき、順位のつけかたが何通りあるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

IntVec getOrder(vector<int> v) {
	IntVec r;
	IIVec a;
	for (int i = 0; i != v.size(); ++i) {
		a.push_back(II(v[i], i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i != v.size(); ++i) {
		r.push_back(a[i].second);
	}
	return r;
}

class RelativeHeights {
	public:
	int countWays(vector <int> h) {
		set<IntVec> s;
		for (int i = 0; i != h.size(); ++i) {
			IntVec a = h;
			a.erase(a.begin() + i);
			s.insert(getOrder(a));
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
			int Arr0[] = {1,3,6,10,15,21};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2,1,3};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,2,352,43,5,44};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,5,6,1,2,3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,7,5,3,1,8,6,4,2};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RelativeHeights ___test;
	___test.run_test(-1);
}
// END CUT HERE
