// B.

#include <sstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> ans;
	set<int> s;
	LL sum = 0;
	for (int i = 2; i <= 30000; ++i) {
		if ((i % 2) == 0 || (i % 3) == 0) {
			ans.push_back(i);
			sum += i;
			if (ans.size() >= n) {
				break;
			}
			s.insert(i);
		}
	}
	for (int i = 2; i <= 30000; ++i) {
		auto ok = [&] {
			for (int i = 0; i < n; ++i) {
				if (gcd(ans[i], sum - ans[i]) == 1) {
					return false;
				}
			}
			return true;
		};
		if (s.find(i) == s.end()) {
			sum -= ans[n - 1];
			ans[n - 1] = i;
			sum += i;
			if (ok()) {
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << (i ? " " : "") << ans[i];
	}
	cout << endl;

	return 0;
}
