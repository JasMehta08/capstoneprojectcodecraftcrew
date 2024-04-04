#include<iostream>
#include<string>
using namespace std;


int main(){
    int n;
    cout<<"Enter (1) for Khelaiya club, (2) for Press club."<<endl;
    cin>>n;
    string password;
    switch(n){
        case 1:
            cout<<"Khelaiya Club"<<endl;
            cout<<"Enter password for khelaiya club:"<<endl;
            cin>>password;
            if(password == "0001")
            {

            }
            else{
                cout<<"Invalid Password"<<endl;
            }

        case 2:
            cout<<"Press Club"<<endl;
            cout<<"Enter password for Press club:"<<endl;
            cin>>password;
            if(password == "0002")
            {

            }
            else{
                cout<<"Invalid Password"<<endl;
            }
        default:
        cout<<"Please select the club you want to access."<<endl;
    }
    return 0;
}
