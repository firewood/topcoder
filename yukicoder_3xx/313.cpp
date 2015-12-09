#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char *argv[])
{
	static char buff[200004];
	fread(buff, 1, 200002, stdin);
	int cnt[10] = { 20104, 20063, 19892, 20011, 19874, 20199, 19898, 20163, 19956, 19841 };
	for (int i = 0; i < 200002; ++i) {
		if (i != 1) cnt[buff[i] - '0'] -= 1;
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] == -1) cout << i;
	}
	cout << " ";
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] == 1) cout << i;
	}
	cout << endl;
	return 0;
}
