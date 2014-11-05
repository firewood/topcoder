// BEGIN CUT HERE
/*
SRM 638 Div2 Medium (500)

PROBLEM STATEMENT
There is a narrow passage.
Inside the passage there are some wolves.
You are given a vector <int> size that contains the sizes of those wolves, from left to right.

The passage is so narrow that some pairs of wolves cannot pass by each other.
More precisely, two adjacent wolves may swap places if and only if the sum of their sizes is maxSizeSum or less.
Assuming that no wolves leave the passage, what is the number of different permutations of wolves in the passage?
Note that two wolves are considered different even if they have the same size.

Compute and return the number of permutations of wolves that can be obtained from their initial order by swapping a pair of wolves zero or more times.


DEFINITION
Class:NarrowPassage2Easy
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> size, int maxSizeSum)


CONSTRAINTS
-size will contain between 1 and 6 elements, inclusive.
-Each element in size will be between 1 and 1,000, inclusive.
-maxSizeSum will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1, 2, 3}
3

Returns: 2

From {1, 2, 3}, you can swap 1 and 2 to get {2, 1, 3}. But you can't get other permutations.


1)
{1, 2, 3}
1000

Returns: 6

Here you can swap any two adjacent wolves. Thus, all 3! = 6 permutations are possible.


2)
{1, 2, 3}
4

Returns: 3

You can get {1, 2, 3}, {2, 1, 3} and {2, 3, 1}.


3)
{1,1,1,1,1,1}
2

Returns: 720

All of these wolves are different, even though their sizes are the same. Thus, there are 6! different permutations possible.


4)
{2,4,6,1,3,5}
8

Returns: 60


5)
{1000}
1000

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NarrowPassage2Easy {
public:
	int count(vector <int> size, int maxSizeSum) {
		int N = (int)size.size();
		int seq[] = {0,1,2,3,4,5};
		int ans = 1;
		while (next_permutation(seq, seq + N)) {
			int f = 1;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < i; ++j) {
					if (seq[i] < seq[j] && size[seq[i]]+size[seq[j]]>maxSizeSum) {
						f = 0;
					}
				}
			}
			ans += f;
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
			int Arr0[] = {1, 2, 3};
			int Arg1 = 3;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arg1 = 1000;
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arg1 = 4;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arg1 = 2;
			int Arg2 = 720;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,4,6,1,3,5};
			int Arg1 = 8;
			int Arg2 = 60;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000};
			int Arg1 = 1000;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NarrowPassage2Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
