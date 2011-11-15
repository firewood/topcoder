// BEGIN CUT HERE 
/*
// SRM 504 Div2 Easy (250)

問題

比較に特化した言語がある。
特定の比較演算結果と一致しているなら、1または7を返す。
1と7の両方を満たす場合は1を返す。
1も7も満たさない場合は-1を返す。

*/
// END CUT HERE
#line 89 "ComparerInator.cpp"
#include <string>
#include <vector>

using namespace std;

typedef vector<int>VI;

class ComparerInator {
	public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
		int length = (int)A.size();
		VI::const_iterator ia, ib, iw;
		int count_a = 0, count_b = 0;
		for (ia = A.begin(), ib = B.begin(), iw = wanted.begin();
				ia != A.end(); ++ia, ++ib, ++iw) {
			if (*ia == *iw) {
				++count_a;
			}
			if (*ib == *iw) {
				++count_b;
			}
		}
		if (count_a >= length || count_b >= length) {
			return 1;
		}

		count_a = 0, count_b = 0;
		for (ia = A.begin(), ib = B.begin(), iw = wanted.begin();
				ia != A.end(); ++ia, ++ib, ++iw) {
			if (*ia < *ib) {
				if (*ia == *iw) {
					++count_a;
				}
				if (*ib == *iw) {
					++count_b;
				}
			} else {
				if (*ib == *iw) {
					++count_a;
				}
				if (*ia == *iw) {
					++count_b;
				}
			}
		}
		if (count_a >= length || count_b >= length) {
			return 7;
		}

		return -1;
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

static void Test(const char *A, const char *B, const char *wanted, int expected)
{
	vector <int> _a = getVector<int>(A);
	vector <int> _b = getVector<int>(B);
	vector <int> _w = getVector<int>(wanted);
	ComparerInator ___test;
	int result = ___test.makeProgram(_a, _b, _w);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main()
{
	// example 0
	Test("1", "2", "2", 1);

	// example 1
	Test("1,3", "2,1", "2,3", 7);

	// example 2
	Test("1,3,5", "2,1,7", "2,3,5", -1);

	// example 3
	Test("1,3,5", "2,1,7", "1,3,5", 1);

	// example 4
	Test("1,2,3,4,5,6,7,8,9,10,11", "5,4,7,8,3,1,1,2,3,4,6", "1,2,3,4,3,1,1,2,3,4,6", 7);

	// example 5
	Test("1,5,6,7,8", "1,5,6,7,8", "1,5,6,7,8", 1);

	return 0;
}
// END CUT HERE
