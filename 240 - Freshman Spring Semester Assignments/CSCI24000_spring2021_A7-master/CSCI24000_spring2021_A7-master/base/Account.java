// Account.java

public class Account {
	protected double balance;
	
	public Account(){
		this.balance = 0;
	}
	
	public Account(double balance){
		this.balance = balance;
	}

	public void deposit(double amount){
		balance += amount;
		balance=Math.round(balance*100)/100.0;
	}

	public double withdraw(double amount){
		if(amount <= balance){
			balance -= amount;
			return amount;
		}
		return 0.0;
	}

	public double checkBalance(){
		return balance;
	}

}
