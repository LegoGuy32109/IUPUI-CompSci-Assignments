//Chameleon.java
//
import java.util.*;
public class Chameleon extends Pet {
	protected String currentColor;

	public Chameleon(){
		currentColor = "green";
		species = "Chameleon";
	}

	public Chameleon(String petName, int hungerState, int playState, String currColor){
		this.petName = petName;
		hunger = new Hunger(hungerState);
		excitement = new Excitement(hungerState);
		currentColor = currColor;
		this.species = "Chameleon";
	}

	public static void main(String[] args){
		Chameleon c = new Chameleon();
		c.menu();
	}
	
	public void menu(){
		Scanner s = new Scanner(System.in);
                System.out.println("What would you like to do with your Chameleon "+petName+" today?");
                System.out.println("1) Change their Name\n2) Feed them\n3) Play with them\n4) Take a nap\n5) Have them blend in to the background\n6) Have them change color\n7) Exit to playground");
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
			System.out.println("Before your eyes, "+petName+" dissapears!\nAfter a while they come back, ");
                }else if(choice==6){
			changeColor();
		}else if(choice==7){
                        System.out.println(petName+" is sorry to see you go, come back soon!");
                }else{
                        System.out.println("I didn't understand "+choice+", could you try again?");
                        menu();
                }
	}
	public String toString(){
		
		return petName+"/"+hunger.getStateIndex()+"/"+excitement.getStateIndex()+"/"+currentColor;
	}
	public void changeColor(){
		Scanner s = new Scanner(System.in);
                boolean keepGoing = true;
                while (keepGoing) {
                        System.out.print("What color would you like you pet to turn into?\n: ");
                        String color = s.nextLine();
                        System.out.print("'"+color+"', are you sure? (yes or no)\n: ");
                        String answer = s.nextLine();
                        if(answer.toUpperCase().substring(0,1).equals("Y")){
                                System.out.println("Alright! "+petName+" just turned from "+currentColor+" to "+color+", cool!");
                                this.currentColor = color;
                                keepGoing = false;
                        }else if(answer.toUpperCase().substring(0,1).equals("N")){
                                System.out.println("Ok, let's try again.");
                        }else{
                                System.out.println("I didn't understand '"+answer+"', would you like to try again?");
                        }
                }
	}
}
