#include <iostream>

class BankAccount
{
    double account_number, balance;

public:
    BankAccount(int account_number)
    {
        this->account_number = account_number;
        // balance = 0;
    }

    int despoite(int amount)
    {
        balance += amount;
    }

    int display()
    {
        std::cout << balance;
    }
};

int main()
{
    int n;
    std::cout << "enter the n: ";
    std::cin >> n;

    return 0;
}