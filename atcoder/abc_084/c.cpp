// C.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n - 1; ++i) {
		int c, s, f;
		cin >> c >> s >> f;
		for (int j = 0; j <= i; ++j) {
			int k = max(t[j], s);
			k += f - 1;
			k -= k % f;
			k += c;
			t[j] = k;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << t[i] << endl;
	}
	return 0;
}
