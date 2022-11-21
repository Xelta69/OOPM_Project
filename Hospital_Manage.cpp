// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class Hospital{
    
};

class Formality : public Hospital{
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

int main() {
    

    return 0;
}
