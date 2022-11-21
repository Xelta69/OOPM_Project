// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <vector>
#include <exception>

using namespace std;

class Formality{
    
    private:
    string name;
    int age;
    
    public:
    void ask_name(){
        cout<<"What is your name? ";
        cin>>name;
    }
    void ask_age(){
        cout<<"What is your age? ";
        cin>>age;
    }
};

class Bed{
    int bed_num;
};

class Medicine{

};

class Department{
    
};

class admitForm{
    string name;
    int age;
    string phone_number;
    string adhaar;

    public:
    void fill_form(){
        cout<<"Give your name: ";
        cin>>name;

        cout<<"Give your age: ";
        cin>>age;

        cout<<"Give your phone_number: ";
        cin>>phone_number;

        cout<<"Give your Adhaar Number: ";
        cin>>adhaar;
    }

    void display_form(){
        cout<<"Your name: "<<name<<endl;
        cout<<"Your age: "<<age<<endl;
        cout<<"Your phone number: "<<phone_number<<endl;
        cout<<"Your Adhaar Card: "<<adhaar<<endl;
    }
};

class Doctors{
    
   
    vector <string> doc_list {"Dr.Ahuja","Dr.Singh","Dr.Patel",
                            "Dr.Khan", "Dr.Saxena","Dr.Nagraj",
                            "Dr.Gulati"};
    // int i = 7;
    int week ;
    
    protected:
    
    void add_doc(string S){
        doc_list.push_back(S);
    }
    void get_doc(){
        for(int i = 0; i < doc_list.size(); i++){
            try{
                if(week == i%7){
                    cout<<doc_list[i]<<" "<<doc_list[i+1];
                }
            }
            catch (out_of_range& e){
                cout<<" ";
            }
                
        }
    }
    
    void get_weekday(int week_num){
        switch(week_num){
            case 0: cout<< "For Monday: ";break;
            case 1: cout<< "For Tuesday: ";break;
            case 2: cout<< "For Wednesday: ";break;
            case 3: cout<< "For Thursday: ";break;
            case 4: cout<< "For Friday: ";break;
            case 5: cout<< "For Saturday: ";break;
            case 6: cout<< "For Sunday: ";break;
            default: cout<<"System error : Sorry For Inconvenience \n";break;
        }
    }

    public:
    
    Doctors(void){
        srand(2);
        week = rand() % 7;
    }
    
    void list_doc(){
        for(week = 0; week < 7; week++){
            get_weekday(week);
            get_doc();
            cout<<"\n";
        }
    }
};

int main() {
    Doctors db;
    db.list_doc();

    return 0;
}
