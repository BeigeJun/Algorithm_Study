#include <iostream>

using namespace std;

int main(void) {
    int a;
    int c;
    cin >> a >> c;
    int a_s = a*a, c_s = c*c;
    int b_square = c_s - a_s;
    cout << b_square << endl;
    return 0;
}
