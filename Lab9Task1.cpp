#include<iostream>
using namespace std;

int countDigits(int n) {
    // Base case: if n is 0, no digits remain
    // -- write here --
    int count =  0;
    if (n==0)
    {
        return 0;
    }
    else
    {
        n = n/10;
        count++;
        return count+countDigits(n);
    }
}

int main() {
    cout << countDigits(12345) << endl;  // Expected: 5
    cout << countDigits(9) << endl;  // Expected: 1
    int n;
    cout << "Enter number:";
    cin >> n;
    cout << countDigits(n);
    return 0;
}

