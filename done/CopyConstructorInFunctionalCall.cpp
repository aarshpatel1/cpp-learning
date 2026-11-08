#include <iostream>
#include <string>

class Box{
     int length;

    public:
    Box( int length){
        this->length = length;
        std::cout << "Constructor called\n";
    }

    Box(const Box &box){
        length = box.length;
        std::cout << "Copy Constructor called\n";
    }

    void display(){
        std::cout << "Length = " << length << std::endl;
    }

    ~Box(){
        std::cout << "Destructor called\n";
    }
};

void show(Box box){
    box.display();
}

int main() {

    int length;
    std::cin >> length;

    Box box(length);
    show(box);
    
    return 0;
}