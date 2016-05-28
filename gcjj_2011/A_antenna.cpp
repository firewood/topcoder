/*

Google Code Jam Japan 2011

Problem A. アンテナ修復

Small input 5 points
Large input 10 points


問題

冒険家のパスカルは古代文明が残した宇宙人との通信装置を発見し使用方法を解明した。
装置のアンテナは K 本のエレメントと呼ばれる特殊物質でできた直線状の棒で構成される。
各エレメントの一端は + 極と呼ばれ、もう一端は - 極と呼ばれる。
エレメントには 1 から K までの番号が振られている。

アンテナを動作させるには以下の4つの条件を満たすように組み立てなければならない。

すべてのエレメントが同一平面上にある
すべてのエレメントの + 極が同じ位置にある。これを接続点と呼ぶ
エレメント同士が重なるのは接続点のみ
隣り合うエレメントがなす角度はすべて 360/K 度である
隣り合うエレメントの - 極の位置 2 点と接続点で作られる三角形の面積を隣り合うエレメントの
組み合わせすべてについて足しあわせた値がアンテナの強度となる。

アンテナの強度を最大化する並べ方を計算し、その強度を出力せよ。

エレメントの太さは無視できるほど細いものとする。エレメントを切断したり、複数のエレメントを
つなぎあわせて1本のエレメントとして使うことはできない。


入力

最初の行はテストケースの個数 T を表す正の整数である。各テストケースは以下のようなフォーマットで表される。

K
E1 E2 ... EK
ここで K はエレメントの数である。Ei は正の整数で、i 番目のエレメントの長さを表している。


出力

各テストケースに対し、

Case #X: P
という内容を1行出力せよ。X は 1 から始まるテストケース番号、P は最大化された強度を表す。


制約

1 <= T <= 100 
1 <= Ei <= 1000
Small

3 <= K <= 5

Large

3 <= K <= 1000

サンプル


入力 

3
3
1 1 1
4
1 1 1 1
4
1 1 2 2


出力 

Case #1: 1.299038106
Case #2: 2
Case #3: 4.5

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
		int K;
		if (sscanf(p, "%d", &K) != 1) {
			return false;
		}
		IntVector Seq;
		IntVector VE;
		p = GetSingleLine();
		p = strtok(p, " ");
		int i;
		for (i = 0; i < K; ++i) {
			if (p == NULL) return false;
			int e = atoi(p);
			VE.push_back(e);
			p = strtok(NULL, " ");
		}

		double y = fabs(sin((2 * M_PI) / (double)K));

/*
		double result = 0;
		do {
			double P = 0;
			for (i = 0; i < K; ++i) {
				double x = VE[Seq[i]];
				double L = VE[Seq[(i + 1) % K]];
				P += x * L * y;
			}
			result = max(result, P);
		} while (next_permutation(Seq.begin(), Seq.end()));
*/

		Seq.resize(K);
		sort(VE.begin(), VE.end());
		i = 0;
		int F = 0;
		int R = K - 1;
		while (F <= R) {
			Seq[F++] = VE[i++];
			if (i < K) {
				Seq[R--] = VE[i++];
			}
		}

		double result = 0;
		double P = 0;
		for (i = 0; i < K; ++i) {
			double x = Seq[i];
			double L = Seq[(i + 1) % K];
			P += x * L * y;
		}
		result = max(result, P);

		printf("Case #%d: %f\n", number + 1, result / 2.0);
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

