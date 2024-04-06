#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Budget {
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
        cout << "Deposited $" << money_to_add << " into the budget of club " << club_name << endl;
    }

    // Function to withdraw money from a club's budget
    bool withdrawMoney(int money_to_withdraw, const string& club_name) {
        if (club_budgets.find(club_name) != club_budgets.end()) {
            if (club_budgets[club_name] >= money_to_withdraw) {
                club_budgets[club_name] -= money_to_withdraw;
                cout << "Withdrawn $" << money_to_withdraw << " from the budget of club " << club_name << endl;
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

int main() {
    Budget budget_manager;

    // Deposit 1000 to the budget of "Khelaiya_club"
    budget_manager.depositMoney(1000, "Khelaiya_club");

    //Withdraw 500 from the budget of "Khelaiya_club"
    budget_manager.withdrawMoney(500, "Khelaiya_club");

    // Withdraw 2000 from the budget of "Nonexistent_club" (This club does not exist)
    budget_manager.withdrawMoney(2000, "Nonexistent_club");

    return 0;
}
