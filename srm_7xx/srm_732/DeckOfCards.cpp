// BEGIN CUT HERE
/*
SRM 732 Div2 Easy (250)

問題
-数値と、aからzまでのどれかのマークが書かれたカードがある
-値v、マークがsの1枚のカードを(v,s)と表す
-何枚かのカードのセットが与えられる
-以下の条件を満たすかどうかを調べよ
  -任意の2枚のカードについて、少なくとも値かマークのどちらかが異なる
  -任意の2枚のカード(v1,s1)と(v2,s2)について、(v1,s2)と(v2,s1)というカードが存在する

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;

class DeckOfCards {

	bool check(int n, vector <int> value, string suit) {
		map<II, int> m;
		for (int i = 0; i < n; ++i) {
			m[II(value[i], suit[i])] += 1;
			if (m[II(value[i], suit[i])] >= 2) {
				return false;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (!m[II(value[i], suit[j])] || !m[II(value[j], suit[i])]) {
					return false;
				}
			}
		}
		return true;
	}

public:
	string IsValid(int n, vector <int> value, string suit) {
		return check(n, value, suit) ? "Perfect" : "Not perfect";
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
			int Arg0 = 1;
			int Arr1[] = {10};
			string Arg2 = "z";
			string Arg3 = "Perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,2,3};
			string Arg2 = "hhh";
			string Arg3 = "Perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {2,3,2,3};
			string Arg2 = "hcch";
			string Arg3 = "Perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,1,1};
			string Arg2 = "hch";
			string Arg3 = "Not perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,2,3,4};
			string Arg2 = "hhcc";
			string Arg3 = "Not perfect";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, IsValid(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DeckOfCards ___test;
	___test.run_test(-1);
}
// END CUT HERE
