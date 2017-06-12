#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, v[100], w[100];

int get_max_value(int max_weight) {
	int dp[100001];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = max_weight; j >= w[i]; --j) {
			int k = dp[j - w[i]];
			if (k >= 0) {
				dp[j] = max(dp[j], k + v[i]);
			}
		}
	}
	return *max_element(dp, dp + max_weight + 1);
}

int main(int argc, char *argv[]) {
	int total_weight = 0, total_value = 0, max_value;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> v[i] >> w[i];
		total_value += v[i];
		total_weight += w[i];
	}
	cin >> max_value;
	int low = 0, high = total_weight;
	while (high - low > 1) {
		int med = (high + low) / 2;
		if (get_max_value(med) >= max_value) {
			high = med;
		} else {
			low = med;
		}
	}
	cout << high << endl;
	if (max_value == total_value) {
		cout << "inf" << endl;
	} else {
		low = high;
		high = total_weight;
		while (high - low > 1) {
			int med = (high + low) / 2;
			if (get_max_value(med) > max_value) {
				high = med;
			} else {
				low = med;
			}
		}
		cout << low << endl;
	}
	return 0;
}
