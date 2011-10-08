/*

Google Code Jam Japan 2011


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

