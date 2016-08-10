#include <iostream>
#include <sstream>
int main() {
	int N, K;
	std::cin >> N >> K;
	std::string ans = N == K ? "Drew" : (N == (K + 2) % 3 ? "Won" : "Lost");
	std::cout << ans << std::endl;
	return 0;
}
