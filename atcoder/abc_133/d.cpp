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
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 2*n; ++i) {
		LL& curr = a[i % n];
		LL& next = a[(i + 1) % n];
		LL diff = next - curr;
		if (diff > 0) {
			LL& nn = a[(i + 2) % n];
			LL d = min(diff, nn);
			r[(i + 2) % n] += 2 * d;
			next -= d;
			nn -= d;
		} else {
			LL& prev = a[(i - 1 + n) % n];
			LL d = min(-diff, prev);
			r[i % n] += 2 * d;
			curr -= d;
			prev -= d;
		}
	}
	LL mn = *min_element(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		a[i] -= mn;
		r[i] += mn;
	}
	for (int i = 0; i < 2 * n; ++i) {
		LL& curr = a[i % n];
		LL& next = a[(i + 1) % n];
		LL d = min(curr, next);
		r[(i + 1) % n] += 2 * d;
		curr -= d;
		next -= d;
	}
	for (int i = 0; i < n; ++i) {
		if (i)cout << " ";
		cout << r[i];
	}
	cout << endl;
	return 0;
}	
