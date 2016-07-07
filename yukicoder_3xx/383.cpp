#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long A, B;
	cin >> A >> B;
	if (A < B) {
		cout << "+";
	}
	cout << (B - A) << endl;
	return 0;
}
