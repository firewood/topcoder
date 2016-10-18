#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    if (c > f) {
        ans = 10000;
    } else if (c == f) {
        if (b > e) {
            ans = (b - e) * 500;
        } else if (b == e) {
            if (a > d) {
                ans = (a - d) * 15;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
