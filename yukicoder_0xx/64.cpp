#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL A, B, N;
	cin >> A >> B >> N;
	LL a[3] = { A, B, A ^ B };
	cout << a[N % 3] << endl;
	return 0;
}
