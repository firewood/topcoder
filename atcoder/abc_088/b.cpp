// B.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a = 0, b = 0;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];

	}
	sort(x.rbegin(), x.rend());
	for (int i = 0; i < n; ++i) {
		((i % 2) ? b : a) += x[i];
	}
	int ans = a - b;
	cout << ans << endl;
	return 0;
}
