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

vector<int> solve(int N, int A, int B) {
	if (A + B > N + 1) {
		return {};
	}
	vector<int> ans(N);
	for (int i = 0; i <= A; ++i) {
		if (i + (N - i + B - 1) / B == A) {
			int r = N - ((N - i) % B);
			for (int j = 0; j < N; ++j) {
				if (j < i) {
					ans[j] = j;
				} else if (j < r) {
					ans[j] = i + B - 1 + (j - i) / B * B - ((j - i) % B);
				} else {
					ans[j] = N - 1 - j + r;


				}
			}
			return ans;
		}
	}
	return {};
}

int main() {
	int N, A, B;
	std::cin >> N >> A >> B;
	vector<int> ans = solve(N, A, B);
	if (ans.empty()) {
		cout << "-1" << endl;
	} else {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << (ans[i] + 1);
		}
		cout << endl;
	}
	return 0;
}
