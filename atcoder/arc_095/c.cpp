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
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<int> y = x;
	sort(y.begin(), y.end());
	int a = y[n / 2 - 1], b = y[n / 2];
	for (int i = 0; i < n; ++i) {
		cout << (x[i] < b ? b : a) << endl;
	}
	return 0;
}
