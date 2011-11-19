// BEGIN CUT HERE
/*
// SRM 512 Div2 Easy (256)

問題

3色のビーズがある。
異なる2色を使ってアクセサリを作る。
色は2色のみで交互に使用しなければならない。
最大の長さを求める。


#line 82 "MarbleDecoration.cpp"
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
typedef vector<int> VI;

class MarbleDecoration {
	public:
	int maxLength(int R, int G, int B) {
		VI v;
		v.push_back(R);
		v.push_back(G);
		v.push_back(B);
		sort(v.begin(), v.end());
		int a = v[1];
		int b = v[2];
		int len = a * 2;
		b -= a;
		len += min(b, 1);
		return len;
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

static void Test(int R, int G, int B, int expected)
{
	MarbleDecoration ___test;
	int result = ___test.maxLength(R, G, B);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test(0, 0, 0, 0);

	// example 1
	Test(3, 0, 0, 1);

	// example 2
	Test(5, 1, 2, 5);

	// example 3
	Test(7, 7, 4, 14);

	// example 4
	Test(2, 3, 5, 7);

	// example 5
	Test(13, 13, 13, 26);

	return 0;
}
// END CUT HERE
