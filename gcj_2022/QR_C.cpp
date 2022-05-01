// Google Code Jam 2022 Qualification Round
// Problem C. d1000000 (9pts, 11pts)

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int solve(int N, vector<int> s) {
	int ans = 0, k = 0;
	sort(s.begin(), s.end());
	for (int i = 0; i < N; ++i) {
		while (k < N && s[k] <= i) {
			++k;
		}
		if (k >= N) {
			break;
		}
		++k;
		++ans;
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T, N, C;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		vector<int> s(N);
		for (int i = 0; i < N; ++i) {
			cin >> s[i];
		}
		int ans = solve(N, s);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
