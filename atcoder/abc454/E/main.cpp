#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const char dirs[4] = { 'R', 'D', 'L', 'U' };
enum { RIGHT, DOWN, LEFT, UP };

string solve(int64_t N, int64_t A, int64_t B) {
	if ((N % 2) != 0 || ((A + B) % 2) == 0) {
		return "";
	}
	string ans;
	int y = 0, x = 0;
	auto move = [&](int dir) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny == A && nx == B) {
			return false;
		}
		y = ny;
		x = nx;
		ans += dirs[dir];
		return true;
	};
	for (int64_t i = 0; i < N; i += 2) {
		while (y < i) {
			move(DOWN);
		}
		if (i == A || i + 1 == A) {
			while (x < N - 1) {
				if (!move(DOWN)) {
					move(RIGHT);
					if (x >= N - 1) break;
					move(DOWN);
				}
				move(RIGHT);
				if (x >= N - 1) break;
				if (!move(UP)) {
					move(RIGHT);
					if (x >= N - 1) break;
					move(UP);
				}
				move(RIGHT);
			}
		} else {
			int dir = x == 0 ? RIGHT : LEFT;
			for (int64_t i = 0; i < N - 1; ++i) move(dir);
			move(DOWN);
			for (int64_t i = 0; i < N - 1; ++i) move(dir ^ 2);
		}
	}
	while (y < N - 1) {
		move(DOWN);
	}
	return ans;
}

void process_case() {
	int64_t N, A, B;
	std::cin >> N >> A >> B;
	--A;
	--B;
	auto ans = solve(N, A, B);
	if (ans.empty()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		cout << ans << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
