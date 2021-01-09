// Given an array and a sum, find if there is a subarray with given sum 
// I/P :  Array = [5,3,8,-2,8,10] & Sum = 11;
// O/P = true

#include <iostream>
#include <unordered_set>
using namespace std;

bool hash_table_solution(int arr[], int length, int x) 
{
    unordered_set<int> hashset;
    hashset.insert(0); 
    int prefix_sum = 0;
    
    for ( int i = 0; i < length; i++ ) {
        prefix_sum += arr[i];
        if ( hashset.find(prefix_sum-x) != hashset.end() )
            return true;
        hashset.insert(prefix_sum);
    }
    return false;
}

int main ()
{
    int arr[] = {1, 2, 3, 5, -5, 10};
    int length = sizeof(arr)/sizeof(int);
    int sum = 11;
     
    if ( hash_table_solution(arr, length, sum))
        cout << "FOUND: Sub array with given sum " << endl;
    else 
        cout << "NOT FOUND: Sub array with given sum" << endl;
    return 0;
}