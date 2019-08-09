// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += i >= 1 && i <= 9;
		cnt += i >= 100 && i <= 999;
		cnt += i >= 10000 && i <= 99999;
	}
	cout << cnt << endl;
	return 0;
}
