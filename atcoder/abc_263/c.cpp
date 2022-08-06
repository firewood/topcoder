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

int N;
int M;

vector<int> seq(10);

void dfs(int i, int k) {
	if (i == N) {
		for (int i = 0; i < N; ++i) {
			if (i) cout << " ";
			cout << seq[i];
		}
		cout << endl;
		return;
	}
	for (int j = k + 1; j <= M; ++j) {
		seq[i] = j;
		dfs(i + 1, j);
	}
}

void solve() {
	dfs(0, 0);
}

int main() {
	std::cin >> N >> M;
	solve();
	return 0;
}
