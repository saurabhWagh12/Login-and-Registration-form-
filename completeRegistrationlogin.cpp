#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Menu{
    private:
    string fname,lname;
    string email;
    string password;

    public:
    void menu();
    void registerUser();
    void login();
    void forgotPw();
    void changePw();
    void changing(string eMail,string passw);
};

int main(){
    Menu m;
    m.menu();
  return 0;  
}

void Menu::menu(){
    back:
    // system("cls");
    cout<<"________Registration and login form_________"<<endl<<endl<<endl;
    int n;
    
    cout<<"        Make a choice : "<<endl<<endl;
    cout<<endl<<endl<<"press '1' for Registration :"<<endl;
    cout<<"press '2' to Login :"<<endl;
    cout<<"press '3' if you Forgot your account password :"<<endl;
    cout<<"press '4' to change your account password :"<<endl;
    cout<<"press '5' to Exit :"<<endl<<endl;
    cout<<"Enter your choice : ";
    cin>>n;

    switch (n)
    {
    case 1:
           Menu::registerUser();
        break;
    case 2:
           Menu::login();
        break;
    case 3:
           Menu::forgotPw();
        break;
    case 4:
           Menu::changePw(); 
        break;    
    case 5:
           cout<<"________Thank you________";
        break;

    default: cout<<"Enter a valid Choice : ";
             goto back;
        break;
    }
    
}

void Menu::registerUser(){
    system("cls");

    cout<<"_________Registration________"<<endl<<endl;
    cout<<"Enter Details"<<endl<<endl;
    cout<<"Enter First Name : ";
    cin>>fname;
    cout<<"Enter Last Name : ";
    cin>>lname;
    cout<<"Enter E-mail : ";
    cin>>email;
    cout<<"Enter Password : ";
    cin>>password;
    
    fstream data;
    data.open("file.txt",ios::app|ios::out);

    data<<fname<<" "<<lname<<" "<<email<<" "<<password<<endl;
    data.close();
    system("cls");
    cout<<endl<<"Successfully Registered"<<endl<<endl<<endl;
    menu();
}

void Menu::login(){
    system("cls");
    string eMail,pw;
        cout<<"__________Welcome__________"<<endl<<endl;
        cout<<"  Enter Details to Login : "<<endl<<endl; 
        cout<<"Enter E-mail : ";
        cin>>eMail;
        cout<<"Enter Password : ";
        cin>>pw; 
 
    fstream data;
    data.open("file.txt",ios::in);

    data>>fname>>lname>>email>>password;
    while(!data.eof()){
        if(eMail==email && pw==password){
            system("cls");
            cout<<"LOGIN SUCCESSFUl"<<endl<<endl;
            break;
        }else{
            data>>fname>>lname>>email>>password; 
        }
    }    
    data.close();
}

void Menu::forgotPw(){
    system("cls");
      string eMail; 
       cout<<"_______PASSWORD RECOVERY_______"<<"\n\n\n";
       cout<<"Enter your E-mail : ";
       cin>>eMail;
    
    fstream data;
    data.open("file.txt",ios::in);

     data>>fname>>lname>>email>>password;
    while(!data.eof()){
        if(eMail==email){
            system("cls");
            cout<<"Your Password is : "<<password<<endl<<endl;
            // menu();
            break;
        }else{
            data>>fname>>lname>>email>>password; 
        }
    }    
    data.close();

}

void Menu::changePw(){
    system("cls");
    back:
    char c; 
    string eMail,pw;
    cout<<"_______PASSWORD CHANGE________"<<endl<<"\n\n";
    cout<<"Do you remember your old password ? "<<endl;
    cout<<"If yes press 'y' else press 'n' : ";
    cin>>c;
    cout<<"\n\n\n\n";
    switch(c){
        case 'y':
             cout<<"Enter e-mail : ";
             cin>>eMail;
             cout<<"Enter old password : ";
             cin>>pw;
             Menu::changing(eMail,pw);
        break;
        case 'n':
           cout<<"RECOVER your old password\n\n\n";
           forgotPw();
        break;
        default:
        cout<<"Make correct choice !!!"<<endl<<endl;
        goto back;
        break;
    }

    menu();
}

void Menu::changing(string eMail,string passw){
    fstream data,data1;
    string pawo;
    data.open("file.txt",ios::in);
    data1.open("file2.txt",ios::app|ios::out);
    
    cout<<"Enter New Password : ";
    cin>>pawo;

     data>>fname>>lname>>email>>password;
    while(!data.eof()){
        if(password==passw){
            data1<<fname<<" "<<lname<<" "<<email<<" "<<pawo<<endl;
        }else{
            data1<<fname<<" "<<lname<<" "<<email<<" "<<password<<endl;
        }
     data>>fname>>lname>>email>>password;
    }
    data.close();
    data1.close();
    remove("file.txt");
    rename("file2.txt","file.txt");

    cout<<"\n\n\n_______Password Changed_______\n\n\n";
    menu();
}