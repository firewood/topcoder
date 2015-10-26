#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
	int N, M;
	cin >> N >> M;
	int a[100001] = {};
	int b[100001] = {};
	for (int i = 0; i != N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i != M; ++i) {
		cin >> b[i];
	}
	sort(a, a + N);
	sort(b, b + M);
	int pos = N - 1;
	for (int i = M - 1; i >= 0; --i) {
		if (pos < 0 || a[pos] < b[i]) {
			cout << "NO" << endl;
			return 0;
		}
		--pos;
	}
	cout << "YES" << endl;
	return 0;
}
