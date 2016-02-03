#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int K, N, F;
	cin >> K >> N >> F;
	int tot = K * N;
	for (int i = 0; i < F; ++i) {
		int A;
		cin >> A;
		tot -= A;
	}
	cout << max(-1, tot) << endl;
	return 0;
}
