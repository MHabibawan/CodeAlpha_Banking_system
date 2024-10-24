#include <iostream>
#include <string>
#include <vector>

class Customer {
private:
    std::string customer_name, customer_ID, address, phone_number;

public:
    Customer(std::string customer_name, std::string customer_ID, std::string phone_number)
        : customer_name(customer_name), customer_ID(customer_ID), phone_number(phone_number) {}

    void displayInfo() {
        std::cout << "Account holder name: " << customer_name << std::endl;
        std::cout << "Account holder ID: " << customer_ID << std::endl;
        std::cout << "Account holder Phone Number: " << phone_number << std::endl;
    }

    std::string getCustomerID() const {
        return customer_ID;
    }
};

class Account {
private:
    double balance;
    std::string account_number, account_title;

public:
    Account(std::string account_number, std::string account_title)
        : balance(0.0), account_number(account_number), account_title(account_title) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: " << amount << ", New Balance: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrew: " << amount << ", New Balance: " << balance << std::endl;
        }
    }

    void displayAccountInfo() {
        std::cout << "Account Title: " << account_title << std::endl;
        std::cout << "Account Number: " << account_number << std::endl;
        std::cout << "Current Balance: " << balance << std::endl;
    }
};

class Transaction {
private:
    double amount;
    int transaction_ID;
    std::string transaction_type;

public:
    Transaction(double amount, int transaction_ID, std::string transaction_type)
        : amount(amount), transaction_ID(transaction_ID), transaction_type(transaction_type) {}

    void displayTransactionInfo() {
        std::cout << "Transaction ID: " << transaction_ID << std::endl;
        std::cout << "Transaction Amount: " << amount << std::endl;
        std::cout << "Transaction Type: " << transaction_type << std::endl;
    }
};

class Banking {
private:
    std::vector<Customer> customers;
    std::vector<Account> accounts;

public:
    void addCustomer(const Customer &customer) {
        customers.push_back(customer);
    }

    void createAccount(const std::string &account_number, const std::string &account_title) {
        accounts.push_back(Account(account_number, account_title)); // Use push_back instead of emplace_back
        std::cout << "Account created: " << account_number << " (" << account_title << ")" << std::endl;
    }

    void displayCustomerAccounts() {
        for (std::size_t i = 0; i < accounts.size(); ++i) { // Traditional for loop for compatibility
            accounts[i].displayAccountInfo();
        }
    }
};

int main() {
    Banking bank;

    // Create a customer
    Customer C1("Habib ur Rehman", "AB220423", "+92-344-4188994");
    bank.addCustomer(C1);

    // Create an account for that customer
    bank.createAccount("ACC001", "Current");

    // Display customer info
    C1.displayInfo();

    // Display account info
    bank.displayCustomerAccounts();

    return 0;
}
