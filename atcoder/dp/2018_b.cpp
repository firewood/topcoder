// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> h(n), cost(n, 1 << 30);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	cost[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (i + j < n) {
				cost[i + j] = min(cost[i + j], cost[i] + abs(h[i + j] - h[i]));
			}
		}
	}
	cout << cost[n - 1] << endl;
	return 0;
}
