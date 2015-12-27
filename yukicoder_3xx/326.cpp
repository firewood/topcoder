#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int N, K;
	cin >> N >> K;
	int p[101];
	for (int i = 1; i <= 100; ++i) {
		p[i] = i;
	}
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		swap(p[x], p[y]);
	}
	int target[101];
	for (int i = 1; i <= N; ++i) {
		cin >> target[i];
	}
	vector<int> v;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (target[j] == i) {
				for (int k = 1; k <= N; ++k) {
					if (p[k] == j) {
						while (k > i) {
							--k;
							v.push_back(k);
							swap(p[k], p[k + 1]);
						}
					}
				}
			}
		}
	}

	cout << v.size() << endl;
	for (int i = 0; i != v.size(); ++i) {
		cout << v[i] << " " << (v[i] + 1) << endl;
	}

	return 0;
}
