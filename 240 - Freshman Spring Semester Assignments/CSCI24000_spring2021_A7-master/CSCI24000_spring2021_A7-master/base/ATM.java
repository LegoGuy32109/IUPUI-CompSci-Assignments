// ATM.java
//
import java.util.*;
import java.io.*;

public class ATM {
 
	protected ArrayList<User> knownUsers;

	// 'main' to be run when make run
	public static void main(String[] args){
		ATM a = new ATM();
		Scanner s = new Scanner(System.in);

		System.out.print("ATM activated\nPlease enter your account number: ");
		int num = s.nextInt();
		System.out.print("Please enter that account's PIN: ");
		int pin = s.nextInt();
		a.login(num, pin);
		
	}
	

	public ATM(){
		this.knownUsers = loadUsers();
	}
	
	//save user data to users.dat	
	public void saveUsers(){
		try{
			BufferedWriter out = new BufferedWriter(new FileWriter("users.dat"));
			for(int i =0; i<this.knownUsers.size(); i++){
				out.write(this.knownUsers.get(i).toString()+"\n");
			}
			out.close();
		}
		catch(FileNotFoundException e)
                {
                        System.out.println("No file found");
                }
                catch(IOException e)
                {
                        System.out.println("Problem reading 'users.dat'");
                }
	}

	public ArrayList<User> loadUsers(){
		ArrayList<User> users = new ArrayList<User>();
		// Opening file user.dat and splitting the data into a string array then creating a User with the data to update
		// local user arrayList then return it for the ATM constructer
		try
		{
			FileReader file = new FileReader("users.dat");
			BufferedReader fileStream = new BufferedReader(file);
			String temp = fileStream.readLine();
			while(temp!=null){	
				System.out.println(temp);
				if(temp != null){
					String[] tempData = temp.split(",");	
					User tempUser = new User(Integer.parseInt(tempData[0]),Integer.parseInt(tempData[1]),Double.parseDouble(tempData[2]),Double.parseDouble(tempData[3]),Double.parseDouble(tempData[4]));		
					users.add(tempUser);
				}
				
				temp = fileStream.readLine();
			}
			fileStream.close();
		}
		catch(FileNotFoundException e)
		{
			System.out.println("No file found");
		}
		catch(IOException e)
		{	
			System.out.println("Problem reading 'users.dat'");
		}
		
		
		return users;
	}

	public void quit(){
		saveUsers();
		System.out.println("ATM closing");
		System.exit(0);
	}
	
	public void login(int accountNum, int pin){
		if(accountNum == 00000 && pin == 12345){
			adminMenu();
			quit();
		}
		for(int i=0; i<this.knownUsers.size(); i++){
			if(accountNum == knownUsers.get(i).accountNumber && pin == knownUsers.get(i).pin){
				menu(knownUsers.get(i));
				quit();
			}
		}
		System.out.println("Sorry, your Account Number or Pin does not match our database");
		quit();
	}
	
	// is called when pin and account num == admin credentials
	public void adminMenu(){
		boolean keepGoing = true;
		Scanner s = new Scanner(System.in);
		while(keepGoing){
			System.out.print("Welcome Admin, would you like to...\n1) Add a User\n2) Delete a User\n3) List all Users\n4) Apply interest to all Saving Accounts\n5) Leave ATM\n\nPlease type number of your choice: ");
			int input = s.nextInt();
			if(input==1){
				System.out.print("New User Account number: ");
				int num = s.nextInt();
				System.out.print("New User PIN: ");
				int pin = s.nextInt();
				knownUsers.add(new User(num,pin));
				System.out.println("User "+num+" was created.");
			}else if(input==2){
				System.out.print("User's Account number: ");
                                int num = s.nextInt();
                                System.out.print("User's PIN: ");
                                int pin = s.nextInt();
				boolean userFound = false;
				for(int i =0; i<knownUsers.size();i++){
					if(knownUsers.get(i).accountNumber == num && knownUsers.get(i).pin == pin){	
						userFound = true;
						if(knownUsers.get(i).a.balance <= 0.0 && knownUsers.get(i).s.balance <= 0.0){
							knownUsers.remove(i);
							System.out.println("Account "+num+" was deleted.");
						}else{
							System.out.println("Account cannot be deleted, funds are still present.");
						}
					}
				}
				if(!userFound){
					System.out.println("No user was found with those credentials.");
				}

			}else if(input==3){
				for(int i =0; i<knownUsers.size(); i++){
					User u = knownUsers.get(i);
					System.out.println("Account "+u.accountNumber+": Checking, "+u.a.balance+" Savings, "+u.s.balance+" Interest Rate "+u.s.interestRate);
				}
			}else if(input==4){
				System.out.print("Number of months to apply interest: ");
				int months = s.nextInt();
				for(int i =0; i<knownUsers.size(); i++){
					User u = knownUsers.get(i);
					u.s.balance += u.s.findInterest(months);
				}
				System.out.println("Interest was applied to every savings account for "+months+" month(s).");
			}else if(input==5){
                                System.out.println("\nThank you for administrating RETH bank :)\n");
                                keepGoing = false;
			} else {
                                System.out.println("I didn't understand "+input+", could you try again?");
                        }

		}
	}

	// basic menu for users, while loop checking input with ints for options
	public void menu(User u){
		boolean keepGoing = true;
		Scanner s = new Scanner(System.in);
		while(keepGoing){
			System.out.print("\nWelcome Account "+u.accountNumber+", would you like to...\n1) View Checking Account Balance\n2) Deposit into Checking\n3) Withdraw from Checking \n4) View Savings Account Balance\n5) Deposit into Savings\n6) Withdraw from Savings\n7) Leave ATM\n\nPlease type number of your choice: ");
			int input = s.nextInt();
			if(input == 1){
				System.out.println("Your Checking Account balance is $"+u.a.checkBalance());
			} else if(input == 2){
				System.out.println("How much would you like to deposit? : ");
				double amount = s.nextDouble();
				u.a.deposit(amount);
				System.out.println("You deposited $"+amount + " into your account. You now have $"+u.a.checkBalance()); 
			} else if(input == 3){
                                System.out.println("How much would you like to withdraw? : ");
                                double amount = u.a.withdraw(s.nextDouble());
				System.out.println("You withdrew $"+amount+" from your account. You now have $"+u.a.checkBalance());
				if (amount==0.0){
					System.out.println("Your account did not have sufficent funds for that withdrawl");
				}
				
                        } else if(input == 4){
                                System.out.println("Your Savings Account balance is $"+u.s.checkBalance());
                        } else if(input == 5){
				System.out.println("How much would you like to deposit? : ");
                                double amount = s.nextDouble();
                                u.s.deposit(amount);
                                System.out.println("You deposited $"+amount + " into your account. You now have $"+u.s.checkBalance());
                        } else if(input == 6){
                                System.out.println("How much would you like to withdraw? : ");
                                double amount = u.s.withdraw(s.nextDouble());
				System.out.println("You withdrew $"+amount+" from your account. You now have $"+u.s.checkBalance());
                                if (amount==0.0){
                                        System.out.println("Your account did not have sufficent funds for that withdrawl");
                                }

                        } else if(input == 7){
                                System.out.println("\nThank you for using RETH bank :)\n");
                                keepGoing = false;
                        }  else {
				System.out.println("I didn't understand "+input+", could you try again?");
			}
			
		}
	}
}
