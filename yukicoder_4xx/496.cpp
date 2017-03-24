#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int Gx, Gy, N, F;
	cin >> Gx >> Gy >> N >> F;
	int cost[101][101];
	for (int i = 0; i <= Gy; ++i) {
		for (int j = 0; j <= Gx; ++j) {
			cost[i][j] = (i + j) * F;
		}
	}
	for (int i = 0; i < N; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		for (int j = Gy - y; j >= 0; --j) {
			for (int k = Gx - x; k >= 0; --k) {
				cost[j + y][k + x] = min(cost[j + y][k + x], cost[j][k] + c);
			}
		}
	}
	cout << cost[Gy][Gx] << endl;
	return 0;
}
