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


// main function 
int main()
{
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
            case 1: addRecord();
                    break;
            case 2: modifyRecord();
                    break;
            case 3: deleteRecord();
                    break;
            case 4: cout<<" Exiting... \n";
                    break;
            default: cout<<"\t Invalid choice. Please enter again. \n";
           
        }
    }while(choice !=4);

    return 0;
}

