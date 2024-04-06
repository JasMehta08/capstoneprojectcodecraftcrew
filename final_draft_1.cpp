#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class club_access
{
private:
    unordered_map<string, string> club_password;

public:
    // Constructor to set custom password for a specific club
    club_access(string club_name, string passcode)
    {
        club_password[club_name] = passcode;
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
    // function to change password
    void change_password(string password, string club_name, string new_password)
    {
        if (verify(club_name, password))
        {

            club_password[club_name] = new_password;
            cout << "password sucessfully updated.\n";
        }
        else
        {
            cout<<"Initial password invalid.\n";
            return;
        }
    }
};

class Budget  {
private:
    unordered_map<string, int> club_budgets;

public:
    

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

int main()
{   
    string new_password,initial_password;
    Budget Budget_Applications;

    string club_name, password;
    cout<<"give the club name for which you are setting the password for the 1st time ";
    cin>>club_name;
    cout<<"Set the password for the club for 1st time ";
    cin>>password;
    club_access club_access_application(club_name,password);
    cout<<"password set successfully";

    int choice;
    cout<<"enter what do you  want to do";
    cin>>choice;

    switch (choice)
    {
        case 0:
        cout<<"Successfully exited";
        break;
        
        case 1:
        Budget_Applications.getCurrentBudget(club_name);
        break;

        case 2:
        int x;
        cout<<"enter money to be added:";
        cin>>x;
        Budget_Applications.depositMoney(x,club_name);
        cout<<"successfully deposited";
        cout<<"Updated blance: ";
        Budget_Applications.getCurrentBudget(club_name);
        break;

        case 3:
        break;

        case 4:
        cout<<"Enter initial password: "<<endl;
        cin>>initial_password;
        cout<<"Enter new password: "<<endl;
        cin>>new_password;
        club_access_application.change_password(initial_password,club_name,new_password);
        break;

        case 5:
        

    }

    return 0;
}
