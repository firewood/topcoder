// BEGIN CUT HERE
/*
// SRM 508 Div2 Medium (500)

問題

N個の駒と、M番目が与えられる。
素数による除算か、左右いずれかのシフト(ローテート)が可能。
M番目の駒をいちばん左端に移動するための最小コストを求める。


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
	// example 0
	Test(56, 14, 3);

	// example 1
	Test(49, 5, 2);

	// example 2
	Test(256, 7, 6);

	// example 3
	Test(6, 1, 0);

	// example 4
	Test(77777, 11111, 2);

	Test(999983, 427, 1);

	return 0;
}
// END CUT HERE
