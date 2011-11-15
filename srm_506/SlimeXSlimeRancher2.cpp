// BEGIN CUT HERE
/*
// SRM 506 Div2 Easy (250)

問題

N個の数値がある。
最大値に合わせるために、加算する総和を求める。


*/
#line 50 "SlimeXSlimeRancher2.cpp"
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SlimeXSlimeRancher2 {
	public:
	int train(vector <int> attributes) {
		sort(attributes.begin(), attributes.end());

		int max = *(attributes.rbegin());

		int result = 0;
		int i;
		for (i = 0; i < ((int)attributes.size() - 1); ++i) {
			result += max - attributes[i];
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

static void Test(const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	SlimeXSlimeRancher2 ___test;
	int result = ___test.train(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("1,2,3", 3);

	// example 1
	Test("5,5", 0);

	// example 2
	Test("900,500,100", 1200);

	return 0;
}
// END CUT HERE
