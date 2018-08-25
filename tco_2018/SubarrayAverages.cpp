// BEGIN CUT HERE
/*
TCO18 R2B Easy (250)

問題
-数値の配列が与えられる
-任意の連続する範囲を選んで、その範囲の数値を、平均値で置き換えることができる
-0回以上任意の回数操作するとき、辞書順最小のものを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SubarrayAverages {
public:
	vector <double> findBest(vector <int> arr) {
		int n = (int)arr.size();
		vector <double> ans(arr.begin(), arr.end());
		for (int i = 0; i < n; ++i) {
			double sum = ans[i], mavg = sum;
			int mj = -1;
			for (int j = i + 1; j < n; ++j) {
				sum += ans[j];
				double avg = sum / (j - i + 1);
				if (avg < mavg + 1e-10) {
					mj = j;
					mavg = avg;
				}
			}
			for (int j = i; j <= mj; ++j) {
				ans[j] = mavg;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) {
		cerr << "Test Case #" << Case << "...";
		double sum = 0;
		for (int i = 0; i != Expected.size(); ++i) {
			sum += fabs(Expected[i] - Received[i]);
		}
		if (fabs(sum) <= 1e-6) {
			cerr << "PASSED" << endl;
		} else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: " << print_array(Expected) << endl;
			cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9};
			double Arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,6,5,4,3,2,1};
			double Arr1[] = {4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,1,2}
;
			double Arr1[] = {1.0, 1.5, 1.5, 2.0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,10,1,1,1,1,10}
;
			double Arr1[] = {1.0, 2.8, 2.8, 2.8, 2.8, 2.8, 10.0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
;
			double Arr1[] = {4.0, 5.0, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000}
;
			double Arr1[] = {1000000.0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9450,7098,6048,1050,672,8232,5028,
672,672,42,42,42,42,42,9450,6048,
3402,3402,2688,9450,7098,6048,1050,
672,8232,5028,672,672,9450,6048,3402};
			double Arr1[] = {2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 6300.0, 6300.0, 6300.0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubarrayAverages ___test;
	___test.run_test(-1);
}
// END CUT HERE
