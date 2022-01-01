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

typedef long double LD;

LD solve(int64_t N, std::vector<int64_t> Ax, std::vector<int64_t> Ay, std::vector<int64_t> Bx, std::vector<int64_t> By) {
	auto get_dists = [&](const vector<int64_t> &x, const vector<int64_t> &y) {
		LD cx = accumulate(x.begin(), x.end(), LD(0)) / N;
		LD cy = accumulate(y.begin(), y.end(), LD(0)) / N;
		LD sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += sqrt((x[i] - cx) * (x[i] - cx) + (y[i] - cy) * (y[i] - cy));
		}
		return sum / N;
	};
	return get_dists(Bx, By) / get_dists(Ax, Ay);
}

int main() {
	cout.precision(20);
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> Ax(N), Ay(N);
	for (int i = 0; i < N; i++) {
		std::cin >> Ax[i] >> Ay[i];
	}
	std::vector<int64_t> Bx(N), By(N);
	for (int i = 0; i < N; i++) {
		std::cin >> Bx[i] >> By[i];
	}
	cout << solve(N, Ax, Ay, Bx, By) << endl;
	return 0;
}
