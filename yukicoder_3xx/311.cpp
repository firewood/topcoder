#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	long long N;
	cin >> N;
	long long ans = (N / 3 + N / 5) * 2;
	cout << ans << endl;
	return 0;
}
