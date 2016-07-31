// B. 

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N, M, cnt[100000] = {}, red[100000] = { 1 };
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cnt[i] = 1;
	}
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (red[x]) {
			red[y] = 1;
		}
		if (--cnt[x] == 0) {
			red[x] = 0;
		}
		++cnt[y];
	}
	int ans = accumulate(red, red + N, 0);
	cout << ans << endl;
	return 0;
}
