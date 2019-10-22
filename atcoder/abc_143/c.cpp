// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, ans = 0;
		cin >> n;
		if (n <= 0) break;
		string s;
		cin >> s;
		char prev = -1;
		for (char c : s) {
			ans += c != prev;
			prev = c;
		}
		cout << ans << endl;
	}
	return 0;
}
