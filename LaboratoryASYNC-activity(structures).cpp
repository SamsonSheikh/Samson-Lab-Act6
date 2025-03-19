#include <iostream>
#include <string>

using namespace std;

const int MAX_RECORDS = 100;

struct Record {
    int identifier;
    string fullName;
    float gradePointAverage;
};

Record records[MAX_RECORDS];
int recordCount = 0;

void showMenu() {
    cout << "\nOptions:\n";
    cout << "[1] Add Student\n";
    cout << "[2] Edit Student\n";
    cout << "[3] Remove Student\n";
    cout << "[4] View Student\n";
    cout << "[5] Quit\n";
    cout << "Choose an option: ";
}

bool checkDuplicate(int id) {
    for (int i = 0; i < recordCount; i++) {
        if (records[i].identifier == id) return true;
    }
    return false;
}

void insertRecord() {
    if (recordCount >= MAX_RECORDS) {
        cout << "Error: No space left!\n";
        return;
    }

    Record newRecord;
    cout << "Enter Student ID: ";
    cin >> newRecord.identifier;
    
    if (checkDuplicate(newRecord.identifier)) {
        cout << "Error: ID already exists!\n";
        return;
    }

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newRecord.fullName);
    cout << "Enter GPA: ";
    cin >> newRecord.gradePointAverage;

    records[recordCount++] = newRecord;
    cout << "Record inserted successfully!\n";
}

void modifyRecord() {
    if (recordCount == 0) {
        cout << "No records to modify!\n";
        return;
    }

    int id;
    cout << "Enter Student ID to modify: ";
    cin >> id;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].identifier == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, records[i].fullName);
            cout << "Enter new GPA: ";
            cin >> records[i].gradePointAverage;
            cout << "Record updated successfully!\n";
            return;
        }
    }
    cout << "Record not found!\n";
}

void removeRecord() {
    if (recordCount == 0) {
        cout << "No records to remove!\n";
        return;
    }

    int id;
    cout << "Enter Student ID to remove: ";
    cin >> id;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].identifier == id) {
            for (int j = i; j < recordCount - 1; j++) {
                records[j] = records[j + 1];
            }
            recordCount--;
            cout << "Record removed successfully!\n";
            return;
        }
    }
    cout << "Record not found!\n";
}

void arrangeByName() {
    for (int i = 0; i < recordCount - 1; i++) {
        for (int j = 0; j < recordCount - i - 1; j++) {
            if (records[j].fullName > records[j + 1].fullName) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void arrangeByGPA() {
    for (int i = 0; i < recordCount - 1; i++) {
        for (int j = 0; j < recordCount - i - 1; j++) {
            if (records[j].gradePointAverage > records[j + 1].gradePointAverage) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void displayRecords() {
    if (recordCount == 0) {
        cout << "No records to display!\n";
        return;
    }

    int option;
    cout << "Display Options:\n[1] By Name\n[2] By GPA\nChoose an option: ";
    cin >> option;

    if (option == 1) {
        arrangeByName();
    } else if (option == 2) {
        arrangeByGPA();
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < recordCount; i++) {
        cout << "ID: " << records[i].identifier << "\nName: " << records[i].fullName 
             << "\nGPA: " << records[i].gradePointAverage << "\n\n";
    }
}

int main() {
    int option;
    do {
        showMenu();
        cin >> option;

        switch(option) {
            case 1:
                insertRecord();
                break;
            case 2:
                modifyRecord();
                break;
            case 3:
                removeRecord();
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
        
        cin.ignore(1000, '\n');
        cout << "\nPress Enter to continue...";
        cin.get();
    } while (option != 5);

    return 0;
}