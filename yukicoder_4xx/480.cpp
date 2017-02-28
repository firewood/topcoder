#include <iostream>
int main(int argc, char *argv[]) {
	int N;
	std::cin >> N;
	int ans = (N * (N + 1)) / 2;
	std::cout << ans << std::endl;
	return 0;
}
