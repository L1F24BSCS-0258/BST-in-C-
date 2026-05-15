#include <iostream>
using namespace std;

void printRow(int row, int col) {
    // Base case: if col > row, print newline and return
    // -- write here --
    if(col > row)
    {
        cout<<endl;
        return;
    }
        cout<<col<<" ";
        printRow(row, col+1);
    // Print current col, then recurse for next col
    // -- write here --
}
 
void printPattern(int n, int row) {
    // Base case: if row > n, return
    // -- write here --
    if(row > n)
    {
        return;
    }
        printRow(row, 1);
        printPattern(n, row+1);
 
    // Print row, then recurse for next row
    // -- write here --
}
 
int main() {
    printPattern(5, 1);
    return 0;
}