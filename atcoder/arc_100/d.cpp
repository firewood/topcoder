// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> getSum(const vector<LL> &v) {
	vector<LL> sum(1, 0);
	for (LL i = 0; i != v.size(); ++i) {
		sum.push_back(sum[i] + v[i]);
	}
	return sum;
}

int main(int argc, char *argv[]) {
	LL n;
	cin >> n;
	vector<LL> v(n);
	for (LL i = 0; i < n; ++i) {
		cin >> v[i];
	}
	auto getBalancedPositions = [&](const vector<LL> &v, const vector<LL> &sum) {
		vector<LL> pos(n + 1);
		LL left = 1;
		for (LL i = 2; i <= n; ++i) {
			while (left < i - 1) {
				LL a = sum[left], b = sum[i] - sum[left];
				LL na = sum[left + 1], nb = sum[i] - sum[left + 1];
				if (abs(na - nb) >= abs(a - b)) {
					break;
				}
				++left;
			}
			pos[i] = left;
		}
		return pos;
	};
	vector<LL> sum = getSum(v);
	vector<LL> l = getBalancedPositions(v, sum);
	reverse(v.begin(), v.end());
	vector<LL> rsum = getSum(v);
	vector<LL> r = getBalancedPositions(v, rsum);

	LL ans = 1LL << 60;
	for (LL i = 2; i <= n - 2; ++i) {
		LL a = sum[l[i]], b = sum[i] - a;
		LL c = rsum[r[n - i]], d = rsum[n - i] - c;
		LL t = max({ a, b, c, d }) - min({ a, b, c, d });
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}
