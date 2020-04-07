// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	int t = a[m - 1];
	int sum = accumulate(a.begin(), a.end(), 0);
	cout << (t * 4 * m < sum ? "No" : "Yes") << endl;
	return 0;
}
