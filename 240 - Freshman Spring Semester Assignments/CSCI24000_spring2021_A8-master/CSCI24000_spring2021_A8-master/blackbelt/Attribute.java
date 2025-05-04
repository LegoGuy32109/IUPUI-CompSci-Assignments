//Attribute.java
//
public abstract class Attribute {
	protected String[] states;
	protected int numStates;
	protected int currState;

	public Attribute(){
		
	}
	public Attribute(int currState){
		this.currState = currState;
	}
	public void raiseState(){
		if(currState < numStates-1){
			currState++;
		}
	}
	public void lowerState(){
		if(currState > 0){
			currState--;
		}
	}
	public String getState(){
		return states[currState];
	}
	public int getStateIndex(){
		return currState;
	}
}
