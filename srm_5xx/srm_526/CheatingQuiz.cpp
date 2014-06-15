// BEGIN CUT HERE
/*
// SRM 526 Div2 Easy (250)

問題
-3択のクイズがある
-事前に選択肢それぞれの総数がわかっている
-各問題が順番に出題されていくとき、その時点で正解の可能性のある選択肢の数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CheatingQuiz {

public:
	vector <int> howMany(string answers) {
		int m[128] = {};
		vector <int> res(answers.length());
		int i, j;
		for (i = 0; i < (int)answers.length(); ++i) {
			m[answers[i]] += 1;
		}
		for (i = 0; i < (int)answers.length(); ++i) {
			int c = 0;
			for (j = 'A'; j <= 'C'; ++j) {
				c += m[j] > 0;
			}
			res[i] = c;
			m[answers[i]] -= 1;
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAAA";
			int Arr1[] = {1, 1, 1, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, howMany(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAABBB";
			int Arr1[] = {2, 2, 2, 1, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, howMany(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CAAAAAC";
			int Arr1[] = {2, 2, 2, 2, 2, 2, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, howMany(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BBCA";
			int Arr1[] = {3, 3, 2, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, howMany(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BACACABCBBBBCAAAAACCCABBCAA";
			int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, howMany(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CheatingQuiz ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
