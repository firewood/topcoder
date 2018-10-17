// BEGIN CUT HERE
/*
SRM 739 Div1 Easy (250)

問題
-24時間未満にいくつかの投稿があった
-経過時間により日付表記が異なる
-1分未満なら"few seconds ago"
-1時間未満なら"X minutes ago"
-それ以外は"X hours ago"となる
-条件をすべて満たす時間のうち辞書順最小のものを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ForumPostEasy {

public:
	string getCurrentTime(vector <string> exactPostTime, vector <string> showPostTime) {
		int n = (int)exactPostTime.size();
		vector<int> t(n);
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			sscanf(exactPostTime[i].c_str(), "%d:%d:%d", &a, &b, &c);
			t[i] = a * 3600 + b * 60 + c;
		}
		int i;
		for (i = 0; i < 86400; ++i) {
			int j;
			char w[64];
			for (j = 0; j < n; ++j) {
				int d = (i + 86400 - t[j]) % 86400;
				string x = "few seconds ago";
				if (d < 60) {
					;
				} else if (d < 3600) {
					sprintf(w, "%d minutes ago", d / 60);
					x = w;
				} else {
					sprintf(w, "%d hours ago", d / 3600);
					x = w;
				}
				if (showPostTime[j] != x) {
					break;
				}
			}
			if (j >= n) {
				sprintf(w, "%02d:%02d:%02d", i / 3600, (i % 3600) / 60, i % 60);
				return w;
			}
		}
		return "impossible";
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
			string Arr0[] = {"12:12:12"};
			string Arr1[] = {"few seconds ago"};
			string Arg2 = "12:12:12";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"23:23:23","23:23:23"};
			string Arr1[] = {"59 minutes ago","59 minutes ago"};
			string Arg2 = "00:22:23";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00:10:10","00:10:10"};
			string Arr1[] = {"59 minutes ago","1 hours ago"};
			string Arg2 = "impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"11:59:13","11:13:23","12:25:15"};
			string Arr1[] = {"few seconds ago","46 minutes ago","23 hours ago"};
			string Arg2 = "11:59:23";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "23:59:01" };
			string Arr1[] = { "few seconds ago" };
			string Arg2 = "00:00:00";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "23:58:01" };
			string Arr1[] = { "1 minutes ago" };
			string Arg2 = "00:00:00";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "22:00:01" };
			string Arr1[] = { "1 hours ago" };
			string Arg2 = "00:00:00";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCurrentTime(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ForumPostEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
