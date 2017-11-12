// D.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int solve(int n, int z, int w, vector<int> &a) {
	int ans = abs(a.back() - w);
	if (n >= 2) {
		ans = max(ans, abs(a[n - 2] - a[n - 1]));
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int n, z, w;
	cin >> n >> z >> w;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << solve(n, z, w, a) << endl;
}
