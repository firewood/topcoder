// BEGIN CUT HERE
/*
TCO18 Fun Round Poland Easy (250)

問題
-N人それぞれの興味分野がアルファベットで表されている
-同じアルファベットは同じ興味分野を示す
-一つ以上の共通の興味分野を持つ人を友達とする
-友達の数の期待値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SocialNetwork {
public:
	double averageFriends(vector <string> interests) {
		int n = (int)interests.size();
		long long f[64] = {};
		for (int i = 0; i < n; ++i) {
			for (char c : interests[i]) {
				f[i] |= 1LL << (c - 'A');
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (i != j && (f[i] & f[j]) != 0) {
					++cnt;
				}
			}
		}
		return 2.0 * cnt / n;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"A", "A"};
			double Arg1 = 1.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ABC", "DE", "FGHIJ"};
			double Arg1 = 0.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ABC", "DE", "FGHIJA"};
			double Arg1 = 0.6666666666666666;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AB", "AC", "AD", "AE", "BCDE"};
			double Arg1 = 4.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ABCDE", "BCDEF"};
			double Arg1 = 1.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"", "", "", ""};
			double Arg1 = 0.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, averageFriends(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SocialNetwork ___test;
	___test.run_test(-1);
}
// END CUT HERE
