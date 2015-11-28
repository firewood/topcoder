#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	for (int i = 0; i < 1000; ++i) {
		printf("%03d\n", i);
		fflush(stdout);
		char buff[1024];
		fgets(buff, 1024, stdin);
		if (buff[0] == 'u') {
			break;
		}
	}
	return 0;
}
