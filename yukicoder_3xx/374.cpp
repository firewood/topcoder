#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long A, B;
	cin >> A >> B;
	bool ans = A >= B;
	cout << (ans ? "S" : "K") << endl;
	return 0;
}
