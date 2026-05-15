#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    // Base case: if start >= end, it is a palindrome
    // -- write here --
    if(start >= end)
    {
        return true;
    }
    
    // If outer characters don't match, not a palindrome
    // -- write here --
    else if(s[start] != s[end])
    {
        
        return false;
    }
    else{
    return isPalindrome(s, start+1, end-1);
    }
    // Recursive case: check inner substring
    // -- write here --
}
 
int main() {
    string s1 = "madam";
    cout << isPalindrome(s1, 0, s1.length()-1) << endl;  // Expected: 1 (true)
    string s2 = "hello";
    cout << isPalindrome(s2, 0, s2.length()-1) << endl;  // Expected: 0 (false)
    return 0;
}