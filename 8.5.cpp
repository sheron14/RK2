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
            cout << "���������: " << amount << ". ����� ������: " << balance <<endl;
        }
        else {
            cout << "����� ���������� ������ ���� �������������." << endl;
        }
    }

   
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "�����: " << amount << ". ����� ������: " << balance <<endl;
        }
        else {
           cout << "������������ ������� ��� �������� �����." <<endl;
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
        cout << "��������� ��������: " << interest << ". ����� ������: " << getBalance() <<endl;
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
