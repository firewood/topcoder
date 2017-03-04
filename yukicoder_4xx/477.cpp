#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long N, K, ans;
	std::cin >> N >> K;
	ans = (N / (K + 1)) + 1;
	std::cout << ans << std::endl;
	return 0;
}
