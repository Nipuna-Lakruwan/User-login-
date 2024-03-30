#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void login();
void registr();
void forgot();

int main()
{
    int choice;
    cout << "---------------------------------------------"<<endl<<endl<<endl;
    cout << "____________________WELCOME__________________"<<endl<<endl<<endl;
    cout << "_________Inventory Management System_________"<<endl<<endl<<endl;
    cout << "1. LOGIN" <<endl;
    cout << "2. REGISTER" <<endl;
    cout << "3. FORGOT PASSWORD (or) USERNAME" <<endl;
    cout << "4. EXIT" <<endl;
    cout << "\nEnter your choice :"
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "Thanks for using this program.\nThis program is created by @Nipuna\n\n";
            break;
        default:
            system("cls");
            cout << "You've made a mistake , Try agian..\n" << endl;
            main();
    }
}

void login() {
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME : ";
    cin>>user;
    cout << "PASSWORD : ";
    cin>>pass;

    ifstream input("database.txt");
    bool found = false;
    while(input >> u >> p) {
        if(u==user && p==pass) {
            found = true;
            break;
        }
    }input.close();
    if(found) {
        cout << "\nHello"<<user<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        cin.get();
        cin.get();
        main();
    } else {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        main();
    }
}

void registr() {
    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    main();
}

void forgot() {
    int ch;
    system("cls");
    cout << "Forgotten ? We're here to help\n";
    cout << "1.Search your id by username"<<endl;
    cout << "2.Search your id by password"<<endl;
    cout << "3.Main menu"<<endl;
    cout << "Enter your choice :";
    cin>>ch;

    switch(ch) {
         case 1:
                {
                        string searchuser, su, sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        bool found = false;
                        while(searchu >> su >> sp)
                        {
                                if(su==searchuser)
                                {
                                        found = true;
                                        break;
                                }
                        }
                        searchu.close();
                        if(found)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        string searchpass, su2, sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        bool found = false;
                        while(searchp >> su2 >> sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        found = true;
                                        break;
                                }
                        }
                        searchp.close();
                        if(found)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
    }

}
