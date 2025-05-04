//SavingsAccount.java
public class SavingsAccount extends Account{
	
	protected double interestRate;

	public SavingsAccount(){
		this.interestRate = 0.03;
	}

	public SavingsAccount(double balance, double interestRate){
		this.balance = balance;
		this.interestRate = interestRate;
	}

	// find interest with balance(1+interestRate*period)
	public double findInterest(int months){
		// to format with rounding
		double raw = balance*(1+interestRate*months);
		return Math.round(raw*100)/100.0;
	}


}
