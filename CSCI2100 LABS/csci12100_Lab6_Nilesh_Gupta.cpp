#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main() {
    string tanningLine;
    while (true) {
        cout << "Enter the tanning line (or '0' to quit): ";
        getline(cin, tanningLine); 
        if (tanningLine == "0") {
            break; 
        }
        int beds = tanningLine[0] - '0';   
        string sequence = tanningLine.substr(2); 

        bool tanning[26] = {false};
        bool known[26] = {false};
        int bedsAvailable = beds;
        int walkedAway = 0;          

        for (int i = 0; i < sequence.length(); i++) {
            char customer = sequence[i];
            int index = customer - 'A';  
            if (tanning[index] == false) {  
              if (bedsAvailable > 0) {
                    tanning[index] = true;  
                    bedsAvailable -= 1;        
            } else if (known[index] == false) {
                  walkedAway += 1;  
                  known[index] = true;   
                }
            } else {  
                tanning[index] = false;  
                bedsAvailable += 1;         
            }
        }
        if (walkedAway == 0) {
            cout << "All customers tanned successfully." << endl;
        } else {
            cout << walkedAway << " customer(s) walked away." << endl;
        }
    }
    return 0;
}

