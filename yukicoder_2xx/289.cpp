#include <iostream>
#include <sstream>
int main() {
	std::string s;
	std::cin >> s;
	int ans = 0;
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			ans += c - '0';
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
