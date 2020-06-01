// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL a;
	double b;
	cin >> a >> b;
	LL ans = a * (LL)round(b * 100) / 100;
	cout << ans << endl;
	return 0;
}
