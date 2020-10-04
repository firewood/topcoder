#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

int main() {
	int deg, dis, wl = 0;
	cin >> deg >> dis;
	const double w[] = { 0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7 };
	const string dirs[] = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };
	double ws = (double)dis / 60 + 0.05 + 1e-9;
	for (int i = 1; i <= 12; ++i) {
		if (ws >= w[i]) {
			wl = i;
		}
	}
	string dir = "C";
	if (wl >= 1) {
		dir = dirs[0];
		for (int i = 0; i < 16; ++i) {
			int low = i * 2250 - 1125, high = low + 2250;
			if (deg * 10 >= low && deg * 10 < high) {
				dir = dirs[i];
			}
		}
	}
	cout << dir << " " << wl << endl;
	return 0;
}
