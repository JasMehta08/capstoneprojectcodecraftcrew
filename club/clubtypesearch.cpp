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
        cout <<"Student ID: "<<st_id;
        cout <<endl<< "Student Name: ";
        cout << st_name;
        cout << endl << "Member of Club: ";
        cout << club; 
        cout<< endl<< "Club type: ";
        cout << club_type;
        cout<< endl << "Faculty(True / False): ";
        cout << faculty<<"\n"<<endl; 
    }

    void print_club(){
        cout <<' ' << st_id <<' ' << "      "<<"  "<<faculty<<' '<<"        "<<' '<< st_name<<' '<<endl;
    }
};


// details of a particular club will be stored in this class
class club {
    private :
    int n ;
    vector < details > list_of_members ;
    public: 
    club(){
        n = 0;
    }
    void add_member_to_club(details member){
        list_of_members.push_back(member);
        n++;
    }
    void printing_club(string club){
        cout<< "the list of the members of the club : "<<club<<endl<<endl;
        cout << " Student ID " << "      "<<" Faculty "<<"      "<<" Student Name "<<endl<<endl;
        for(int i =0 ; i< list_of_members.size(); i++ ){
            details temp_mem = list_of_members[i]; 
            temp_mem.print_club();
        }
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

club Khelaiya_club,Press_club,Debate_club,Music_club,Dance_club,Cubing_club,Quiz_club,Drama_club,Muse_club,Radio_club,Programming_club,Developers_club;

void sort_into_club(details member,string club){
            if(club == "Khelaiya_club"){
                 Khelaiya_club.add_member_to_club(member);
            }
            else if(club == "Press_club"){
                 Press_club.add_member_to_club(member);
            }
            else if(club == "Music_club"){
                 Music_club.add_member_to_club(member);
            }
            else if(club == "Debate_club"){
                 Debate_club.add_member_to_club(member);
            }
            else if(club == "Dance_club"){
                 Dance_club.add_member_to_club(member);
            }
            else if(club == "Cubing_club"){
                 Cubing_club.add_member_to_club(member);
            }
            else if(club == "Quiz_club"){
                 Quiz_club.add_member_to_club(member);
            }
            else if(club == "Drama_club"){
                 Drama_club.add_member_to_club(member);
            }
            else if(club == "Muse_club"){
                 Muse_club.add_member_to_club(member);
            }
            else if(club == "Radio_club"){
                 Radio_club.add_member_to_club(member);
            }
            else if(club == "Programming_club"){
                 Programming_club.add_member_to_club(member);
            }
            else if(club == "Developers_club"){
                 Developers_club.add_member_to_club(member);
            }
}
void display_club(string club){
            if(club == "Khelaiya club"){
                 Khelaiya_club.printing_club(club);
            }
            else if(club == "Press club"){
                 Press_club.printing_club(club);
            }
            else if(club == "Music club"){
                 Music_club.printing_club(club);
            }
            else if(club == "Debate club"){
                 Debate_club.printing_club(club);
            }
            else if(club == "Dance club"){
                 Dance_club.printing_club(club);
            }
            else if(club == "Cubing club"){
                 Cubing_club.printing_club(club);
            }
            else if(club == "Quiz club"){
                 Quiz_club.printing_club(club);
            }
            else if(club == "Drama club"){
                 Drama_club.printing_club(club);
            }
            else if(club == "Muse club"){
                 Muse_club.printing_club(club);
            }
            else if(club == "Radio club"){
                 Radio_club.printing_club(club);
            }
            else if(club == "Programming club"){
                 Programming_club.printing_club(club);
            }
            else if(club == "Developers club"){
                 Developers_club.printing_club(club);
            }
    }

    // general list consisting of all the members of all the clubs
class general_list{
    public: 
        unordered_map<int , details> gen_list;
        unordered_map<string , details> gen2_list;

        void add_new(int id, details member){
            gen_list[id]=member;
        }
        void add_2new(string name, details member){
        gen2_list[name] = member;
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
                    add_2new(name,member);
                sort_into_club(member,club);
                
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
        void find_mem_by_name(string name){
            details member = gen2_list.at(name);
            member.print();
        }
};

int main(){
    ofstream outputFile("output.txt");          // Opening a file for output
    
    if (!outputFile.is_open()) {                            // Checking if the file was opened successfully
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    streambuf *coutbuf = cout.rdbuf(); 
    cout.rdbuf(outputFile.rdbuf());             // Redirecting output to file instead of console

    // Our main code
    general_list main ;
    main.get_from_file("gen_list.txt");
    main.find_mem_by_id(202301414);
    main.find_mem_by_name("Parshv_Joshi"); 
    display_club("Khelaiya club");
    // end of the main code
    
    cout.rdbuf(coutbuf);
    outputFile.close();             // closing the output file
    return 0;
}
