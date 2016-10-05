// C.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

int main(int argc, char *argv[])
{
	int N, M;
	cin >> N >> M;
	M = min(N, M);
	int a[2000] = {}, cnt[2001] = {}, mx[2001] = {}, del[2001] = {};
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		if (a[i] <= M) {
			++cnt[a[i]];
		} else {
			v.push_back(i);
		}
	}
	int r = N % M;
	for (int i = 1; i <= M; ++i) {
		int d = cnt[i] - N / M;
		if (d > 0) {
			int c = min(d, r);
			r -= c;
			del[i] = d - c;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (a[i] <= M && del[a[i]] > 0) {
			v.push_back(i);
			--del[a[i]];
		}
	}
	priority_queue<II> q;
	for (int i = 1; i <= M; ++i) {
		q.push(II(-cnt[i], i));
	}
	int ans = 0;
	while (v.size() > 0) {
		II t = q.top();
		if (-t.first >= (N / M)) {
			break;
		}
		++ans;
		q.pop();
		int i = v.back();
		v.pop_back();
		a[i] = t.second;
		q.push(II(t.first - 1, t.second));
	}
	cout << (N / M) << " " << ans << endl;
	for (int i = 0; i < N; ++i) {
		cout << (i > 0 ? " " : "") << a[i];
	}
	cout << endl;
	return 0;
}
