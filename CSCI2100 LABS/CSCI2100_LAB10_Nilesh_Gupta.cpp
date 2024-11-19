#include <iostream>
#include <string>
using namespace std;

//function to calculate depth using recursion
int depth(string::const_iterator &it) { 
    int max_depth = 0;
    while (*it == 'd') {  
        ++it; 
        int child_depth = depth(it);  //recursive call
        max_depth = max(max_depth, child_depth + 1);  
    }
    ++it;
    return max_depth;
}

//I tried doing it with the padding "d" and "u" but it kept giving me an output with a value 1 too big. This worked for me.
int tree_height(const string &traversal) {
    string::const_iterator it = traversal.begin();  
    return depth(it);  
}

int main() {
    int case_number = 1;
    string traversal;
    
    cout << "Enter tree traversal strings" << endl;
    cout << "Enter '#' on a new line to stop and display results." << endl;
    
    while (true) {
        cout << "Enter traversal string for Tree " << case_number << ": ";
        getline(cin, traversal);
        
        if (traversal[0] == '#')  
            break;
        
        int height = tree_height(traversal); 
        cout << "Tree " << case_number << ": " << height << endl;
        
        ++case_number;
    }
    return 0;
}
