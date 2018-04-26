// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int x = a.back();
	int y = 0;
	for (int i = 0; i < (n - 1); ++i) {
		if (min(a[i], x - a[i]) > min(y, x - y)) {
			y = a[i];
		}
	}
	cout << x << " " << y << endl;
	return 0;
}
