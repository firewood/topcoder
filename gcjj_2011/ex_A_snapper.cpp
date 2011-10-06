/*

Google Code Jam Japan 2011

example A

問題

Snapper はちっちゃな電化製品で、片側に入力プラグ、反対側に出力ソケットがついています。
この出力ソケットには、電球などの電化製品や、他の Snapper の入力プラグを接続することができます。

Snapper は ON か OFF の状態を持っていて、状態が ON で入力プラグから電力を受け取っているときのみ、
出力ソケットに電力が供給されます。 また、あなたが指をパチリと鳴らすと、その破裂音に反応して、
入力プラグから電力を受け取っている Snapper は ON/OFF の状態が切り替わります。

ある日、私は N 個の Snapper を買ってきて、1 個目の Snapper の入力プラグを電源ソケットに接続、
2 個目の Snapper の入力プラグを 1 個目の出力ソケットに接続、といった要領で数珠つなぎにし、
N 個目の Snapper の出力ソケットに電球を取り付けました。

はじめの状態では、Snapper はすべて OFF で、1 個目の Snapper のみに電力が供給され、電球は付いていません。
一回指を鳴らすと、1 個目の Snapper は ON になり、2 個目の Snapper に電力が供給されます。 
もう一度指を鳴らすと、1 個目と 2 個目の Snapper の状態が切り替わり、
2 個目の Snapper は ON であるものの電源が供給されていない、という状態になります。
3 回目には、1 個目の状態が切り替わり、1 個目と 2 個目の両方が ON になります。 
もし、ここで 2 個目の出力ソケットに電球が接続されていたとすると、電球が光ります。

私は指を何時間にもわたって鳴らし続けました。 指を K 回鳴らしたとき、果たして電球は光っているでしょうか？
電球は仕掛けのないどこにでもあるようなもので、直前の Snapper から電力を供給されているときにのみ光ります。

入力

1 行目にはテストケースの数 T が含まれています。その後ろに T 行が続きます。
それらの行にはそれぞれ 2 つの整数 N と K が含まれています。

出力

各テストケースにつき 1 行、 "Case #X: Y" と出力してください。
ただし、X は 1 から始まるテストケースの番号です。
Y は電球が光っているかどうかで、光っているならば "ON"、消えているならば "OFF" としてください。

制約

1 <= T <= 5000

Small

1 <= N <= 10
0 <= K <= 100

Large

1 <= N <= 30
0 <= K <= 10^8

サンプル


入力 
 	
出力 
 
4
1 0
1 1
4 0
4 47
Case #1: OFF
Case #2: ON
Case #3: OFF
Case #4: ON

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
		int n, k;
		if (sscanf(p, "%d %d", &n, &k) != 2) {
			return false;
		}
		int mask = (1 << n) - 1;
		bool result = (k & mask) == mask;
		printf("Case #%d: %s\n", number + 1, result ? "ON" : "OFF");
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

