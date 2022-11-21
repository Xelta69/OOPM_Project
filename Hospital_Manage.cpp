// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
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
}

class Doctors{
    string doc_list[7] = {"Dr.Ahuja","Dr.Singh","Dr.Patel",
                            "Dr.Khan", "Dr.Saxena","Dr.Nagraj",
                            "Dr.Gulati"};
    int i = 0;
    protected:
    void id_info(){
        
    }
}

int main() {
    

    return 0;
}
