#include <iostream>
#include <cmath>
using namespace std;

bool iterativeSolution ( int n ) {
    bool prime = false;
    int factors = 0;
    for ( int i = 1; i <= n; i++ ) {
        if ( n % i == 0 ) {
            factors++;
        }
    } 
    if ( factors == 2 ) {
        prime = true;
    }
    return prime;
}

int main()
{
    int num = 66;
    bool prime = iterativeSolution(num);
    
    cout << "Is " << num << " a prime number? " << endl;
    if ( prime ) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}