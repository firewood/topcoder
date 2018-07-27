// BEGIN CUT HERE
/*
TCO18 R2B Easy (250)

PROBLEM STATEMENT

Li Chen has an array of positive integers. You are given its initial state in the vector <int> arr.

Li Chen can modify the array by repeatedly performing the following operation: Choose a contiguous subarray, and replace all values in the subarray with their exact average.

For example, if the current array is {1, 3, 2, 4}, some ways to perform the next operation look as follows:

Li Chen can select the first three elements, obtaining the array {2, 2, 2, 4}.
Li Chen can select the middle two elements, obtaining the array {1, 2.5, 2.5, 4}.
Li Chen can select the entire array, obtaining the array {2.5, 2.5, 2.5, 2.5}.
Li Chen can select the last element only, which does not change the array.

Multiple operations may modify the same indices in the given array. For example, given the array {1, 4, 2} Li Chen may use one operation to change it to {1, 3, 3} and then another operation to change this array into {2, 2, 3}.

Find the lexicographically smallest array Li Chen can obtain by performing a sequence of zero or more operations.
Return a vector <double> with the elements of that array.
(See Notes for a more precise definition.)


DEFINITION
Class:SubarrayAverages
Method:findBest
Parameters:vector <int>
Returns:vector <double>
Method signature:vector <double> findBest(vector <int> arr)


NOTES
-Given two different arrays S and T with the same number of elements, the lexicographically smaller one is the one that has a smaller element at the first index at which they differ.
-Your answer will be accepted if each element of your return value has an absolute or a relative error at most 1e-9.


CONSTRAINTS
-arr will contain between 1 and 1,000 elements, inclusive.
-Each element of arr will be between 1 and 10^6, inclusive.


EXAMPLES

0)
{1,2,3,4,5,6,7,8,9}

Returns: {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 }

Here, Li Chen should leave the array unchanged.

1)
{7,6,5,4,3,2,1}

Returns: {4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0 }

In this case, Li Chen should perform one operation on the entire array.
Note that the subarray chosen for each operation has to be contiguous. For example, Li Chen is not allowed to change {7, 6, 5, 4, 3, 2, 1} into {3.25, 6, 5, 4, 3.25, 3.25, 3.25}.

2)
{1,2,1,2}


Returns: {1.0, 1.5, 1.5, 2.0 }



3)
{1,10,1,1,1,1,10}


Returns: {1.0, 2.8, 2.8, 2.8, 2.8, 2.8, 10.0 }



4)
{4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,1,1,1,1,1,1,1,1,1,1,1,1,1}


Returns: {4.0, 5.0, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846 }



5)
{1000000}


Returns: {1000000.0 }



6)
{9450,7098,6048,1050,672,8232,5028,
672,672,42,42,42,42,42,9450,6048,
3402,3402,2688,9450,7098,6048,1050,
672,8232,5028,672,672,9450,6048,3402}

Returns: {2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 6300.0, 6300.0, 6300.0 }



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
