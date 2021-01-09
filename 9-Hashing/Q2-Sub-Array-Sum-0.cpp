// Given an array, find if there is a subarray with sum 0 
// I/P = [5,6,-4,-2,8,10];
// O/P = true

#include <iostream>
#include <unordered_set>
using namespace std;

bool iterative_solution(int arr[], int length) 
{
    // Time Complexity = O(n^2)
    // Using 2 for-loops 

    for ( int i = 0; i < length; i++ ) {
        int size_of_sub_array = 0;
        for ( int j = i; j < length; j++ ) {
            size_of_sub_array += arr[j];
            if ( size_of_sub_array == 0 ) 
                return true;
        }
    }
    return false;
}

bool hash_table_solution(int arr[], int length) 
{
    // Time Complexity = O(n)
    // Using prefix sum and hashing 

    unordered_set<int> hashset;
    hashset.insert(0); 
    int prefix_sum = 0;
    for ( int i = 0; i < length; i++ ) {
        prefix_sum += arr[i];
        if ( hashset.find(prefix_sum) != hashset.end() ) {
            // Hashset contains this number already 
            // hence, sub array exists
            return true;
        }
        hashset.insert(prefix_sum);
    }
    return false;
}

int main ()
{
    int arr[] = {1, 2, 3, 5, -5, 10};
    int length = sizeof(arr)/sizeof(int);
    
    // if ( iterative_solution(arr, length)) 
    if ( hash_table_solution(arr, length))
        cout << "FOUND: Sub array with 0 sum " << endl;
    else 
        cout << "NOT FOUND: Sub array with 0 sum" << endl;
    return 0;
}