// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;

int main(int argc, char* argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = k; i < n; ++i) {
		cout << (a[i - k] < a[i] ? "Yes" : "No") << endl;
	}
	return 0;
}
