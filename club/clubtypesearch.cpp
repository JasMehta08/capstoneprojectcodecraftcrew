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
        cout << ' ' << st_id << ' ' << "      "
             << "  " << faculty << ' ' << "        " << ' ' << st_name << ' ' << endl;
    }
};

// details of a particular club will be stored in this class
class club{
private:
    string club_name;
    vector<details> list_of_members;

public:
    
    void add_member_to_club(details member)
    {
        list_of_members.push_back(member);
    }
    void name(string name){
         club_name = name;
    }
    string name_return(){
        return club_name;
    }
    void printing_club(string club)
    {
        cout << "the list of the members of the club : " << club << endl
             << endl;
        cout << " Student ID "
             << "      "
             << " Faculty "
             << "      "
             << " Student Name " << endl
             << endl;
        for (int i = 0; i < list_of_members.size(); i++)
        {
            details temp_mem = list_of_members[i];
            temp_mem.print_club();
        }
    }
};



vector < club > existing_clubs;
unordered_map<string , club> clubs;

void add_to_club_list(string club_name){
    club temp ;
    temp.name(club_name);
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
                 << Id <<" "<< Name <<" "<< Club_name <<" "<< Club_type<<" "<<Faculty;
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
                getline(ss, club, ' ');

                add_to_club_list(club);
            }
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }
};

int main()
{
    ofstream outputFile("output.txt"); // Opening a file for output

    if (!outputFile.is_open())
    { // Checking if the file was opened successfully
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf()); // Redirecting output to file instead of console

    // Our main code
    general_list main;
    club_list list;
    list.get_from_file("clublist.txt");
    main.get_from_file("gen_list.txt");
    main.find_mem_by_id(202301414);
    main.find_mem_by_name("Parshv_Joshi");
    display_club("Khelaiya_club");
    display_club("Press_club");
    main.add_to_file("gen_list.txt",202301000,"Add_func_check","Khelaiya_club","Arts","True");
    // end of the main code

    cout.rdbuf(coutbuf);
    outputFile.close(); // closing the output file
    return 0;
}
