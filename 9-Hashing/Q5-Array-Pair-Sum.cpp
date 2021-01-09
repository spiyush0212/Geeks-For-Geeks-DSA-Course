// Given an unsorted array and a number x, find if there is a pair with sum = x 
// I/P :  Array = [3,5,2,8,11,7] & X = 16
// O/P = true

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool iterative_solution(int arr[], int length, int x) 
{
    // Time Complexity = O(n^2)

    for ( int i = 0; i < length; i++ ) {
        int num = arr[i];
        int num_left = x - num;
        for ( int j = 0; j < length; j++ ) {
            if ( j != i && arr[j] == num_left ) {
                // pair found
                cout << arr[i] << " " << arr[j] << endl;
                return true;
            }
        }
    }

    // pair not found 
    return false;
}

bool hash_map_solution(int arr[], int length, int sum)
{
    // Time complexity = O(n)

    unordered_map<int, int> hm;
    for ( int i = 0; i < length; i++) {
        hm[arr[i]]++;
    }

    for ( auto i : hm ) {
        int first_num = i.first;
        i.second -= 1;
        int second_num = sum - first_num;
        if ( hm.find(second_num) != hm.end() ) {
            if ( hm.at(second_num) >= 1) {
                // pair found
                cout << first_num << " and " << second_num << endl;
                return true;
            }
        }
        i.second += 1;
    }

    // pair not found
    return false;

}

bool hash_set_solution(int arr[], int length, int sum) 
{
    // Time complexity = O(n)

    unordered_set<int> us;

    for ( int i = 0; i < length; i++ ) {
        int current_num = arr[i];
        int remaining_num = sum - current_num;
        if ( us.find(remaining_num) != us.end() ) {
            // pair found
            cout << current_num << " and " << remaining_num << endl;
            return true;
        }
        else {
            us.insert(current_num);
        }
    }
    
    // pair not found
    return false;
}

int main ()
{
    int arr[] = {3,5,2,8,11,7};
    int length = sizeof(arr)/sizeof(int);
    int sum = 15;
     
    // if ( iterative_solution(arr, length, sum) )
    // if ( hash_map_solution(arr, length, sum))
    if ( hash_set_solution(arr, length, sum) )
        cout << "FOUND: Pair with given sum " << endl;
    else 
        cout << "NOT FOUND: Pair with given sum" << endl;

    return 0;
}