// C.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

int main(int argc, char *argv[])
{
	IIVec v;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		v.push_back(II(a, i));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += (i % 2) != (v[i].second % 2);
	}
	cout << ans / 2 << endl;
	return 0;
}
