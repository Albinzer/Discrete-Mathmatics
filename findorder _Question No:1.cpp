// find the ordered pairs 
// Let A be the set A={1,2,3,4}. Write a program to find the ordered pairs are in the relation .
// (i).{ (a,b) |a divides b| }
// (ii). { (a,b) |a<=b| }


#include <iostream>
#include <set>

using namespace std;

int main() {
    // Input set A
    int n;
    cout << "Enter the number of elements in set A: ";
    cin >> n;

    set<int> A;
    cout << "Enter the elements of set A: " << endl;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        A.insert(ele);
    }

    // Function to print ordered pairs
    auto printPairs = [](const set<int>& A, const string& relation) {
        cout << "Ordered pairs in " << relation << ":" << endl;
        for (int a : A) {
            for (int b : A) {
                cout << "(" << a << "," << b << "), ";
            }
        }
        cout << endl;
    };

    // Print Cartesian Product A x A
    printPairs(A, "A x A");

    // Print relation R1 {(a,b) | a divides b}
    cout << "Enter R1: {(a,b) | a divides b}" << endl;
    printPairs(A, "R1");

    // Print relation R2 {(a,b) | a <= b}
    cout << "Enter R2: {(a,b) | a <= b}" << endl;
    printPairs(A, "R2");

    return 0;
}
