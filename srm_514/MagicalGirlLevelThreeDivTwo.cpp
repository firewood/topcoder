// BEGIN CUT HERE
/*
// SRM 514 Div2 Hard (1000)

問題
-魔法少女が、悪い魔女を倒すために応用呪文を唱えようとしている
-応用呪文はK個の基本呪文の組み合わせからなる
-応用呪文A[i]は、A[i-1] + A[i-K-1] + A[i-2*K-1] + ...という和である
-呪文の強さは、呪文を唱える範囲のビットが立っている数の和である
-応用呪文A[n][lo..hi]の強さSを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<string> StrVec;

#define MAX_N 100
#define MAX_LENGTH 1000000000000000LL

class MagicalGirlLevelThreeDivTwo {
	int K;
	StrVec First;
	LL Length[MAX_N+1];

	int get_magical_power(int index, LL pos) {
		if (index < K) {
			return First[index][pos] - '0';
		}
		int i;
		for (i = index - 1; i >= 0; i -= K) {
			LL len = Length[i];
			if (pos < len) {
				break;
			}
			pos -= len;
		}
		return get_magical_power(i, pos);
	}

public:
	int theCount(vector <string> first, int n, long long lo, long long hi) {
		K = (int)first.size();
		First = first;
		// generate length table
		memset(Length, 0, sizeof(Length));
		int i, j;
		for (i = 0; i <= n; ++i) {
			if (i < K) {
				Length[i] = first[i].length();
			} else {
				for (j = i-1; j >= 0; j -= K) {
					// ignore remain part exceeds length of 10**15
					Length[i] = min(MAX_LENGTH+1, Length[i] + Length[j]);
				}
			}
		}

		// summarize power of the ultimate magic
		int result = 0;
		LL x;
		for (x = lo; x <= hi; ++x) {
			result += get_magical_power(n, x);
		}
		return result;
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
			string Arr0[] = {"101", "01"};
			int Arg1 = 4;
			long long Arg2 = 2LL;
			long long Arg3 = 5LL;
			int Arg4 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"01", "10"};
			int Arg1 = 5;
			long long Arg2 = 4LL;
			long long Arg3 = 5LL;
			int Arg4 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"1", "11", "111"};
			int Arg1 = 46;
			long long Arg2 = 10000LL;
			long long Arg3 = 11000LL;
			int Arg4 = 1001;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0", "00", "000"};
			int Arg1 = 46;
			long long Arg2 = 10000LL;
			long long Arg3 = 11000LL;
			int Arg4 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00110110101101001111101101001011010011111011010010"};
			int Arg1 = 100;
			long long Arg2 = 999999999999915LL;
			long long Arg3 = 1000000000000000LL;
			int Arg4 = 50;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"};
			int Arg1 = 91;
			long long Arg2 = 123456LL;
			long long Arg3 = 123654LL;
			int Arg4 = 76;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalGirlLevelThreeDivTwo ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
