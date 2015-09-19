#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long N, Z[50];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> Z[i];
	}
	cout << Z[N - 1] << "/" << Z[0] << endl;
	return 0;
}
