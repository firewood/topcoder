#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	unordered_map<int, int> m;
	int ans = N;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		m[n] += 1;
		if (m[n] == 2) {
			ans -= 2;
		} else if (m[n] > 2) {
			--ans;
		}
	}
	cout << ans << endl;
	return 0;
}
