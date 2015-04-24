// BEGIN CUT HERE
/*
SRM 656 Div2 Medium (500)

PROBLEM STATEMENT

Charlie has N pancakes.
He wants to serve some of them for breakfast.
We will number the pancakes 0 through N-1.
For each i, pancake i has width i+1 and deliciousness d[i].

Charlie chooses the pancakes he is going to serve using the following randomized process:
He starts by choosing the first pancake uniformly at random from all the pancakes he has.
He places the chosen pancake onto a plate.
This pancake now forms the bottom of a future stack of pancakes.
Then, Charlie repeats the following procedure:

If there are no more pancakes remaining, terminate.
Choose a pancake uniformly at random from the pancakes that have not been chosen yet.
If the width of this pancake is greater than the width of the pancake on top of the stack, terminate without taking it.
Place the chosen pancake on top of the stack and go back to step 1.

You are given the vector <int> d with N elements.
The total deliciousness of a serving of pancakes is the sum of the deliciousness of all pancakes used in the serving.
Compute and return the expected value of the total deliciousness of the pancakes chosen by Charlie.


DEFINITION
Class:RandomPancakeStackDiv2
Method:expectedDeliciousness
Parameters:vector <int>
Returns:double
Method signature:double expectedDeliciousness(vector <int> d)


NOTES
-Your return value must have an absolute or relative error smaller than or equal to 1e-6


CONSTRAINTS
-The number of elements in d will be between 1 and 10, inclusive.
-Each element of d will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,1,1}

Returns: 1.6666666666666667

The following scenarios may occur:

With probability 1/3, Charlie chooses pancake 0 first. In this case he won't be able to add any more pancakes and the total deliciousness of his serving of pancakes will be 1.
With probability 1/3, Charlie chooses pancake 1 first. What happens in the second round? With probability 1/2 he will choose pancake 0 and with probability 1/2 it will be pancake 2. In the first case the total deliciousness of Charlie's pancakes will be 2, in the second case it will be 1.
With probability 1/3, Charlie chooses pancake 2 first. If he chooses pancake 0 next, the total deliciousness of his pancakes will be 2. If he happens to choose pancake 1 next (followed by pancake 0 in the third round), the total deliciousness will be 3.

Summing this up, we get the expected deliciousness to be 1/3 * (1) + 1/3 * (1/2 * 1 + 1/2 * 2) + 1/3 * (1/2 * 2 + 1/2 * 3) = 5/3 = 1.666...

1)
{10,20}

Returns: 20.0


2)
{3,6,10,9,2}

Returns: 9.891666666666667


3)
{10,9,8,7,6,5,4,3,2,1}

Returns: 10.999999724426809


4)
{1,2,3,4,5,6,7,8,9,10}

Returns: 7.901100088183421


5)
{1,1,1,1,1,1,1,1,1,1}

Returns: 1.7182818011463845

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

class RandomPancakeStackDiv2 {
public:
	double expectedDeliciousness(vector <int> d) {
		int N = (int)d.size();
		int seq[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		double a = 0, b = 0;
		do {
			b += 1;
			for (int i = 0; i < N; ++i) {
				if (i > 0 && seq[i] >= seq[i - 1]) {
					break;
				}
				a += d[seq[i]];
			}
		} while (next_permutation(seq, seq + N));
		return a / b;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			double Arg1 = 1.6666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,20};
			double Arg1 = 20.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,10,9,2};
			double Arg1 = 9.891666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,8,7,6,5,4,3,2,1};
			double Arg1 = 10.999999724426809;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			double Arg1 = 7.901100088183421;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
			double Arg1 = 1.7182818011463845;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomPancakeStackDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
