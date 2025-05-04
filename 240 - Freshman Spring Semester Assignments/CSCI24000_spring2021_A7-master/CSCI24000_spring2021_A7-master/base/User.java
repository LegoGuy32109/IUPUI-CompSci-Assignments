// User.java

public class User{
	protected int accountNumber;
	protected int pin;
	protected Account a;
	protected SavingsAccount s;

	public User(){
		this.accountNumber = 10000;
		this.pin = 00000;
		this.a = new Account();
		this.s = new SavingsAccount();
	}

	public User(int accountNumber, int pin, double accountBalance, double savingsBalance, double savingsInterest){
		this.accountNumber = accountNumber;
		this.pin = pin;
		this.a = new Account(accountBalance);
		this.s = new SavingsAccount(accountBalance, savingsInterest);	
	}

	public User(int accountNumber, int pin){
		this.accountNumber = accountNumber;
                this.pin = pin;
		this.a = new Account();
		this.s = new SavingsAccount();
	}

	public String toString(){
		return accountNumber + "," + pin + "," + a.balance + "," + s.balance + "," + s.interestRate;
	}
}
