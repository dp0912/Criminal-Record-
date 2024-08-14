#include<iostream>
#include<string>

using namespace std;


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

