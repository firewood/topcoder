/*

Google Code Jam Japan 2011

問題B. 最高のコーヒー

問題

ヘインの一日は朝のコーヒーを飲むことから始まります。

彼の手元には N 種類のコーヒーがあります。i 番目の種類のコーヒーは ci 杯分残っていて、
今日から数えて ti 日目に消費期限を迎えます。彼は i 番目（1 <= i <= N）の種類のコーヒーを
一杯飲むごとに si の満足度が得られます。消費期限の切れたコーヒーを飲むことはできません
（ちょうど ti 日目であればそのコーヒーは飲むことができます）。たとえば ti = 1 であれば、
今日中に飲んでしまうか、そのコーヒーをあきらめるかのどちらかにしなければなりません。

彼はコーヒーを一日に一杯だけ、朝だけにしか飲まないことにしています。もし手元に飲める
コーヒーがない日は、満足度を得ることはできません。

これらのコーヒーを飲むことで、今日から始めて K 日目までに彼は合計して最大でどれだけの
満足度を得られるでしょうか。

入力

入力の最初の行はテストケースの個数 T です。そのあとに T 個のテストケースが続きます。
それぞれのテストケースは 1 つのスペースで区切られた 2 つの正の整数が含まれる行から始まります。
最初の整数はコーヒーの種類数 N を表し、次の整数は日数 K を表します。
そのあとにそれぞれの種類のコーヒーの残数、消費期限、満足度を表す以下の形式の行が N 行続きます。

ci ti si
出力

各テストケースごとに、

Case #X: Y
と一行出力してください。ここで X は 1 から始まるテストケースの番号、Y はヘインの満足度の合計の最大値です。
制約

1 <= T <= 100
1 <= ci <= K
1 <= ti <= K
1 <= si <= 1000

Small

1 <= N <= 8
1 <= K <= 8
Large

1 <= N <= 100
1 <= K <= 2 * 10^12 (32bit整数型には収まらないことに注意)
サンプル


入力 
 	
出力 
 
3
2 3
2 2 2
3 3 1
2 3
1 3 2
1 3 1
5 5
5 5 1
4 4 2
3 3 3
2 2 4
1 1 5
Case #1: 5
Case #2: 3
Case #3: 15

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
#include <algorithm>
#include <vector>

using namespace std;

#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))
typedef long long LL;

struct Coffee {
	LL C;
	LL T;
	LL S;
};
typedef vector<Coffee> CoffeeList;

static bool CoffeeByLimit(const Coffee &l, const Coffee &r) {
	return l.T > r.T;
}


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
		int N;
		LL K;
		char *p = GetSingleLine();
		if (p == NULL || sscanf(p, "%d %lld", &N, &K) != 2) return false;
		CoffeeList CV;
		int i;
		for (i = 0; i < N; ++i) {
			Coffee coffee;
			p = GetSingleLine();
			if (p == NULL || sscanf(p, "%lld %lld %lld", &coffee.C, &coffee.T, &coffee.S) != 3) {
				return false;
			}
			CV.push_back(coffee);
		}
		// 賞味期限の長い順にソート
		sort(CV.begin(), CV.end(), CoffeeByLimit);
/*
		for (i = 0; i < N; ++i) {
			Coffee &c = CV[i];
			printf("c %lld t %lld s %lld\n", c.C, c.T, c.S);
		}
*/

		LL result = 0;
		while (K > 0 && CV.size() > 0) {
			CoffeeList::iterator Max = CV.begin();
			LL T = min(K, Max->T);		// 開始日時
			LL E = max(0, T - Max->C);	// 終了日時
			CoffeeList::iterator it = Max;
			for (++it; it != CV.end(); ++it) {
				if (it->T < T) {
					// 賞味期限が異なるものが見つかったので区切りにする
					E = max(E, it->T);
					break;
				}
				if (it->S > Max->S) {
					// より満足度の高いものが見つかった
					Max = it;
					E = max(0, T - Max->C);
				}
			}
			LL consume = T - E;		// 対象区間の消費量
			result += consume * Max->S;
			Max->C -= consume;
			if (Max->C <= 0) {
				// 在庫がなくなったら取り除く
				CV.erase(Max);
			}
			K = E;		// 開始区間を更新
		}

		printf("Case #%d: %lld\n", number, result);
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

