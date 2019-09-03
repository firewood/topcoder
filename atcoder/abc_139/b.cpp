// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, curr = 1, ans = 0;
	cin >> a >> b;
	while (curr < b) {
		++ans;
		--curr;
		curr += a;
	}
	cout << ans << endl;
	return 0;
}
