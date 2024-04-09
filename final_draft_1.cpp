#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class club_access
{
private:
    unordered_map<string, int> club_budgets;
    unordered_map<string, string> club_password;
    int n;
    vector<string> club_names;
public:
club_access(){
    n=0;
}
    // Constructor to set custom password for a specific club
    void add_access_to_club(string club_name, string pass, int budget){
        club_password[club_name] = pass;
        club_budgets[club_name] = budget;
        club_names.push_back(club_name);
        n++;
    }   
    // Function to read password and budget information from file
    void read_from_file() {
        ifstream file("password.txt");
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
    // Function to write updated budget information to file
    void write_to_file() {
        ofstream file("password.txt");
        if (file.is_open()) {
            for (int i=0; i<n; i++) {
                file << club_names[i] << " " << club_password[club_names[i]] << " " << club_budgets[club_names[i]] << endl;
            }
            file.close();
            cout << "Budgets updated to file: "<< endl;
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
    int getCurrentBudget(const string& club_name) {
        if (club_budgets.find(club_name) != club_budgets.end()) {
            return club_budgets[club_name];
        } else {
            cout << "Club " << club_name << " does not exist." << endl;
            return -1;
        }
    }    

   // Function to deposit money into a club's budget
    void depositMoney(int money_to_add, const string& club_name) {
        club_budgets[club_name] += money_to_add;
        cout << "Deposited " << money_to_add << " into the budget of club " << club_name << endl;
        
    }


    // Function to withdraw money from a club's budget
    bool withdrawMoney(int money_to_withdraw, const string& club_name) {
        if (club_budgets.find(club_name) != club_budgets.end()) {
            if (club_budgets[club_name] >= money_to_withdraw) {
                club_budgets[club_name] -= money_to_withdraw;
                cout << "Withdrawn " << money_to_withdraw << " from the budget of club " << club_name << endl;
                
                return true;
            } else {
                cout << "Not enough balance in the budget of club " << club_name << endl;
                return false;
            }
        } else {
            cout << "Club " << club_name << " does not exist." << endl;
            return false;
        }
    }
};

club_access access;

void get_from_file()
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


int main()
{   
   
    get_from_file();
    string new_password,initial_password, club_name;
    
    int choice;
    cout<<"Enter the club_name you want access";
    cin >> club_name;
    cout<<"Enter the password of the club";
    cin >> initial_password;
    if(access.verify(club_name, initial_password )){

        
    do{    
        cout<<"Enter 1 to get the current budget\n"<<"Enter 2 to deposite money"<<"Enter 3 to \n"<<"Enter 4 to change password\n"<<"Enter 5 to "; 
        cin>>choice;
    switch (choice)
    {
        case 0:
        access.write_to_file();
        cout<<"Successfully exited";
        break;
        
        case 1:
        cout<<access.getCurrentBudget(club_name);

        break;

        case 2:
        int x;
        cout<<"enter money to be added: ";
        cin>>x;
        access.depositMoney(x,club_name);
        cout<<"successfully deposited ";
        cout<<"Updated blance: ";
        access.getCurrentBudget(club_name);
        break;

        case 3:
        break;

        case 4:
        cout<<"Enter initial password: "<<endl;
        cin>>initial_password;
        cout<<"Enter new password: "<<endl;
        cin>>new_password;
        access.change_password(initial_password,club_name,new_password);
        break;

        case 5:
        break;
    }
    }while(choice);
    }
    else{
        cout<<"incorrect club name or password entered\n";
    }

    return 0;
}
