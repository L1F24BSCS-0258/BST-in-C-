#include<iostream>
#include <string>
using namespace std;
int fibonacci(int n) {
    if(n<=0)
    {
        return n;
    }
    else{
        return  fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    cout<<"fibonacci(0) = "<<-fibonacci(0)<<endl;
    cout<<"fibonacci(1) = "<<-fibonacci(1)<<endl;
    cout<<"fibonacci(5) = "<<-fibonacci(5)<<endl;
    cout<<"fibonacci(6) = "<<-fibonacci(6)<<endl;
    cout<<"fibonacci(10) = "<<-fibonacci(10)<<endl;
    return 0;
}



