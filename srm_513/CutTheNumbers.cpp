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

using namespace std;

typedef vector<string> StrVec;

class CutTheNumbers {
	int w;
	int h;
	int n[4][4];
	int memo[65536];

	int _rec(int x, int y, int b) {
		int res = 0;
		int filled = b;
		int m = 1 << (y*4+x);
		int sum = 0;
		int i;
		for (i = x; i < w; ++i) {
			if (b & m) {
				break;
			}
			sum = sum * 10 + n[y][i];
			filled |= m;
			m <<= 1;
			res = max(res, sum + rec(filled));
		}
		filled = b;
		m = 1 << (y*4+x);
		sum = 0;
		for (i = y; i < h; ++i) {
			if (b & m) {
				break;
			}
			sum = sum * 10 + n[i][x];
			filled |= m;
			m <<= 4;
			res = max(res, sum + rec(filled));
		}
		return res;
	}

	int rec(int b) {
		int &res = memo[b];
		if (res < 0) {
			res = 0;
			int x, y;
			for (y = 0; y < h; ++y) {
				for (x = 0; x < w; ++x) {
					int m = 1 << (y*4+x);
					if ((b & m) == 0) {
						return res = _rec(x, y, b);
					}
				}
			}
		}
		return res;
	}

public:
	int maximumSum(vector <string> board) {
		memset(n, 0, sizeof(n));
		memset(memo, -1, sizeof(memo));
		w = board[0].length();
		h = board.size();
		int i, j;
		for (i = 0; i < h; ++i) {
			for (j = 0; j < w; ++j) {
				n[i][j] = board[i][j] - '0';
			}
		}
		return rec(0);
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
