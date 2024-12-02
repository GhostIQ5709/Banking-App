#include <iostream>
#include <string>
#include <vector>

class Account {
public:
	Account(std::string name, double balance) : name(name), balance(balance) {}
	std::string getName() { return name; }
	double getBalance() { return balance; }
	void deposit(double amount) { balance += amount; }
	void withdraw(double amount) { balance -= amount; }

private:
	std::string name;
	double balance;
};

class Bank {
public:
	void addAccount(Account account) { accounts.push_back(account); }
	Account getAccount(std::string name) {
		for (auto& account : accounts) {
			if (account.getName() == name) {
				return account;
			}
		}
		return Account("", 0.0); // Return an empty account if not found
	}

private:
	std::vector<Account> accounts;
};

int main() {
	Bank bank;
	bank.addAccount(Account("John Doe", 1000.0));
	bank.addAccount(Account("Jane Doe", 500.0));

Account account = bank.getAccount("John Doe");
	std::cout << "Account Name: " << account.getName() << std::endl;
	std::cout << "Account Balance: " << account.getBalance() << std::endl;

	account.deposit(500.0);
	std::cout << "New Balance: " << account.getBalance() << std::endl;

	account.withdraw(200.0);
	std::cout << "New Balance: " << account.getBalance() << std::endl;

	return 0;
}
