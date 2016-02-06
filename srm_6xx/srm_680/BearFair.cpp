// BEGIN CUT HERE
/*
SRM 680 Div1 Easy (250)

問題
-森で熊に出会った
-熊が配列Xに関するクイズを出す
-Xの要素は全て異なる
-Xはn個の数値からなり、nは偶数である
-Xの全ての要素は1以上b以下である
-Xの半分は偶数で半分は奇数である
-q個のヒントが与えられる
-Xの要素のうちupTo[i]以下の個数はquantity[i]個である
-熊が嘘をついているかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class BearFair {
public:
	bool check(int n, int b, vector <int> &upTo, vector <int> &quantity) {
		IIVec v(1, II(0,0));
		for (int i = 0; i != upTo.size(); ++i) {
			v.push_back(II(upTo[i], quantity[i]));
		}
		v.push_back(II(b, n));
		sort(v.begin(), v.end());
		int cnt[2] = {};
		for (int i = 1; i != v.size(); ++i) {
			int last_u = v[i - 1].first, u = v[i].first;
			int last_q = v[i - 1].second, q = v[i].second;
			int d = q - last_q;
			if (last_u == u) {
				if (last_q != q) {
					return false;
				}
				continue;
			}
			if (d < 0 || (u - last_u) < d) {
				return false;
			}
			int t[2] = {};
			for (int j = last_u + 1; j <= u; ++j) {
				t[j % 2] += 1;
			}
			cnt[0] += min(t[0], d);
			cnt[1] += min(t[1], d);
		}
		return cnt[0] >= n / 2 && cnt[1] >= n / 2;
	}

	string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
		return check(n, b, upTo, quantity) ? "fair" : "unfair";
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
			int Arg0 = 4;
			int Arg1 = 6;
			int Arr2[] = {3,6};
			int Arr3[] = {2,4};
			string Arg4 = "fair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arr2[] = {3,6};
			int Arr3[] = {2,3};
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 6;
			int Arr2[] = {1,2,3};
			int Arr3[] = {1,1,2};
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 1000;
			int Arr2[] = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357};
			int Arr3[] = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
			string Arg4 = "fair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = {400,600};
			int Arr3[] = {4,0};
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = { 400, 400 };
			int Arr3[] = { 4, 5 };
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = { 998, 999 };
			int Arr3[] = { 2, 3 };
			string Arg4 = "fair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1000;
			int Arr2[] = { 998, 999 };
			int Arr3[] = { 1, 2 };
			string Arg4 = "unfair";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearFair ___test;
	___test.run_test(-1);
}
// END CUT HERE
