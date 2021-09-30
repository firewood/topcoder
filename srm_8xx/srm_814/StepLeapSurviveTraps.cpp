// BEGIN CUT HERE
/*
SRM 814 Div2 Hard (1000)

PROBLEM STATEMENT

You have reached the final level of the game you are playing.
This level consists of N+1 blocks, numbered from 0 to N from the left to the right.
You start the level on block 0 and your goal is to reach block N exactly.

In this level, your character can make jumps of maximum length J.
The character may jump both to the left and to the right, as long as they never leave the level.

A jump of length x will skip over x-1 consecutive blocks and land on the next (x-th) one in the direction of the jump.
In particular, a jump of length 1 is simply a step to the next block on the left or on the right.

Block 0 is safe. All other blocks that form the level contain spiky traps that deal damage. More precisely, each time you land on block i, you receive T[i] damage.

Calculate and return the minimum total amount of damage you have to receive in order to reach block N.

In order to keep the input small, the damage is pseudorandom, as described below:

T[0] = 0
state = seed
for i = 1 to N:
    state = (state * 1103515245 + 12345) modulo 2^31
    T[i] = 1 + (state modulo M)


DEFINITION
Class:StepLeapSurviveTraps
Method:minDamage
Parameters:int, int, int, int
Returns:long long
Method signature:long long minDamage(int N, int J, int seed, int M)


NOTES
-The reference solution does not depend on the damages to be (pseudo)random, it would solve any input of the same size within the time limit.


CONSTRAINTS
-N will be between 1 and 500,000, inclusive.
-J will be between 1 and 500,000, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.
-M will be between 1 and 10^9, inclusive.


EXAMPLES

0)
8
3
47
10

Returns: 17


The damage for the cells that form this level is as follows: T = {0, 9, 6, 9, 2, 9, 4, 1, 8}.

Here, the optimal strategy is to only jump to the right, making jumps of lengths 2, 2, 3, and 1. This way, we'll receive a total of 6+2+1+8 = 17 damage.


1)
100
1
47
123456789

Returns: 5835166389


With J = 1 the optimal strategy is to simply walk to the right and receive a total of sum(T) damage.

For reference, the correct T looks as follows: T = {0, 78707731, 16700828, 54223987, 37397303, 112252759, 46678489, 43595839, 18674904, 13909121, 118477438, 88033399, 105356379, 57997612, 53876392, 95020013, 74587130, 65130672, 87137913, 21107663, 31915521, 93853982, 18919115, 39849879, 77942770, 35619505, 115508126, 38321619, 81217888, 48486089, 99385754, 3518042, 54541781, 56535927, 103271783, 118677266, 9471515, 42240439, 63756943, 22645319, 78498270, 24766051, 23259469, 97059690, 78644199, 106718369, 103400840, 52991972, 82679980, 11571002, 51967363, 92835245, 14642439, 8424125, 24743784, 97337616, 122077541, 1705829, 100021156, 109475123, 72076633, 108579776, 115648995, 69629823, 17743411, 112870250, 19785396, 23719093, 30779622, 32618435, 122368451, 78015617, 67622124, 44870230, 12344214, 55071073, 113446855, 52198724, 46857513, 99791617, 82202168, 19463620, 21983457, 19896614, 36547647, 10608455, 19619123, 19874030, 26282158, 63021190, 25389104, 82849251, 37721099, 93169629, 115038596, 6768175, 47951505, 65151308, 78430545, 36017979, 3777986}


2)
5
5
12345
54321

Returns: 46038

Here the optimal solution is to cross the entire level in one jump, only receiving T[N] damage.

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

template<typename T> inline T minimum(const T& a, const T& b) { return min(a, b); }

template<typename T, int64_t SIZE, T DEF_VAL, T Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	void update(int64_t i, const T& value) {
		i += SIZE;
		// val[i] = Compare(val[i], value);
		val[i] = value;
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
	T get(int64_t a, int64_t b, int64_t l = 0, int64_t r = SIZE, int64_t i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	int64_t find_leftmost_index(int64_t a, int64_t b, const T& value, int64_t l = 0, int64_t r = SIZE, int64_t i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		int64_t leftmost_index = find_leftmost_index(a, b, value, l, (l + r) / 2, i * 2);
		if (leftmost_index >= 0) return leftmost_index;
		return find_leftmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
	}
	int64_t find_rightmost_index(int64_t a, int64_t b, const T& value, int64_t l = 0, int64_t r = SIZE, int64_t i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		int64_t rightmost_index = find_rightmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
		if (rightmost_index >= 0) return rightmost_index;
		return find_rightmost_index(a, b, value, l, (l + r) / 2, i * 2);
	}
};
typedef SegmentTree<int64_t, 1 << 19, 1LL << 60, minimum<int64_t>> MinSegTree;

class StepLeapSurviveTraps {
public:
	long long minDamage(int N, int J, int seed, int M) {
		int64_t state = seed;
		MinSegTree st;
		st.update(0, 0);
		for (int i = 1; i <= N; ++i) {
			state = (state * 1103515245 + 12345) % (1LL << 31);
			int64_t t = 1 + (state % M);
			st.update(i, st.get(max(0, i - J), i) + t);
		}
		return st.get(N, N + 1);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 3;
			int Arg2 = 47;
			int Arg3 = 10;
			long long Arg4 = 17LL;

			verify_case(n, Arg4, minDamage(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 47;
			int Arg3 = 123456789;
			long long Arg4 = 5835166389LL;

			verify_case(n, Arg4, minDamage(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 12345;
			int Arg3 = 54321;
			long long Arg4 = 46038LL;

			verify_case(n, Arg4, minDamage(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StepLeapSurviveTraps ___test;
//	___test.run_test(0);
	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
