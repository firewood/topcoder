#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	for (int i = 1; i <= 10; ++i) {
		int a;
		cin >> a;
		if (a != i) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
