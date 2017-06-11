#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	long long n, k, c = 0;
	cin >> n >> k;
	int d[200001];
	int r[200001];
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		r[d[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (d[i] != i) {
			++c;
			int pos = r[i];
			swap(d[i], d[pos]);
			r[i] = i;
			r[d[pos]] = pos;
		}
	}
	bool ans = c <= k && ((k - c) % 2) == 0;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
