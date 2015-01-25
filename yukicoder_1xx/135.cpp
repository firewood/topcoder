#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	LL N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	vector<LL> v(N);
	for (LL i = 0; i < N; ++i) {
		ss >> v[i];
	}
	sort(v.begin(), v.end());
	LL ans = 1LL << 60;
	for (LL i = 1; i < N; ++i) {
		if (v[i] != v[i - 1]) {
			ans = min(ans, abs(v[i] - v[i - 1]));
		}
	}
	if (ans >= (1LL << 60)) {
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
