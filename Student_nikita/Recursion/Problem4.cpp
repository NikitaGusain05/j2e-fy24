#include <iostream>

void moveDisk(int disk, char source, char destination) {
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

void towersOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        moveDisk(disks, source, destination);
    } else {
        towersOfHanoi(disks - 1, source, destination, auxiliary);
        moveDisk(disks, source, destination);
        towersOfHanoi(disks - 1, auxiliary, source, destination);
    }
}

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;
    
    towersOfHanoi(numDisks, 'A', 'B', 'C');
    
    return 0;
}
