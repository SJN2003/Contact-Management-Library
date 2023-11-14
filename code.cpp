//including header files
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//Global variables
string fname, lname, phoneNumber;

//Functions
bool checkDigits(string x){
    if(x.length() == 10){
        return true;
    }
    else{
        return false;
    }
}

bool checkNumber(string x){
    bool check = true;
    for(int i=0; i<x.length(); i++){
        if(! (int(x[i]) >= 48 && int(x[i]) <= 57)){
             check = false;
             break;
        }
    }
    if(check == true){
        return true;
    }
    else{
        return false;
    }
}

void addContact(){
    ofstream phone("number.txt", ios::app);
    system("cls");      //clear screen
    cout<<"\n\n\tEnter First Name : ";
    cin>>fname;
    cout<<"\n\tEnter Last Name : ";
    cin>>lname;
    cout<<"\n\tEnter 10-Digit Phone Number : ";
    cin>>phoneNumber;

    if(checkDigits(phoneNumber) == true){
        if(checkNumber(phoneNumber) == true){
            if(phone.is_open()){
                phone<<fname<<" "<<lname<<" : "<<phoneNumber<<endl;
                cout<<"\n\tContact Saved Successfully!"<<endl;
                cout<<"--------------------------------------------------------------------";
            }
            else{
                cout<<"\n\tError Opening File!";
            }
        }
        else{
            cout<<"\n\tPhone Number Must Contain Numbers Only!"<<endl;
            cout<<"--------------------------------------------------------------------";
        }
    }
    else{
        cout<<"\n\tA Phone Number Must Contain 10 Digits."<<endl;
        cout<<"--------------------------------------------------------------------";
    }
    phone.close();
}

void searchContact(){
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout<<"\n\tEnter Name To Search : ";
    cin>>keyword;
    while(myfile >> fname >> lname>> phoneNumber){
        if(keyword == fname || keyword == lname){
            system("cls");
            cout<<"\n\n\n\t\tContact Details...";
            cout<<"\n\n\tFirst Name : "<<fname;
            cout<<"\n\tLast Name : "<<lname;
            cout<<"\n\tPhone Number : "<<phoneNumber<<endl;
            cout<<"--------------------------------------------------------------------";
            found = true;
            break;
        }
        if(found == false){
            cout<<"\n\tNo Such Contact Found"<<endl;
            cout<<"--------------------------------------------------------------------";
        }
    }
}

void help(){
    system("cls");
    cout<<"\n\n\n\t\tThis Displays help"<<endl;
    cout<<"--------------------------------------------------------------------";
}

void self_exit(){
    system("cls");
    cout<<"\n\n\n\t\tThank You For Using!"<<endl;
    cout<<"--------------------------------------------------------------------";
    exit(1);
}

int main(){
    short int choice;
    system("cls");
    system("color 0A");
    cout<<"\n\n\n\t\t\tContact Management";
    cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t > ";
    cin>>choice;

    switch(choice){
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout<<"\n\n\tInvalid Input!";
            cout<<"\n\tPress Any key to cotinue..."<<endl;
            cout<<"--------------------------------------------------------------------";
            getch();
            main();
    }
    return 0;
}