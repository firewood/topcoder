// BEGIN CUT HERE
/*
// SRM 518 Div2 Hard (1000)

問題

N枚のコインがあり全て表になっている。
K個の整数を含む配列 a が与えられる。
1ターン毎に a[i] 枚のコインを裏返す。
Kターン後に表になっている枚数の期待値を求める。

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
	// example 0
	Test(3, "2,2", 1.6666666666666667);

	// example 1
	Test(10, "10,10,10", 0.0);

	// example 2
	Test(10, "2,7,1,8,2,8", 4.792639999999999);

	// example 3
	Test(1000, "916,153,357,729,183,848,61,672,295,936", 498.1980774932278);

	return 0;
}
// END CUT HERE
