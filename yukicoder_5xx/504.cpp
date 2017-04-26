#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k, r = 1;
	cin >> n >> k;
	cout << r << endl;
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		r += a > k;
		cout << r << endl;
	}
	return 0;
}
