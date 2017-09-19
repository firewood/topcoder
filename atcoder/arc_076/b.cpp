// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a[100000], f[100000] = {};
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	int pos = 0, ans = 0;
	while (pos != 1 && !f[pos]) {
		++ans;
		f[pos] = 1;
		pos = a[pos];
	}
	cout << (pos == 1 ? ans : -1) << endl;
	return 0;
}
