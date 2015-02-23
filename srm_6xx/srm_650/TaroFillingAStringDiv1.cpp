// BEGIN CUT HERE
/*
SRM 650 Div1 Easy (250)

問題
-文字AかBだけからなる文字列がある
-何箇所かはAとB未定である
-同じ文字が連続する個数を最小にするとき、可能な場合の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007;

class TaroFillingAStringDiv1 {
public:
	int getNumber(int N, vector <int> position, string value) {
		vector<pair<int, char> > v;
		for (LL i = 0; i < position.size(); ++i) {
			v.push_back(make_pair(position[i], value[i]));
		}
		sort(v.begin(), v.end());
		LL ans = 1;
		for (LL i = 1; i < v.size(); ++i) {
			LL d = v[i].first - v[i - 1].first;
			if ((v[i].second == v[i - 1].second) == ((d % 2) != 0)) {
				ans = (ans * d) % MOD;
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
			int Arg0 = 3;
			int Arr1[] = {1, 3};
			string Arg2 = "AB";
			int Arg3 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {2, 1, 3, 4};
			string Arg2 = "ABBA";
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 25;
			int Arr1[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13};
			string Arg2 = "ABBBBABABBAAABA";
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 305;
			int Arr1[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246};
			string Arg2 = "ABAABBABBAABABBBBAAAABBABBBA";
			int Arg3 = 43068480;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroFillingAStringDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
