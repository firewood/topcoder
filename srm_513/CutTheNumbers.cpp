// BEGIN CUT HERE
/*
// SRM 513 Div2 Hard (1000)

問題
最大で4x4の各マスに数値が書かれている。
任意の場所の数値を左から右または上から下に読むように分割する。
分割した数の合計の最大値を求める。

*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>
#if _MSC_VER >= 1400
#include <intrin.h>
#endif

using namespace std;

typedef vector<string> StrVec;

class CutTheNumbers {
	static int find_first_set_bit(unsigned int b) {
#ifdef __GNUC__
		return __builtin_ctz(b);	// undefined for zero
#elif _MSC_VER >= 1400
		unsigned long r; _BitScanForward(&r, b); return r;
#else
		unsigned int i = 0; while ((1<<i) & b) ++i; return i;
#endif
	}

	int w;
	int h;
	int n[4][4];
	int memo[65536];

	int rec(int b) {
		int &res = memo[b];
		if (res < 0) {
			res = 0;

			// find position
			int pos = find_first_set_bit(b);
			int x = pos & 3;
			int y = pos / 4;

			int m = 1 << pos;
			int pat = b;
			int sum = 0;
			int i;
			for (i = x; i < w; ++i) {
				if (!(b & m)) {
					break;
				}
				sum = sum * 10 + n[y][i];
				pat ^= m;		// pat &= ~m;
				m <<= 1;
				res = max(res, sum + rec(pat));
			}
			m = 1 << pos;
			pat = b;
			sum = 0;
			for (i = y; i < h; ++i) {
				if (!(b & m)) {
					break;
				}
				sum = sum * 10 + n[i][x];
				pat ^= m;		// pat &= ~m;
				m <<= 4;
				res = max(res, sum + rec(pat));
			}
		}
		return res;
	}

public:
	int maximumSum(vector <string> board) {
		w = board[0].length();
		h = board.size();
		unsigned int mask = 0;
		int i, j;
		for (i = 0; i < h; ++i) {
			for (j = 0; j < w; ++j) {
				mask |= (1 << (i*4+j));
				n[i][j] = board[i][j] - '0';
			}
		}
		memset(memo, -1, sizeof(memo));
		memo[0] = 0;
		return rec(mask);
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
	StrVec v = getVector<string>(seq);
	CutTheNumbers ___test;
	int result = ___test.maximumSum(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("123 312", 435);
	Test("99 11", 182);
	Test("001 010 111 100", 1131);
	Test("8", 8);

	Test("4937 2591 3846 9150", 24925);

	return 0;
}
// END CUT HERE
