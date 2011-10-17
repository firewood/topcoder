// BEGIN CUT HERE
/*
// SRM 517 Div2 Medium (500)

問題
  正の整数の値を保持するボールがある。
  ボールの値xが、2つの2以上の整数yとzの積で表せるとき、ボールをぶつけることで
  2つのボールに分裂する。
  Nとtargetが与えられたとき、Nをぶつける過程で、常に少なくとも1回は
  targetが観測されるかどうかを答える。

#line 96 "CompositeSmash.cpp"
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

class CompositeSmash {
	bool isPossible(int N, int Target) {
		if (N == Target) {
			return true;
		}
		if (N % Target) {
			return false;
		}

		int r = (int)sqrt((double)N);
		int i;
		for (i = 2; i <= r; ++i) {
			if ((N % i) != 0) {
				continue;
			}
			if (!isPossible(N / i, Target) && !isPossible(i, Target)) {
				return false;
			}
		}
		return true;
	}

	public:
	string thePossible(int N, int target) {
		return isPossible(N, target) ? "Yes" : "No";
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

static void Test(int N, int target, const char *expected)
{
	CompositeSmash ___test;
	string result = ___test.thePossible(N, target);
	printf("result: %s, %s\n", result.compare(expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	// example 0
	Test(517, 47, "Yes");

	// example 1
	Test(8, 4, "Yes");

	// example 2
	Test(12, 6, "No");

	// example 3
	Test(5, 8, "No");

	// example 4
	Test(100000, 100000, "Yes");

	// example 5
	Test(5858, 2, "Yes");

	// example 6
	Test(81461, 2809, "No");

	// example 7
	Test(65536, 256, "No");

	Test(16, 4, "Yes");
	Test(33649, 23, "Yes");

	return 0;
}
// END CUT HERE
