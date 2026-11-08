#include <iostream>

class StudentMarks
{
    int size = 0;
    int arr[100];

public:
    StudentMarks(int size)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }

    void average()
    {

        int avg = 0;
        for (int i = 0; i < size; i++)
        {
            avg += arr[i];
        }
        avg /= size;
        std::cout << "average: " << avg;
    }

    ~StudentMarks() {};
};

int main()
{
    int n;
    std::cout << "enter the size: ";
    std::cin >> n;

    StudentMarks student(n);
    student.average();

    return 0;
}