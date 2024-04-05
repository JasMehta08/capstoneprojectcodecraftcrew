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
            return;
        }
    }
};

int main()
{
    // Setting the password for a specific club
    club_access access1("Music_club", "melody123");

    return 0;
}
