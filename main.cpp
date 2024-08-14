#include<iostream>
#include<string>

using namespace std;

// structure for physical description of criminal 
struct Description{
    string color;
    string face_desc;
    float height;
    string identification_mark;
};

// structure for crime details
struct Court{
    string crime;
    string act;
    string court_name;
    string court_address;
};

// structure for police info
struct Police{
    string fir_No;
    string police_station_address;
};

// structure for Date
struct Date{
    int day;
    int month;
    int year;
};


// class for Criminal Record
class Criminal_record{
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
        Criminal_record() {}// constructor

        // function to input details of criminal record
        void addRecord(){
            cout<<"Enter convict number : ";
            getline(cin,convict_no);

            cout<<"Enter name :";
            getline(cin,name);

            cout<<"Enter sex (M/F): ";
            getline(cin,sex);

            cout<<"Enter age: ";
            cin>>age;

            cout<<"Enter Description of Criminal";
            cout<<"Color: ";
            getline(cin,description.color);
            cout<<"Face: ";
            getline(cin,description.face_desc);
            cout<<"Height: ";
            cin>>description.height;
            cout<<"Identification mark: ";
            getline(cin,description.identification_mark);

        }

};

// main function 
int main()
{
    Criminal_record record;
    int choice;

    do{
        cout<<"\n CRIMINAL RECORD SYSTEM \n";
        cout<<" 1. Enter a new record \n";
        cout<<" 2. Modify a existing record \n";
        cout<<" 3. Delete a record \n ";
        cout<<" 4. Exit \n\n";
        cout<<" Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1: record.addRecord();
                    break;
            case 2: record.modifyRecord();
                    break;
            case 3: record.deleteRecord();
                    break;
            case 4: cout<<" Exiting... \n";
                    break;
            default: cout<<"\t Invalid choice. Please enter again. \n";
           
        }
    }while(choice !=4);

    return 0;
}

