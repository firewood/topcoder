#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 1;
    for (char c : s) {
        ans += c <= 'Z';
    }
    cout << ans << endl;
    return 0;
}
