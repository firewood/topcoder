#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int getres(const char *w) {
	printf("%s\n", w);
	fflush(stdout);
	char buff[1024];
	fgets(buff, 1024, stdin);
	return atoi(buff);
}

int main(int argc, char *argv[])
{
	char w[16] = "0000000000";
	int a = getres(w);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			w[i] = '0' + j;
			int b = getres(w);
			if (b < a) {
				w[i] = '0' + j - 1;
				break;
			}
			if (b > a) {
				a = b;
				break;
			}
		}
	}
	return 0;
}
