// BEGIN CUT HERE
/*
SRM 739 Div1 Easy (250)

PROBLEM STATEMENT
In this problem we are using 24-hour time. That is, the first second of each day is 00:00:00 and the last second of each day is 23:59:59.
You are visiting an online forum. Whenever there is a post that has been made strictly less than 24 hours ago, the forum displays a human-readable message stating when it was made. There are three types of messages:

"few seconds ago", which means the post is made between 0 and 59 seconds ago, inclusive.
"X minutes ago", where X is an integer between 1 and 59, inclusive, which means the post is made between X minutes and X minutes 59 seconds ago, inclusive.
"X hours ago", where X is an integer between 1 and 23, inclusive, which means the post is made between X hours and X hours 59 minutes 59 seconds ago, inclusive.

You are given the vector <string>s exactPostTime and showPostTime, both with the same number of elements.
For each valid index i you know the following information:

Post i was made strictly less than 24 hours ago.
The exact time of day when post i was made is exactPostTime[i].
The human-readable string currently displayed by the forum software about post i is showPostTime[i].

Given all the information above, what is the current time?

Return the answer in the format "HH:MM:SS".
If there are multiple solutions, return the one that comes first lexicographically.
If the information given to you is self-contradictory and there is no solution, return "impossible" instead.


DEFINITION
Class:ForumPostEasy
Method:getCurrentTime
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string getCurrentTime(vector <string> exactPostTime, vector <string> showPostTime)


NOTES
-The lexicographically smaller of two equally-long strings is the one that has a character with a smaller ASCII value at the first index at which they differ.


CONSTRAINTS
-exactPostTime will contain between 0 and 50 elements, inclusive.
-Each element of exactPostTime will be formatted as HH:MM:SS where HH is a two-digit integer between 00 and 23, inclusive, and both MM and SS are two-digit integers between 00 and 59, inclusive.
-exactPostTime and showPostTime will contain same number of elements.
-Each element of showPostTime will have one of the formats described in problem statment.


EXAMPLES

0)
{"12:12:12"}
{"few seconds ago"}

Returns: "12:12:12"

The current time is somewhere between 12:12:12 and 12:13:11, inclusive. The returned time is the lexicographically smallest one out of all these times.


1)
{"23:23:23","23:23:23"}
{"59 minutes ago","59 minutes ago"}

Returns: "00:22:23"

Both posts were made on the previous day. The current time is a bit after midnight.


2)
{"00:10:10","00:10:10"}
{"59 minutes ago","1 hours ago"}

Returns: "impossible"

Two posts made in the same second cannot have two different human-readable strings.


3)
{"11:59:13","11:13:23","12:25:15"}
{"few seconds ago","46 minutes ago","23 hours ago"}

Returns: "11:59:23"

The post made at 12:25:15 was posted yesterday at that time of day.

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
