// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <vector>
#include <exception>
#include<cctype>

using namespace std;

class Reception{
    
    private:
    string name;
    int age;
    
    public:
    Reception(){
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        tt = localtime(&t);

        if(tt->tm_hour < 12 && tt->tm_hour >= 5)
            cout<<"Good Morning!!!\nHow may I help you?"<<endl;
        else if(tt->tm_hour < 5 && tt->tm_hour >= 17)
            cout<<"Good Evening!!!\nHow may I help you?"<<endl;
        else if(tt->tm_hour < 17 && tt->tm_hour >= 12)
            cout<<"Good Afteroon!!!\nHow may I help you?"<<endl;

    }
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
    int bed_avail;
    public:
    
    Bed(void){
        srand(5);
        bed_num = rand() % (100 + 1);
    }

    void bed_status(){
        if(bed_num > 0 && bed_num < 50){
            cout<<"Many beds are available."<<endl;
            bed_avail = 1;
        }
        else if(bed_num >= 50 && bed_num < 100){
            cout<<"Few beds are available."<<endl;
            bed_avail = 1;
        }
        else if(bed_num == 100){
            cout<<"Sorry all beds are occupied"<<endl;
            bed_avail = 0;
        }
        else{
            cout<<"System error..."<<endl<<"Sorry for the inconveniece"<<endl;
            bed_avail = 2;
        }
    }

};

class medicineInfo{
    vector<string> name = {"Forte Tablets", "Aspirin", "Ditropan XL", "Eytazox",
                            "Motrin", "Exelon"};

    public:
    medicineInfo(){   }
};

class Medicine: public medicineInfo{
    public:
    Medicine(){
        // medicineInfo path_1()
    }
};

class departmentInfo{
    protected:
    string name;
    vector <int> doc_IDs;
    vector <int> med_IDs;
    
    public:
    departmentInfo(){ }
    departmentInfo(string dep_name, int doc, int med){
        name = dep_name;
        doc_IDs.push_back(doc);
        med_IDs.push_back(med);
    }
    departmentInfo(string dep_name, int doc){
        name = dep_name;
        doc_IDs.push_back(doc);
    }
};

class Department : public departmentInfo{
    public:
    Department(){
        departmentInfo Path("Pathology", 2, 0), Cardio("Cardiology", 4, 1);
        departmentInfo Uro("Urology", 0, 2), Med("Medicine", 3), Opt("Optics", 1, 3);
        departmentInfo Dent("Dentistry", 6, 4), Neu("Neurology", 5, 5);
    }
};

class admitForm{

    string name;
    int age;
    string phone_number;
    string adhaar;
    char gender;

    public:
    void fill_form(){
        cout<<"Give your name: ";
        cin>>name;

        cout<<"State your age: ";
        cin>>age;

        cout<<"Give your phone_number: ";
        cin>>phone_number;

        cout<<"Give your Adhaar Number: ";
        cin>>adhaar;

        cout<<"State your Gender\n(M-Male, F-Female, O-Others): ";
        cin>>gender;

        review_form();
    }

    string get_gender(char gen){
        switch(toupper(gen)){
            case 'M': return "Male"; break;
            case 'F': return "Female"; break;
            default : return "Others....";
        }
    }

    void review_form(){
        char alr = 'x';

        cout<<"Review is your form....\n"<<endl;

        cout<<"Your name: "<<name<<endl;
        cout<<"Your age: "<<age<<endl;
        cout<<"Your gender: "<<get_gender(gender)<<endl;
        cout<<"Your phone number: "<<phone_number<<endl;
        cout<<"Your Adhaar Card: "<<adhaar<<endl;
        
        cout<<"Is this alright??\n(Y- yes, N - no) :"<<endl;
        cin>>alr;

        while('Y' != toupper(alr)){           

            if('N' == toupper(alr)){
                cout<<"Ok lets try again"<<endl;
                fill_form();
                break;
            }
            
            cout<<"Invalid input\n Try Again!!!!\n"<<endl;

            cout<<"Is this alright??\n(Y- yes, N - no) :"<<endl;
            cin>>alr;

        }
    }
};

class Doctors{

    vector <string> doc_list {"Dr.Ahuja","Dr.Singh","Dr.Patel",
                            "Dr.Khan", "Dr.Saxena","Dr.Nagraj",
                            "Dr.Gulati"};
    // int i = 7;
    int week ;
    
    protected:
    
    
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
    void add_doc(string S){
        doc_list.push_back(S);
    }
};

int main() {
    Doctors db;
    db.list_doc();

    return 0;
}
