//Playground.java
//
import java.util.*;
import java.io.*;
public class Playground {
	protected ArrayList<Pet> pets;
	protected int numPets;

	public Playground() {
		// need to load data when creating playground
		this.pets = load();
		this.numPets = pets.size();
	}

	public static void main(String[] args){
		Playground p = new Playground();
		p.playgroundMenu();
	}

	public void listPets(){
		System.out.println("Printing all "+pets.size()+" or "+numPets+" pets");
		for (int i =0; i<pets.size(); i++){
			Pet p = pets.get(i);
			System.out.println("Pet #"+(i+1)+": The "+p.species+" "+p.petName+", they are "+p.hunger.getState()+" and "+p.excitement.getState());
		}
	}

	public void playgroundMenu(){
		Scanner s = new Scanner(System.in);
		System.out.println("Welcome to the Chameleon and Mole-Rat playground!");
		// when program starts, the User has no pets and need to get one
		if(numPets == 0){
			System.out.println("It looks like you don't have either of these wonderful creatues, would you like to have one?");
			boolean keepGoing = true;
			while(keepGoing){
				System.out.print("(yes or no) :");
				String answer = s.nextLine();
				if(answer.toUpperCase().substring(0,1).equals("Y")){
					keepGoing = false;
				}else{
					System.out.println("Um, ok..?");
					save();
				}
			}
			// call newPet() 
			System.out.print("Wonderful! ");
			newPet();
			
		}
		
		// now menu can start
		System.out.println("Here are all your current pets:");
		listPets();
		System.out.print("If you want to play with one, type their number from 1-"+numPets+", or you could type 'add' to get a new pet or 'delete' to get rid of one. If you want to leave, type 'exit'\n: ");
		// try catch to see if user typed in an integer
		String answer = s.nextLine();
		int num;
		try {
			num = Integer.parseInt(answer);
		} catch (NumberFormatException e){
			num = -1;	
		}

		if(num!=-1 && num<=numPets){
			pets.get(num-1).menu();
			playgroundMenu();
		}else if(answer.toUpperCase().substring(0,1).equals("A")){
			newPet();
			playgroundMenu();
		}else if(answer.toUpperCase().substring(0,1).equals("D")){
			System.out.print("Aw, which pet number would you set free? (1-"+numPets+")\n: ");
			int delNum =-1;
			String delAnswer = s.nextLine();
			// did user type in an integer
			try{
				delNum = Integer.parseInt(delAnswer);
			} catch (NumberFormatException e){
				System.out.println("Sorry, that's not a valid number");
				
			}
			// is the integer a valid pet
			if(delNum<=numPets && delNum>0){
				freePet(delNum-1);
			}else{	
				System.out.println("Sorry, that's not a valid number");	
			}
			playgroundMenu();
		}else if(answer.toUpperCase().substring(0,1).equals("E")){
				System.out.println("Your pets wave goodbye, thanks for visiting the Playground!");
				save();
			}
	}

	public void freePet(int petIndex){
		System.out.println(pets.get(petIndex).petName+" waves goodbye, you're setting it free. Maybe you'll meet them again someday.");
		pets.remove(petIndex);
		numPets--;
	}
	public void newPet(){
		 	boolean keepGoing = true;
			Scanner s = new Scanner(System.in);
			Pet p;
			while(keepGoing){
                                System.out.print("Would you like a [Chameleon] or [Mole-Rat]?\n(type your choice) : ");
                                String answer = s.nextLine();
                                if(answer.toUpperCase().substring(0,1).equals("C")){
                                        System.out.println("You picked Chameleon, awesome!");
                                        // I want to remove the copied code but the compiler thinks p is undefined
                                        p = new Chameleon();
					p.changeName();
					pets.add(p);
                                        keepGoing = false;
                                } else if(answer.toUpperCase().substring(0,1).equals("M")){
                                        System.out.println("You picked Mole-Rat, awesome!");
                                        p = new MoleRat();
					p.changeName();
					pets.add(p);
					keepGoing = false;
                                }else{
                                        System.out.println("I didn't understand that, could you try again?");
				}
			}
			
			numPets++;
	}

	public void save(){
		try{
			BufferedWriter out = new BufferedWriter(new FileWriter("pets.dat"));
			for(int i =0; i<this.pets.size(); i++){
				out.write(pets.get(i).species+"/"+pets.get(i).toString()+"\n");
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
		System.exit(0);
	}
	public ArrayList<Pet> load(){
		ArrayList<Pet> loadingPets = new ArrayList<Pet>();
		// return an array list of pets to be the global ish var of pets for program
		// open pets.dat to get the data
		try{
			FileReader file = new FileReader("pets.dat");
			BufferedReader fileStream = new BufferedReader(file);
			String line = fileStream.readLine();
			while(line!=null){
				// System.out.println(line);
				if(line!=null){
					String[] data = line.split("/");
					// System.out.println(data[0]);
					if(data[0].equals("Chameleon")){
						Chameleon c = new Chameleon(data[1], Integer.parseInt(data[2]), Integer.parseInt(data[3]), data[4]);
						loadingPets.add(c);
					}else if(data[0].equals("Mole-Rat")){
						MoleRat m = new MoleRat(data[1], Integer.parseInt(data[2]), Integer.parseInt(data[3]), Integer.parseInt(data[4]));
						loadingPets.add(m);
					// 	System.out.println("I added "+m.toString());
					}
				}
				line = fileStream.readLine();
			
			}
			// done with file, close it
			fileStream.close();
		}
		catch(FileNotFoundException e){
			System.out.println("No pets.dat file found");
		}
		catch(IOException e){
			System.out.println("Problem reading 'pets.dat'\n"+e);
		}
		return loadingPets;	
	}
}
