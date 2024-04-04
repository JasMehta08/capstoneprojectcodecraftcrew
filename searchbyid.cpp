#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class club_data {
public: 
    unordered_map<int, string> student_map;

    void add_student(int Id, string Name){
        student_map[Id]=Name;
    }

    int check_id(int Id){
        if(student_map.find(Id)!=student_map.end()){
            return 1;
        }
        else{
            return 0;
        }
    }
    void print_info(int Id){
        cout<<"Student Id: "<< Id <<"\n"<<"Student Name: "<< student_map[Id]<<endl;
    }
};

int main(){
    club_data Khelaiya_club,Press_club,general;
    int input_id;
    Khelaiya_club.add_student(202301414,"Visha Sitapara"); 
    Khelaiya_club.add_student(202301212,"Ishti Patel"); 
    Khelaiya_club.add_student(202301095,"Dhruv Patel"); 

    Press_club.add_student(202301039,"Parshv Joshi");
    Press_club.add_student(202301072,"Siddharth Rambhia");

    cout<<"Enter student Id you want to search: "<<endl;
    cin>>input_id;
    general.print_info(input_id);
    
    if(Khelaiya_club.check_id(input_id)){
        Khelaiya_club.print_info(input_id);
        cout<<"Member of club: Khelaiya Club"<<endl;
    }
    if(Press_club.check_id(input_id)){
        Press_club.print_info(input_id);
        cout<<"Member of club: Press Club"<<endl;
    }
    return 0;
}