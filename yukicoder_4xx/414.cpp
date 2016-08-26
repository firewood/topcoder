#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long long M, i;
	cin >> M;
	for (i = 2; i * i <= M; ++i) {
		if ((M % i) == 0) {
			break;
		}
	}
	if (i * i > M) {
		i = 1;
	}
	cout << i << " " << M / i << endl;
	return 0;
}
