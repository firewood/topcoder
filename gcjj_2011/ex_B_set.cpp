/*

Google Code Jam Japan 2011

example B

問題

連続する複数の整数を、以下の手順によっていくつかの集合に分割します。

まず、対象となる整数の区間と、ある整数 P が与えられます。
初期状態では、区間中の整数はそれぞれその整数のみを含む別々の集合に属しています。
そして、区間に属する整数同士のペアのそれぞれについて、その 2 つの整数に共通する P 以上の素因数が存在するならば、
その 2 つの整数が属する集合同士を併合して 1 つの集合にする、という操作を行います。

この手順を終えたとき、集合の数はいくつになっているでしょうか？

入力

最初の行はテストケースの数 C を含んでいます。

各テストケースは 1 行で、スペースで区切られた 3 つの整数 A, B, P が含まれます。
A と B はそれぞれ区間の最初と最後の整数で、P は上述した数です。

出力

各テストケースにつき、 "Case #X: Y" という文字列を含んだ一行を出力してください。
ここで X は 1 から始まるテストケースの番号であり、Y は集合の個数です。

制約

Small

1 <= C <= 10
1 <= A <= B <= 1000
2 <= P <= B

Large

1 <= C <= 100
1 <= A <= B <= 1012
B <= A + 1000000
2 <= P <= B

サンプル


入力 
 	
出力 
 
2
10 20 5
10 20 3

Case #1: 9
Case #2: 7

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

#define MAX_N 1000001
#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))
typedef unsigned long long ULL;
typedef vector<int> IntVector;


struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};


class GCJ {
	FILE *m_Source;
	char m_Buffer[1024000];
	IntVector m_Primes;

public:
	GCJ(FILE *source) : m_Source(source) {
		gen_prime(MAX_N + 1, m_Primes);
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

private:
	bool Solve(int number) {
		char *line = GetSingleLine();
		ULL A, B;
		int P;
		if (sscanf(line, "%lld %lld %d", &A, &B, &P) != 3) {
			return false;
		}

		int Size = (int)(B - A + 1);
		UnionFind uf(Size);

		int i, j;
		for (i = 0; i < (int)m_Primes.size(); ++i) {
			int p = m_Primes[i];
			if (p < P) {
				continue;
			}
			ULL r = A % (ULL)p;
			int x = (p - (int)r) % p;
			for (j = x + p; j < Size; j += p) {
				uf.unionSet(x, j);
			}
		}

		int result = 0;
		for (i = 0; i < Size; ++i) {
			if (uf.root(i) == i) {
				++result;
			}
		}

		printf("Case #%d: %d\n", number + 1, result);
		return true;
	}

	static void gen_prime(int N, IntVector &v) {
		v.push_back(2), v.push_back(3);
		for (int n = 5; n <= N; n += 2) {
			const int *s = &v[0];
			int p, p2;
			while ((p2 = ((p = *++s) * p)) < n && (n % p) != 0) ;
			if (p2 > n) v.push_back(n);
		}
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

