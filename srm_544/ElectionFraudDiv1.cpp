// BEGIN CUT HERE
/*
// SRM 544 Div1 Easy (275)

問題
候補者がX人、投票者がY人いる。
候補者の得票率を丸めた数値の配列が与えられる。
投票者の総数の候補の最小値を求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ElectionFraudDiv1 {

public:
	int MinimumVoters(vector <int> percentages) {
		int sz = percentages.size();
		int votes, i;
		for (votes = 1; votes < 10000; ++votes) {
			int MinSum = 0;
			int margin = 0;
			for (i = 0; i < sz; ++i) {
				bool f = false;
				int per = percentages[i];
				int Min = (per*votes - votes/2)/100;
				int t;
				for (t = max(0, Min); ; ++t) {
					int n = (t*100 + votes/2) / votes;
					if (n == per) {
						if (!f) {
							f = true;
							MinSum += t;
						} else {
							++margin;
						}
					} else if (n > per) {
						break;
					}
				}
				if (!f) {
					break;
				}
			}
			if (i >= sz && MinSum <= votes && (MinSum + margin) >= votes) {
				return votes;
			}
		}
		return -1;
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
			int Arr0[] = {33, 33, 33};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {29, 29, 43};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12, 12, 12, 12, 12, 12, 12, 12};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 100};
			int Arg1 = 200;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
			int Arg1 = 97;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 99, 0};
			int Arg1 = 67;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 4, 3, 10, 3, 3, 4, 3, 3, 3, 3, 5, 1, 6, 4, 3, 3, 3, 3, 7, 4, 4, 4, 3, 0, 3};
			int Arg1 = 115;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 34, 34, 34};
			int Arg1 = -1;
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, MinimumVoters(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ElectionFraudDiv1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
