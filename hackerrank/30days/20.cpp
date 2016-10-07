#include <string>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int numberOfSwaps = 0;
    int i = 0;
    while (i < n) {
        for (i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                numberOfSwaps++;
                break;
            }
        }
    }
    cout << "Array is sorted in " << numberOfSwaps << " swaps." << endl;
    cout << "First Element: " << a.front() << endl;
    cout << "Last Element: " << a.back() << endl;
    return 0;
}
