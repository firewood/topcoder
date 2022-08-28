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

bool solve(int64_t A_x, int64_t A_y, int64_t B_x, int64_t B_y, int64_t C_x, int64_t C_y, int64_t D_x, int64_t D_y) {
	vector<int64_t> x = { A_x, B_x, C_x, D_x };
	vector<int64_t> y = { A_y, B_y, C_y, D_y };
	auto calc = [&](int i, int j, int k) {
		return abs((x[i] - x[k]) * (y[j] - y[k]) - (x[j] - x[k]) * (y[i] - y[k]));
	};
	return calc(0, 1, 2) + calc(2, 3, 0) == calc(1, 2, 3) + calc(3, 0, 1);
}

int main() {
	int64_t A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;
	std::cin >> A_x >> A_y >> B_x >> B_y >> C_x >> C_y >> D_x >> D_y;
	cout << (solve(A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y) ? "Yes" : "No") << endl;
	return 0;
}
