#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
  int ans = (N % 2) ? N : N / 2;
  cout << ans << endl;
	return 0;
}
