// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	LL sq = (LL)sqrt(n);
	vector<LL> sum;
	for (LL i = 1; i <= sq; ++i) {
		if ((n % i) == 0) {
			LL x = n / i;
			LL a = ((x - 1) * x) / 2 * i + x;
			sum.push_back(a);
			LL y = n / x;
			a = ((y - 1) * y) / 2 * x + y;
			sum.push_back(a);
		}
	}
	sort(sum.begin(), sum.end());
	size_t sz = unique(sum.begin(), sum.end()) - sum.begin();
	for (int i = 0; i != sz; ++i) {
		if (i) {
			cout << " ";
		}
		cout << sum[i];
	}
	cout << endl;
	return 0;
}
