// BEGIN CUT HERE
/*
SRM 712 Div1 Easy (300)

問題
-N個の配列Aについてある操作を行う
-A[i-1]はA[i]の左、A[i+1]はA[i]の右とする
-A[0]の左はA[N-1]、A[N-1]の右はA[0]とする
-操作Lは、各Aの要素に、左の要素の値を加算する。加算は一斉に行う。
-操作Rは、各Aの要素に、右の要素の値を加算する。加算は一斉に行う。
-配列Aの初期状態Sと、最終状態Tが与えられる
-Tにするための操作手順を求める

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
typedef vector<LL> LLVec;

class LR {
public:
	string construct(vector<long long> s, vector<long long> t) {
		int N = (int)s.size();
		string w;
		LLVec a = s;
		for (int l = 0; l <= 100; ++l) {
			string ans = w;
			LLVec b = a;
			for (int r = 0; l + r <= 100; ++r) {
				if (b == t) {
					return ans;
				}
				LLVec c = b;
				for (int i = 0; i < N; ++i) {
					b[i] += c[(i + 1) % N];
				}
				if (*max_element(b.begin(), b.end()) > *max_element(t.begin(), t.end())) {
					break;
				}
				ans += "R";
			}
			LLVec c = a;
			for (int i = 0; i < N; ++i) {
				a[i] += c[(i - 1 + N) % N];
			}
			if (*max_element(a.begin(), a.end()) > *max_element(t.begin(), t.end())) {
				break;
			}
			w += "L";
		}
		return "No solution";
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
			long Arr0[] = {0,1,0,0,0};
			long Arr1[] = {0,1,2,1,0};
			string Arg2 = "LL";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {0,0,0,1};
			long Arr1[] = {0,1,0,0};
			string Arg2 = "No solution";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			long Arr1[] = {12,24,56,95,12,78,0,100,54,88};
			string Arg2 = "No solution";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {1,0,0};
			long Arr1[] = {11,11,10};
			string Arg2 = "RRRRR";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			LL Arr0[] = {1,1};
			LL Arr1[] = {562949953421312,562949953421312};
			string Arg2 = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {0,0,0,0,0};
			long Arr1[] = {0,0,0,1,0};
			string Arg2 = "No solution";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {123,456};
			long Arr1[] = {123,456};
			string Arg2 = "";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LR ___test;
	___test.run_test(-1);
}
// END CUT HERE
