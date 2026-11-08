#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Payment {
  public:
    virtual void processPayment() = 0;
    virtual void paymentType() { cout << "Payment: General" << endl; }
    virtual ~Payment() { cout << "Payment destructor" << endl; }
};

class UPIPayment : public Payment {
  public:
    double amount;
    UPIPayment(double amount) { this->amount = amount; }
    void processPayment() {
        cout << "UPI Payment: " << fixed << setprecision(2) << amount << endl;
    }
    ~UPIPayment() { cout << "UPI destructor" << endl; }
};
class CardPayment : public Payment {
  public:
    double amount;
    CardPayment(double amount) { this->amount = amount; }
    void processPayment() {
        cout << "Card Payment: " << fixed << setprecision(2) << amount << endl;
    }
    ~CardPayment() { cout << "Card destructor" << endl; }
};
class WalletPayment : public Payment {
  public:
    double amount;
    WalletPayment(double amount) { this->amount = amount; }
    void processPayment() {
        cout << "Wallet Payment: " << fixed << setprecision(2) << amount << endl;
    }
    ~WalletPayment() { cout << "Wallet destructor" << endl; }
};

int main() {
    int n;
    cin >> n;
    vector<Payment *> arr;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        double amount;
        cin >> amount;
        if (type == 'U') {
            arr.push_back(new UPIPayment(amount));
        } else if (type == 'C') {
            arr.push_back(new CardPayment(amount));
        } else if (type == 'W') {
            arr.push_back(new WalletPayment(amount));
        }
    }

    for (Payment *p : arr) {
        p->paymentType();
        p->processPayment();
    }

    for (Payment *p : arr) {
        delete p;
    }

    return 0;
}