/*

Google Developer Day 2011

solitaire

*/


#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> II;
typedef queue<II> IIQ;

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
	bool solve(int case_index) {
		char *p = getSingleLine();
		int N = atoi(p);
		int TBL[21][10] = {0};
		unsigned int MASK[21] = {0};
		p = getSingleLine();
		p = strtok(p, " ,");
		int i, j;
		for (j = 0; j < N; ++j) {
			if (!p) return false;
			TBL[0][j] = atoi(p);
			p = strtok(NULL, " ,");
			for (i = 1; i <= 20; ++i) {
				TBL[i][j] = TBL[i - 1][j] / 2;
			}
		}
		for (i = 0; i <= 20; ++i) {
			unsigned int bit = 1;
			unsigned int mask = -1;
			for (j = 0; j < N; ++j) {
				if ((TBL[i][j] % 5) == 0) {
					mask &= ~bit;
				}
				bit <<= 1;
			}
			MASK[i] = mask;
		}

		IIQ q;
		int all = (1 << N) - 1;
		q.push(II(0, all));
		int turns;
		for (turns = 1; ; ++turns) {
			IIQ new_q;
			while (q.size() > 0) {
				II p = q.front();
				q.pop();
				int level = p.first;
				unsigned int remain = p.second & MASK[level];
				if (remain == 0) {
					printf("%d\n", turns);
					return true;
				}
				new_q.push(II(level, remain));
				if (level >= 20) {
					printf("ERROR!\n");
					return false;
				}
				new_q.push(II(level + 1, p.second));
			}
			q = new_q;
		}

		printf("ERROR\n");
		return false;
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

