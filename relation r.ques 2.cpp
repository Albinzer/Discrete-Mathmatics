// two set making relation r and matrices .Finding the relation between two set (A&B) containing (a,b) such that aEA,  bEB and a>b.

#include <iostream>
#include <set>

using namespace std;

int main() {
    int sA, sB;  // Sizes of sets A and B
    set<int> A, B;  // Sets A and B

    // Input size of set A
    cout << "Enter size of A: ";
    cin >> sA;

    // Input size of set B
    cout << "Enter size of B: ";
    cin >> sB;

    // Input elements of set A
    cout << "Enter elements of A:" << endl;
    for (int i = 0; i < sA; i++) {
        int eleA;
        cin >> eleA;
        A.insert(eleA);
    }

    // Input elements of set B
    cout << "Enter elements of B:" << endl;
    for (int i = 0; i < sB; i++) {
        int eleB;
        cin >> eleB;
        B.insert(eleB);
    }

    // Print the relation pairs where a > b
    cout << "\nRelation R = {(a, b) | a > b}:" << endl;
    for (int a : A) {
        for (int b : B) {
            if (a > b) {
                cout << "(" << a << "," << b << "), ";
            }
        }
    }
    cout << endl;

    // Print the matrix representation of the relation
    cout << "\nMatrix Representation:" << endl;
    for (int a : A) {
        for (int b : B) {
            cout << (a > b ? 1 : 0) << " ";  // 1 if a > b, otherwise 0
        }
        cout << endl;
    }

    return 0;
}
