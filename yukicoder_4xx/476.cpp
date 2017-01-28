#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, a, sum = 0, x;
	cin >> n >> a;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum += x;
	}
	bool ans = a * n == sum;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
