#include <iostream>
#include <vector>
using namespace std;

int Ways(int n, vector<int>& memo) {
    //Base cases take O(1) time 
    if (n == 1) 
        return 1;  
    if (n == 2) 
        return 2;
    if (memo[n] != -1)
        return memo[n];
    
    //With memonization each unique n is calculated exactly once taking to O(n) time overall. 
    //In the case where we dont use memonization, (return countWays(n - 1) + countWays(n - 2);)
    //this recursive function would take O(2^n) since we would claculate the same values multiple times. 
    memo[n] = Ways(n - 1, memo) + Ways(n -2, memo);
    return memo[n];
}

int main() {
    int n;
    vector<int> memo(41, -1); 
    while (cin >> n && n != 0) {
        cout << Ways(n, memo) << endl;  
    }
    return 0;
}

/*

RECURSIVE FUNCTION WITHOUT MEMONIZATION 

#include <iostream>

using namespace std;


int Ways(int n) {
    //base case are constant, so O(1)
    if (n == 1) return 1;  
    if (n == 2) return 2;  
    //O(2^n) time complexity, since we calculate the same values multiple times with the fibbonacci sequence.
    return Ways(n - 1) + Ways(n - 2);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << Ways(n) << endl;  
    }
    return 0;
}
*/