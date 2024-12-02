import java.util.ArrayList;
import java.util.List;

class Account {
	private String name;
	private double balance;

	public Account(String name, double balance) {
		this.name = name;
		this.balance = balance;
	}

	public String getName() { return name; }
	public double getBalance() { return balance; }
	public void deposit(double amount) { balance += amount; }
	public void withdraw(double amount) { balance -= amount; }
}

class Bank {
	private List<Account> accounts = new ArrayList<>();

public void addAccount(Account account) { accounts.add(account); }
	public Account getAccount(String name) {
		for (Account account : accounts) {
			if (account.getName().equals(name)) {
				return account;
			}
		}
		return new Account("", 0.0); // Return an empty account if not found
	}
}

public class Main {
	public static void main(String[] args) {
		Bank bank = new Bank();
		bank.addAccount(new Account("John Doe", 1000.0));
		bank.addAccount(new Account("Jane Doe", 500.0));

		
	}
}
