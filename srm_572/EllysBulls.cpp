// BEGIN CUT HERE
/*
SRM 572 Div1 Medium (500)

問題
-数当てゲーム
-推測した数字と、当たりの数の配列が与えられる
-元の数がわかるなら答える

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef map<IntVec, StrVec> IntVecStrVecMap;

class EllysBulls {
public:
	string getNumber(vector <string> guesses, vector <int> bulls) {
		string ans;
		int g = (int)guesses.size();
		int len_a = (int)guesses[0].length() / 2;
		int len_b = (int)guesses[0].length() - len_a;
		int i, j, k, m;
		char temp[64];

		IntVecStrVecMap ivsvm;

		m = (int)pow(10.0, (double)len_a);
		for (i = 0; i < m; ++i) {
			sprintf(temp, "%0*d", len_a, i);
			IntVec v = bulls;
			for (j = 0; j < g; ++j) {
				for (k = 0; k < len_a; ++k) {
					v[j] -= temp[k] == guesses[j][k];
				}
				if (v[j] < 0) {
					break;
				}
			}
			if (j >= g) {
				ivsvm[v].push_back(temp);
			}
		}

		m = (int)pow(10.0, (double)len_b);
		for (i = 0; i < m; ++i) {
			sprintf(temp, "%0*d", len_b, i);
			IntVec v(g);
			for (j = 0; j < g; ++j) {
				for (k = 0; k < len_b; ++k) {
					v[j] += temp[k] == guesses[j][len_a+k];
				}
			}
			IntVecStrVecMap::const_iterator it = ivsvm.find(v);
			if (it == ivsvm.end()) {
				continue;
			}

			if (!ans.empty() || it->second.size() > 1) {
				// answer is not unique
				return "Ambiguity";
			}

			ans = it->second[0];
			ans += temp;
		}

		return ans.empty() ? "Liar" : ans;
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
			string Arr0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
			int Arr1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
			string Arg2 = "1337";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0000", "1111", "2222"};
			int Arr1[] = {2, 2, 2};
			string Arg2 = "Liar";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"666666", "666677", "777777", "999999"};
			int Arr1[] = {2, 3, 1, 0};
			string Arg2 = "Ambiguity";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"000", "987", "654", "321", "100", "010"};
			int Arr1[] = {2, 1, 0, 0, 1, 1};
			string Arg2 = "007";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"};
			int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			string Arg2 = "54";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"};
			int Arr1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
			string Arg2 = "4266642";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysBulls ___test;
	___test.run_test(-1);
}
// END CUT HERE
