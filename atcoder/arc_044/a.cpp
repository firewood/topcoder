// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int M = sqrt(N);
	bool is_prime = N > 1;
	for (int n = 2; n <= M; ++n) {
		if ((N % n) == 0) {
			is_prime = ((N % 2) != 0 && (N % 10) != 5 && (N % 3) != 0);
			break;
		}
	}
	cout << (is_prime ? "Prime" : "Not Prime") << endl;
	return 0;
}
