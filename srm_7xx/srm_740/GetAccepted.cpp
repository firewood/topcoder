// BEGIN CUT HERE
/*
SRM 740 Div2 Easy (250)

問題
-質問に対してTrueまたはFalseを返すシステムを作成している
-肯定文や二重否定文に対してはTrue、否定文に対してはFalseを返したい
-質問に対する適切な応答を作成せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GetAccepted {
public:
	string answer(string question) {
		map<string, int> m;
		string ans;
		stringstream ss(question);
		string x = " ";
		while (!x.empty()) {
			x.clear();
			ss >> x;
			m[x] += 1;
		}
		return m["not"] % 2 ? "False." : "True.";
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
			string Arg0 = "Do you want to get accepted?";
			string Arg1 = "True.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you not want to get accepted?";
			string Arg1 = "False.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you want to not get accepted?";
			string Arg1 = "False.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you want to get not not accepted?";
			string Arg1 = "True.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Do you not want to not get not not not accepted?";
			string Arg1 = "False.";

			verify_case(n, Arg1, answer(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GetAccepted ___test;
	___test.run_test(-1);
}
// END CUT HERE
