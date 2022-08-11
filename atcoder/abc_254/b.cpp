#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

void solve(int64_t N) {
	int64_t C[32][32] = { };
	for (int i = 0; i < N; ++i) {
		C[i][0] = 1;
		cout << "1";
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			cout << " " << C[i][j];
		}
		cout << endl;
	}
}

int main() {
	int64_t N;
	std::cin >> N;
	solve(N);
	return 0;
}
