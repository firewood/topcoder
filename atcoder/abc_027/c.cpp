// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n;

bool is_win(LL x, LL depth) {
	x = x * 2;
	if (x > n) return false;
	return !is_win(x + (depth % 2), depth - 1);
}

int main(int argc, char* argv[]) {
	cin >> n;
	LL d = 0, x = n;
	while (x > 0) {
		++d;
		x /= 2;
	}
	cout << (is_win(1, d) ? "Takahashi" : "Aoki") << endl;
	return 0;
}
