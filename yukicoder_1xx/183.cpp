#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	int f[32768];
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < 32768; ++j) {
			if (f[j] < i) {
				f[j ^ a] = i;
			}
		}
	}

	int ans = 0;
	for (int j = 0; j < 32768; ++j) {
		ans += f[j] <= N;
	}
	cout << ans << endl;

	return 0;
}
