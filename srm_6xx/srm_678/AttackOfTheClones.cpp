// BEGIN CUT HERE
/*
SRM 678 Div2 Medium (500)

問題
-はるかな銀河の彼方で...一週間はN日からなる
-オビワンはN種類のシャツを1枚ずつ持っている
-各週において、毎日違うシャツを着る
-シャツは洗濯する必要があり、同じシャツはN-1日後以降にしか着られない
-最初の週のシャツを着る順番と、最後の週のシャツを着る順番が与えられる
-条件を満たすための週の総数の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AttackOfTheClones {
public:
	int count(vector <int> firstWeek, vector <int> lastWeek) {
		int a[2560], b[2560], d[2560];
		int N = (int)firstWeek.size();
		for (int i = 0; i != N; ++i) {
			a[firstWeek[i] - 1] = i;
			b[lastWeek[i] - 1] = i;
		}
		for (int i = 0; i != N; ++i) {
			d[i] = b[i] + N - a[i];
		}
		int m = *min_element(d, d + N);
		return N - m + 1;
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
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {4,3,2,1};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {1,2,3,4};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,4,5,1,7,6,2,3};
			int Arr1[] = {2,4,6,8,1,3,5,7};
			int Arg2 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AttackOfTheClones ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
