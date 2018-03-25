// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	LL sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += abs(a[i - 1] - a[i]);
	}
	sum += abs(a[n] - a[0]);

	for (int i = 1; i <= n; ++i) {
		LL x = sum;
		x -= abs(a[i - 1] - a[i]);
		x -= abs(a[i + 1] - a[i]);
		x += abs(a[i - 1] - a[i + 1]);
		cout << x << endl;
	}
	return 0;
}
