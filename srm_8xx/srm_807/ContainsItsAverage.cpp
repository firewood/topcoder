// BEGIN CUT HERE
/*
SRM 807 450

PROBLEM STATEMENT

In this problem we are interested in sequences of integers that contain their own average.

For example, the sequence {1, 2, 3, 4, 5} is such a sequence: its average is (1+2+3+4+5) / 5 = 3, and 3 is indeed an element of the sequence.

The sequence {0, 0, 0, 0} does also contain its own average. (In this case, all four elements are equal to the average of the sequence.)
The sequence {1, 2, 3, 4, 5, 0, -15} is also such a sequence: its average is 0 and that is one of the elements of the sequence.
The sequence {1, 1, 2, 3, 5, 4} does not contain its own average: its average is 8/3 = 2.6666666 and that is not an element of this sequence (and not an integer).
The sequence {10, 20, 30, 40} has an integer average (25) but 25 is not an element of this sequence, so we are not interested in this sequence either.

Ela has shown you N-1 elements of her N-element sequence.
The values she has shown you are in the vector <int> seq.

Ela claims that the missing element is also an integer and that her sequence contains its own average.

Given that information, you now want to find the last element X of Ela's sequence.

If there are at most 100 different possible values of X, return a vector <int> with all possible values of X, sorted in ascending order.
Otherwise, return an empty vector <int>.


DEFINITION
Class:ContainsItsAverage
Method:missing
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> missing(vector <int> seq)


NOTES
-Only the elements in the input must be between 0 and 20,000,000, inclusive. The missing element may lie outside this range. (See Example #1.)
-It is guaranteed that for each input that matches the constraints each valid X fits into a 32-bit signed integer variable.


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 0 and 20,000,000, inclusive.


EXAMPLES

0)
{0, 0, 0}

Returns: {0 }


The only option is that the missing element is also 0. As we already know, the sequence {0, 0, 0, 0} does contain its average.


For any other X, the sequence will be {0, 0, 0, X}, its average will be X/4, and that's clearly not an element of the sequence.


1)
{1, 10, 1000, 100}

Returns: {-1106, -1061, -611, 3889 }

The sequence {1, 10, 1000, 100, -1106} has the average (1 + 10 + 1000 + 100 + (-1106)) / 5 = 5/5 = 1. And as 1 is one of the five elements of {1, 10, 1000, 100, -1106}, this sequence does contain its own average.

We can easily verify that each of the other three options for X also produces a sequence that contains its own average.

Please remember that the returned array must be sorted.


2)
{500000, 400000, 200000, 100000}

Returns: {-700000, -200000, 300000, 800000, 1300000 }


3)
{47}

Returns: {47 }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ContainsItsAverage {
public:
	vector <int> missing(vector <int> seq) {
		vector <int> ans;
		int sum = accumulate(seq.begin(), seq.end(), 0);
		int avg = sum / seq.size();
		if (avg * seq.size() == sum) {
			ans.emplace_back(avg);
		}
		for (auto x : seq) {
			ans.emplace_back(x * (seq.size() + 1) - sum);
		}
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0};
			int Arr1[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, missing(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 10, 1000, 100};
			int Arr1[] = {-1106, -1061, -611, 3889 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, missing(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {500000, 400000, 200000, 100000};
			int Arr1[] = {-700000, -200000, 300000, 800000, 1300000 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, missing(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {47};
			int Arr1[] = {47 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, missing(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ContainsItsAverage ___test;
	___test.run_test(-1);
}
// END CUT HERE
