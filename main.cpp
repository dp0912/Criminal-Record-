#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Description {
    string color;
    string face_desc;
    float height;
    string identification_mark;
};

struct Court {
    string crime;
    string act;
    string court_name;
    string court_address;
};

struct Police {
    string fir_No;
    string police_station_address;
};

struct Date {
    int day;
    int month;
    int year;
};

class Criminal {
private:
    string name;
    string sex;
    string convict_no;
    float age;
    string address;
    Description description;
    Court court;
    Police police;
    Date date;

public:
    Criminal() {} // constructor

    void input() {
        cout << "Enter convict number : ";
        getline(cin, convict_no);

        cout << "Enter name : ";
        getline(cin, name);

        cout << "Enter sex (M/F): ";
        getline(cin, sex);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // Clear newline left in the buffer

        cout << "Enter criminal address : ";
        getline(cin, address);

        cout << "Enter Description of Criminal\n";
        cout << "Color: ";
        getline(cin, description.color);
        cout << "Face: ";
        getline(cin, description.face_desc);
        cout << "Height: ";
        cin >> description.height;
        cin.ignore(); // Clear newline left in the buffer
        cout << "Identification mark: ";
        getline(cin, description.identification_mark);

        cout << "Enter court details\n";
        cout << "Court: ";
        getline(cin, court.court_name);
        cout << "Address: ";
        getline(cin, court.court_address);
        cout << "Crime: ";
        getline(cin, court.crime);
        cout << "Crime Act: ";
        getline(cin, court.act);

        cout << "Enter Police details\n";
        cout << "Enter FIR number: ";
        getline(cin, police.fir_No);
        cout << "Enter police station address: ";
        getline(cin, police.police_station_address);

        cout << "Enter Date: (dd mm yyyy) ";
        cin >> date.day >> date.month >> date.year;
        cin.ignore(); // Clear newline left in the buffer
    }

    void display() const {
        cout << "Convict number : " << convict_no << endl;
        cout << "Name : " << name << endl;
        cout << "Sex : " << sex << endl;
        cout << "Age : " << age << endl;
        cout << "Address : " << address << endl;

        cout << "Description : \n";
        cout << "Color : " << description.color << endl;
        cout << "Face : " << description.face_desc << endl;
        cout << "Height : " << description.height << endl;
        cout << "Identification Mark : " << description.identification_mark << endl;

        cout << "Court Details : \n";
        cout << "Crime : " << court.crime << endl;
        cout << "Act : " << court.act << endl;
        cout << "Court name : " << court.court_name << endl;
        cout << "Court Address : " << court.court_address << endl;

        cout << "Police Details : \n";
        cout << "FIR number : " << police.fir_No << endl;
        cout << "Police station address : " << police.police_station_address << endl;
        cout << "Date of Arrest : " << date.day << "/" << date.month << "/" << date.year << endl;
    }

    string getConvictNo() const {
        return convict_no;
    }
};

class Criminal_record {
private:
    vector<Criminal> rec;

public:
    Criminal_record() {}

    void addRecord() {
        Criminal newCriminal;
        newCriminal.input();
        rec.push_back(newCriminal);
        cout << "\nRecord Added\n";
    }

    void modifyRecord() {
        string convict_no;
        cout << "Enter convict number to modify record: ";
        getline(cin, convict_no);

        bool found = false;
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i].getConvictNo() == convict_no) {
                cout << "Modifying record...\n";
                rec[i].input(); // Update the record
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Record updated\n";
        } else {
            cout << "Record not found\n";
        }
    }

    void deleteRecord() {
        string convict_no;
        cout << "Enter convict number to delete record: ";
        getline(cin, convict_no);

        bool found = false;
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i].getConvictNo() == convict_no) {
                rec.erase(rec.begin() + i);
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Record deleted\n";
        } else {
            cout << "Record not found\n";
        }
    }

    void displayRecord() {
        string convict_no;
        cout << "Enter convict number to display: ";
        getline(cin, convict_no);

        bool found = false;
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i].getConvictNo() == convict_no) {
                rec[i].display(); // Display the record
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Record not found\n";
        }
    }

    void printAllRecords() {
        if (rec.empty()) {
            cout << "No records to display.\n";
            return;
        }
        for (const auto& c : rec) {
            c.display();
            cout << "--------\n";
        }
    }
};

// main function
int main() {
    Criminal_record record;
    int choice;

    do {
        cout << "\n CRIMINAL RECORD SYSTEM \n";
        cout << " 1. Enter a new record \n";
        cout << " 2. Modify an existing record \n";
        cout << " 3. Delete a record \n";
        cout << " 4. Display record of a criminal \n";
        cout << " 5. Exit \n\n";
        cout << " Enter your choice : ";
        cin >> choice;
        cin.ignore(); // Clear newline left in the buffer

        switch (choice) {
            case 1: record.addRecord(); break;
            case 2: record.modifyRecord(); break;
            case 3: record.deleteRecord(); break;
            case 4: record.displayRecord(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "\tInvalid choice. Please enter again.\n"; break;
        }
    } while (choice != 5);

    return 0;
}
