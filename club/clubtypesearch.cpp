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
    int st_id;              //the id of the member
    string st_name;         //name of the member
    string club;            //name of the club that member is a part of
    string club_type;       //type of the club that member is a part of
    string faculty;         //to display if the member is a faculty or not

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
    // create a new member (used mainly for reading from file)
    void create(int id, string name, string club, string clubtype, string fac)
    {
        st_id = id;
        st_name = name;
        this->club = club;
        this->club_type = clubtype;
        faculty = fac;
    }
    //displaying a particular member in the console
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
    //function is used with another function to create a table that is displaying the whole club
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
//the class is used to gain access to a few important things related to a particular club 
//requires password to access a particular club and the password of a particular club can be changed to become unique to a club
class club_access
{
private:
    unordered_map<string, int> club_budgets;            //a hashmap relating club names to their budgets
    unordered_map<string, string> club_password;        //a hashmap relating club names to their passwords
    int n;                                              //a count of the number of clubs that are present
    vector<string> club_names;                          //a vector(dynamic array) which is storing the names of all the clubs
public:
//Constructor initializing count of the number of clubs
club_access(){
    n=0;
}
    // Function to set custom password for a specific club
    void add_access_to_club(string club_name, string pass, int budget){
        club_password[club_name] = pass;
        club_budgets[club_name] = budget;
        club_names.push_back(club_name);
        n++;
    }   
    // Function to read password and budget information from file
    void read_from_file() {
        ifstream file("password.txt");      //fixed file which is storing all the club names , passwords and club budgets 
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string club;
                string pass;
                int budget;
                ss >> club >> pass >> budget;
                add_access_to_club(club, pass, budget);
            }
            file.close();
        } else {
            cerr << "Error: Unable to open file "<< endl;
        }
    }
    // Function to write updated budget information to the fixed file at the end of the code as to store it for future use
    void write_to_file_at_exit() {
        ofstream file("password.txt");
        if (file.is_open()) {
            for (int i=0; i<n; i++) {
                file << club_names[i] << " " << club_password[club_names[i]] << " " << club_budgets[club_names[i]] << endl;
            }
            file.close();
        } else {
            cerr << "Error: Unable to open file "  << endl;
        }
    }

    // funcition to verify wether the password is correct or not.
    bool verify(string club_name, string passcode)
    {

        if (club_password[club_name] == passcode)
        {
            return true;
        }
        else
        {
            cout << "Incorrect password, please try again.\n";
            return false;
        }
    }
    
    // Function to change password
    void change_password(string password, string club_name, string new_password) {
        if (verify(club_name, password)) {
            club_password[club_name] = new_password;
            cout << "Password successfully updated.\n";
            
        } 
        else {
            cout << "Initial password invalid.\n";
        }
    }
    // Function to get the current budget of a club
    void getCurrentBudget(const string& club_name) {
        try {
            cout<<club_budgets[club_name]<<endl<<endl;
        } catch (const out_of_range& e){
            cerr<<"Error : club not found "<<endl<<endl;
        }
    }    

   // Function to deposit money into a club's budget
    void depositMoney(int money_to_add, const string& club_name) {
        club_budgets[club_name] += money_to_add;
        cout << "Deposited " << money_to_add 
             << " into the budget of club " << club_name << endl;
        
    }


    // Function to withdraw money from a club's budget
    void withdrawMoney(int money_to_withdraw, const string& club_name) {
        try {
            if (club_budgets[club_name] >= money_to_withdraw) {

                club_budgets[club_name] -= money_to_withdraw;
                cout << "Withdrawn " << money_to_withdraw << " from the budget of club " << club_name << endl;

            } else {

                cout << "Not enough balance in the budget of club " << club_name << endl;

            }
        } catch(const out_of_range& e) {

            cerr << "Club " << club_name << " does not exist." << endl;

        }
    }
};
// a global object that has club access
club_access access;

// function to load the club details into the club access object
void get_from_file_access()
    {
        ifstream file("password.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string club;
                string pass;
                string budget;
                getline(ss, club, ' ');
                getline(ss, pass, ' ');
                getline(ss,budget, ' ');
                access.add_access_to_club(club ,pass, stoi(budget));
            }
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << endl;
        }
    }

// class that is used in the calender to store a event
class event_details{
    public:
    string event_name,event_description,date,club_name;
    int cost;
    bool operator<(const event_details& other) const {
    return date < other.date;
    }
};

// class is used to create a calender that stores all the events in a proper date-wise order
class calendar{
    public:
    // we are using a priority queue for making the calender and using pairs
    //where the first part of the pair is used to set priority of the events using a expression
    priority_queue<pair<int,event_details> > Calender_pq;

    void add_event_to_pq(int d,int m,int y,event_details object){
        //the particular data is broken into 3 parts and then a formula is used so as it make it useful in setting priority
        int priority = ((y*365)+(m*31)+(d))*(-1);
        Calender_pq.push(make_pair(priority, object));
    }
    //function to get preset information from a file
    void get_from_file_calander()
    {
        ifstream file("event_list.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string name;
                string description,cost_str,day_str,month_str,year_str;
                string club_name;
                event_details obj;
                int cost,day,month,year;
                if (getline(ss, name, ',') && getline(ss, description, ',') && getline(ss, cost_str, ',') && getline(ss, day_str, ',') && getline(ss, month_str, ',') && getline(ss, year_str, ',')&&getline(ss,club_name, ','))
                {
                    cost = stoi(cost_str);
                    day = stoi(day_str);
                    month = stoi(month_str);
                    year = stoi(year_str);
                    obj.event_name=name;
                    obj.event_description=description;
                    obj.cost=cost;
                    obj.club_name=club_name;
                    stringstream ss;
                    ss<< day << "\\" << month << "\\" << year;
                    ss>>obj.date;
                    int priority = ((year * 365) + (month * 31) + (day)) * (-1);
                    Calender_pq.push(make_pair(priority, obj));
                }
            }
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << endl;
        }
    }
    //function to display all the events
    void display_all_events(){
       priority_queue<pair<int, event_details> > temp = Calender_pq;
        if (temp.empty()) {
            cout << "Calendar is empty." << endl;
            return;
        }
        while (!temp.empty()) {
            auto event = temp.top();
            cout << "Event Name: " << event.second.event_name 
                 << "\nEvent Description: " << event.second.event_description 
                 << "\nEvent cost: " << event.second.cost 
                 << "\nEvent date: " << event.second.date 
                 << "\nEvent host: "<< event.second.club_name << endl<<endl;
            temp.pop();
        }
    }
    // function to display the closest event
    void display_most_recent_event(){
        if (!Calender_pq.empty()) {
            auto event = Calender_pq.top();
            cout <<"Most recent event:\n"
                 << "Event Name: " << event.second.event_name 
                 << "\nEvent Description: " << event.second.event_description 
                 << "\nEvent cost: " << event.second.cost 
                 << "\nEvent date: " << event.second.date 
                 <<"\nEvent host: "<< event.second.club_name<< endl<<endl;
        }
        else {
            cout << "Calendar is empty." << endl;
        }
    }
    //function to add new event
    void enter_event(){
        event_details object;
        int year,month,day;
        stringstream ss;
        cout<<"You are entering a new event: "<<endl;
        cout<<"Enter event name: ";
        cin.ignore();
        getline(cin,object.event_name);
        cout<<"Enter event description: ";
        getline(cin,object.event_description);
        cout<<"Enter cost of this event: ";
        cin>>object.cost;
        cout<<"Enter event date in the form (dd mm yyyy): ";
        cin>>day>>month>>year;
        cout<<"Enter club who is hosting the event: ";
        cin >> object.club_name;
        add_event_to_pq(day,month,year,object);
        ss<< day << "\\" << month << "\\" << year;
        ss>>object.date;
        add_to_file("event_list.txt",object.event_name,object.event_description,object.cost,day,month,year,object.club_name);
        cout<<"New event entered successfully."<<endl;
    }
    //function to add the created function into a file
    void add_to_file(const string &filename, const string &name, const string &description,int cost, int day,int month,int year,const string& club_name)
    {
        ofstream file(filename, ios_base::app);
        if (file.is_open())
        {
            file <<name << "," << description << "," << cost << "," << day << "," << month << "," << year<<","<<club_name << endl;
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

// details of a particular club will be stored in this class
class club{
private:

    string type;
    string club_name;
    vector<details> list_of_members;

public:
    //function to add the member to a club
    void add_member_to_club(details member)
    {
        list_of_members.push_back(member);
    }
    //function to access the name of the club
    void name_(string name){

         club_name = name;

    }
    //function to access the type the club
    void type_(string type){
        this->type = type; 
    }
    //function to get the name of the club
    string name_return(){

        return club_name;

    }
    //function to get the club type
    string type_return(){
        return type;
    }
    //function to display the whole club
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

//a vector(dynamic array) to store all the existing clubs
vector < club > existing_clubs;

//a hashmap to relate the name of a club with the club object 
unordered_map<string , club> clubs_map;

//function to add a club to the list of clubs
void add_to_club_list(string club_name , string type){

    club temp ;
    temp.name_(club_name);
    temp.type_(type);
    existing_clubs.push_back(temp);
    clubs_map[club_name]=temp;

}

//function to sort a member into a club
void sort_into_club(details member, string club)
{
    for(int i = 0 ; i< existing_clubs.size();i++){

        if(existing_clubs[i].name_return() == club){

            existing_clubs[i].add_member_to_club(member);
            return;
        }
    }
}

//function to display the whole club
void display_club(string club)
{
    for(int i = 0 ; i< existing_clubs.size();i++){

        if(existing_clubs[i].name_return() == club){

            existing_clubs[i].printing_club(club);
            return;
        }
    }
}

//class that is used to display clubs of the same type
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

// defination of all the different club types
club_type Arts,Media,Recreational,Literature,Technical;


//sorting clubs into the type of clubs that are present
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

//function to display all the same clubs of the same type
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
    //function for adding new member to the general list (by id)
    void add_new(int id, details member)
    {
        gen_list[id] = member;
    }
    //function for adding new member to the general list (by name)
    void add_2new(string name, details member)
    {
        gen2_list[name] = member;
    }
    // function to get information stored in file
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
    //function finding member using id
    void find_mem_by_id(int id)
    {
        try{
            details member = gen_list.at(id);
            member.print();
        }catch(const out_of_range& e){
            cerr << "Input not found, does not exist "<<endl << endl; 
        }
    }
    //function finding member using name
    void find_mem_by_name(string name)
    {
        try{
            details member = gen2_list.at(name);
            member.print();
        }catch(const out_of_range& e){
            cerr << "Input not found, does not exist "<<endl << endl; 
        }
    }
    // function for adding a new member to the file
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
            sort_into_club(member,Club_name);
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

//function displaying all the clubs
void dis_club(){
    for (auto it = existing_clubs.begin(); it != existing_clubs.end(); ++it) {
        cout << " " << it->name_return() << endl;
    }
}
//class containing clubs in a list from the file
class club_list{
    private: 

    public:
    void get_from_file_club(const string &filename)
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
    list.get_from_file_club("clublist.txt");
    mem_list.get_from_file("gen_list.txt");
    sort_clubs_into_sametype();
    get_from_file_access();
    input:
    int runner=1 ;
    cout << "select which of the following you want to perform : "<<endl
         << "1. search"<<endl
         << "2. access clubs"<<endl
         << "3. club events"<<endl;
    cin >> runner ; 
    if(runner == 1 || runner == 2 || runner ==3 );
    else{
        cout<< "wrong input, try again";
        goto input;
    }
    if (runner == 1){
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

                    
                    mem_list.find_mem_by_id(id);
                    
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

                    
                    mem_list.find_mem_by_name(given_name);
                    
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

                        
                        display_club(club_name);
                       
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

                    
                    display_using_clubtype(given_type);
                    
                    cout.rdbuf(coutbuf);
                }
                break;
            default:
                cout <<endl <<endl << "invalid selection, try again";
                break;
        }
    }

    outputFile.close(); // closing the output file
    }
    else if (runner == 2 ){
        string new_password,initial_password, club_name;
        string name, club_name_,club_type_,faculty;
        int choice,id;
        cout<<"Enter the club_name you want access : ";
        cin >> club_name;
        cout<<"Enter the password of the club : ";
        cin >> initial_password;
        if(access.verify(club_name, initial_password )){

            
        do{    
            cout<<endl<<"Enter 1 to get the current budget"<<endl
            <<"Enter 2 to deposit money"<<endl
            <<"Enter 3 to add member to general list"<<endl
            <<"Enter 4 to change password"<<endl
            <<"0 to exit the code"<<endl
            <<endl; 
            cin>>choice;
        switch (choice)
        {
            case 0:
            access.write_to_file_at_exit();
            cout<<"Successfully exited";
            break;
            
            case 1:
            cout<< "current budget: ";
            access.getCurrentBudget(club_name);

            break;

            case 2:
            int x;
            cout<<"enter money to be added: ";
            cin>>x;
            cout << endl;
            access.depositMoney(x,club_name);
            cout<<"successfully deposited "<<endl;
            cout<<"Updated balance: ";
            access.getCurrentBudget(club_name);
            break;

            case 3:
                    cout << "insert details" << endl
                        << "id. number :";
                    cin >> id;
                    cout << endl
                        << "name :";
                    cin >> name;
                    cout << endl
                        << "club :";
                    dis_club();
                    cin >> club_name_;
                    cout << endl
                        << "type of club :"
                        <<endl;
                        cout<<" Arts\n Media\n Recreational\n Literature\n Technical\n";
                    cin >> club_type_;
                    cout << endl
                        << "faculty(true / false) :";
                    cin >> faculty;
                    mem_list.add_to_file("gen_list.txt", id, name, club_name_, club_type_, faculty);
            break;

            case 4:
            cout<<"Enter initial password: "<<endl;
            cin>>initial_password;
            cout<<"Enter new password: "<<endl;
            cin>>new_password;
            access.change_password(initial_password,club_name,new_password);
            break;

            default:
            cout << "invalid input";
            break;
        }
        }while(choice);
        }
        else{
            cout<<"incorrect club name or password entered\n";
        }
    }
    else if(runner == 3){
        calendar calendar_application;
        calendar_application.get_from_file_calander();
        int use=1;
        while(use){
            cout<<"Which task do you want to perform?"<<endl;
            cout<<"1. Enter a new event\n"
                <<"2. Display most recent event\n"
                <<"3. Display all the events of the club\n";
            cin>>use;
            switch (use)
            {
                case 0: break;
                case 1:
                    calendar_application.enter_event();
                    break;
                case 2:
                    calendar_application.display_most_recent_event();
                    break;
                case 3:
                    calendar_application.display_all_events();
                    break;
                default:
                    cout << "invalid input";
                    break;
            }
        }
    }
    string end;
    cout << "do you want to end the performing tasks?(Yes/No) :"<<endl;
    cin >> end;
    if(end == "Yes"){
        return 0;
    }
    else if(end == "No"){
        goto input;
    }
    return 0;
}
