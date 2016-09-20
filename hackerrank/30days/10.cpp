#include <string>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    while (n) {
        if (n & 1) {
            ++cnt;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
        n >>= 1;
    }
    cout << ans << endl;
    return 0;
}
