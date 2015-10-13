#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int L, N;
	cin >> L >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
	}
	long long ans = (1LL << (L - 3)) * N;
	cout << ans << endl;
	return 0;
}
