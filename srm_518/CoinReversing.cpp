// BEGIN CUT HERE
/*
// SRM 518 Div2 Hard (1000)
// PROBLEM STATEMENT
// You initially have N coins on the table, all with heads up. 
Given vector <int> a containing K integers, you first randomly choose a[0] coins and reverse them
(from head to tail, or from tail to head), then randomly choose a[1] coins and reverse them, ...,
and finally randomly choose a[K-1] coins and reverse them. 
Calculate and return the expected number of heads after these operations.

DEFINITION
Class:CoinReversing
Method:expectedHeads
Parameters:int, vector <int>
Returns:double
Method signature:double expectedHeads(int N, vector <int> a)


NOTES
-When you choose a specified number (say x) of coins,
each combination of x coins has the same probability of being chosen. 
-The returned value must have an absolute or relative error less than 1e-9. 


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-Each element in a will be between 1 and N, inclusive.


EXAMPLES

0)
3
{2,2}

Returns: 1.6666666666666667

You first reverse 2 coins from heads to tails. Then you randomly choose 2 coins and reverse them.
There are two possible situations that can occur on the second operation: 

Choosing 2 tails (which occurs with probability 1/3): it results in 3 heads. 
Choosing 1 head and 1 tail (which occurs with probability 2/3): it results in 1 head. 

So the expected number of heads is 1/3*3+2/3*1=5/3. 

1)
10
{10,10,10}

Returns: 0.0

You reverse every coin three times, so after the operations there will be 10 tails and no heads. 

2)
10
{2,7,1,8,2,8}

Returns: 4.792639999999999



3)
1000
{916,153,357,729,183,848,61,672,295,936}

Returns: 498.1980774932278



#line 68 "CoinReversing.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef map<int, int> IntMap;

class CoinReversing {
	public:
	double expectedHeads(int N, vector <int> a) {
		double result = N;
		int i;
		for (i = 0; i < (int)a.size(); ++i) {
			double turns = a[i];
			double remains = N - turns;

			double cur_up = result;
			double cur_down = N - result;

			double tr = turns / N;
			double rr = remains / N;

			double up = cur_up * rr + cur_down * tr;
			result = up;
		}

		return result;
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(int N, const char *seq, double expected)
{
	vector <int> v = getVector<int>(seq);
	CoinReversing ___test;
	double result = ___test.expectedHeads(N, v);
	printf("result: %s, %.6f\n", fabs(result - expected) < 0.000001 ? "OK" : "FAILED", result);
}

int main() {
	Test(3, "2,2", 1.6666666666666667);
	Test(10, "10,10,10", 0.0);
	Test(1000, "916,153,357,729,183,848,61,672,295,936", 498.1980774932278);
	return 0;
}
// END CUT HERE
