#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string s;
        cin >> s;
        string a[2];
        for (int i = 0; i != s.length(); ++i) {
            a[i % 2] += s[i];
        }
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}
