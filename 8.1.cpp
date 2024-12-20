#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// Функция для сложения двоичных строк
string binarySum(const string& a, const string& b) {
    string result;
    int carry = 0;
    int aLen = a.length();
    int bLen = b.length();
    int maxLen = max(aLen, bLen);
    string aPadded = string(maxLen - aLen, '0') + a;
    string bPadded = string(maxLen - bLen, '0') + b;
    for (int i = maxLen - 1; i >= 0; --i) {
        int sum = (aPadded[i] - '0') + (bPadded[i] - '0') + carry;
        result.push_back((sum % 2) + '0');
        carry = sum / 2; 

    if (carry) {
        result.push_back('1'); 
    }

    reverse(result.begin(), result.end()); 
    return result;
}
    int main() {
    string A = "101101"; 
    string B = "110011"; 

    bitset<6> aBitset(A);
    bitset<6> bBitset(B);
    bitset<6> andResult = aBitset & bBitset;

    
    cout << "Результат A AND B: " << andResult << endl;

    string sumResult = binarySum(A, B);

  
    cout << "Сумма A и B в двоичной системе: " << sumResult << endl;

    return 0;
}
