#include <iostream>
#include <vector>

const int MAX_FLOOR = 10;
const int MIN_FLOOR = 0;

int currentFloor = MIN_FLOOR;
std::vector<int> destinationFloors;

void goToFloor(int floor) {
    if (floor >= MIN_FLOOR && floor <= MAX_FLOOR) {
        currentFloor = floor;
        std::cout << "Elevator is now on floor " << currentFloor << std::endl;
    } else {
        std::cout << "Invalid floor number." << std::endl;
    }
}

void addDestinationFloor(int floor) {
    if (floor >= MIN_FLOOR && floor <= MAX_FLOOR && floor != currentFloor) {
        destinationFloors.push_back(floor);
        std::cout << "Floor " << floor << " added to destination list." << std::endl;
    } else {
        std::cout << "Invalid floor number." << std::endl;
    }
}

void moveElevator() {
    if (!destinationFloors.empty()) {
        int destination = destinationFloors.front();
        destinationFloors.erase(destinationFloors.begin());
        goToFloor(destination);
    } else {
        std::cout << "No destination floor set." << std::endl;
    }
}

int main() {
    std::cout << "Elevator simulator." << std::endl;
    std::cout << "Commands: go [floor], add [floor], move" << std::endl;
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "go") {
            int floor;
            std::cin >> floor;
            goToFloor(floor);
        } else if (command == "add") {
            int floor;
            std::cin >> floor;
            addDestinationFloor(floor);
        } else if (command == "move") {
            moveElevator();
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}
