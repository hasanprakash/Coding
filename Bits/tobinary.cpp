#include <bits/stdc++.h>
using namespace std;
string toBinary(int num) {
    string binary = "";
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}
string toBinaryOfFixedLength(int num, int length) {
    string binary = toBinary(num);
    while (binary.length() < length) {
        binary = "0" + binary;
    }
    return binary;
}
int toDecimal(string binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++) {
        decimal += (binary[i] - '0') * pow(2, binary.length() - i - 1);
    }
    return decimal;
}
int main() {
    int num;
    cin >> num;
    cout << toBinary(num);
    return 0;
}