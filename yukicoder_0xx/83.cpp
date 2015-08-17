#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	string s(N / 2, '1');
	s[0] = (N % 2) ? '7' : '1';
	cout << s << endl;
	return 0;
}
