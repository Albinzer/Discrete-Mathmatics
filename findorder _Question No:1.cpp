// find the ordered pairs 
// Let A be the set A={1,2,3,4}. Write a program to find the ordered pairs are in the relation .
// (i).{ (a,b) |a divides b| }
// (ii). { (a,b) |a<=b| }


#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Relation R1
    cout << "R1 = {";
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j] % A[i] == 0) { // Corrected condition
                
                    cout << ", ";
                }
                cout << "(" << A[i] << ", " << A[j] << ")";
             
            }
        }
    
    cout << "}" << endl;

    // Relation R2
    cout << "R2 = {";
   

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j] <= A[i]) { // Corrected condition
               
                    cout << ", ";
                }
                cout << "(" << A[i] << ", " << A[j] << ")";
               
            }
        }
    
    cout << "}" << endl;

    return 0;
}
