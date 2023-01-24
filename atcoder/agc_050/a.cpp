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
	for (int i = 0; i < N; ++i) {
		cout << (((i * 2) % N) + 1) << " " << (((i * 2 + 1) % N) + 1) << endl;
	}
}

int main() {
	int64_t N;
	std::cin >> N;
	solve(N);
	return 0;
}
