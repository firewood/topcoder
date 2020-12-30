#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
	int x, y;
	cin >> x >> y;
	if (y <= 0) {
		cout << "ERROR" << endl;
	} else {
		int ans = (x * 100) / y;
		printf("%.02f\n", ans * 0.01);
	}
	return 0;
}
