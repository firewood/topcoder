// BEGIN CUT HERE
/*
// SRM 538 Div2 Hard (1050)

問題
3色のブロックと、1x2の大きさの黒いブロックがある
幅w以内で縦に積む
横から見たときの図が与えられる
その図になるように積めるかどうかを求める

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

class SkewedPerspectives {

	bool possible(IntVec cubes, int B, int w, const string &view) {
		IntVec v;
		int i, j, k;
		for (i = 0; i < (int)view.length(); ++i) {
			if (view[i] != 'b') {
				if (--cubes[view[i]-'0'] < 0) {
					return false;
				}
				continue;
			}

			for (j = 0; view[i+j] == 'b'; ++j) {
				;
			}
			B -= (j + 1) / 2;
			if ((j % 2) == 0) {
				i += j - 1;
				continue;
			}

			if (i == 0) {
				if (j == 1) {
					return false;
				}
				v.push_back(1);
			} else {
				v.push_back(i-1);
			}
			i += j - 1;
		}

		for (i = 0; i < (int)v.size(); ++i) {
			while (v[i] >= 2 && B > 0) {
				v[i] -= 2;
				--B;
			}
			for (j = 0; v[i] > 0 && j < 3; ++j) {
				k = min(v[i], cubes[j]);
				v[i] -= k;
				cubes[j] -= k;
			}
			if (v[i] > 0) {
				return false;
			}
		}

		return B >= 0 && v.size() < w;
	}

public:
	vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
		vector <string> res;
		for (int i = 0; i < (int)views.size(); ++i) {
			res.push_back(possible(cubes, B, w, views[i]) ? "valid" : "invalid");
		}
		return res;
	}

	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arg1 = 1;
			int Arg2 = 2;
			string Arr3[] = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" };
			string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "valid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,0};
			int Arg1 = 3;
			int Arg2 = 2;
			string Arr3[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" };
			string Arr4[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,0,0};
			int Arg1 = 20;
			int Arg2 = 3;
			string Arr3[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"};
			string Arr4[] = {"valid", "valid", "valid", "valid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,6,3};
			int Arg1 = 0;
			int Arg2 = 1;
			string Arr3[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"};
			string Arr4[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,100,100};
			int Arg1 = 100;
			int Arg2 = 50;
			string Arr3[] = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
};
			string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0};
			int Arg1 = 0;
			int Arg2 = 1;
			string Arr3[] = {"0", "bb"};
			string Arr4[] = {"invalid", "invalid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,0,0};
			int Arg1 = 4;
			int Arg2 = 3;
			string Arr3[] = {"00b0b", "bbbbbbbb", "000b"};
			string Arr4[] = {"invalid", "valid", "valid" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_26
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {61, 23, 39};
			int Arg1 = 11;
			int Arg2 = 4;
			string Arr3[] = {"00bbbb1bb202102020220020022200000000000", "2011bb11bb20221202202200020000200020000000000000", "02b02b2b200b0002100101b000010b02b210120b00", "0200bb210022001002122220220000000000220000000", "bb20220002112021102200000000002000000220000000", "0221200200002101120000001200200000020000", "101bb201122201220121022000000000000000000000", "102202202110110002020000002022000000200000", "01112bb2bb012102210121002000200000000000000", "0000000b0020002011b0100001b022bbb200021010", "100010b20200200000002202220000021000b22200", "0001001bbbb12202220000000220022000000000000", "bb0001000212000000b010000202200000000022000b000020", "22bb12110020200000202000000022000220000000", "200b0200002220000b0bbb1222000202210b100", "02001202000b200b020010b2020002200b210120000100220", "0002221bb11201212022002000000000000000000200000", "1000201112112010220102200000000000000200000000000", "0202bbbb01012221202220200000000000000000000", "b1020020b002120b0b0100b0010020002001121000b"};
			string Arr4[] = {"valid", "valid", "invalid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "valid", "valid", "valid", "valid", "invalid", "invalid", "valid", "valid", "valid", "invalid"};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SkewedPerspectives ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
