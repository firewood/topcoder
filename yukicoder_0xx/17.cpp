#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef vector<II> IIVec;
typedef priority_queue<III> Queue;

static inline int popcount_ll(LL b) {
#ifdef __GNUC__
	return __builtin_popcountll(b);
#elif _MSC_VER >= 1400 && defined(_M_AMD64)
	return (int)__popcnt64(b);
#else
	b = (b & 0x5555555555555555LL) + (b >> 1 & 0x5555555555555555LL);
	b = (b & 0x3333333333333333LL) + (b >> 2 & 0x3333333333333333LL);
	b = (b & 0x0f0f0f0f0f0f0f0fLL) + (b >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	b += b >> 8;
	b += b >> 16;
	return (int)((b + (b >> 32)) & 0x7F);
#endif
}

int main(int argc, char *argv[])
{
	LL i, j, k;
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int S[50];
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> S[i];
	}

	getline(cin, s);
	LL dist[64][64];
	int M = atoi(s.c_str());
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			dist[i][j] = 1LL << 60;
		}
	}
	for (int i = 0; i < M; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int a, b, c;
		ss >> a >> b >> c;
		dist[a][b] = dist[b][a] = c;
	}
	for (k = 0; k < N; ++k) {
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	LL ans = 1LL << 60;
	for (i = 1; i < N - 1; ++i) {
		for (j = 1; j < N - 1; ++j) {
			if (i != j) {
				ans = min(ans, dist[0][i] + dist[i][j] + dist[j][N - 1] + S[i] + S[j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
