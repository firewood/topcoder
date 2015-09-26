#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		sum = sum * 2 + a;
	}
	cout << sum << endl;
	return 0;
}
