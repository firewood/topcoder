#include <iostream>
int main(int argc, char *argv[]) {
	int H, W;
	std::cin >> H >> W;
	std::cout << (H > W ? "TATE" : "YOKO") << std::endl;
	return 0;
}
