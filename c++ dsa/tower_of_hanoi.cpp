#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    
    // Move n-1 disks from source to auxiliary using destination as helper
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    
    // Move n-1 disks from auxiliary to destination using source as helper
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    
    cout << "\nSteps to solve Tower of Hanoi with " << n << " disks:\n\n";
    towerOfHanoi(n, 'A', 'B', 'C');
    
    cout << "\nTotal moves: " << (1 << n) - 1 << endl;
    
    return 0;
}
