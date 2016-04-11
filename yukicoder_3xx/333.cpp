#include <iostream>
int main(int argc, char *argv[])
{
	long long A, B, ans;
	std::cin >> A >> B;
	ans = A > B ? (2000000000 - B - 1) : (B - 2);
	std::cout << ans << std::endl;
	return 0;
}
