// BEGIN CUT HERE
/*
SRM 569 Div1 Medium (500)

問題
何階建てかの建物に、ジェダイの素質を持った子供がいる。
ジェダイの騎士は最大K人まで面倒を見ることができる。
子供は上下に1階だけ移動できる。
必要なジェダイの騎士の数を求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheJediTest {
public:
	int minimumSupervisors(vector <int> students, int K) {
		int ans = 0, sz = (int)students.size();
		int i, j, k, l;
		students.push_back(0);
		students.push_back(0);
		for (i = 1; i <= sz; ++i) {
			j = students[i-1];
			ans += j / K;
			j %= K;
			if (j) {
				++ans;
				k = min(K - j, students[i]);
				students[i] -= k;
				l = min(K - j - k, students[i+1]);
				students[i+1] -= l;
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
			int Arr0[] = {3, 6, 3};
			int Arg1 = 4;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1};
			int Arg1 = 4;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0};
			int Arg1 = 12345;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {15, 0, 13, 4, 29, 6, 2};
			int Arg1 = 7;
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
			int Arg1 = 114;
			int Arg2 = 102138;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {29541663, 85732198, 69829763, 77760462, 32153432, 79240058, 13641353, 50236888, 83780217, 82884996, 5909451, 68242201, 64320036, 82420030, 16758585, 12089161, 92006984, 90761986};
			int Arg1 = 67854681;
			int Arg2 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {99203485, 17324730, 5410737, 11860563, 34237187, 11126721, 56157622, 48960271, 3684793};
			int Arg1 = 1725617;
			int Arg2 = 167;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimumSupervisors(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheJediTest ___test;
	___test.run_test(-1);
}
// END CUT HERE
