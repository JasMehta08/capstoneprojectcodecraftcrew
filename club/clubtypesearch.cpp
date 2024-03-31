#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>
 
using namespace std;

// basic details of a particular member
class details{
    private: 
    int st_id;
    string st_name;
    string club;
    string club_type;
    bool faculty;
    public: 
    // function to insert a new member
    void insert(){
        cout << "insert details"<<endl<< "id. number ";
        cin >> st_id;
        cout <<endl<< "name";
        cin >> st_name;
        cout << endl << "club";
        cin >> club; 
        cout<< endl<< "type of club";
        cin >> club_type;
        cout<< endl << "faculty(true / false)";
        cin >> faculty; 
    }
};
// details of a particular club will be stored in this class
class club : public details{
    private :
    int n ;
    details *a;
    public: 
    club(int m){
        n = m ;
        create();
    }
    void create(){
        a=new details[n];
        for (int i =0 ; i < n ;i ++ ){
            a[i].insert();
        }
    }

};

// details of same type of clubs are stored here
class clubtype{
    private: 
    string *st;
    int m ;
    public: 
    clubtype(int k){
        m=k;
        st = new string[m];
        for(int i =0 ; i<k ;i++){
            cout<< "club name";
            cin >> st[i];
        }
    }
};
int main(){
    

    return 0;
}