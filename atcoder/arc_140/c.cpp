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

int get_lis(const vector<int>& a) {
	size_t N = a.size();
	vector<int> c(N, 1 << 30);
	for (int i = 0; i < N; ++i) {
		*lower_bound(c.begin(), c.end(), a[i]) = a[i];
	}
	return int(lower_bound(c.begin(), c.end(), 1 << 30) - c.begin());
}

int eval(const vector<int>& a) {
	size_t N = a.size();
	vector<int> v(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		v[i] = abs(a[i] - a[i + 1]);
	}
	return get_lis(v);
}

vector<int> solve(int N, int X) {
	vector<int> ans(N);
	ans[0] = X;
	int left = 0, right = N - 1;
	bool f = X < N / 2;
	for (int i = N - 1; i > 0; --i) {
		if (!f) {
			left += left == X;
			ans[i] = left++;
		} else {
			right -= right == X;
			ans[i] = right--;
		}
		f = !f;
	}
	return ans;
}

vector<int> solve2(int N, int X) {
	int mx = 0;
	vector<int> ans(N);
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	do {
		if (seq[0] != X) {
			continue;
		}
		int cnt = eval(seq);
		if (mx < cnt) {
			mx = cnt;
			ans = seq;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	return ans;
}

int main() {
/*
	{
		for (int tt = 0; tt < 1000; ++tt) {
			int N = 1 + (rand() % 6);
			int X = rand() % N;
			vector<int> p = solve(N, X);
			vector<int> q = solve2(N, X);
			int a = eval(p);
			int b = eval(q);
			if (a != b) {
				a += 0;
			}
		}
	}
*/
	int N, X;
	std::cin >> N >> X;
	--X;
	vector<int> ans = solve(N, X);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
	return 0;
}
