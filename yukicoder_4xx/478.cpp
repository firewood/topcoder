#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k, s = 1;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cout << " " << s;
		s += 2;
	}
	for (int i = k; i < n; ++i) {
		const int p[] = { 2, -1, 2, -3 };
		cout << " " << s;
		s += p[(i - k) % 4];
	}
	cout << endl;
	return 0;
}
