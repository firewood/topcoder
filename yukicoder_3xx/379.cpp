#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	int A[100];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<pair<int, int> > v;
	int i = 0, j;
	while (i < N) {
		for (i = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				if (A[i] > A[j]) {
					break;
				}
			}
			if (j < N) {
				v.push_back(make_pair(i, j));
				swap(A[i], A[j]);
				break;
			}
		}
	}
	cout << v.size() << endl;
	for (i = 0; i != v.size(); ++i) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	cin >> N;
	return 0;
}
