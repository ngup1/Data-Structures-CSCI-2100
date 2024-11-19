#include <iostream>
using namespace std;

int Ways(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int prev_value1 = 2;  
    int prev_value2 = 1;  
    int current_result = 0;
    //For the base cases, since the funiton just checks the values and returns the result the time complexity is O(1), or constant time.
    for (int i = 3; i <= n; ++i) {
        //In the for loop, we get larger values of n >= 3, and the function iterates n-2 times, so the time complexity is O(n)
        current_result = prev_value1 + prev_value2;  
        prev_value2 = prev_value1;           
        prev_value1 = current_result;         
    }
    return current_result;  
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << Ways(n) << endl;  
    }

    return 0;
}

//Since in the worst case scenario of this program is O(n), the time complexity is O(n).