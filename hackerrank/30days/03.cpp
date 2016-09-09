#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double meal, tip, tax;
    cin >> meal >> tip >> tax;
    int ans = (int)floor(meal * (1 + tip * 0.01 + tax * 0.01) + 0.5);
    cout << "The total meal cost is " << ans << " dollars." << endl;
    return 0;
}
