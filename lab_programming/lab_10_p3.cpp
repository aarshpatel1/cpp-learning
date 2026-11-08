#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

class insufficiant_balance : public runtime_error {
  public:
    explicit insufficiant_balance(const string &message)
        : runtime_error(message) {}
};

class invalid_balance : public runtime_error {
  public:
    explicit invalid_balance(const string &message) : runtime_error(message) {}
};

class invalid_withdrawal : public runtime_error {
  public:
    explicit invalid_withdrawal(const string &message)
        : runtime_error(message) {}
};

class BankException {
  private:
    float balance = 0;

  public:
    BankException(float b) {
        if (b < 0) {
            throw invalid_balance("Error: Invalid initial balance");
        }
        balance = b;
    }
    void withdraw(float amount) {
        if (amount <= 0) {
            throw invalid_withdrawal("Error: Invalid withdrawal amount");
        } else if (amount > balance) {
            throw insufficiant_balance("Error: Insufficient balance");
        }
        balance -= amount;
        cout << "Remaining Balance: " << fixed << setprecision(2) << balance
             << endl;
    }
};

int main() {
    int initial_balance, withdrawal_amount;
    cin >> initial_balance >> withdrawal_amount;
    try {
        BankException bank_exception(initial_balance);
        bank_exception.withdraw(withdrawal_amount);
    } catch (const exception &e) {
        // cerr << e.what() << endl;
        cout << e.what() << endl;
        cout << "Transaction failed" << endl;
    }
    return 0;
}