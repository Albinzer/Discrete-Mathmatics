// two set making relation r and matrices .Finding the relation between two set (A&B) containing (a,b) such that aEA,  bEB and a>b.

#include <iostream>
#include <set>

using namespace std;

int main() {
    int sA, sB;
    set<int> A, B;

    cout << "Enter size of A: ";
    cin >> sA;
    cout << "Enter size of B: ";
    cin >> sB;

    cout << "Enter elements of A:" << endl;
    for (int i = 0; i < sA; i++) {
        int eleA;
        cin >> eleA;
        A.insert(eleA);
    }

    cout << "Enter elements of B:" << endl;
    for (int i = 0; i < sB; i++) {
        int eleB;
        cin >> eleB;
        B.insert(eleB);
    }

    // Print Relation
    cout << "Relation:" << endl;
    for (int a : A) {
        for (int b : B) {
            if (a > b) {
                cout << "(" << a << "," << b << "), ";
            }
        }
    }
    cout << endl;

    // Print Matrix
    cout << "Matrix:" << endl;
    for (int a : A) {
        for (int b : B) {
            cout << (a > b ? 1 : 0) << " ";
        }
        cout << endl;
    }

    return 0;
}
