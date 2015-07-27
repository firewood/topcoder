#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	long long a = N / 2;
	long long ans = (a + 1) * (N - a + 1) - 1;
	cout << ans << endl;
	return 0;
}
