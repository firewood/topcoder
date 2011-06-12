// BEGIN CUT HERE
/*
// SRM 508 Div2 Middle (500)
// PROBLEM STATEMENT
// Manao is playing a game called "Divide and Shift". There is a sequence of N slots in the game numbered from 1 to N. Initially each of them contains an object. Manao's goal is to obtain the object which is initially in slot M. At any time of the game, he can only obtain an object that is in slot 1 at that time. 

Manao can perform two types of moves. The first is choosing a prime number p which divides N and dividing the sequence of the slots in p contiguous subsequences, namely the slots from 1 to N/p, the slots from N/p+1 to 2N/p, etc. Then, Manao keeps the subsequence which contains the desired object and gets rid of the remaining slots. The length of the chosen subsequence is then assigned to N and the slots in it are renumbered from 1 to the new value of N.

The second type of move is shifting the objects in the slots. Manao can perform a left shift and a right shift. After a left shift, for each i &gt 1 the object in slot i is moved to slot i-1 and the object in slot 1 is moved to the last slot of the sequence. After a right shift, each object is moved to the slot to the right and the object in the last slot is moved to slot 1.

Determine the least number of moves in which Manao can reach the goal. Taking the object from slot 1 is not considered a move.

DEFINITION
Class:DivideAndShift
Method:getLeast
Parameters:int, int
Returns:int
Method signature:int getLeast(int N, int M)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-A prime number p divides N if the ratio N/p is an integer.


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.
-M will be between 1 and N, inclusive.


EXAMPLES

0)
56
14

Returns: 3

One possible way to obtain the object in slot 14 is to perform the following operations:
1. Divide by 2. N becomes equal to 28 now.
2. Shift right. The object moves to slot 15.
3.?Divide?by?2?again.?The?sequence?15..28?is?kept,?renumbered?as?1..14?and?the?object?appears?in?slot?1.


1)
49
5

Returns: 2

Manao divides by 7 twice and gets a single slot.

2)
256
7

Returns: 6

Shift?left?until?the?object?is?in?slot?1.

3)
6
1

Returns: 0

The object may be in slot 1 right in the beginning.

4)
77777
11111

Returns: 2



#line 78 "DivideAndShift.cpp"
*/
// END CUT HERE
#include <math.h>
#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;

typedef set<int> IntSet;
typedef vector<int> IntVector;
typedef list<int> IntList;

class DivideAndShift {
	IntVector m_p;

	public:

	DivideAndShift(void) {
		gen_prime(1000000, m_p);
	}

	int getLeast(int N, int M) {
		--M;		// 0-based index

		// costs without division
		int cost = min(M, N - M);
		if (cost <= 1) {
			return cost;
		}

		int d;
		for (d = 2; d <= N; ++d) {
			int n = N / d;
			if ((n * d) != N) {
				continue;
			}

			int primes = 0;
			int x = d;
			size_t j;
			for (j = 0; x > 1 && j < m_p.size(); ++j) {
				while ((x % m_p[j]) == 0) {
					++primes;
					x /= m_p[j];
				}
			}

			int m = M % n;		// new position
			cost = min(cost, primes + min(m, n - m));
		}

		return cost;
	}

	// generate N primes
	static void gen_prime(int N, IntVector &v) {
		v.push_back(2);
		v.push_back(3);
		int n;
		for (n = 5; n <= N; n += 2) {
			const int *r = &v[1];
			int p;
			while (((p = *r++) * p) < n && (n % p) != 0) {
				;
			}
			if ((p * p) > n) {
				v.push_back(n);
			}
		}
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

static void Test(int N, int M, int expected)
{
	DivideAndShift ___test;
	int result = ___test.getLeast(N, M);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test(56, 14, 3);
	Test(49, 5, 2);
	Test(256, 7, 6);
	Test(6, 1, 0);
	Test(77777, 11111, 2);
	Test(999983, 427, 1);
	return 0;
}
// END CUT HERE
