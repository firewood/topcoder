// BEGIN CUT HERE 
/*
// SRM 505 Div2 Middle
// PROBLEM STATEMENT
// A perfect sequence is a sequence such that all of its elements are non-negative integers and the product of all of them is equal to their sum. For example: {2,2}, {1,3,2} and {0,0,0,0} are perfect sequences and {4,5,6} and {0,2,-2} are not perfect sequences (4*5*6 is not equal to 4+5+6, and negative numbers are not allowed by the definition).

You are given a vector <int> seq. Return "Yes" if it is possible to change exactly one element of seq so that the resulting sequence is perfect. Otherwise, return "No".



DEFINITION
Class:PerfectSequences
Method:fixIt
Parameters:vector <int>
Returns:string
Method signature:string fixIt(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 0 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{1,3,4}

Returns: "Yes"

If we change the last element to 2, we have {1,3,2}.
1+3+2 = 1*3*2.

1)
{1,2,3}

Returns: "No"

This sequence is already perfect and it is not possible to change exactly one of its elements and keep it perfect.

2)
{1,4,2,4,2,4}

Returns: "No"



3)
{1000000,1,1,1,1,2}

Returns: "Yes"

It is possible to replace 1000000 with 6 to make the sequence become perfect.

4)
{8}

Returns: "Yes"

It is possible to change the first element to any non-negative number and the sequence will stay perfect.

5)
{2,0,2}

Returns: "No"

Note that {2,0,-2} is not considered a perfect sequence because negative numbers are not allowed by the definition.

*/
#line 71 "PerfectSequences.cpp"
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;

class PerfectSequences {
	public:
	string fixIt(vector <int> seq) {
		if (seq.size() <= 1) {
			return "Yes";
		}
		if (isPerfect(seq)) {
			return "No";
		}

		sort(seq.begin(), seq.end());

		int prev = -1;
		size_t i;
		for (i = 0; i < seq.size(); ++i) {
			if (prev == seq[i]) {
				continue;
			}
			prev = seq[i];
			double sum;
			double product;
			if (!calc(seq, 0, seq.size(), i, sum, product)) {
				continue;
			}

			// (product * x) == (sum + x)
			// (product * x) - x == sum
			// x * (product - 1) == sum
			// x == sum / (product - 1)
			if (sum < 1 && product < 1) {
				// all zero
				return "Yes";
			}
			if (product < 2) {
				// div by zero
				continue;
			}
			double d = sum / (product - 1);
			int x = (int)d;
			sum += x;
			product *= x;
			if (sum == product) {
				return "Yes";
			}
		}

		return "No";
	}

	bool calc(const VI &seq, size_t start, size_t end, size_t skip, double &sum, double &product) {
		sum = 0;
		product = 1;
		while (start < end) {
			if (start != skip) {
				sum += seq[start];
				product *= seq[start];
				if (sum > 1000000000 || product > 1000000000) {
					sum = -1;
					return false;
				}
			}
			++start;
		}
		return true;
	}
	bool isPerfect(const VI &seq) {
		if (seq.size() < 1) {
			return false;
		}
		double sum, product;
		calc(seq, 0, seq.size(), seq.size(), sum, product);
		return sum == product;
	}
};

// BEGIN CUT HERE 
static void Test(const char *seq)
{
	char buffer[1000];
	strcpy(buffer, seq);
	vector <int> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		int var = atoi(p);
//		if (var) {
			v.push_back(var);
//		}
		p = strtok(NULL, " ,");
	}
	PerfectSequences ___test;
	string result = ___test.fixIt(v);
	printf("result: %s, seq: %s\n", result.c_str(), seq);
}

int main() {
//	Test("1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 17");
//	Test("3,3,1,1,4");
	Test("2,0,2");
//	Test("0, 0, 0, 1000000000, 1000000000, 0, 0, 0, 0, 0, 1000000000");

	return 0;
}
// END CUT HERE
