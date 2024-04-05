#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility> 
#include <functional> 

using namespace std;

class calendar{

    int y,m,d;
    cout<< "Enter the year you want to look for:"<<endl;
    cin>>y;
    cout<< "Enter the month:"<<endl;
    cin>>m;
    cout<< "Enter the date:"<<endl;
    cin>>d;

    int priority = ((y*365)+(m*12)+(d*31))*(-1);

    priority_queue<pair<int,object>> calendar;


    calendar.first.push(priority);
    calendar.second.push(object);


};