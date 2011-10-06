/*

Google Code Jam Japan 2011

問題A. カードシャッフル

問題

フランクはカードゲームが好きで、週末は友達の家でゲームパーティーに
参加しています。彼らがゲームに使うカードは M 枚からなり、
それぞれ 1 から M までの数字が重複しないように書かれています。
フランクはパーティーで友人が使っている自動カードシャッフル装置と
同じものを持っていて、どのように動作するか理解しています。
その装置はカードの山を C 回カットすることでシャッフルを行います。
i 回目のカットではカードの山の上から Ai 番目から Bi 枚、つまり
Ai 番目から Ai + Bi - 1 番目のカードがそのままの順番で山の上に移動します。

ある日、いつも使っているカードが汚れたため、新しいカードを使うことに
なりました。新しいカードは上から順番に 1 から M まで並んだ状態で
そのままシャッフル装置にかけられました。フランクはシャッフル装置の
性質を利用し、シャッフル後に上から W 番目にあるカードが何かを
知ろうとしています。

入力

最初の行はテストケースの個数 T を表す正の整数です。続いて、
各テストケースが次のようなフォーマットで与えられます。

M C W
A1 B1
...
AC BC
1行目では、1 つのスペースで区切られた 3 つの整数 M, C, W が与えられます。
ここで M はカードの枚数 、C はカットの回数、W は知りたいカードの位置です。
続く C 行の各行では、1 つのスペースで区切られた 2 つの整数 Ai, Bi が
与えられます。 ここで Ai, Bi はカットの操作で、i 回目の操作で上から
Ai 番目から Bi 枚のカードを山の上に移動させることを意味しています。

出力

各テストケースに対し、

Case #X: P
という内容を1行出力してください。ここで X は 1 から始まるテストケース番号、
P はシャッフル後のカードの山の上から W 番目にあるカードを表します。
制約

1 <= T <= 200
1 <= C <= 100
1 <= W <= M
1 <= Ai <= M
1 <= Bi <= M
1 <= Ai + Bi - 1 <= M
Small

1 <= M <= 100
Large

1 <= M <= 10^9
サンプル


入力 
 	
出力 
 
3
1 1 1
1 1
2 3 1
2 1
2 1
2 1
5 3 2
4 2
5 1
4 2
Case #1: 1
Case #2: 2
Case #3: 2

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
typedef vector<string> StringVector;
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
		int M, C, W;
		if (sscanf(p, "%d %d %d", &M, &C, &W) != 3) {
			return false;
		}
		IntVector VA, VB;
		int j;
		for (j = 0; j < C; ++j) {
			p = GetSingleLine();
			int A, B;
			if (sscanf(p, "%d %d", &A, &B) != 2) {
				return false;
			}
			--A;
			VA.push_back(A);
			VB.push_back(B);
		}
		int pos = W - 1;
		for (j = C - 1; j >= 0; --j) {
			int A = VA[j];
			int B = VB[j];
			int E = A + B;
			if (pos < B) {
				pos += A;
			} else if (pos < E) {
				pos -= B;
			}
		}

		int result = pos + 1;
#if 0
		for (j = 0; j < C; ++j) {
			int A = VA[j];
			int B = VB[j];
			int E = A + B;
			if (pos < A) {
				pos += B;
			} else if (pos < E) {
				pos -= A;
			}
		}

		bool v = (pos + 1) == W;

		if (!v) {
			printf("FAILED\n");
			return false;
		}
#endif
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

