// BEGIN CUT HERE
/*
SRM 636 Div2 Medium (500)

PROBLEM STATEMENT
Everyone likes some sequences more than others.
Every person has their own function which tells them how good a sequence is.
For example, for some people this function could simply be the count of negative numbers in the sequence.

Jezalb's most favorite sequences are ones that are sorted in increasing order.
When he sees a sequence S, he immediately calculates the number of pairs of indexes i < j such that S[i] < S[j].
He calls this number the "sortedness" of S.

This morning Jezalb entered a classroom and saw a permutation of 1 through N on the blackboard.
He quickly calculated its sortedness.
He then left the classroom and forgot the permutation.
He only remembered the sortedness he computed.
You are given this value in a int sortedness. 

Later that day Jezalb reentered the classroom and saw a sequence on the blackboard.
The sequence was a permutation of 1 through N, but with some elements erased.
You are given this sequence as a vector <int> seq with N elements.
Some of the elements in seq may be 0, which indicates an erased number.

Jezalb thinks that the sequence seq may have been obtained by erasing some elements of the sequence he saw during his first visit to the classroom.
He would like to restore the erased elements.

You are given the int sortedness and the vector <int> seq.
Return the number of ways in which he can fill in the missing elements into seq in such a way that the sortedness of the obtained permutation will be exactly sortedness.


DEFINITION
Class:SortishDiv2
Method:ways
Parameters:int, vector <int>
Returns:int
Method signature:int ways(int sortedness, vector <int> seq)


CONSTRAINTS
-sortedness will be between 0 and 1,000,000,000, inclusive. 
-seq will contain between 1 and 100 elements, inclusive. 
-Elements in seq will be between 0 and number of elements in seq, inclusive. 
-Positive elements in seq will be distinct. 
-Number of elements equal to 0 in seq will be between 0 and 5, inclusive.


EXAMPLES

0)
5
{4, 0, 0, 2, 0}

Returns: 2

There are six ways to fill in the missing elements. Out of those six permutations, only two have sortedness 5: {4, 1, 5, 2, 3} and {4, 3, 1, 2, 5}.


1)
4
{0, 0, 0, 0}

Returns: 5

All 5 possible ways are: {1, 3, 4, 2}, {1, 4, 2, 3}, {2, 1, 4, 3}, {2, 3, 1, 4}, {3, 1, 2, 4}.


2)
2
{1, 3, 2}

Returns: 1

There are no gaps and sortedness is indeed equal to 2.


3)
2
{1, 2, 0, 5, 0, 0}

Returns: 0

Regardless of how he fills in the gaps, the sortedness of the resulting permutation will always be greater than 2.

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;
typedef vector<int> IntVec;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
//		++i;
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
//		++i;
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

class SortishDiv2 {
public:
	int ways(int sortedness, vector <int> seq) {
		int ans = 0;
		int N = (int)seq.size();
		int zi[128] = {};
		int zc = 0;
		IntSet r;
		for (int i = 1; i <= N; ++i) {
			r.insert(i);
		}
		for (int i = 0; i < N; ++i) {
			r.erase(seq[i]);
			if (!seq[i]) {
				zi[zc++] = i;
			}
		}
		IntVec v(r.begin(), r.end());
		do {
			BIT b(128);
			for (int i = 0; i < zc; ++i) {
				seq[zi[i]] = v[i];
			}
			int cnt = 0;
			for (int i = 0; i < N; ++i) {
				cnt += b.sum(seq[i]);
				b.add(seq[i], 1);
			}
			ans += cnt == sortedness;
		} while (zc && next_permutation(v.begin(), v.end()));
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
			int Arg0 = 5;
			int Arr1[] = {4, 0, 0, 2, 0};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {0, 0, 0, 0};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 3, 2};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 2, 0, 5, 0, 0};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SortishDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
