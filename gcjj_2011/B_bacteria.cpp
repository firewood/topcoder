/*

Google Code Jam Japan 2011

Problem B. バクテリアの増殖

Small 8 points
Large 18 points


問題

微生物の研究者であるパスカルは、特殊な増殖の傾向を示すバクテリアを発見した。
どうやらそのバクテリアは、ある時点で x 個存在したとすると、理想的な環境下では1時間後に xx 個に増えるようなのである。

そこであなたは、この興味深い性質をより深く調べるために、入力として 3 つの整数 A, B, C が与えられたときに、
A 個のバクテリアが B 時間後には何個になっているかを出力するプログラムを書くことにした。
答えの値は非常に大きくなるので、その値を C で割った余りを出力してほしい。

入力

最初の行はテストケースの個数 T を表す正の整数である。それ以降の行に、T 個のケースを表すデータが続く。

それぞれのテストケースは、スペースで区切られた3つの整数からなる1行の文字列で表現される。
これらの整数は、順番に A, B, C を表す。

出力

それぞれのテストケースについて、

Case #X: N
という1行の文字列を出力せよ。ここで、X は 1 から始まるテストケースの番号であり、
N は求めるべきバクテリアの数を C で割った余りである。


制約

1 <= T <= 500
1 <= A <= 1000
1 <= C <= 1000
Small

1 <= B <= 2
Large

1 <= B <= 1000


サンプル


入力 

5
1 10 997
2 2 997
2 2 6
461 1 709
461 1000 709


出力 

Case #1: 1
Case #2: 256
Case #3: 4
Case #4: 674
Case #5: 461

*/

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <Windows.h>
#include <openssl/applink.c>
#endif
#include <openssl/bn.h>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))
typedef unsigned long long ULL;
typedef vector<int> IntVector;
#define MAX_N 1000001


class GCJ {
	FILE *m_Source;
	char m_Buffer[1024000];
	IntVector m_Primes;

public:
	GCJ(FILE *source) : m_Source(source) {
		gen_prime(MAX_N, m_Primes);
	}
	~GCJ() { }

	bool Solve(void) {
		int cases = GetInt();
		int i, solved = 0;
		for (i = 0; i < cases; ++i) {
			solved += Solve(i);
		}
		return cases == solved;
	}

	static ULL modpow(ULL b, ULL e, ULL m) {
		ULL r = 1;
		while (e > 0) {
			if (e & 1) {
				r = (r * b) % m;
			}
			e >>= 1;
			b = (b * b) % m;
		}
		return r;
	}

	// N以下の素数を生成する
	static void gen_prime(int N, IntVector &v) {
		v.push_back(2), v.push_back(3);
		for (int n = 5; n <= N; n += 2) {
			const int *s = &v[0];
			int p, p2;
			while ((p2 = ((p = *++s) * p)) < n && (n % p) != 0) ;
			if (p2 > n) v.push_back(n);
		}
	}

	ULL totient(ULL x) {
		ULL t = x;
		int i;
		for (i = 0; i < (int)m_Primes.size(); ++i) {
			int p = m_Primes[i];
			if ((x % p) == 0) {
				t = (t / p) * (p - 1);
			}
		}
		return t;
	}

private:
	bool Solve(int number) {
		char *p = GetSingleLine();
		int A, B, C;
		if (sscanf(p, "%d %d %d", &A, &B, &C) != 3) {
			return false;
		}

		int result = 0;

		BN_CTX *ctx = BN_CTX_new();
		BIGNUM a;
		BIGNUM m;
		BIGNUM x;
		BN_init(&a);
		BN_init(&m);
		BN_init(&x);
		BN_set_word(&a, A);
		BN_set_word(&m, C);
		if (B > 1) {
			BN_exp(&x, &a, &a, ctx);
			BN_copy(&a, &x);
		}
		BN_mod_exp(&x, &a, &a, &m, ctx);

		result = (int)BN_get_word(&x);

		BN_free(&a);
		BN_free(&m);
		BN_free(&x);
		BN_CTX_free(ctx);

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

