// B.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	int n, l, r, a;
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cin >> a;
    cout << max(l, min(r, a));
	}
  cout << endl;
	return 0;
}
