#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Record {
private:
    char name[50];  // Array to hold the name (up to 49 characters + null terminator)
    int number;     // Example integer field (can be any field you like)

public:
    // Constructor
    Record() {
        strcpy(name, "");
        number = 0;
    }

    // Function to input a record
    void inputRecord() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    // Function to display a record
    void displayRecord() const {
        cout << "Name: " << name << ", Number: " << number << endl;
    }

    // Function to update the name
    void updateName(const char* newName) {
        strcpy(name, newName);
    }

    // Getter for the name
    const char* getName() const {
        return name;
    }
};

// Function to update the 51st record in the binary file
void updateFiftyFirstRecord(const char* filename) {
    fstream file(filename, ios::in | ios::out | ios::binary);  // Open for reading and writing in binary mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Calculate the position of the 51st record (0-based index, hence 50)
    long position = 50 * sizeof(Record);

    // Move the file pointer to the 51st record
    file.seekg(position);  // Set pointer to the 51st record position

    Record record;

    // Read the current record
    file.read(reinterpret_cast<char*>(&record), sizeof(Record));
    cout << "Current record at 51st position:" << endl;
    record.displayRecord();

    // Update the name
    char newName[50];
    cout << "Enter new name for the 51st record: ";
    cin >> newName;
    record.updateName(newName);

    // Move the file pointer back to the 51st record position for writing
    file.seekp(position);  // Set pointer to the 51st record position
    file.write(reinterpret_cast<char*>(&record), sizeof(Record)); // Write the updated record

    cout << "Record updated successfully!" << endl;

    file.close(); // Close the file
}

int main() {
    const char* filename = "records.dat";

    // Uncomment this section to create a sample file with 100 records
    /*
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    for (int i = 0; i < 100; ++i) {
        Record record;
        record.inputRecord();
        outFile.write(reinterpret_cast<char*>(&record), sizeof(Record));
    }
    outFile.close();
    */

    // Update the 51st record
    updateFiftyFirstRecord(filename);

    return 0;/
}