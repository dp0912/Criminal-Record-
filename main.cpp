#include <iostream>
#include <string>
#include <vector>
#include <cctype>    // For isalpha and isspace
#include <stdexcept> // For std::runtime_error

using namespace std;

// Structure to hold date
struct Date
{
    int day;
    int month;
    int year;
};

// Custom exception class for invalid date
class InvalidDateException : public runtime_error
{
public:
    InvalidDateException() : runtime_error("Invalid date entered. Please enter a valid date.") {}
};

// Function to check if a string contains only alphabetic characters and spaces
bool isValidName(const string &name)
{
    if (name.empty())
        return false;
    for (char c : name)
    {
        if (!isalpha(c) && !isspace(c))
            return false;
    }
    return true;
}

// Function to get a valid name input from the user
string getValidName(const string &prompt)
{
    string name;
    while (true)
    {
        cout << prompt;
        getline(cin, name);
        if (isValidName(name))
        {
            return name;
        }
        else
        {
            cout << "Invalid name. Name should only contain alphabetic characters and spaces.\n";
        }
    }
}

// Function to check if a string is a valid positive integer
bool isValidPositiveInteger(const string &str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// Function to get a positive integer input from the user
int getPositiveIntegerInput(const string &prompt)
{
    string input;
    int value;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (isValidPositiveInteger(input))
        {
            value = stoi(input); // Convert valid string to integer
            if (value > 0)
            {
                return value;
            }
            else
            {
                cout << "Please enter a positive integer.\n";
            }
        }
        else
        {
            cout << "Invalid input. Please enter a positive integer.\n";
        }
    }
}

// Function to check if date is valid
bool isValidDate(int day, int month, int year)
{
    if (year < 0 || year > 2024)
        return false;
    if (month < 1 || month > 12)
        return false;

    int daysInMonth;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daysInMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            daysInMonth = 29; // Leap year
        }
        else
        {
            daysInMonth = 28; // Non-leap year
        }
        break;
    default:
        return false;
    }

    return (day > 0 && day <= daysInMonth);
}

// Function to get a valid date input from the user
Date getValidDate()
{
    Date date;
    while (true)
    {
        cout << "Enter Date (dd mm yyyy): ";
        cin >> date.day >> date.month >> date.year;

        // Check if the input is valid
        if (cin.fail())
        {
            cout << "Invalid input. Please enter the date in the format dd mm yyyy.\n";
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the invalid input up to newline
            continue;
        }

        // Clear newline left in the buffer
        cin.ignore(10000, '\n');

        // Validate the date
        if (isValidDate(date.day, date.month, date.year))
        {
            return date;
        }
        else
        {
            cout << "Invalid date. Please enter a valid date.\n";
        }
    }
}

// Structure to hold criminal description
struct Description
{
    string color;
    string face_desc;
    int height;
    string identification_mark;
};

// Structure to hold court details
struct Court
{
    string crime;
    string act;
    string court_name;
    string court_address;
};

// Structure to hold police details
struct Police
{
    string fir_No;
    string police_station_address;
};

// Class to represent a criminal
class Criminal
{
private:
    string name;
    string sex;
    string convict_no;
    int age;
    string address;
    Description description;
    Court court;
    Police police;
    Date date;

public:
    Criminal() {} // Default constructor

    void input()
    {
        cout << "Enter convict number : ";
        getline(cin, convict_no);

        // Get valid name input from user
        name = getValidName("Enter name: ");

        // Get valid sex input from user
        while (true)
        {
            cout << "Enter sex (Male / Female) : ";
            getline(cin, sex);
            if (sex == "Male" || sex == "Female")
            {
                break;
            }
            cout << "Invalid sex entered. Please enter 'Male' or 'Female'.\n";
        }

        // Get valid age input from user
        age = getPositiveIntegerInput("Enter age: ");

        // Get valid height input from user
        description.height = getPositiveIntegerInput("Enter height (in cm): ");

        cout << "Enter criminal address : ";
        getline(cin, address);

        cout << "Enter Description of Criminal\n";
        cout << "Color: ";
        getline(cin, description.color);
        cout << "Face: ";
        getline(cin, description.face_desc);
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

        // Get valid date input from user
        date = getValidDate();
    }

    // Function to display the criminal details
    void display()
    {
        cout << "Convict number : " << convict_no << endl;
        cout << "Name : " << name << endl;
        cout << "Sex : " << sex << endl;
        cout << "Age : " << age << endl;
        cout << "Address : " << address << endl;

        cout << "Description : \n";
        cout << "Color : " << description.color << endl;
        cout << "Face : " << description.face_desc << endl;
        cout << "Height : " << description.height << " cm" << endl; // Display height in cm
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

    // Function to get the convict number
    string getConvictNo() const
    {
        return convict_no;
    }
};

// Class to manage the collection of criminal records
class Criminal_record
{
private:
    vector<Criminal> rec; // Vector to store criminal records

public:
    Criminal_record() {} // Default constructor

    // Function to add a new criminal record
    void addRecord()
    {
        Criminal newCriminal;
        newCriminal.input();
        rec.push_back(newCriminal);
        cout << "\nRecord Added\n";
    }

    // Function to modify an existing record
    void modifyRecord()
    {
        string convict_no;
        cout << "Enter convict number to modify record: ";
        getline(cin, convict_no);

        bool found = false;
        for (int i = 0; i < rec.size(); i++)
        {
            if (rec[i].getConvictNo() == convict_no)
            {
                cout << "Modifying record...\n";
                rec[i].input(); // Update the record
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "Record updated\n";
        }
        else
        {
            cout << "Record not found\n";
        }
    }

    // Function to delete a record
    void deleteRecord()
    {
        string convict_no;
        cout << "Enter convict number to delete record: ";
        getline(cin, convict_no);

        bool found = false;
        for (int i = 0; i < rec.size(); i++)
        {
            if (rec[i].getConvictNo() == convict_no)
            {
                rec.erase(rec.begin() + i);
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "Record deleted\n";
        }
        else
        {
            cout << "Record not found\n";
        }
    }

    // Function to display a specific record
    void displayRecord()
    {
        string convict_no;
        cout << "Enter convict number to display: ";
        getline(cin, convict_no);

        bool found = false;
        for (int i = 0; i < rec.size(); i++)
        {
            if (rec[i].getConvictNo() == convict_no)
            {
                rec[i].display(); // Display the record
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Record not found\n";
        }
    }
};

// Main function
int main()
{
    Criminal_record record; // Object to manage criminal record
    int choice;

    do
    {
        cout << "\n CRIMINAL RECORD SYSTEM \n";
        cout << " 1. Enter a new record \n";
        cout << " 2. Modify an existing record \n";
        cout << " 3. Delete a record \n";
        cout << " 4. Display record of a criminal \n";
        cout << " 5. Exit \n\n";
        cout << " Enter your choice : ";
        cin >> choice;
        cin.ignore(); // Clear newline left in the buffer

        switch (choice)
        {
        case 1:
            record.addRecord();
            break;
        case 2:
            record.modifyRecord();
            break;
        case 3:
            record.deleteRecord();
            break;
        case 4:
            record.displayRecord();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "\tInvalid choice. Please enter again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
