#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(12);
	int M;
	cin >> M;
	M = 1 << M;
	double S[1024];
	double P[2][1024];
	vector<int> G[2][1024];
	for (int i = 0; i < M; ++i) {
		cin >> S[i];
		S[i] *= S[i];
		P[0][i] = 1.0;
		G[0][i].push_back(i);
	}
	int prev = 0, curr = 1;
	while (M > 1) {
		for (int i = 0; i < M / 2; ++i) {
			G[curr][i].clear();
		}
		for (int i = 0; i < M; ++i) {
			vector<int> &v = G[prev][i];
			vector<int> &opp = G[prev][i ^ 1];
			for (int j : v) {
				double p = 0;
				for (int k : opp) {
					p += P[prev][j] * P[prev][k] * S[j] / (S[j] + S[k]);
				}
				P[curr][j] = p;
				G[curr][i / 2].push_back(j);
			}
		}
		M /= 2;
		prev ^= 1, curr ^= 1;
	}
	double ans = P[prev][0];
	cout << ans << endl;
	return 0;
}
