/*
 * Recording.java
 * 
 * A simple data structure for a song including the title of the song, 
 * and the artist that produced it.
 */

package midterm;

public class Recording {
    // Title of the song
    public String title;

    // Artist that produced the song
    public String artist;

    // Default constructor for Recording, contians place holder values
    public Recording(){
        this.title = "untitled";
        this.artist = "unknown";
    }

    // Parameterized constructor for Recording, sets title and artist from inputs
    public Recording(String title, String artist){
        this.title = title;
        this.artist = artist;
    }
}
