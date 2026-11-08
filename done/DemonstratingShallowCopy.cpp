#include <iostream>

class Array{
    int *value;

    public:
    Array(int value){
        this->value = new int(value);
        std::cout << "Original value: " << value << std::endl ;
    }

    Array(const Array &array){
        value = array.value;
        std::cout << "Copied value: " << *value << std::endl;
    }
    
    void updateValue(int updated_value) {
        *value = updated_value;
    }

    int display(){
        return *value;
    }
};

int main() {

    int value;
    std::cin >> value;
    
    int update_value;
    std::cin >> update_value;

    Array array1(value);
    Array array2 = array1;
    array2.updateValue(update_value);

    std::cout << "\nAfter modifying copied object:\n";

    std::cout << "Original value: " << array1.display() << std::endl;
    std::cout << "Copied value: " << array2.display() ;

    return 0;
}