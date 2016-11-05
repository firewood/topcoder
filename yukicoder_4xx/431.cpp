#include <iostream>
int main(int argc, char *argv[]) {
	int d[3], s;
	std::cin >> d[0] >> d[1] >> d[2] >> s;
	std::cout << (((d[0] + d[1] + d[2]) < 2 || s) ? "SURVIVED" : "DEAD") << std::endl;
	return 0;
}
