// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int ans = 0;
	long long n, t, a;
	cin >> n >> t >> a;
	t *= 1000, a *= 1000;
	vector<long long> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		if (abs(t - h[i] * 6 - a) < abs(t - h[ans] * 6 - a)) {
			ans = i;
		}
	}
	cout << (ans + 1) << endl;
	return 0;
}
