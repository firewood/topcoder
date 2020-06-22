// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int n, a, q;
	cin >> n;
	map<int, int> m;
	LL sum = 0, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		m[a] += 1;
		sum += a;
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> b >> c;
		LL d = m[b];
		m[b] = 0;
		sum -= b * d;
		m[c] += d;
		sum += c * d;
		cout << sum << endl;
	}
	return 0;
}
