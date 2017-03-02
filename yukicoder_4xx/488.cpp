#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int N, M, d[50][50] = {};
	std::cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1, d[b][a] = 1;
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				for (int l = k + 1; l < N; ++l) {
					ans += (d[i][j] && d[i][k] && !d[i][l] && d[j][l] && d[l][k] && !d[j][k]);
					ans += (d[i][j] && d[i][l] && !d[i][k] && d[j][k] && d[l][k] && !d[j][l]);
					ans += (d[j][k] && d[j][l] && !d[i][j] && d[k][i] && d[i][l] && !d[k][l]);
				}
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
