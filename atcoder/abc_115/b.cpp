// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	sort(p.rbegin(), p.rend());
	int ans = accumulate(p.begin(), p.end(), 0LL) - p[0] / 2;
	cout << ans << endl;
	return 0;
}
