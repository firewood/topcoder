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

int solve(int N, int M, int P) {
	return N >= M ? (1 + (N - M) / P) : 0;
}

int main() {
	int N, M, P;
	std::cin >> N >> M >> P;
	cout << solve(N, M, P) << endl;
	return 0;
}
