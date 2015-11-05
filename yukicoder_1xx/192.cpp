#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	cout << (N - (N % 2)) << endl;
	return 0;
}
