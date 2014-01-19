// BEGIN CUT HERE
/*
// SRM 535 Div2 Easy (250)

問題
A-BとB-CとA+BとB+CからA、B、Cを求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<string> StrSet;
typedef set<int, int> IntMap;
typedef set<LL, LL> LLMap;
typedef set<string, string> StrMap;

class FoxAndIntegers {

public:
	vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
		vector <int> res;
		int a = AminusB + AplusB;
		int b = BminusC + BplusC;
		int c = -BminusC + BplusC;
		if ((abs(a)%2)==0 && (abs(b)%2) == 0 && (abs(c)%2) == 0 &&
				a-b == 2*AminusB && b-c == 2*BminusC && a+b == 2*AplusB && b+c == 2*BplusC) {
			res.push_back(a/2);
			res.push_back(b/2);
			res.push_back(c/2);
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
			int Arg0 = 1;
			int Arg1 = -2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arr4[] = {2, 1, 3 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 5;
			int Arg3 = 5;
//			int Arr4[] = { };
			int Arr4[] = { 1 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = -23;
			int Arg2 = -10;
			int Arg3 = 3;
			int Arr4[] = {0, -10, 13 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = -27;
			int Arg1 = 14;
			int Arg2 = 13;
			int Arg3 = 22;
//			int Arr4[] = { };
			int Arr4[] = { 1 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 30;
			int Arg2 = 30;
			int Arg3 = -30;
			int Arr4[] = {30, 0, -30 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndIntegers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
