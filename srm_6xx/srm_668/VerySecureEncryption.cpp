// BEGIN CUT HERE
/*
SRM 668 Div2 Easy (250)

問題
-i番目の文字をkey[i]番目に置く操作をK回繰り返す
-文字列messageに適用した結果を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class VerySecureEncryption {
public:
	string encrypt(string message, vector <int> key, int K) {
		string m[2];
		m[0] = message, m[1] = message;
		for (int k = 0; k < K; ++k) {
			int prev = k & 1;
			int curr = prev ^ 1;
			for (int i = 0; i != message.length(); ++i) {
				m[curr][key[i]] = m[prev][i];
			}
		}
		return m[K & 1];
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
			string Arg0 = "abc";
			int Arr1[] = {1,2,0};
			int Arg2 = 1;
			string Arg3 = "cab";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcde";
			int Arr1[] = {4, 3, 2, 1, 0};
			int Arg2 = 1;
			string Arg3 = "edcba";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcde";
			int Arr1[] = {4, 3, 2, 1, 0};
			int Arg2 = 2;
			string Arg3 = "abcde";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "uogcodlk";
			int Arr1[] = {4, 3, 6, 2, 5, 1, 0, 7};
			int Arg2 = 44;
			string Arg3 = "goodluck";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	VerySecureEncryption ___test;
	___test.run_test(-1);
}
// END CUT HERE
