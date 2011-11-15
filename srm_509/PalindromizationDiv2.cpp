// BEGIN CUT HERE
/*
// SRM 509 Div2 Easy (250)

問題

0から100000までの数が与えられる。
加算または減算で、左右対称にするための最小コストを求める。


#line 63 "PalindromizationDiv2.cpp"
*/
// END CUT HERE
#include <string>
#include <vector>

using namespace std;

static bool isPalindromic(int x) {
	if (x <= 9) {
		return true;
	}
	char a[16] = {0};
	char b[16] = {0};
	char *aw = a;
	char *bw = b + 16;
	while (x > 0) {
		char r = (char)(x % 10);
		*aw++ = r;
		*--bw = r;
		x /= 10;
	}
	return memcmp(a, bw, (aw - a) / 2) == 0;
}

class PalindromizationDiv2 {
	public:
	int getMinimumCost(int X) {
		int i;
		for (i = 0; i < X; ++i) {
			if (isPalindromic(X + i) || isPalindromic(X - i)) {
				break;
			}
		}
		return i;
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

static void Test(int n, int expected)
{
	PalindromizationDiv2 ___test;
	int result = ___test.getMinimumCost(n);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

static void Test_isPalindromic(int x) {
	printf("test of %d: %s\n", x, isPalindromic(x) ? "Yes" : "No");
}

int main() {
	Test_isPalindromic(1);
	Test_isPalindromic(10);
	Test_isPalindromic(100);
	Test_isPalindromic(101);
	Test_isPalindromic(1000);
	Test_isPalindromic(1001);
	Test_isPalindromic(10000);
	Test_isPalindromic(10001);
	Test_isPalindromic(12011);
	Test_isPalindromic(12021);
	Test_isPalindromic(12022);

	// example 0
	Test(25, 3);

	// example 1
	Test(12321, 0);

	// example 2
	Test(40, 4);

	// example 3
	Test(2011, 9);

	// example 4
	Test(0, 0);

	return 0;
}
// END CUT HERE
