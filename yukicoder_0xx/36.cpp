#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream sa(s);
	LL N;
	sa >> N;
	LL m = sqrt(N);
	LL f = 0;
	for (LL n = 2; n <= m; ++n) {
		while ((N % n) == 0) {
			++f;
			N /= n;
		}
	}
	f += N > 1;
	bool ans = f >= 3;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
