#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int N, K;
	cin >> N >> K;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	int ans = 0;
	if (a != b) {
		for (int i = 0; i < K; ++i) {
			vector<int> c;
			for (int j = i; j < N; j += K) {
				c.push_back(a[j]);
			}
			for (int j = 0; j != c.size(); ++j) {
				for (int k = j + 1; k != c.size(); ++k) {
					ans += c[j] > c[k];
				}
			}
			sort(c.begin(), c.end());
			for (int j = i; j < N; j += K) {
				a[j] = c[j/K];
			}
		}
		if (a != b) {
			ans = -1;
		}
	}
	cout << ans << endl;
	return 0;
}
