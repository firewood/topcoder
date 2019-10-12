// BEGIN CUT HERE
/*
SRM 768 Div1 Easy (250)

PROBLEM STATEMENT

Bear Limak has just started a new year at school.
The school teaches N subjects.
At the end of the year Limak will get a grade for each of the subjects.
Each grade will be an integer between 0 (worst) and 10 (best), inclusive.

The grade for each subject depends on the number of days Limak will spend studying that subject.
If he does not study a subject at all, his grade for that subject will be 0.
Each subject has its own difficulty rating d[i]: each d[i] days spent studying the subject will increase Limak's grade by 1 (up to a maximum of 10, of course).

Note that these increases are discrete.
E.g., if Limak spends d[i]-1 days studying subject i, his grade will still be 0.

Limak's parents are quite strict.
Each of them has made a request:

Mama bear told Limak that his mean grade must be at least needMean.
Papa bear told Limak that his median grade must be at least needMedian.

Compute and return the smallest possible number of days of studying Limak needs in order to satisfy the requests of both parents.


DEFINITION
Class:MeanMedian
Method:minEffort
Parameters:int, int, vector <int>
Returns:int
Method signature:int minEffort(int needMean, int needMedian, vector <int> d)


NOTES
-The mean of N values is their sum divided by N. (The mean can be non-integer.)
-The median of N values is the middle element of a sorted list of all those values. (In this problem, N is always odd and thus the middle element always exists.)


CONSTRAINTS
-needMean will be between 0 and 10, inclusive.
-needMedian will be between 0 and 10, inclusive.
-N (the number of elements in d) will be between 1 and 49, inclusive.
-N will be odd.
-Each element in d will be between 1 and 1000, inclusive.


EXAMPLES

0)
2
4
{30, 25, 20}

Returns: 180

There are three subjects at school.
Limak's grades should have mean at least 2 and median at least 4.
The only optimal solution is to study subject 0 for 0 days, subject 1 for 4*25 = 100 days and subject 2 for 4*20 = 80 days.
Afterwards, Limak's grades will be {0, 4, 4}.
Their mean is 8/3 (which is more than we need) and their median is 4 (which is exactly what we need).


1)
4
4
{30, 25, 20}

Returns: 260

Limak should get grades 0, 4, 8. The mean is exactly 4 and so is the median. The answer is 4*25+8*20=260.


2)
10
3
{1, 4, 3, 2, 1}

Returns: 110


3)
0
0
{1000}

Returns: 0


4)
8
3
{4, 8, 12, 16, 18, 20, 22, 23, 24}

Returns: 1046

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MeanMedian {
public:
	int minEffort(int needMean, int needMedian, vector <int> d) {
		int n = (int)d.size(), r = needMean * n, ans = 0;
		sort(d.begin(), d.end());
		vector<int> v(n);
		for (int i = 0; i <= n / 2; ++i) {
			r -= needMedian;
			v[i] = needMedian;
			ans += d[i] * needMedian;
		}
		for (int i = 0; i < n; ++i) {
			while (r > 0 && v[i] < 10) {
				--r;
				v[i] += 1;
				ans += d[i];
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
			int Arg0 = 2;
			int Arg1 = 4;
			int Arr2[] = {30, 25, 20};
			int Arg3 = 180;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minEffort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arr2[] = {30, 25, 20};
			int Arg3 = 260;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minEffort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 3;
			int Arr2[] = {1, 4, 3, 2, 1};
			int Arg3 = 110;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minEffort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arr2[] = {1000};
			int Arg3 = 0;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minEffort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 3;
			int Arr2[] = {4, 8, 12, 16, 18, 20, 22, 23, 24};
			int Arg3 = 1046;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minEffort(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MeanMedian ___test;
	___test.run_test(-1);
}
// END CUT HERE
