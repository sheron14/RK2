#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:

    BankAccount(string accNum, string owner, double initialBalance)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено: " << amount << ". Новый баланс: " << balance <<endl;
        }
        else {
            cout << "Сумма пополнения должна быть положительной." << endl;
        }
    }

   
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято: " << amount << ". Новый баланс: " << balance <<endl;
        }
        else {
           cout << "Недостаточно средств или неверная сумма." <<endl;
        }
    }   double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
  
    SavingsAccount(string accNum, string owner, double initialBalance, double rate)
        : BankAccount(accNum, owner, initialBalance), interestRate(rate) {}

    
    void applyInterest() {
        double interest = getBalance() * interestRate / 100;
        deposit(interest);
        cout << "Начислены проценты: " << interest << ". Новый баланс: " << getBalance() <<endl;
    }
};

int main() {
    BankAccount account("123456", "Alice", 1000.0);
    account.deposit(500);
    account.withdraw(200);

    SavingsAccount savings("654321", "Bob", 2000.0, 5.0);
    savings.deposit(300);
    savings.withdraw(100);
    savings.applyInterest();

    return 0;
}
