// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <vector>
#include <exception>
#include<cctype>
#include<stdlib.h>

using namespace std;

string department_selec = "Press 1 - Pathology\n"
                              "Press 2 - Cardiology\n"
                              "Press 3 - Urology\n"
                              "Press 4 - Dermitology\n"
                              "Press 5 - Optics\n"
                              "Press 6 - Dentistry\n"
                              "Press 7 - Neurology\n";
                              
string part_selec = "Press 1 - Bones and Joints\n"
                        "Press 2 - Heart\n"
                        "Press 3 - Urinary System\n"
                        "Press 4 - Skin\n"
                        "Press 5 - Eyes\n"
                        "Press 6 - Teeth\n"
                        "Press 7 - Brain\n";

struct departmentInfo{
    // protected:
    string name;
    vector <int> doc_ID;
    vector <int> med_ID;                             
    // public:
    // departmentInfo(){ }
    // de  name = dep_name;
    //     doc_IDs.push_back(doc);
    //     med_IDs.push_back(med);
    // }
    // departmentInfo(string dep_name, int doc){
    //     name = dep_name;
    //     doc_IDs.push_back(doc);
    // }partmentInfo(string dep_name, int doc, int med){
      
};

departmentInfo Path = {"Pathology", {2}, {0}};
departmentInfo Cardio = {"Cardiology", {4}, {1}};
departmentInfo Uro{"Urology", {0}, {2}};
departmentInfo Derm{"Dermatology", {3}, {3}};
departmentInfo Opt{"Optics", {1}, {4}};
departmentInfo Dent{"Dentistry", {6}, {5}};
departmentInfo Neu{"Neurology", {5}, {6}};

departmentInfo *p = &Path;
departmentInfo *c = &Cardio;
departmentInfo *u = &Uro;
departmentInfo *dm = &Derm;
departmentInfo *o = &Opt;
departmentInfo *dn = &Dent;
departmentInfo *n = &Neu;

void exit_sys(void){
        cout<<"Come Again :)"<<endl;
        exit(1);
    }


// class Reception{};
// class Doctors{};
// class Bed{};
// class Medicine{};

class medicineInfo{
    protected:
    vector<string> med_list = {"Forte Tablets", "Aspirin", "Ditropan XL", "Avelumab"
                               "Eytazox", "Motrin", "Exelon"};
    int med_num = 5;

    public:
    medicineInfo(){   }
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

        cout<<"\n* * * * * * * * * * * * * * * * * * *\n\n";

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
        
        cout<<"Is this alright??\n(Y- yes, N - no): ";
        cin>>alr;

        while('Y' != toupper(alr)){           

            if('N' == toupper(alr)){
                cout<<"Ok lets try again"<<endl;
                fill_form();
                // cout<<"Is this alright??\n(Y- yes, N - no) :"<<endl;
                // cin>>alr;
                break;
            }
            
            cout<<"Invalid input\n Try Again!!!!\n"<<endl;

            // cout<<"Is this alright??\n(Y- yes, N - no) :"<<endl;
            // cin>>alr;

        }
    }
};

class Bed: admitForm{
    int bed_num;
    int bed_avail;

    // friend admitForm;

    protected:

    void check_bed(char C){
        char x;
        bed_status(C);
        if(bed_avail == 1){
            cout<<"Do you want to book Bed?\n(Y - Yes): ";
            cin>>x;

            if(toupper(x) == 'Y'){
                fill_form();return;
            }
        }
        else if(bed_avail = 0){
            cout<<"Do you want to go back to the Option Panel??\n(Y - Yes): ";
            cin>>x;
            
            if(toupper(x) == 'Y'){
                return;
            }
        }
    }
    public:
    
    Bed(void){
        srand(5);
        bed_num = rand() % (100 + 1);
    }

    void bed_status(char x){

        srand(5);
        bed_num = rand() % (100 + 1);

        if(toupper(x) == 'C'){

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
                // user_op();
                bed_avail = 0;
            }
        }
        else if(toupper(x) == 'H'){

            if(bed_num > 0 && bed_num < 100){
                cout<<bed_num<<" beds are available."<<endl;
                bed_avail = 1;
            }
            else if(bed_num == 100){
                cout<<"All beds are occupied"<<endl;
                bed_avail = 0;
            }
            else{
                cout<<"System error..."<<endl<<"Sorry for the inconveniece\n"<<endl;
                // manage_op();
                bed_avail = 2;
            }            
        }
    }

};


class Medicine: protected medicineInfo{    
    protected:
    void add_med(void){
        string med;
        int selec;

        cout<<"What is the name of the Medicine?";
        cin>>med;

        med_list.push_back(med);
        med_num++;

        cout<<"For what body part is the medicine for?"<<endl<<part_selec;
        cin>>selec;

        switch(selec){
            case 1: p->med_ID.push_back(med_num);break;
            case 2: c->med_ID.push_back(med_num);break;
            case 3: u->med_ID.push_back(med_num);break;
            case 4: dm->med_ID.push_back(med_num);break;
            case 5: o->med_ID.push_back(med_num);break;
            case 6: dn->med_ID.push_back(med_num);break;
            case 7: n->med_ID.push_back(med_num);break;
            default: cout<<"Invalid input...\nTRY AGAIN!!!!"<<endl;
        }

    }

    public:
    Medicine(){
        // medicineInfo path_1()        
    }
    
};

class Doctors{
    // friend class Reception;

    vector <string> doc_list {"Dr.Ahuja","Dr.Singh","Dr.Patel",
                            "Dr.Khan", "Dr.Saxena","Dr.Nagraj",
                            "Dr.Gulati"};
    int doc_num = 6;
    int week ;
    
    protected:  
    
    void get_doc(){
        for(int i = 0; i < doc_list.size(); i++){
            try{
                if(week == i%7){
                    cout<<doc_list[i]<<"  "<<doc_list[i+1]<<endl;
                }
            }
            catch (out_of_range& e){
                cout<<" "<<endl;
            }
                
        }
    }

    void get_doc(int var){
        for(int i = 0; i < doc_list.size(); i++){
            try{
                if(var == i%7){
                    cout<<doc_list[i]<<" "<<doc_list[i+1]<<endl;
                }
            }
            catch (out_of_range& e){
                cout<<" "<<endl;
            }
                
        }
    }

    void doc_today(){
        
        srand(2);
        week = rand() % 7;

        get_weekday(week);
        get_doc(week);

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
        for(int var = 0; var < 7; var++){
            get_weekday(var);
            get_doc(var);
            cout<<"\n";
        }
    }
    void add_doc(string doc, int selec){
        doc_list.push_back(doc);
        doc_num++;

        switch(selec){
            case 1: p->doc_ID.push_back(doc_num);break;
            case 2: c->doc_ID.push_back(doc_num);break;
            case 3: u->doc_ID.push_back(doc_num);break;
            case 4: dm->doc_ID.push_back(doc_num);break;
            case 5: o->doc_ID.push_back(doc_num);break;
            case 6: dn->doc_ID.push_back(doc_num);break;
            case 7: n->doc_ID.push_back(doc_num);break;
            default: cout<<"Invalid input...\nTRY AGAIN!!!!"<<endl;
        }
    }
    void add_doc(void){
        string doc;
        int selec;
        cout<<"What is the name of Doctor?";
        cin>>doc;

        doc_list.push_back(doc);
        doc_num++;

        cout<<"What Department he specializes in ?"<<endl<<department_selec;
        cin>>selec;
        switch(selec){
            case 1: p->doc_ID.push_back(doc_num); return; break;
            case 2: c->doc_ID.push_back(doc_num); return; break;
            case 3: u->doc_ID.push_back(doc_num); return; break;
            case 4: dm->doc_ID.push_back(doc_num); return; break;
            case 5: o->doc_ID.push_back(doc_num); return; break;
            case 6: dn->doc_ID.push_back(doc_num); return; break;
            case 7: n->doc_ID.push_back(doc_num); return; break;
            default: cout<<"Invalid input...\nTRY AGAIN!!!!"<<endl;
        }
        // cout<<;
    }
    
};

class Reception: public Doctors, public Bed, protected Medicine{    
    
    string name;
    int age;
    // char choice = 'X';
    int key = 6969;
    char CorH;
    
    protected:

    char ask_position(){

        char choice;
        int var = 0;

        cout<<"Are you Customer(Press C) or Hospital Management(Press H)? ";
        cin>>choice;

        while (var == 0){
            

            // if(toupper(choice) != 'C' || toupper(choice) != 'H'){
            //     cout<<"Wrong Input\nTry Again!\n"<<endl;
            // }

            // return choice;
            switch(toupper(choice)){
                case 'C': cout<<"Thanks for visiting us :)"<<endl;CorH = 'C';user_op();var = 1; return choice; break;
                case 'H': cout<<"Thanks for your hardwork :)"<<endl;CorH = 'H';managment_check();var = 2; return choice; break;
                default: cout<<"Wrong Input\nTry Again!\n"<<endl;
                         cout<<"Are you Customer(Press C) or Hospital Management(Press H)";
                         cin>>choice;            
            }
        }
    }

    void greet(){
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        tt = localtime(&t);

        if(tt->tm_hour < 12 && tt->tm_hour >= 5)
            cout<<"Good Morning!!!\nHow may I help you?"<<endl;
        else if(tt->tm_hour <= 24 && tt->tm_hour >= 17)
            cout<<"Good Evening!!!\nHow may I help you?"<<endl;
        else if(tt->tm_hour < 17 && tt->tm_hour >= 12)
            cout<<"Good Afteroon!!!\nHow may I help you?"<<endl;
        else cout<<"Good Evening!!!\nHow may I help you?"<<endl;
    }

    // void greet(){
    //     time_t t; // t passed as argument in function time()
    //     struct tm * tt; // decalring variable for localtime()
    //     time (&t); //passing argument to time()
    //     tt = localtime(&t);
    //     cout<<"HEY!!!!!"<<endl<<tt->tm_hour<<endl;
    // }
    void manage_op(void){
        int ch;
        cout<<manage_options;
        cin>>ch;

        switch(ch){
            case 1: add_doc();manage_op();break;
            case 2: add_med();manage_op();break;
            case 3: doc_today();manage_op();break;
            case 4: bed_status(CorH);manage_op();break;
            case 5: cout<<"Okay your attendance for today has been marked"<<endl;
                    manage_op();break;
            case 6: ask_position(); break;
            case 7: exit_sys();break;
            default : cout<<"Wrong input\nTry Again Please!!"<<endl;manage_op();
        }
    }

    void user_op(void){
        int ch;
        cout<<user_options;
        cin>>ch;

        switch(ch){
            case 1: check_bed(CorH);user_op();break;
            case 2: add_med();user_op();break;
            case 3: doc_today();user_op();break;
            case 4: bed_status(CorH);user_op();break;
            case 5: exit_sys();break;
            default : cout<<"Wrong input\nTry Again Please!!"<<endl;user_op();
        }        
    }

    void managment_check(){
        int pass;
        cout<<"Enter PIN: ";
        cin>>pass;

        if(pass == key){
            manage_op();
        }
        else{
            char yes;
            cout<<"Wrong PIN\nWant to try again (Yes - Y) ?";
            cin>>yes;
            if(toupper(yes) == 'Y'){
                managment_check();
            }
            else {
                exit_sys();
            }
        }
    }


    string user_options = "* * * * * * * * * * * * * * * * * * *\n"
                          "Press 1 - For Patient Admit Details\n"
                          "Press 2 - For Medicine Details\n"
                          "Press 3 - For Doctor Appointment\n"
                          "Press 4 - Diagnose an issue\n"
                          "Press 5 - Exit...\n"
                          "* * * * * * * * * * * * * * * * * * *\n";

    string manage_options = "* * * * * * * * * * * * * * * * * * *\n"
                            "Press 1 - For Registering New Doctor\n"
                            "Press 2 - For Registering New Medicines\n"
                            "Press 3 - Get List of Doctors Available Today\n"
                            "Press 4 - Information on Beds available\n"
                            "Press 5 - Punch the employee attendance\n"
                            "Press 6 - Go back to previous panel\n"
                            "Press 7 - Exit...\n"
                            "* * * * * * * * * * * * * * * * * * *\n";
    
    public:
    Reception(){

        greet();
        CorH = ask_position();

    //     if(toupper() == 'C'){
    //         user();
    //     }
    //     else if(toupper(ask_position()) == 'H')
    //         managment_check();

    }


    // friend class Doctors;    
};



// class Department{
//     public:
//     Department(){
//         // departmentInfo Path("Pathology", 2, 0), Cardio("Cardiology", 4, 1);
//         // departmentInfo Uro("Urology", 0, 2), Med("Medicine", 3), Opt("Optics", 1, 3);
//         // departmentInfo Dent("Dentistry", 6, 4), Neu("Neurology", 5, 5);
//     }

    
// };




int main() {
    // Doctors db;
    // db.list_doc();

    Reception R;


    return 0;
}
