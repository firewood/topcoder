#include <iostream>
#include <sstream>
#include <algorithm>
int main(int argc, char *argv[]) {
	std::string s;
	std::cin >> s;
	int pos = s.find('w');
	int ans = std::min(pos - 1, (int)s.length() - pos);
	std::cout << ans << std::endl;
	return 0;
}
