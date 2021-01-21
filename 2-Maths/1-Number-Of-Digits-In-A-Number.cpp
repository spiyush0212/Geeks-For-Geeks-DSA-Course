#include <iostream>
#include <cmath>
using namespace std;

int iterativeSolution ( int n ) {
    int count = 0;
    while ( n != 0 ) {
        n = n / 10;
        count++;
    }
    return count;
}

int recursiveSolution ( int n ) {
    if ( n == 0 ) {
        return 0;
    }
    else {
        return 1 + recursiveSolution(n/10);
    }
}

int logSolution ( int n ) {
    return floor(log10(n)) + 1;
}

int main()
{
    int num = 111;
    // int digits = iterativeSolution(num);
    // int digits = recursiveSolution(num);
    int digits = logSolution(num);
    cout << "Number of digits in " << num << " = " << digits << endl;
    return 0;
}