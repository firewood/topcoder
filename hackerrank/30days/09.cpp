#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n) {
    return n > 1 ? (n * factorial(n - 1)) : 1;
}

int main() {
    int N;
    cin >> N;
    cout << factorial(N) << endl;
    return 0;
}
