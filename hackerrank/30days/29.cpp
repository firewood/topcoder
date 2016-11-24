#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if ((i & j) < k) {
                    ans = max(ans, i & j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
