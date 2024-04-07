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
#include <memory>

using namespace std;

// basic details of a particular member
class details
{
private:
    int st_id;
    string st_name;
    string club;
    string club_type;
    string faculty;

public:
    // function to insert a new member
    void insert()
    {
        cout << "insert details" << endl
             << "id. number ";
        cin >> st_id;
        cout << endl
             << "name";
        cin >> st_name;
        cout << endl
             << "club";
        cin >> club;
        cout << endl
             << "type of club";
        cin >> club_type;
        cout << endl
             << "faculty(true / false)";
        cin >> faculty;
    }
    // create a new member
    void create(int id, string name, string club, string clubtype, string fac)
    {
        st_id = id;
        st_name = name;
        this->club = club;
        this->club_type = clubtype;
        faculty = fac;
    }
    void print()
    {
        cout << "Student ID: " << st_id;
        cout << endl
             << "Student Name: ";
        cout << st_name;
        cout << endl
             << "Member of Club: ";
        cout << club;
        cout << endl
             << "Club type: ";
        cout << club_type;
        cout << endl
             << "Faculty(True / False): ";
        cout << faculty << "\n"
             << endl;
    }

    void print_club()
    {
        cout << ' ' << st_id << ' '
             << "      "
             << "  " << faculty << ' ' 
             << "        " 
             << ' ' << st_name << ' ' 
             << endl;
    }
};

// details of a particular club will be stored in this class
class club{
private:

    string type;
    string club_name;
    vector<details> list_of_members;

public:
    
    void add_member_to_club(details member)
    {
        list_of_members.push_back(member);
    }
    void name_(string name){

         club_name = name;

    }
    void type_(string type){
        this->type = type; 
    }
    string name_return(){

        return club_name;

    }
    string type_return(){
        return type;
    }
    void printing_club(string club)
    {
        cout << "the list of the members of the club : " << club << endl
             << endl
             << " Student ID "
             << "      "
             << " Faculty "
             << "      "
             << " Student Name " << endl
             << endl;
        for (int i = 0; i < list_of_members.size(); i++){
            
            details temp_mem = list_of_members[i];
            temp_mem.print_club();
        }
        cout<<endl<<endl;
    }
};

vector < club > existing_clubs;
unordered_map<string , club> clubs;

void add_to_club_list(string club_name , string type){

    club temp ;
    temp.name_(club_name);
    temp.type_(type);
    existing_clubs.push_back(temp);
    clubs[club_name]=temp;

}
void sort_into_club(details member, string club)
{
    for(int i = 0 ; i< existing_clubs.size();i++){

        if(existing_clubs[i].name_return() == club){

            existing_clubs[i].add_member_to_club(member);
            return;
        }
    }
}
void display_club(string club)
{
    for(int i = 0 ; i< existing_clubs.size();i++){

        if(existing_clubs[i].name_return() == club){

            existing_clubs[i].printing_club(club);
            return;
        }
    }
}

class club_type{
    private:
    vector<string> clubs_sametype;
    public:
    void input_clubs(string club){
        clubs_sametype.push_back(club);
    }
    void printing_clubs_of_same_type(){
        for(int i = 0 ; i<clubs_sametype.size(); i++){
            display_club(clubs_sametype[i]);
        }
    }
};

club_type Arts,Media,Recreational,Literature,Technical;

void sort_clubs_into_sametype(){
    for(int i = 0 ; i<existing_clubs.size(); i++){
        if(existing_clubs[i].type_return() == "Arts"){
            Arts.input_clubs(existing_clubs[i].name_return());
        }
        else if(existing_clubs[i].type_return() == "Media"){
            Media.input_clubs(existing_clubs[i].name_return());
        }
        else if(existing_clubs[i].type_return() == "Recreational"){
            Recreational.input_clubs(existing_clubs[i].name_return());
        }
        else if(existing_clubs[i].type_return() == "Literature"){
            Literature.input_clubs(existing_clubs[i].name_return());
        }
        else if(existing_clubs[i].type_return() == "Technical"){
            Technical.input_clubs(existing_clubs[i].name_return());
        }
        else{
            cout<<"clubtype does not exist";
        }
    }
}

void display_using_clubtype(string type){
    {
        cout << "displaying clubs of the type : "
        <<type
        <<endl
        <<endl;
        if(type == "Arts"){
            Arts.printing_clubs_of_same_type();
        }
        else if(type == "Media"){
            Media.printing_clubs_of_same_type();
        }
        else if(type == "Recreational"){
            Recreational.printing_clubs_of_same_type();
        }
        else if(type == "Literature"){
            Literature.printing_clubs_of_same_type();
        }
        else if(type == "Technical"){
            Technical.printing_clubs_of_same_type();
        }
        else{
            cout<<"clubtype does not exist";
        }
}
}
// general list consisting of all the members of all the clubs
class general_list
{
public:
    unordered_map<int, details> gen_list;
    unordered_map<string, details> gen2_list;

    void add_new(int id, details member)
    {
        gen_list[id] = member;
    }
    void add_2new(string name, details member)
    {
        gen2_list[name] = member;
    }

    void get_from_file(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string id;
                string name;
                string club;
                string clubtype;
                string faculty;

                getline(ss, id, ' ');
                getline(ss, name, ' ');
                getline(ss, club, ' ');
                getline(ss, clubtype, ' ');
                getline(ss, faculty, ' ');

                details member;
                member.create(stoi(id), name, club, clubtype, faculty);
                add_new(stoi(id), member);
                add_2new(name, member);
                sort_into_club(member, club);
            }
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

    void find_mem_by_id(int id)
    {
        details member = gen_list.at(id);
        member.print();
    }
    void find_mem_by_name(string name)
    {
        details member = gen2_list.at(name);
        member.print();
    }
    void add_to_file(const string &filename, int Id, const string &Name, const string &Club_name, const string &Club_type, const string &Faculty)
    {
        details member;
        member.create(Id,Name, Club_name, Club_type, Faculty);
        ofstream file(filename, ios_base::app);
        if (file.is_open())
        {
            file << "\n"
                 << Id <<" "
                 << Name <<" "
                 << Club_name <<" "
                 << Club_type<<" "
                 <<Faculty;

            file.close();
            
            add_new(Id, member);
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

class club_list{
    private: 

    public:
    void get_from_file(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string club;
                string type;
                getline(ss, club, ' ');
                getline(ss, type, ' ');

                add_to_club_list(club ,type);
            }
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }
};

general_list mem_list;
club_list list;

int main()
{
    
list.get_from_file("clublist.txt");
mem_list.get_from_file("gen_list.txt");
sort_clubs_into_sametype();
bool flag = true,output_file=false;
int picker,output_type;
string filename;
cout<<"select output type"<<endl
        <<"1. output in console"<<endl
        <<"2. output in file"<<endl<<endl;
        cin>>output_type;
        if(output_type==2){
            output_file = true;
            cout << "give name of the file to output into :";
            cin>>filename;
        }
        
        ofstream outputFile(filename+".txt"); // Opening a file for output

        if (!outputFile.is_open())
        { // Checking if the file was opened successfully
            cerr << "Error opening output file!" << endl;
        }
while(flag){
    cout<<"what do you want to perform:"<<endl
        <<"1. search for a id"<<endl
        <<"2. search for a name"<<endl
        <<"3. search for a club"<<endl
        <<"4. search for clubs by its type"<<endl
        <<"enter 0 to exit"<<endl<<endl
        <<"enter serial number of the function you want to perform : "<<endl<<endl;
        cin>>picker;
        if(picker == 0 ){
            flag = false ;
            break;
        }  
    string given_name;
    string club_name;
    string given_type;
        switch(picker){
            case 0:
                flag = false;
                break;
            case 1:
                int id;
                cout<<"input particular id that you would like to search for : ";
                cin>>id;
                cout<<endl;
                if(!output_file) mem_list.find_mem_by_id(id);
                else{
                    streambuf *coutbuf = cout.rdbuf();
                    cout.rdbuf(outputFile.rdbuf()); // Redirecting output to file instead of console

                    // Our main code
                    mem_list.find_mem_by_id(id);
                    // end of the main code
                    cout.rdbuf(coutbuf);
                }
                break;
            case 2:
                cout<<"input particular name that you would like to search for((Name_Surname)initial letter of name and surname capital with seperation using underscore) : ";
                cin>>given_name;
                cout<<endl;
                if(!output_file) mem_list.find_mem_by_name(given_name);
                else{

                    streambuf *coutbuf = cout.rdbuf();
                    cout.rdbuf(outputFile.rdbuf()); // Redirecting output to file instead of console

                    // Our main code
                    mem_list.find_mem_by_name(given_name);
                    // end of the main code
                    cout.rdbuf(coutbuf);
                }
                break;
            case 3:
                cout << "Enter the club name you would like to search for from these existing clubs: " << endl;
                for (auto it = existing_clubs.begin(); it != existing_clubs.end(); ++it) {
                    cout << " " << it->name_return() << endl;
                }
                cin>>club_name;
                    cout<<endl;
                    if(!output_file) display_club(club_name);
                    else{
                        streambuf *coutbuf = cout.rdbuf();
                        cout.rdbuf(outputFile.rdbuf()); // Redirecting output to file instead of console

                        // Our main code
                        display_club(club_name);
                        // end of the main code
                        cout.rdbuf(coutbuf);
                    }
                break;
            case 4:
                cout << "Enter type of club that you what to be displayed from the existing types : "<<endl;
                cout<<" Arts\n Media\n Recreational\n Literature\n Technical\n";
                cin >> given_type;
                cout<<endl;
                if(!output_file) display_using_clubtype(given_type);
                else{
                    streambuf *coutbuf = cout.rdbuf();
                    cout.rdbuf(outputFile.rdbuf()); // Redirecting output to file instead of console

                    // Our main code
                    display_using_clubtype(given_type);
                    // end of the main code
                    cout.rdbuf(coutbuf);
                }
                break;
            default:
                cout <<endl <<endl << "invalid selection, try again";
                break;
        }
}

outputFile.close(); // closing the output file
    return 0;
}
