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

    // Function to print ordered pairs based on the given relation
    auto printPairs = [](const set<int>& A, const string& relation, bool (*condition)(int, int)) {
        cout << "Ordered pairs in " << relation << ": ";
        for (int a : A) {
            for (int b : A) {
                if (condition(a, b)) {
                    cout << "(" << a << "," << b << ") ";
                }
            }
        }
        cout << endl;
    };

    // Condition function for relation R1: a divides b
    auto dividesCondition = [](int a, int b) -> bool {
        return (b % a == 0);
    };

    // Condition function for relation R2: a <= b
    auto lessEqualCondition = [](int a, int b) -> bool {
        return (a <= b);
    };

    // Print relation R1 {(a,b) | a divides b}
    printPairs(A, "R1 {(a,b) | a divides b}", dividesCondition);

    // Print relation R2 {(a,b) | a <= b}
    printPairs(A, "R2 {(a,b) | a <= b}", lessEqualCondition);

    return 0;
}
