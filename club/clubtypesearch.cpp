#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

 
using namespace std;

// basic details of a particular member
class details{
    private: 
    int st_id;
    string st_name;
    string club;
    string club_type;
    string faculty;
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
    // create a new member 
    void create(int id, string name, string club, string clubtype,string fac ){
        st_id = id;
        st_name = name;
        this->club = club;
        this->club_type = clubtype;
        faculty = fac;
    }
    void print(){
        cout << "insert details"<<endl<< "id. number ";
        cout << st_id;
        cout <<endl<< "name ";
        cout << st_name;
        cout << endl << "club ";
        cout << club; 
        cout<< endl<< "type of club ";
        cout << club_type;
        cout<< endl << "faculty(true / false) ";
        cout << faculty; 
    }
};

// general list consisting of all the members of all the clubs
class general_list{
    public: 
        unordered_map<int , details> gen_list;
        
        void add_new(int id, details member){
            gen_list[id]=member;
        }

        void get_from_file(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string id;
                string name;
                string club;
                string clubtype;
                string faculty;

                getline(ss,id,' ');
                getline(ss,name,' ');
                getline(ss,club,' ');
                getline(ss,clubtype,' ');
                getline(ss,faculty,' ');

                    details member;
                    member.create(stoi(id) , name , club , clubtype , faculty);
                    add_new(stoi(id), member);
                
            }
            file.close();
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
        }

        void find_mem_by_id(int id){
            details member = gen_list.at(id);
            member.print();
        }
};
// details of a particular club will be stored in this class
class club {
    private :
    int n ;
    vector < details > list_of_members ;
    public: 
    club(int m){
        n = m;
    }
    

};

// details of same type of clubs are stored here
class clubtype{
    private: 
    vector < club > list_of_clubs;
    int m ;
    public: 
    clubtype(){
        m=0;
    }
    void add_club(club add){
        list_of_clubs.push_back(add);
        m++;
    }
};
int main(){
    general_list main ;
    main.get_from_file("gen_list.txt");
    main.find_mem_by_id(2);
    return 0;
}