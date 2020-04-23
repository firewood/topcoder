// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, a;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a;
		r[a - 1] += 1;
	}
	for (int i = 0; i < n; ++i) {
		cout << r[i] << endl;
	}
	return 0;
}
