#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility> 
#include <functional> 
#include <sstream>
#include <fstream>

using namespace std;
class event_details{
    public:
    string event_name,event_description,date;
    int cost;
    bool operator<(const event_details& other) const {
    return date < other.date;
    }
};

class calendar{
    public:
    priority_queue<pair<int,event_details>> Calender_pq;

    void add_event_to_pq(int d,int m,int y,event_details object){
        int priority = ((y*365)+(m*31)+(d))*(-1);
        Calender_pq.push(make_pair(priority, object));
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
                string name;
                string description,cost_str,day_str,month_str,year_str;
                event_details obj;
                int cost,day,month,year;
                if (getline(ss, name, ',') && getline(ss, description, ',') && getline(ss, cost_str, ',') && getline(ss, day_str, ',') && getline(ss, month_str, ',') && getline(ss, year_str, ','))
                {
                    cost = stoi(cost_str);
                    day = stoi(day_str);
                    month = stoi(month_str);
                    year = stoi(year_str);
                    obj.event_name=name;
                    obj.event_description=description;
                    obj.cost=cost;
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
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }
    void display_all_events(){
       priority_queue<pair<int, event_details>> temp = Calender_pq;
        if (temp.empty()) {
            cout << "Calendar is empty." << endl;
            return;
        }
        while (!temp.empty()) {
            auto event = temp.top();
            cout << "Event Name: " << event.second.event_name << "\nEvent Description: " << event.second.event_description << "\nEvent cost: " << event.second.cost << "\nEvent date: " << event.second.date << endl<<endl;
            temp.pop();
        }
    }
    void display_most_recent_event(){
        if (!Calender_pq.empty()) {
            auto event = Calender_pq.top();
            cout <<"Most recent event:\n"<< "Event Name: " << event.second.event_name << "\nEvent Description: " << event.second.event_description << "\nEvent cost: " << event.second.cost << "\nEvent date: " << event.second.date << endl;
        }
        else {
            cout << "Calendar is empty." << endl;
        }
    }
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
        add_event_to_pq(day,month,year,object);
        ss<< day << "\\" << month << "\\" << year;
        ss>>object.date;
        add_to_file("event_list.txt",object.event_name,object.event_description,object.cost,day,month,year);
        cout<<"New event entered successfully."<<endl;
    }
    void add_to_file(const string &filename, const string &name, const string &description,int cost, int day,int month,int year)
    {
        ofstream file(filename, ios_base::app);
        if (file.is_open())
        {
            file <<name << "," << description << "," << cost << "," << day << "," << month << "," << year << endl;
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

int main(){
    int choice;
    calendar calendar_application;
    calendar_application.get_from_file("event_list.txt");
    cout<<"Which task do you want to perform?"<<endl;
    cout<<"1. Enter a new event\n"<<"2. Display most recent event\n"<<"3. Display all the events of the club\n";
    cin>>choice;
    switch (choice)
    {
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
        break;
    }

    return 0;
}