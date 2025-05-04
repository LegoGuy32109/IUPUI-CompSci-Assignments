//MoleRat.java
//
import java.util.*;

public class MoleRat extends Pet {
	protected Wrinkliness wrinkliness;

	public MoleRat(){
		wrinkliness = new Wrinkliness();
		this.species = "Mole-Rat";
	}

	public MoleRat(String petName, int hungerState, int playState, int wrinklinessState){
		wrinkliness = new Wrinkliness(wrinklinessState);
		this.petName = petName;
		hunger = new Hunger(hungerState);
		excitement = new Excitement(playState);
		this.species = "Mole-Rat";
	}

	public void menu(){
                Scanner s = new Scanner(System.in);
                System.out.println("What would you like to do with your Mole-Rat "+petName+" today?");
                System.out.println("1) Change their Name\n2) Feed them\n3) Play with them\n4) Take a nap\n5) Check their wrinkliness\n6) Rub it's tummy\n7) Exit to playground");
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
                        System.out.println(petName+" is looking pretty "+wrinkliness.getState());
                	menu();
		}else if(choice==6){
                        System.out.println("You rub "+petName+"'s tummy");
			Random r = new Random();
			if(r.nextBoolean()){
				wrinkliness.lowerState();
			}else{
				wrinkliness.raiseState();
			}
			System.out.println("Now they're looking kinda "+wrinkliness.getState());
			menu();                	
		}else if(choice==7){
                        System.out.println(petName+" is sorry to see you go, come back soon!");
                }else{
                        System.out.println("I didn't understand "+choice+", could you try again?");
                        menu();
                }
        }
	public String toString(){
		return petName+"/"+hunger.getStateIndex()+"/"+excitement.getStateIndex()+"/"+wrinkliness.getStateIndex();
	}
}
