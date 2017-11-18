// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	long long a = 2, b = 1, n;
	cin >> n;
	for (long long i = 1; i < n; ++i) {
		long long c = a + b;
		a = b, b = c;
	}
	cout << b << endl;
	return 0;
}
