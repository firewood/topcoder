// BEGIN CUT HERE
/*
// SRM 561 Div2 Easy (250)

問題
-それぞれの都市の滞在日数が与えられる
-総滞在日数でいくつの都市に訪問できるか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndVacation {

public:
	int maxCities(int total, vector <int> d) {
		sort(d.begin(), d.end());
		int res = 0;
		int t = 0;
		int i;
		for (i = 0; i < (int)d.size(); ++i) {
			if ((t+d[i]) <= total) {
				t += d[i];
				++res;
			}
		}
		return res;
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
			int Arg0 = 5;
			int Arr1[] = {2,2,2};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {5,6,1};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {6,6,6};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {1,1,1,1,1};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {7,1,5,6,1,3,4};
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int Arg2 = 9;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 21;
			int Arr1[] = {14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14};
			int Arg2 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndVacation ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
