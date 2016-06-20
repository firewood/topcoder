// BEGIN CUT HERE
/*
TCO 2016 Round 1A Easy (250)

問題
-短針と長針の時間を入れ替えることができるタイムマシンがある
-与えられた時刻に対する変換後の時刻を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysTimeMachine {
public:
	string getTime(string time) {
		const char *a[] = { "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
		const char *b[] = { "05", "10", "15", "20", "25", "30", "35", "40", "45", "50", "55", "00" };
		string x = time.substr(0, 2);
		string y = time.substr(3, 2);
		string ans;
		for (int i = 0; i < 12; ++i) {
			if (y.compare(b[i]) == 0) {
				ans += a[i];
				break;
			}
		}
		ans += ":";
		for (int i = 0; i < 12; ++i) {
			if (x.compare(a[i]) == 0) {
				ans += b[i];
				break;
			}
		}
		return ans;
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
			string Arg0 = "11:20";
			string Arg1 = "04:55";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "02:25";
			string Arg1 = "05:10";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "06:30";
			string Arg1 = "06:30";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "05:55";
			string Arg1 = "11:25";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "03:45";
			string Arg1 = "09:15";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "01:00";
			string Arg1 = "12:05";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysTimeMachine ___test;
	___test.run_test(-1);
}
// END CUT HERE
