/*
 * RecordingCategory.java
 * 
 * A data structure to represent a category of music, and has the ability to
 * contain references of other RecordingCategories as sub categories of itself
 */

package midterm;

import java.util.Vector; // To add vectors for dynamic list storage

public class RecordingCategory {
    // label of the genre/category of music
    public String label;

    // A dynamic list of recordings/songs within the category
    public Vector<Recording> recordings;

    // A dynamic list of other RecordingCateogries steming from this one
    public Vector<RecordingCategory> subCategories;

    // Default construction of a RecordingCategory with place holder values
    public RecordingCategory() {
        this.label = "untitled";
        this.recordings = new Vector<Recording>();
        this.subCategories = new Vector<RecordingCategory>();
    }

    // Parameterized construction with a value for the categories' label
    public RecordingCategory(String label) {
        this.label = label;
        this.recordings = new Vector<Recording>();
        this.subCategories = new Vector<RecordingCategory>();
    }
}
