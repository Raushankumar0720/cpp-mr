#include <iostream>
#include <cstdlib>   // for llabs
using namespace std;

/* Check Prime */
bool isPrime(long long n) {

    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

/* Reverse Number */
long long reverseNumber(long long n) {

    long long rev = 0;

    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev;
}

/* Check Armstrong */
bool isArmstrong(long long n) {

    if (n == 0) return true;

    long long temp = n;
    int digits = 0;

    // Count digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    long long sum = 0;

    // Calculate power sum
    while (temp > 0) {

        int d = temp % 10;

        long long power = 1;
        for (int i = 0; i < digits; i++)
            power *= d;

        sum += power;
        temp /= 10;
    }

    return (sum == n);
}

int main() {

    long long n;
    cin >> n;

    long long num = llabs(n);   // convert to positive

    bool prime = isPrime(num);

    long long rev = reverseNumber(num);
    bool palindrome = (rev == num);

    bool armstrong = isArmstrong(num);

    cout << "Prime: " << (prime ? "Yes" : "No") << endl;
    cout << "Palindrome: " << (palindrome ? "Yes" : "No") << endl;
    cout << "Armstrong: " << (armstrong ? "Yes" : "No") << endl;

    return 0;
}