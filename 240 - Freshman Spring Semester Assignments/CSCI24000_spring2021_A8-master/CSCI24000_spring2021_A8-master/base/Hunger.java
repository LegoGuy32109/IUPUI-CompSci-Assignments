//Hunger.java

public class Hunger extends Attribute {

	public Hunger(){
		this.numStates = 4;
		String[] states = {"starving", "satisfied", "stuffed", "obese"};
		this.states = states;
		this.currState = 1;
	}

	public Hunger(int currState){
		this.numStates = 4;
		String[] states = {"starving", "satisfied", "stuffed", "obese"};
		this.states = states;
		this.currState = currState;
	}

	public void feed(String foodName){
		if(currState < numStates -1){
			System.out.println("Your pet eats "+foodName);
			raiseState();
		}else{
			System.out.println("Your pet is bursting at the seams! It can't eat " +foodName+"!");
		}
	}

	public static void main(String[] args){
		Hunger h = new Hunger();
		h.feed("Deez nuts");
		h.raiseState();
		h.raiseState();
		h.feed("poop");
		System.out.println(h.getState());
	}

}
