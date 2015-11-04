#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	int tot = 0;
	int c[100];
	for (int i = 0; i < N; ++i) {
		cin >> c[i];
		tot += c[i];
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += c[i] * 10 <= tot;
	}
	cout << ans * 30 << endl;
	return 0;
}
