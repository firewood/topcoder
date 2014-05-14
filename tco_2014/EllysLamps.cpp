// BEGIN CUT HERE
/*
TCO 2014 Round 1A Hard (1000)

問題
-N個のランプとボタンがある
-各ボタンはトグル動作し、押すとランプがON/OFFする
-ただし、両隣の片方または両方のランプも同時にON/OFFするようなボタンが存在する可能性がある
-ボタンの挙動がワーストケースの場合に、ONにできないランプの最小値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysLamps {
public:
	int getMin(string lamps) {
		int ans = 0;
		int yc = 0;
		int N = (int)lamps.size();
		for (int i = 1; i < N; ++i) {
			if (lamps[i - 1] != lamps[i]) {
				++ans;
				++i;
				yc = 0;
			} else {
				++yc;
				if (yc >= 2 && lamps[i] == 'Y') {
					++ans;
					++i;
					yc = 0;
				}
			}
		}
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
			string Arg0 = "YNNYN";
			int Arg1 = 2;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NNN";
			int Arg1 = 0;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YY";
			int Arg1 = 0;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YNYYYNNNY";
			int Arg1 = 3;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY";
			int Arg1 = 13;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysLamps ___test;
	___test.run_test(-1);
}
// END CUT HERE
