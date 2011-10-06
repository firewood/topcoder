/*

Google Code Jam Japan 2011

問題C. ビット数

問題

f(x) を 「x を 2進数表記した時の "1" の個数を返す関数」と定義します。
例えば、5 は 1012 と 2 進数表記されるので、f(5) = 2 です。

正の整数 N が与えられるので、 a + b = N を満たす 0 以上の整数 a, b の組の中で
f(a) + f(b) が最大になるものを求め、その時の f(a) + f(b) の値を出力してください。

入力

最初の行はテストケースの個数 T を表す正の整数です。
各テストケースは1行の文字列で表現され、それぞれの行には N を表す正の整数が
1つだけ含まれています。

出力

各テストケースごとに、

Case #X: P
という内容を1行出力してください。ここで X は 1 から始まるテストケース番号、
P は f(a) + f(b) の最大値です。
制約

1 <= T <= 1000
Small

N <= 10000
Large

N <= 10^18 (32bit整数型には収まらないことに注意)
サンプル


入力 
 	
出力 
 
4
1
4
31
1125899906842624
Case #1: 1
Case #2: 3
Case #3: 5
Case #4: 51

*/

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <Windows.h>
#endif
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))
typedef unsigned long long ULL;


class GCJ {
	FILE *m_Source;
	char m_Buffer[1024000];

public:
	GCJ(FILE *source) : m_Source(source) { }
	~GCJ() { }

	bool Solve(void) {
		int cases = GetInt();
		int i, solved = 0;
		for (i = 0; i < cases; ++i) {
			solved += Solve(i);
		}
		return cases == solved;
	}

private:
	bool Solve(int number) {
		char *p = GetSingleLine();
		ULL N;
		if (sscanf(p, "%lld", &N) != 1) {
			return false;
		}

		int result = 0;
		while (N > 0) {
			--N;
			result += 1 + (N & 1);
			N >>= 1;
		}
		printf("Case #%d: %d\n", number + 1, result);
		return true;
	}

	int GetInt(void) {
		char *p = GetSingleLine();
		return p ? atoi(p) : -1;
	}

	char *GetSingleLine(void) {
		char *p = fgets(m_Buffer, SizeOfArray(m_Buffer), m_Source);
		if (p) {
			char *term = p + strlen(p) - 1;
			if (term >= p && *term == '\n') {
				*term = 0;
			}
		}
		return p;
	}
};

int main() {
	GCJ *gcj = new GCJ(stdin);
	if (!gcj->Solve()) {
		printf("FAILED\n");
	}
	delete gcj;
	return 0;
}

