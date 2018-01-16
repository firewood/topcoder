// C.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>
#include <bitset>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	const int m = 2000 * 2000 + 1;
	bitset<m> bs;
	bs.set(0);
	for (int i = 0; i < n; ++i) {
		bs |= (bs << a[i]);
	}
	int sum = accumulate(a.begin(), a.end(), 0LL);
	int mid = (sum + 1) / 2;
	for (int i = mid; i <= sum; ++i) {
		if (bs.test(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
