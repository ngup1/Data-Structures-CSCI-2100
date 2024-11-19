#include <iostream>
using namespace std;

int calculateMaxPercentage(int A, int B, int C, int D){
    
        // Compute percentage for original orientation 
        int Original_Side1 = min((C * 100) / A, 100);
        int Original_Side2 = min((D * 100) / B, 100);
        int Orientation1 = min(Original_Side1, Original_Side2);

        // Compute percentage for rotated orientation 
        int Rotated_Side1 = min((C * 100) / B, 100);
        int Rotated_Side2 = min((D * 100) / A, 100);
        int Orientation2 = min(Rotated_Side1, Rotated_Side2);
    
        // Return the maximum of the two
        return max(Orientation1, Orientation2);

}

int main() {
  int A, B, C, D, line_num(1);
  while (line_num < 1000){
    // Input four integers
    cin >> A >> B >> C >> D;
    // Check for the terminating condition
    if (A == 0 && B == 0 && C == 0 && D == 0) {
            break;
        }

        // Calculate and display the maximum percentage
        int percentage = calculateMaxPercentage(A, B, C, D);
        cout << percentage << "%" << endl;
        line_num++;
    }
  }
  
