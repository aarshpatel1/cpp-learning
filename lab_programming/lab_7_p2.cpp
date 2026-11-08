#include <iomanip>
#include <iostream>
using namespace std;

class Account {
  private:
    int accountNumber = 0;

  protected:
    float balance = 0;

  public:
    int getAccountNumber() { return accountNumber; }
    void setAccountNumber(int ac_number) { accountNumber = ac_number; }
};

class Savings : public Account {
  public:
    Savings(int ac_number, float initial_balance) {
        balance = initial_balance;
        setAccountNumber(ac_number);
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: Savings" << endl;
        calculate_interest();
        cout << fixed << setprecision(2);
        cout << "Final Balance: " << balance << endl;
    }
    void calculate_interest() {
        float interest = balance * 5 / 100;
        balance += interest;
    }
};

class Current : public Account {
  public:
    Current(int ac_number, float initial_balance) {
        balance = initial_balance;
        setAccountNumber(ac_number);
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: Current" << endl;
        reduce_balance();
        cout << fixed << setprecision(2);
        cout << "Final Balance: " << balance << endl;
    }
    void reduce_balance() { balance -= 500; }
};

int main() {
    int accountNumber = 67890;
    float balance = 10000;
    short accountType = 1;

    if (accountType == 1) {
        Savings savingAccount1(accountNumber, balance);
    } else if (accountType == 2) {
        Current currentAccount1(accountNumber, balance);
    } else {
        cout << "Wrong Account type..!";
    }

    return 0;
}