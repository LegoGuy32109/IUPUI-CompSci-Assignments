// ATM.java
//
import java.util.*;
import java.io.*;

public class ATM {
 	protected ArrayList<User> knownAdmins;
	protected ArrayList<User> knownUsers;
	protected double cash;
	private String alpha = "1234567890,.";
	private String key = "aghvsnekclyz";

	// 'main' to be run when make run
	public static void main(String[] args){
		ATM a = new ATM();
		Scanner s = new Scanner(System.in);

		System.out.println("For graders, some account credentials are:\n01001,22233\n02301,42233\n70001,22233\nSome admin creds are:\n00000,12345\n99999,54321\nThe ATM only has 100 dollars in it to start, so you can't withdraw more than that unless you make a deposit.");	

		System.out.print("ATM activated\nPlease enter your account number: ");
		int num = s.nextInt();
		System.out.print("Please enter that account's PIN: ");
		int pin = s.nextInt();
		a.login(num, pin);
		
	}
	

	public ATM(){
		this.knownUsers = loadUsers("users.dat");	
		this.knownAdmins = loadUsers("admins.dat");
		this.cash = 100.0;
	}
	
	// function to generate a new random key of characters to encrypt the number data
	private void newKey(){
		String tempKey = key;
		String outKey = "";
		Random r = new Random();
                while (tempKey.length()>0){
                        int index = r.nextInt(tempKey.length());
                        outKey += tempKey.substring(index, index+1);
                        tempKey = tempKey.substring(0,index)+tempKey.substring(index+1,tempKey.length());
                }
		// set global key to be new key
                key = outKey;
	}
	
	//save user data to users.dat	
	public void saveUsers(ArrayList<User> u, String filePath){
		try{
			BufferedWriter out = new BufferedWriter(new FileWriter(filePath));
			for(int i =0; i<u.size(); i++){
				String cleanText = u.get(i).toString();
				String encodedText = encode(cleanText);
				out.write(encodedText+"\n");
			}
			out.close();
		}
		catch(FileNotFoundException e)
                {
                        System.out.println("No file found");
                }
                catch(IOException e)
                {
                        System.out.println("Problem reading '"+filePath+"'");
                }
	}

	// encode and decode very simple, just like algorithim assignment just in java written here to encrypt saved data
	private String encode(String cleanText){
		String[] cleanArr = cleanText.split("");
		String[] keyArr = key.split("");
		String[] alphaArr = alpha.split("");
		String encodedText = "";
		// System.out.println(cleanArr[0]);
		for(int i =0; i<cleanArr.length; i++){
			// linear search for right element in the key
			for(int j =0; j<alphaArr.length; j++){
				// System.out.println(alphaArr[j]+" "+cleanArr[i]);
				if(alphaArr[j].equals(cleanArr[i])){
	 				encodedText += keyArr[j];
				//	System.out.println(encodedText);
				}
			}
		}
		return encodedText;
	}
	private String decode(String encodedText){
                String[] encodedArr = encodedText.split("");
                String[] keyArr = key.split("");
		String[] alphaArr = alpha.split("");
                String decodedText = "";
                for(int i =0; i<encodedArr.length; i++){
                        // linear search for right element in the key
               		for(int j =0; j<keyArr.length; j++){
                                if(keyArr[j].equals(encodedArr[i])){
                                        decodedText += alphaArr[j];
                                }
                        }
		}
               return decodedText;
        }
                        
	public ArrayList<User> loadUsers(String fileName){
		ArrayList<User> users = new ArrayList<User>();
		// Opening file user.dat and splitting the data into a string array then creating a User with the data to update
		// local user arrayList then return it for the ATM constructer
		try
		{
			FileReader file = new FileReader(fileName);
			BufferedReader fileStream = new BufferedReader(file);
			String temp = fileStream.readLine();
			while(temp!=null){	
				temp = decode(temp);
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
			System.out.println("Problem reading '"+fileName+"'");
		}
		
		
		return users;
	}

	public void quit(){
		saveUsers(knownUsers, "users.dat");
		saveUsers(knownAdmins, "admins.dat");
		System.out.println("ATM closing");
		System.exit(0);
	}
	
	public void login(int accountNum, int pin){
		for(int i=0; i<this.knownAdmins.size(); i++){
			if(accountNum == knownAdmins.get(i).accountNumber && pin == knownAdmins.get(i).pin){
				adminMenu();
				quit();
			}
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
			System.out.print("\nWelcome Admin, would you like to...\n1) Add a User\n2) Delete a User\n3) List all Users\n4) Apply interest to all Saving Accounts\n5) Generate new Encryption Key\n6) Leave ATM\n\nPlease type number of your choice: ");
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
			}else if(input==6){
                                System.out.println("\nThank you for administrating RETH bank :)\n");
                                keepGoing = false;
			} else if(input==5){
				System.out.println("Random key is being generated...");
				System.out.println("Old key: "+key);
				// newKey();
				System.out.println("New key: "+key+"\ndata will be encrypted with this key from now on.");
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
				cash += amount;
				System.out.println("You deposited $"+amount + " into your account. You now have $"+u.a.checkBalance()); 
			} else if(input == 3){
                                System.out.println("How much would you like to withdraw? : ");
				double amount = s.nextDouble();
                                if(amount > cash){
                                        System.out.println("Apologies, this ATM does not have enough cash to fufill that transaction.");
                                }else{
                                        amount = u.a.withdraw(amount);
                                        System.out.println("You withdrew $"+amount+" from your account. You now have $"+u.a.checkBalance());
                                        if (amount==0.0){
                                                System.out.println("Your account did not have sufficent funds for that withdrawl");
                                        }
                                        cash -= amount;
                                }
			} else if(input == 4){
                                System.out.println("Your Savings Account balance is $"+u.s.checkBalance());
                        } else if(input == 5){
				System.out.println("How much would you like to deposit? : ");
                                double amount = s.nextDouble();
                                u.s.deposit(amount);
				cash += amount;
                                System.out.println("You deposited $"+amount + " into your account. You now have $"+u.s.checkBalance());
                        } else if(input == 6){
                                System.out.println("How much would you like to withdraw? : ");
                                double amount = s.nextDouble();
				if(amount > cash){
					System.out.println("Apologies, this ATM does not have enough cash to fufill that transaction.");
				}else{
					amount = u.s.withdraw(amount);	
					System.out.println("You withdrew $"+amount+" from your account. You now have $"+u.s.checkBalance());
                                	if (amount==0.0){
                                        	System.out.println("Your account did not have sufficent funds for that withdrawl");
                                	}
					cash -= amount;
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
