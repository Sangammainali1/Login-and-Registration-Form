#include<iostream>
using namespace std;
#include<fstream>

class temp {
    string userName, Email, password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
        void login();
        void signUp();
        void forgot();
}obj;

int main(){

    char choice;
    cout<<"\n1-Login";
    cout<<"\n2- Sign-up";
    cout<<"\n3- Forgot-password";
    cout<<"\n4- Exit";
    cout<<"\nEnter Your Choice ::";
    cin>>choice;
    
    switch (choice){
        case '1':
            obj.login();
        break;
        case '2':
            obj.signUp();
        break;
        case '3':
            obj.forgot();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Envalid choice !";
    }
}

void temp ::  signUp(){
    cout<<"\nEnter your username :: ";
    getline(cin,userName);
    cout<<"Enter your Email address :: ";
    getline(cin,Email);
    cout<<"Enter your Password :: ";
    getline(cin,password);

    file.open("loginData.txt", ios::out | ios::app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp :: login(){
    cout<<"-----------LOGIN-------------"<<endl;
    cout<<"Enter Your User Name ::"<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password ::"<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');

    while (!file.eof())
    {
        if(userName == searchName){
            if(password == searchPass){
                cout<<"\n Account Login Successfull ............!";
                cout<<"\n Username :: "<<userName<<endl;
                cout<<"\n Email :: "<<Email<<endl;

            }
            else {
                cout<<" passport is incorrect ...........!";
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
    }
    file.close();
}

void temp :: forgot(){
    cout<<"\nEnter Your UserName "<<endl;
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address "<<endl;
    getline(cin,searchEmail);

    file.open("loginData.txt", ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'*');
    while(!file.eof()){
        if (userName == searchName){
            if (Email == searchEmail){
                cout<<"\n Account Found.....!"<<endl;
                cout<<"Your Password is :: "<<password<<endl;
            } else {
            cout<<"Not Found!........\n";
            }
        } else {
            cout<<"\n NOt found ........!";
        }
    }
    file.close();
}