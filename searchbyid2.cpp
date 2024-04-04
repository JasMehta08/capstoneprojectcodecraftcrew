#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class club_data
{
public:
    unordered_map<int, string> student_map;

    void add_student(int Id, string Name)
    {
        student_map[Id] = Name;
    }

    int check_id(int Id)
    {
        if (student_map.find(Id) != student_map.end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void print_info(int Id)
    {
        cout << "Student Id: " << Id << "\n"
             << "Student Name: " << student_map[Id] << endl;
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
                int id;
                string name;
                if (ss >> id >> name)
                {
                    add_student(id, name);
                }
            }
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }
    void add_to_file(const string &filename, int Id, const string &Name)
    {
        ofstream file(filename, ios_base::app);
        if (file.is_open())
        {
            file << "\n"<< Id << " " << Name << endl;
            file.close();
            add_student(Id, Name);
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

int main()
{
    club_data Khelaiya_club, Press_club, general;
    int input_id, choice;
    string stud_name; //only needed in switch case 3
    Khelaiya_club.get_from_file("khelaiya_club_file.txt");
    Press_club.get_from_file("Press_club_file.txt");
    do
    {
        cout << "\n Enter the number of the task you want to perform. Enter 0 to exit:" << endl;
        cout << " 1. To search by student ID \n 2. To display club members \n 3. To add a member \n 4. To clear the screen" << endl;
        cout << "\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;

        case 1:
            cout << "Enter student Id you want to search: " << endl;
            cin >> input_id;

            if (Khelaiya_club.check_id(input_id))
            {
                Khelaiya_club.print_info(input_id);
                cout << "Member of club: Khelaiya Club" << endl;
            }
            if (Press_club.check_id(input_id))
            {
                Press_club.print_info(input_id);
                cout << "Member of club: Press Club" << endl;
            }
            break;

        case 2:
            char temp;
            cout << "Enter the club you want to be displayed: \na.Khelaiya club\nb.Press club\n"
                 << endl;
            cin >> temp;
            switch (temp)
            {
            case 'a':
                cout << "Members of Khelaiya Club:" << endl;
                for (const auto &pair : Khelaiya_club.student_map)
                {
                    int id = pair.first;
                    string name = pair.second;
                    cout << "ID: " << id << "\t Name: " << name << endl;
                }
                break;
            case 'b':
                cout << "\nMembers of Press Club:" << endl;
                for (const auto &pair : Press_club.student_map)
                {
                    int id = pair.first;
                    string name = pair.second;
                    cout << "ID: " << id << "\t Name: " << name << endl;
                }
                break;

            default:
                break;
            }
            break;

        case 3:
            char extra;
            int stud_id;
            cout << "Enter student ID:" << endl;
            cin >> stud_id;
            cout << "Enter student name in the format(Name_Surname):" << endl;
            cin >> stud_name;
            cout << "Select the club you want to add the member to: \na.Khelaiya club\nb.Press club"
                 << endl;
            cin >> extra;
            switch (extra)
            {
            case 'a':
                Khelaiya_club.add_to_file("khelaiya_club_file.txt", stud_id, stud_name);
                cout << "Student details uploaded successfully."<<endl<<"\n";
                break;

            case 'b':
                Press_club.add_to_file("Press_club_file.txt", stud_id, stud_name);
                cout << "Student details uploaded successfully."<<endl<<"\n";
                break;

            default:
                break;
            }
            break;

        case 4:
            system("cls");
            break;

        default:
            cout << "Enter a valid number!";
            break;
        }
    } while (choice != 0);
    return 0;
}