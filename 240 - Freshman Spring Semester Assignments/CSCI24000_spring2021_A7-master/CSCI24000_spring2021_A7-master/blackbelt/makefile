ATM.class: ATM.java Account.class SavingsAccount.class User.class
	javac -g ATM.java

Account.class: Account.java
	javac -g Account.java

SavingsAccount.class: SavingsAccount.java
	javac -g SavingsAccount.java

User.class: User.java
	javac -g User.java

clean:
	rm *.class

run: ATM.class
	java ATM

debug: ATM.class
	jdb ATM
