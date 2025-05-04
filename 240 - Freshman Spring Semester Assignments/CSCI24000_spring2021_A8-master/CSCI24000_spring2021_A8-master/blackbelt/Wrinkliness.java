//Wrinkliness.java
//
public class Wrinkliness extends Attribute {
	
	public Wrinkliness(){
		String[] states = {"Smooth", "Grooved", "Crinkled", "Crumpled", "Crinkly", "Wrinkled"};
		this.states = states;
		this.numStates = 6;
		this.currState = 2;
	}
	public Wrinkliness(int currState){
		
		String[] states = {"Smooth", "Grooved", "Crinkled", "Crumpled", "Crinkly", "Wrinkled"};
		this.states = states;
		this.numStates = 6;
		this.currState = currState;
	}

}
