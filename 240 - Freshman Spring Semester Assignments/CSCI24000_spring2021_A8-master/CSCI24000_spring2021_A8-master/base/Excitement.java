//Excitement.java
//
public class Excitement extends Attribute {

	public Excitement(){
		String[] states = {"Bored", "Fine", "Hyper"};
		this.states = states;
		this.numStates = 3;
		this.currState = 0;
	}

	public Excitement(int currState){
		this.currState = currState;
		String[] states = {"Bored", "Fine", "Hyper"};
		this.states = states;
		this.numStates = 3;
	}

	public void play(String gameName){
		if(currState < numStates -1){
			System.out.println("You play "+gameName+" with your pet.");
			raiseState();
		} else{
			System.out.println("You can't play "+gameName+" with you pet, they're too hyper!");
		}
	}
}
