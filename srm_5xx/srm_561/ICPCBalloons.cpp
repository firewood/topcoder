// BEGIN CUT HERE
/*
// SRM 561 Div1 Easy (250)

問題
コンテストを開催し、M個の問題を出題した。
正解者には風船を配る。
風船の色は問題毎に全て異なっている必要がある。
風船のサイズはMとLの二種類あり、同じ問題では同じサイズの風船を配る必要がある。
風船は別の色に塗ることができるが、サイズは変更できない。
風船を塗りなおす回数を求める。

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class ICPCBalloons {

public:
	int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
		IntVec M, L;
		int i;
		for (i = 0; i < (int)balloonCount.size(); ++i) {
			if (balloonSize[i] == 'M') {
				M.push_back(balloonCount[i]);
			} else {
				L.push_back(balloonCount[i]);
			}
		}
		sort(M.rbegin(), M.rend());
		sort(L.rbegin(), L.rend());
		sort(maxAccepted.rbegin(), maxAccepted.rend());
		int m_max = accumulate(M.begin(), M.end(), 0);
		int l_max = accumulate(L.begin(), L.end(), 0);
		int masks = 1 << maxAccepted.size();
		int mask;
		int result = 1000000000;
		for (mask = 0; mask < masks; ++mask) {
			int m = 0, l = 0;
			int m_total = 0, l_total = 0;
			int ok = 0;
			for (i = 0; i < (int)maxAccepted.size(); ++i) {
				if ((1 << i) & mask) {
					m_total += maxAccepted[i];
					if (m < M.size()) {
						ok += min(maxAccepted[i], M[m]);
					}
					++m;
				} else {
					l_total += maxAccepted[i];
					if (l < L.size()) {
						ok += min(maxAccepted[i], L[l]);
					}
					++l;
				}
			}
			if (m_total <= m_max && l_total <= l_max) {
				result = min(result, m_total + l_total - ok);
			}
		}
		return result < 1000000000 ? result : -1;
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
			int Arr0[] = {100};
			string Arg1 = "L";
			int Arr2[] = {1,2,3,4,5};
			int Arg3 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minRepaintings(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			string Arg1 = "M";
			int Arr2[] = {10,20,30,40,50};
			int Arg3 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minRepaintings(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,6,1,5,6,1,5,6,1};
			string Arg1 = "MLMMLMMLM";
			int Arr2[] = {7,7,4,4,7,7};
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minRepaintings(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,100};
			string Arg1 = "ML";
			int Arr2[] = {50,51,51};
			int Arg3 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minRepaintings(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
			string Arg1 = "MMMLLLMMLLMLMLM";
			int Arr2[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
			int Arg3 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minRepaintings(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
			string Arg1 = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
			int Arr2[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
			int Arg3 = 210;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minRepaintings(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ICPCBalloons ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
