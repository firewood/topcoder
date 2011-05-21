/*

Round 1A
Problem A. FreeCell Statistics

*/


#include <stdio.h>
#include <string.h>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef __int64 __ll;

class GCJ {
	static const size_t BufferSize = 1024000;
	FILE *m_Source;
	size_t m_BufferSize;
	char *m_Buffer;

public:
	GCJ(FILE *source, size_t buffer_size = BufferSize) {
		m_Source = source;
		m_BufferSize = buffer_size;
		m_Buffer = new char[m_BufferSize];
	}

	~GCJ() {
		delete [] m_Buffer;
	}

	bool solve(void) {
		int cases;
		if (!getInt(cases) || cases < 1) {
			return false;
		}

		int solved = 0;
		int i;
		for (i = 0; i < cases; ++i) {
			if (solve(i)) {
				++solved;
			}
		}
		return solved >= cases;
	}

private:
	int gcd(int m, int n) {
		if (n == 0) {
			return m;
		}
		if ((m % n) == 0) {
			return n;
		}
		return gcd(n, m % n);
	}

	int lcm(int m, int n) {
		int g = gcd(m, n);
		return m * n / g;
	}

	bool solve(__ll N, int PD, int PG) {
		if (PG == 0 || PG == 100) {
			return PD == PG;
		}
		if (PD == 0 || PD == 100) {
			return true;
		}
		int g = gcd(100, PD);
		__ll a = 100 / g;
		return a <= N;
	}

	bool solve(int case_index) {
		char *p = getSingleLine();
		if (!p) return false;

		__ll N;
		int PD, PG;
		if (sscanf(p, "%lld %d %d", &N, &PD, &PG) != 3) {
			return false;
		}

		// N: known
		// G: unknown
		// D: unknown
		// 1 <= D <= N
		// 1 <= D <= G

		bool result = solve(N, PD, PG);
		printf("Case #%d: %s\n", case_index + 1, result ? "Possible" : "Broken");
		return true;
	}

	int getCases(void) {
		int cases;
		char *p = getSingleLine();
		if (p != NULL && sscanf(p, "%d", &cases) >= 1) {
			return cases;
		}
		return -1;
	}

	bool getInt(int &i) {
		char *p = getSingleLine();
		return p != NULL && sscanf(p, "%d", &i) >= 1;
	}

	char *getSingleLine(void) {
		char *p = fgets(m_Buffer, m_BufferSize, m_Source);
		if (!p) {
			return NULL;
		}
		char *term = p + strlen(p) - 1;
		if (term > p && *term == '\n') {
			*term = 0;
		}
		return p;
	}

};


int main()
{
	GCJ gcj(stdin);
	return gcj.solve() ? 0 : -1;
}

