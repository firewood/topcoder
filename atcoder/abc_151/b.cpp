// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k, m, sum = 0, a;
	cin >> n >> k >> m;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a;
		sum += a;
	}
	int r = max(0, m * n - sum);
	cout << ((r > k) ? -1 : r) << endl;
	return 0;
}
