// A. 

#include <iostream>
#include <sstream>

using namespace std;

int fib[1001];

void gen(int a, int b) {
	if (b <= 1000) {
		fib[b] = 1;
		gen(b, a + b);
	}
}

int main(int argc, char *argv[])
{
	gen(1, 1);
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; ++i) {
		s += fib[i] ? 'O' : 'o';
	}
	cout << s << endl;
	return 0;
}
