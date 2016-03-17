#include <iostream>
#include <sstream>
#include <algorithm>
int main() {
	std::string s;
	std::cin >> s;
	std::sort(s.rbegin(), s.rend());
	std::cout << s << std::endl;
	return 0;
}
