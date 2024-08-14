#include<iostream>
#include<string>
#include<vector>

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
class Criminal{
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
        Criminal() {}// constructor

        // function to input details of criminal record
        void input(){
            cout<<"Enter convict number : ";
            getline(cin,convict_no);

            cout<<"Enter name :";
            getline(cin,name);

            cout<<"Enter sex (M/F): ";
            getline(cin,sex);

            cout<<"Enter age: ";
            cin>>age;

            cout<<"Enter Description of Criminal\n";
            cout<<"Color: ";
            getline(cin,description.color);
            cout<<"Face: ";
            getline(cin,description.face_desc);
            cout<<"Height: ";
            cin>>description.height;
            cout<<"Identification mark: ";
            getline(cin,description.identification_mark);

            cout<<"Enter court details\n";
            cout<<"Court: ";
            getline(cin,court.court_name);
            cout<<"Address: ";
            getline(cin,court.court_address);
            cout<<"Crime: ";
            getline(cin,court.crime);
            cout<<"Crime Act:";
            getline(cin,court.act);

            cout<<"Enter Police deatials\n";
            cout<<"Enter FIR number: ";
            getline(cin,police.fir_No);
            cout<<"Enter police station address: ";
            getline(cin,police.police_station_address);

            cout<<"Enter Date: (dd mm yyyy) ";
            cin>>date.day>>date.month>>date.year;
        }

        // getter for convict number 
        string getConvictNo() const{
            return convict_no;
        }

};

class Criminal_record{
    private:
        vector<Criminal> rec;;

     public:
        Criminal_record() {}

        void addRecord(){
             Criminal newCriminal;
             newCriminal.input();
             rec.push_back(newCriminal);
             cout<<"\nRecord Added\n";
        }

        void modifyRecord(){
            string convict_no;
            cout<<"Enter convict number to modify record: ";
            getline(cin,convict_no);

            bool found = false;
            for(int i =1; i<rec.size(); i++){
                if (rec[i].getConvictNo() == convict_no){
                    rec[i].input();
                    found = true;
                    break;
                }
            }
            if(found){
                cout<<"Record updated\n";
            }
            else{
                cout<<"Record not found\n";
            }
        }

        void deleteRecord(){
            string convict_no;
            cout<<"Enter convict number to delete record: ";
            getline(cin,convict_no);

            bool found = false;
            for(int i =1; i<rec.size(); i++){
                if (rec[i].getConvictNo() == convict_no){
                    rec.erase(rec.begin()+i);
                    found = true;
                    break;
                }
            }
            if(found){
                cout<<"Record updated\n";
            }
            else{
                cout<<"Record not found\n";
            }
        }

        void displayRecord(){
            string convict_no;
            cout<<"Enter convict number to display: ";
            getline(cin,convict_no);

            bool found=false;
            for(int i = 1; i<rec.size();i++){
                if(rec[i].getConvictNo() == convict_no){
                    rec[i].display();
                    found =true;
                    break;
                }
            }
            if(!found){
                cout<<"Record not found\n";
            }
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
        cout<<" 3. Delete a record \n";
        cout<<" 4. Display record of a crimina\n";
        cout<<" 5. Exit \n\n";
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
            case 4: record.displayRecord();
                    break;
            case 5: cout<<" Exiting... \n";
                    break;
            default: cout<<"\t Invalid choice. Please enter again. \n";
           
        }
    }while(choice !=5);

    return 0;
}

