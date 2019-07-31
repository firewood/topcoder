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
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		cnt += p != i + 1;
	}
	cout << (cnt <= 2 ? "YES" : "NO") << endl;
	return 0;
}
