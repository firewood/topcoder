// Google Code Jam 2022 Round 1B
// Problem A. Pancake Deque (7pts, 8pts, 10pts)

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int solve(deque<int> p) {
	int mx = 0, ans = 0;
	while (!p.empty()) {
		int top;
		if (p.front() <= p.back()) {
			top = p.front();
			p.pop_front();
		} else {
			top = p.back();
			p.pop_back();
		}
		ans += top >= mx;
		mx = max(mx, top);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T, N, x;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		deque<int> p;
		for (int i = 0; i < N; ++i) {
			cin >> x;
			p.push_back(x);
		}
		int ans = solve(p);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
