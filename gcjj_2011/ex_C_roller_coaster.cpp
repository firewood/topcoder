/*

Google Code Jam Japan 2011

example C


問題

みんな大好きジェットコースター! この遊園地に来た人はみんなこれがお目当てさ。
1 人で来る人もいるし、グループで来る人もいる。グループで来たからにはやっぱり
みんなで一緒じゃないと乗りたくないよね。 楽しい楽しいジェットコースター!
このジェットコースター、乗った人はみんなもう一度乗りたがるんだ。
乗車料は一回一人当たり 1 ユーロ。 このジェットコースターの今日の売上を予測するのが君のお仕事さ!

このジェットコースターは同時に k 人乗ることができて、グループが列を作って待っています。
グループは順番にジェットコースターに乗り込み、全部のグループが乗ったか、
次に待っているグループ全員が乗れるだけの席が無くなった時点で、空席が残っていたとしても出発します。
ジェットコースターを降りた後、グループは乗り込んだ順番と同じ順番で列の後ろに並びします。
ジェットコースターは 1 日に R 回発車します。

例えば R=4, k=6 の場合に、1 人, 4 人, 2 人, 1 人の 4 つのグループがこの順番に並んでいたとしましょう。
1 回目の出発は 1 人, 4 人の 2 つのグループが乗り込んで、残りひとつの席は空けたまま出発します
（次の 2 人のグループは座りきれず、 最後の 1 人のグループは前のグループを抜かすことはできません）。
1 回目が終わった後、彼らは列の後ろに並びなおし、列は 2 人, 1 人, 1 人, 4 人となります。
2 回目は 2 人, 1 人, 1 人の計 4 人が乗り、終わった後の列は 4 人, 2 人, 1 人, 1 人となります。
3 回目は 4 人, 2 人 の計 6 人が乗り、終わった後の列は 1 人, 1 人, 4 人, 2 人となり、
最後に 1 人, 1 人, 4 人の計 6 人が乗るので、合計 21 ユーロの売上になります。

入力

1 行目にはテストケースの数 T が含まれており、次の行から T 個のテストケースが後に続きます。
各テストケースは 2 行からなり、始めの行にはスペースで区切られた 3 つの整数 R, k, Nが含まれています。
次の行には N 個のスペースで区切られた整数 gi が含まれています。 gi は列に並んでいる各グループの
人数を表しており、 g0 は 1 番目のグループの人数、g1 は 2 番目のグループの人数、... となっています。

出力

各テストケースにつき 1 行、 "Case #X: Y" と出力してください。
ただし、X は 1 から始まるテストケースの番号、Y はジェットコースターのその日の売上です。

制約

1 <= T <= 50
gi <= k

Small

1 <= R <= 1000
1 <= k <= 100
1 <= N <= 10
1 <= gi <= 10

Large

1 <= R <= 10^8
1 <= k <= 10^9
1 <= N <= 1000
1 <= gi <= 10^7

サンプル


入力 
 	
出力 
 
3
4 6 4
1 4 2 1
100 10 1
1
5 5 10
2 4 2 3 4 2 1 2 1 3

Case #1: 21
Case #2: 100
Case #3: 20

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
#include <set>
#include <vector>

using namespace std;

#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))
typedef unsigned long long ULL;
typedef vector<int> IntVector;
typedef vector<ULL> LLVector;


class GCJ {
	FILE *m_Source;
	char m_Buffer[1024000];
	IntVector m_Primes;

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
		char *line = GetSingleLine();
		int R;
		ULL k;
		int N;
		if (sscanf(line, "%d %lld %d", &R, &k, &N) != 3) {
			return false;
		}
		IntVector v;
		line = GetSingleLine();
		char *p = strtok(line, " ");
		int i;
		for (i = 0; i < N; ++i) {
			if (p == NULL) {
				return false;
			}
			int g = atoi(p);
			v.push_back(g);
			p = strtok(NULL, " ");
		}

		ULL result = 0;
		LLVector Money(N, 0);
		IntVector Turn(N, 0);
		i = 0;
		int g = 0;
		ULL x = 0;
		while (R > 0) {
			if (g >= N || x + v[i] > k) {
				--R;
				result += x;
				g = 0;
				x = 0;

				if (Money[i] > 0) {
					int T = Turn[i] - R;
					ULL M = result - Money[i];
					int Loops = R / T;
					result += Loops * M;
					R -= T * Loops;
				} else {
					Money[i] = result;
					Turn[i] = R;
				}
			} else {
				++g;
				x += v[i];
				i = (i + 1) % N;
			}
		}

		printf("Case #%d: %lld\n", number + 1, result);
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

