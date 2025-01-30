#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    bool isReserved;

    Room(int num) : roomNumber(num), isReserved(false) {}

    void reserve() {
        isReserved = true;
    }

    void release() {
        isReserved = false;
    }

    void displayRoom() {
        cout << "Room Number: " << roomNumber << " | Status: " << (isReserved ? "Reserved" : "Available") << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int totalRooms) {
        for (int i = 1; i <= totalRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    void displayRooms() {
        for (auto& room : rooms) {
            room.displayRoom();
        }
    }

    void reserveRoom(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && !room.isReserved) {
                room.reserve();
                cout << "Room " << roomNumber << " reserved successfully!" << endl;
                return;
            }
        }
        cout << "Room not available or invalid room number!" << endl;
    }

    void releaseRoom(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.isReserved) {
                room.release();
                cout << "Room " << roomNumber << " released successfully!" << endl;
                return;
            }
        }
        cout << "Room not found or not reserved!" << endl;
    }
};

int main() {
    Hotel hotel(5);  // Hotel with 5 rooms
    int choice, roomNumber;

    do {
        cout << "\nHotel Reservation System\n";
        cout << "1. Display Rooms\n";
        cout << "2. Reserve Room\n";
        cout << "3. Release Room\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.displayRooms();
            break;
        case 2:
            cout << "Enter room number to reserve: ";
            cin >> roomNumber;
            hotel.reserveRoom(roomNumber);
            break;
        case 3:
            cout << "Enter room number to release: ";
            cin >> roomNumber;
            hotel.releaseRoom(roomNumber);
            break;
        case 4:
            cout << "Exiting Hotel Reservation System.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
