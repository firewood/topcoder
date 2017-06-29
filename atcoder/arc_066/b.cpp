// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m, p, x, t[100000], sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		sum += t[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> p >> x;
		cout << (sum - t[p - 1] + x) << endl;
	}
	return 0;
}
