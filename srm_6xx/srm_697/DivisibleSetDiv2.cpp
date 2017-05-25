// BEGIN CUT HERE
/*
SRM 697 Div2 Medium (500)

問題
-N個の正の整数からなる配列bが与えられる
-以下の条件を全て満たす配列aが存在するかどうかを求める
-aの要素a[0],a[1],...a[N-1]は2以上かつ2のべき乗である
-a[i]^b[i]は、aの全要素の積で割り切れる

*/
// END CUT HERE

#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class DivisibleSetDiv2 {
    bool possible(vector<int> b) {
        sort(b.rbegin(), b.rend());
        vector<int> a(b.size(), 1);
        int sum = accumulate(a.begin(), a.end(), 0);
        for (int t = 0; t < 1000000; ++t) {
            bool ok = true;
            for (int i = 0; i != a.size(); ++i) {
                while (a[i] * b[i] < sum) {
                    if (a[i] >= 1000000) {
                        return false;
                    }
                    ok = false;
                    ++a[i], ++sum;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
    
public:
    string isPossible(vector <int> b) {
        return possible(b) ? "Possible" : "Impossible";
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
			int Arr0[] = {3,2};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,10};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 10};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,10,4,6,3};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,9,9,9,9,9,9,9,9};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,4,5,6,7};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	DivisibleSetDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
