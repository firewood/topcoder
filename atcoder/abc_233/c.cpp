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

int main() {
	int64_t N, X, Y, Z, ans = 0;
	map<int64_t, int64_t> m;
	m[1] = 1;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		map<int64_t, int64_t> nm;
		cin >> Y;
		for (int j = 0; j < Y; ++j) {
			cin >> Z;
			for (auto kv : m) {
				int64_t nx = kv.first * Z;
				if (nx <= X && nx / Z == kv.first) {
					nm[nx] += kv.second;
				}
			}
		}
		m = nm;
	}
	cout << m[X] << endl;
	return 0;
}
