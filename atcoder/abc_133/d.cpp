// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<LL> a(n), r(n);
	LL all_sum = 0, odd_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		all_sum += a[i];
		if (i % 2) {
			odd_sum += a[i];
		}
	}
	r[0] = all_sum - 2 * odd_sum;
	for (int i = 1; i < n; ++i) {
		r[i] = 2 * a[i - 1] - r[i - 1];
	}
	for (int i = 0; i < n; ++i) {
		if (i)cout << " ";
		cout << r[i];
	}
	cout << endl;
	return 0;
}	
