#include<iostream>
#include <string>

class Student{
    std::string name;
    int roll_number;

    public:
    Student (std::string name, int roll_number){
        this->name = name;
        this->roll_number = roll_number;
        std::cout << "Constructor called for Student " << roll_number << std::endl;
    }

    Student(const Student &student){
        name= student.name;
        roll_number=student.roll_number;
        std::cout << "Copy Constructor called for Student " << roll_number << std::endl;
    }

    ~Student() {
        std::cout << "Destructor called for Student "<< roll_number << std::endl;
    }
};

int main(){

    std::string name;
    std::getline(std::cin, name);
    
    int roll_number;
    std::cin >> roll_number;

    Student student1(name, roll_number);
    Student student2=student1;
    
    return 0;
}
