// B. 

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N, P[20000], A[20000], B[20000];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	for (int i = 0; i < N; ++i) {
		A[i] = (i + 1) * 30000;
		B[i] = (N - i) * 30000;
	}
	for (int i = 0; i < N; ++i) {
		A[P[i] - 1] += i;
	}
	string delim = "";
	for (int i = 0; i < N; ++i) {
		cout << delim << A[i];
		delim = " ";
	}
	cout << endl;
	delim = "";
	for (int i = 0; i < N; ++i) {
		cout << delim << B[i];
		delim = " ";
	}
	cout << endl;
	return 0;
}
