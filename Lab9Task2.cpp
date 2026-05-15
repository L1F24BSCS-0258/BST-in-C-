#include<iostream>
using namespace std;


int sumOfDigits(int n) {
    int sum = 0;
    if(n==0)
    {
        return 0;
    }
    else{
        sum = n%10;
        n = n/10;
        return sum+sumOfDigits(n);
    }
}
 
int main() {
    cout << sumOfDigits(1234) << endl;  // Expected: 10
    cout << sumOfDigits(567)  << endl;     // Expected: 18
    cout << sumOfDigits(999)  << endl;
    cout << sumOfDigits(100)  << endl;
    return 0;
}

