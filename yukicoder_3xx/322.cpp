#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	vector<pair<double, int> > v(N);
	for (int i = 0; i < N; ++i) {
		v[i].second = i + 1;
		cin >> v[i].first;
	}
	for (int i = 0; i < N; ++i) {
		double d;
		cin >> d;
		v[i].first /= d;
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < N; ++i) {
		if (i) {
			cout << " ";
		}
		cout << v[i].second;
	}
	cout << endl;
	return 0;
}
