
#include <iostream>
#include <cstdlib>
using namespace std;

/* Check if digit is prime */
bool isPrimeDigit(int d) {
    return (d == 2 || d == 3 || d == 5 || d == 7);
}

/* Check Perfect Number */
bool isPerfect(long long n) {

    if (n <= 1) return false;

    long long sum = 1;

    for (long long i = 2; i * i <= n; i++) {

        if (n % i == 0) {

            sum += i;

            if (i != n / i)
                sum += n / i;
        }
    }

    return (sum == n);
}

int main() {

    long long n;
    cin >> n;

    long long num = llabs(n);

    int digitCount = 0;
    int evenSum = 0;
    int maxPrimeDigit = -1;
    long long product = 1;

    bool hasNonZero = false;

    // Special case: 0
    if (num == 0) {
        digitCount = 1;
        evenSum = 0;
        maxPrimeDigit = -1;
        product = 0;
    }

    long long temp = num;

    while (temp > 0) {

        int d = temp % 10;

        digitCount++;

        // Even sum
        if (d % 2 == 0)
            evenSum += d;

        // Largest prime digit
        if (isPrimeDigit(d))
            maxPrimeDigit = max(maxPrimeDigit, d);

        // Product of non-zero
        if (d != 0) {
            product *= d;
            hasNonZero = true;
        }

        temp /= 10;
    }

    if (!hasNonZero)
        product = 0;

    bool perfect = isPerfect(num);

    cout << "Digits: " << digitCount << endl;
    cout << "EvenSum: " << evenSum << endl;

    if (maxPrimeDigit == -1)
        cout << "LargestPrimeDigit: None" << endl;
    else
        cout << "LargestPrimeDigit: " << maxPrimeDigit << endl;

    cout << "Product: " << product << endl;
    cout << "Perfect: " << (perfect ? "Yes" : "No") << endl;

    return 0;
}