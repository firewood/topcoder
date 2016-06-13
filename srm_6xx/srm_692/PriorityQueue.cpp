// BEGIN CUT HERE
/*
SRM 692 Div2 Easy (250)

問題
-N人の生徒がいて、食堂に一人ずつ入ってくる
-入ってきた生徒は、列の末尾に並ぶ(e)か、または、列の先頭に横入りする(b)
-生徒iが抜かされた場合に感じる不快度D[i]が与えられる
-不快度の総量を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PriorityQueue {
public:
	int findAnnoyance(string S, vector <int> a) {
		int ans = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			if (S[i] == 'b') {
				ans += accumulate(a.begin(), a.begin() + i, 0);
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
			string Arg0 = "bbbbb";
			int Arr1[] = {1,1,1,1,1};
			int Arg2 = 10;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bee";
			int Arr1[] = {50,40,30};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ebbe";
			int Arr1[] = {5,2,11,1};
			int Arg2 = 12;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbeebeebeeeebbb";
			int Arr1[] = {58,517,301,524,79,375,641,152,810,778,222,342,911,313,336};
			int Arg2 = 20485;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PriorityQueue ___test;
	___test.run_test(-1);
}
// END CUT HERE
