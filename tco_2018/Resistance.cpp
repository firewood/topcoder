// BEGIN CUT HERE
/*
TCO18 R1A Medium (500)

問題
-P人のプレーヤーがいる
-そのうちS人はスパイである
-P人のうち何人かが参加してミッションを行う
-スパイが参加するミッションは失敗する可能性がある
-N個のミッションについて、各人が参加したかどうかと、成功したかどうかの記録が与えられる
-ミッションの記録が正しい場合、各人がスパイである確率を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class Resistance {
public:
	vector <double> spyProbability(int P, int S, vector <string> missions) {
		int m = (int)missions.size();
		int bm = 1 << P;
		int vc = 0;
		int scnt[10] = {};
		for (int b = 0; b < bm; ++b) {
			if (popcount(b) == S) {
				bool valid = true;
				for (int i = 0; i < m; ++i) {
					if (missions[i][0] == 'F') {
						bool ok = false;
						for (int j = 0; j < P; ++j) {
							if (missions[i][j+1] == '1' && (((1 << j) & b) != 0)) {
								ok = true;
								break;
							}
						}
						if (!ok) {
							valid = false;
							break;
						}
					}
				}
				if (valid) {
					++vc;
					for (int j = 0; j < P; ++j) {
						for (int i = 0; i < m; ++i) {
							if ((((1 << j) & b) != 0)) {
								scnt[j]++;
								break;
							}
						}
					}
				}
			}
		}
		vector <double> ans;
		if (vc) {
			for (int j = 0; j < P; ++j) {
				ans.push_back((1.0 * scnt[j]) / vc);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1;
			string Arr2[] = {"S0110",
 "F1100",
 "S0011"};
			double Arr3[] = {0.5, 0.5, 0.0, 0.0 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			string Arr2[] = {"F0100",
 "S0101",
 "F1010",
 "S1011"};
			double Arr3[] = {0.5, 1.0, 0.5, 0.0 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			string Arr2[] = {"F110",
 "F101",
 "F011"};
//			double Arr3[] = { };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3;
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			string Arr2[] = {"F11000",
 "S00011",
 "F10100",
 "S01111"};
			double Arr3[] = {0.8, 0.4, 0.4, 0.2, 0.2 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 3;
			string Arr2[] = {"S100001100",
 "F011110000",
 "F001000010",
 "F100010101",
 "S010010001",
 "F100001010",
 "F000100100"};
			double Arr3[] = {0.3, 0.1, 0.4, 0.5, 0.2, 0.1, 0.6, 0.7, 0.1 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 2;
			string Arr2[] = { "S100001100" };
			double Arr3[] = { 0.4, 0.4, 0.4, 0.4, 0.4 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Resistance ___test;
	___test.run_test(-1);
}
// END CUT HERE
