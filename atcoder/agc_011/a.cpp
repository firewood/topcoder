// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int N, C, K;
	cin >> N >> C >> K;
	int ans = 0, r = 0, bt, t[100000];
	for (int i = 0; i < N; ++i) {
		cin >> t[i];
	}
	sort(t, t + N);
	for (int i = 0; i < N; ++i) {
		if (r > 0 && t[i] <= bt) {
			--r;
		} else {
			++ans;
			r = C - 1;
			bt = t[i] + K;
		}
	}
	cout << ans << endl;
	return 0;
}
