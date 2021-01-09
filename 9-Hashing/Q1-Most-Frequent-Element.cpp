// Find the most frequent element in an array
// I/P = [1,2,3,4,5,4,4,4,2,1];
// O/P = 4

#include <iostream>
#include <unordered_map>
using namespace std;

int main ()
{
    int arr[] = {1,2,3,4,5,1,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    unordered_map<int, int> hashmap;

    for ( auto num : arr ) 
        hashmap[num]++;

    int element = -1;
    int max = 0;
    
    for ( auto i : hashmap ) {
        if ( i.second >= max ) {
            max = i.second;
            element = i.first;
        }
            
    }

    cout << "The most frequnt element is = " << element << " with frequency of = " << max << endl;
    return 0;
}