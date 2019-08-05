// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

bool possible(const vector<int> &a, int x, int k) {
	int pp = k, mm = k;
	int n = (int)a.size();
	vector<int> rems(n);
	for (int i = 0; i < n; ++i) {
		rems[i] = a[i] % x;
	}
	sort(rems.begin(), rems.end());
	int left = 0;
	for (int right = n - 1; right >= 0; --right) {
		int r = (x - rems[right]) % x;
		pp -= r;
		while (r > 0 && left < right) {
			int m = min(r, rems[left]);
			r -= m;
			rems[left] -= m;
			mm -= m;
			if (rems[left] <= 0) {
				++left;
			}
		}
		if (pp < 0 || mm < 0 || r > 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	vector<int> r(1, sum);
	for (int i = 2; i * i <= sum; ++i) {
		if ((sum % i) == 0) {
			r.push_back(i);
			if (i * i != sum) {
				r.push_back(sum / i);
			}
		}
	}
	sort(r.rbegin(), r.rend());
	int ans = 1;
	for (int x : r) {
		if (possible(a, x, k)) {
			ans = x;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
