#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        int u = sqrt(n);
        int j;
        for (j = 2; j <= u; ++j) {
            if ((n % j) == 0) {
                break;
            }
        }
        cout << ((n > 1 && j > u) ? "Prime" : "Not prime") << endl;
    }
    return 0;
}
