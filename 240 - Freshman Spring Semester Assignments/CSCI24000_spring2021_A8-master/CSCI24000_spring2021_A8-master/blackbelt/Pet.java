//Pet.java
import java.util.*;
public abstract class Pet {
	protected String species;
	protected String petName;
	protected Hunger hunger;
	protected Excitement excitement;

	public static void main(String[] args){
	//	Pet p = new Pet();
	//	p.menu();
	//	Pet is abstract, can't be instantiated
	}
	
	public Pet(){
		species = "Pet";
		petName = "unNamed";
		hunger = new Hunger();
		excitement = new Excitement();
	}
	public Pet(String petName, int hungerVal, int excitementVal){
		this.species = "Pet";
		this.petName = petName;
		this.hunger = new Hunger(hungerVal);
		this.excitement = new Excitement(excitementVal);
	}
	
	public void menu(){
		Scanner s = new Scanner(System.in);
		System.out.println("What would you like to do with "+petName+" today?");
		System.out.println("1) Change their Name\n2) Feed them\n3) Play with them\n4) Take a nap\n5) Exit to Playground");
		System.out.print("Enter the number of your choice\n: ");
		int choice = s.nextInt();
		if(choice==1){
			changeName();
			menu();
		}else if(choice==2){
			feed();
			menu();
		}else if(choice==3){
			play();
			menu();
		}else if(choice==4){
			sleep();
			menu();
		}else if(choice==5){
			System.out.println(petName+" is sorry to see you go, come back soon!");
		}else{
			System.out.println("I didn't understand "+choice+", could you try again?");
			menu();
		}

	}
	public void changeName(){
		Scanner s = new Scanner(System.in);
		boolean keepGoing = true;
		while (keepGoing) {
			System.out.print("What would you like to call your pet?\n: ");
			String newName = s.nextLine();
			System.out.print("'"+newName+"', are you sure? (yes or no)\n: ");
			String answer = s.nextLine();
			if(answer.toUpperCase().substring(0,1).equals("Y")){
				this.petName = newName;
				System.out.println("Alright! "+petName+" is now the name of your pet!");
				keepGoing = false;
			}else if(answer.toUpperCase().substring(0,1).equals("N")){
				System.out.println("Ok, let's try again.");
			}else{
				System.out.println("I didn't understand '"+answer+"', would you like to try again?");
			}		
		}
	}

	public void feed(){
		Scanner s = new Scanner(System.in);
                boolean keepGoing = true;
                while (keepGoing) {
                         System.out.print("What would you like to feed your pet?\n: ");
                        String food = s.nextLine();
                        System.out.print("'"+food+"', are you sure? (yes or no)\n: ");
                        String answer = s.nextLine();
                        if(answer.toUpperCase().substring(0,1).equals("Y")){
                                this.hunger.feed(food);
                                System.out.println("You fed "+petName+" "+food+", yummy!");
                                keepGoing = false;
                        }else if(answer.toUpperCase().substring(0,1).equals("N")){
                                System.out.println("Ok, let's try again.");
                        }else{
                                System.out.println("I didn't understand '"+answer+"', would you like to try again?");
                        }
                }
	}

	public void play(){
		Scanner s = new Scanner(System.in);
                boolean keepGoing = true;
                while (keepGoing) {
                        System.out.print("What game would you like to play with your pet?\n: ");
                        String game = s.nextLine();
                        System.out.print("'"+game+"', are you sure? (yes or no)\n: ");
                        String answer = s.nextLine();
                        if(answer.toUpperCase().substring(0,1).equals("Y")){
                                this.excitement.play(game);
                                System.out.println("Alright! "+petName+" played "+game+" with you.");
                                keepGoing = false;
                        }else if(answer.toUpperCase().substring(0,1).equals("N")){
                                System.out.println("Ok, let's try again.");
                        }else{
                                System.out.println("I didn't understand '"+answer+"', would you like to try again?");
                        }
                }
	}

	public void sleep(){
		System.out.println("You take a nap with "+petName+", sweet dreams!");
		hunger.lowerState();
		excitement.lowerState();
		System.out.println("zzzzz....\nYou wake up and "+petName+" is "+hunger.getState()+" and "+excitement.getState()+".");
		
	}
	// this will be overwritten by child classes
	public String toString(){
		String output = "";
		output+=species+"\n"+petName+"|"+hunger.getStateIndex()+"|"+excitement.getStateIndex();
		return output;
	}
}
