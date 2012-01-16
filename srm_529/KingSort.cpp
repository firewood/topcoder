// BEGIN CUT HERE
/*
// SRM 529 Div2 Medium (500)

問題

王様の名前を辞書順に並べたい。
名前＋代(ローマ数字) になっている。
名前でソートした上で、代については数値順に並べよ。

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

typedef vector<string> StrVec;
typedef map<string, string> StrMap;

static const char *roman1[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
static const char *roman10[] = {"", "X", "XX", "XXX", "XL", "L"};

class KingSort {

public:
	vector <string> getSortedList(vector <string> kings) {
		StrMap r2n;
		StrMap n2r;
		int i;
		for (i = 1; i <= 50; ++i) {
			int a = i / 10;
			int b = i % 10;
			string s;
			s += roman10[a];
			s += roman1[b];
			char d[16];
			sprintf(d, "%02d", i);
			r2n[s] = d;
			n2r[d] = s;
		}

		StrVec res;
		for (i = 0; i < (int)kings.size(); ++i) {
			char temp[256];
			strcpy(temp, kings[i].c_str());
			char *p = strchr(temp, ' ');
			if (p) {
				++p;
				StrMap::const_iterator it = r2n.find(p);
				if (it != r2n.end()) {
					strcpy(p, it->second.c_str());
				}
			}
			res.push_back(temp);
		}

		sort(res.begin(), res.end());
		for (i = 0; i < (int)kings.size(); ++i) {
			char temp[256];
			strcpy(temp, res[i].c_str());
			char *p = strchr(temp, ' ');
			if (p) {
				++p;
				StrMap::const_iterator it = n2r.find(p);
				if (it != n2r.end()) {
					strcpy(p, it->second.c_str());
				}
			}
			res[i] = temp;
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
			string Arr0[] = {"Louis IX", "Louis VIII"};
			string Arr1[] = {"Louis VIII", "Louis IX" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getSortedList(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Louis IX", "Philippe II"};
			string Arr1[] = {"Louis IX", "Philippe II" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getSortedList(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Richard III", "Richard I", "Richard II"};
			string Arr1[] = {"Richard I", "Richard II", "Richard III" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getSortedList(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"John X", "John I", "John L", "John V"};
			string Arr1[] = {"John I", "John V", "John X", "John L" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getSortedList(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
			string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getSortedList(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Philippe II", "Philip II"};
			string Arr1[] = {"Philip II", "Philippe II" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getSortedList(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingSort ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
