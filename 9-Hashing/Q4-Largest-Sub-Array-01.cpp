// Given a binary array , find the lengthh of largest sub array containg equal 0 and 1 
// I/P :  Array = [0,1,1,0,1,1,0]
// O/P = 4

#include <iostream>
#include <unordered_map>
using namespace std;

int iterative_solution(int arr[], int length) 
{
    // Time Complexity = O(N^2)

    int largest_subarray_length = 0;

    for ( int i = 0; i < length; i++ ) {
        int countOf0 = 0;
        int countOf1 = 0;
        for ( int j = i; j < length; j++ ) {
            if ( arr[j] == 1 ) {
                countOf1++;
            }
            else {
                countOf0++;
            }
            if ( countOf0 == countOf1 ) {
                // subarray with equal 0 and 1 found
                if ( j-i > largest_subarray_length ) {
                    largest_subarray_length = j-i+1;
                }
            }
        }
    }

    return largest_subarray_length;
}

int hash_table_solution(int arr[], int length) 
{
    // Time Complexity = O(n)

    unordered_map<int, int> hashmap;
    // hashmap.insert({ 0, -1 }); 
    int prefix_sum = 0;
    int longest_length = 0;
    int index = 0;

    for ( int i = 0; i < length; i++ ) {
        if ( arr[i] == 1)
            prefix_sum += 1;
        else 
            prefix_sum -= 1;
        if ( hashmap.find(prefix_sum) != hashmap.end() ) {
            if ( i - hashmap.at(prefix_sum) >= longest_length ) {
                // cout << "I = " << i << " and J = " << hashmap.at(prefix_sum) << endl;
                longest_length = i - hashmap.at(prefix_sum);
            }            
        }
        else {
            hashmap.insert({prefix_sum, index});
            index++;
        }        
    }

    return longest_length;
}

int main ()
{
    int arr[] = {1,1,1,1,0,0,1,1,0,0};
    int length = sizeof(arr)/sizeof(int);
     
    // int longest_length = iterative_solution(arr,length);
    int longest_length = hash_table_solution(arr, length);

    if ( longest_length >= 1)
        cout << "FOUND: Subarray with equal 0 and 1 *** Length " << longest_length << endl;
    else 
        cout << "NOT FOUND: Subarray with equal 0 and 1 *** Length = " << longest_length << endl;
    
    return 0;
}