#include <iostream>
using namespace std ;

int main () {

    int n;

    cin >>  n ;
    int sum = 0 , temp = n , digit , maxDigit = 0 , reverse = 0 ;

    while(temp > 0){
        digit = temp % 10 ;
        sum += digit;
        if(digit > maxDigit){
            maxDigit = digit;
        }
        reverse = reverse * 10 + digit ;
        temp = temp/10;

    }

    cout << "sum : " <<  sum << endl ;
    cout << "MaxDigit : " << maxDigit << endl ;
    cout << "Reverse No. : " << reverse << endl;
    


    return 0;
}


///////////////////////////////////////////////////////////////

            // more optimised code 

////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

int main() {

    long long n;
    cin >> n;

    long long temp = n;

    // Handle negative
    if (temp < 0)
        temp = -temp;

    int sum = 0;
    int maxDigit = -1;
    long long reverse = 0;

    // Special case: n == 0
    if (temp == 0) {
        maxDigit = 0;
    }

    while (temp > 0) {
        int digit = temp % 10;

        sum += digit;
        maxDigit = max(maxDigit, digit);
        reverse = reverse * 10 + digit;

        temp /= 10;
    }

    // Restore sign
    if (n < 0)
        reverse = -reverse;

    cout << "Sum: " << sum << endl;
    cout << "Max Digit: " << maxDigit << endl;
    cout << "Reverse: " << reverse << endl;

    return 0;
}
