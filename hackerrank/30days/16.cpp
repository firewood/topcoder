#include <ctime>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string S;
    cin >> S;
    try {
        std::istringstream iss(S);
        iss.exceptions(std::ios::failbit);
        int n;
        iss >> n;
        cout << n << endl;
    } catch (...) {
        cout << "Bad String" << endl;
    }
    return 0;
}
