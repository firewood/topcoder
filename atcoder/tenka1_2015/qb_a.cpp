#include <iostream>
int main(int argc, char *argv[])
{
	int a[100];
	a[0] = 100, a[1] = 100, a[2] = 200;
	for (int i = 3; i < 20; ++i) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	std::cout << a[19] << std::endl;
	return 0;
}
