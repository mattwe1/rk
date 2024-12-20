#include <iostream>
#include <string>
using namespace std;

// Класс для базового банковского счета
class BankAccount {
protected:
    int accountNumber;
    string ownerName;
    double balance;

public:
    // Конструктор
    BankAccount(int number, string name, double initialBalance) {
        accountNumber = number;
        ownerName = name;
        balance = initialBalance;
    }

    // Метод для пополнения счета
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение на сумму " << amount << " успешно. Новый баланс: " << balance << endl;
        } else {
            cout << "Сумма пополнения должна быть положительной!" << endl;
        }
    }

    // Метод для снятия средств
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие на сумму " << amount << " успешно. Новый баланс: " << balance << endl;
        } else {
            cout << "Ошибка: недостаточно средств или неверная сумма!" << endl;
        }
    }

    // Метод для вывода информации о счете
    void printAccountDetails() {
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << endl;
    }
};

// Производный класс для сберегательного счета
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Конструктор с дополнительным параметром процентной ставки
    SavingsAccount(int number, string name, double initialBalance, double rate)
        : BankAccount(number, name, initialBalance) {
        interestRate = rate;
    }

    // Метод для начисления процентов
    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Проценты на сумму " << interest << " начислены. Новый баланс: " << balance << endl;
    }
};

int main() {
    // Создание объектов
    BankAccount account1(12345, "Alice", 5000);
    SavingsAccount savings1(67890, "Bob", 10000, 5); // 5% процентная ставка

    // Операции с обычным счетом
    cout << "\nОперации с обычным счетом:\n";
    account1.printAccountDetails();
    account1.deposit(2000);
    account1.withdraw(1000);
    account1.printAccountDetails();

    // Операции с сберегательным счетом
    cout << "\nОперации с сберегательным счетом:\n";
    savings1.printAccountDetails();
    savings1.deposit(3000);
    savings1.withdraw(2000);
    savings1.addInterest();
    savings1.printAccountDetails();

    return 0;
}
