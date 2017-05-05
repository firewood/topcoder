#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int x, y, n, prev;
	cin >> x >> y >> n >> prev;
	bool ans = true;
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		int pos = (prev * y + x - 1) / x;
		if (pos > a) {
			ans = false;
		}
		prev = a;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
