/*
 * ReflexiveAssociation.java
 * 
 * A test of the RecordingCategory and Recording data structures, specifically
 * proving the Reflexive Association of RecordingCateogry and it's utility
 * to produce subcategories. 
 */

package midterm;

public class ReflexiveAssociationTest {
    public static void main(String args[]){
        System.out.println("Testing relexive association of RecordingCategory");
        // Creating the Rock category and adding a few songs to it's recordings
        RecordingCategory rockCategory = new RecordingCategory("Rock");
        rockCategory.recordings.add(new Recording("Song #1", "The oneders"));
        rockCategory.recordings.add(new Recording("Another song", "The oneders"));
        rockCategory.recordings.add(new Recording("Newcomer to the group", "Beatless"));
        
        // Creating the Punk category and adding a few songs to it's recordings
        RecordingCategory punkCategory = new RecordingCategory("Punk Rock");
        punkCategory.recordings.add(new Recording("I hate you mom", "hopeless darkness"));
        punkCategory.recordings.add(new Recording("I hate you too dad", "hopeless darkness"));
        punkCategory.recordings.add(new Recording("I think society needs to WAKE UP", "kid/changers"));
        
        // Creating the Baby Punk category and adding a few songs to it's recordings
        RecordingCategory babyPunkCategory = new RecordingCategory("Baby Punk");
        babyPunkCategory.recordings.add(new Recording("I hate you mom WAHHH", "hopeless baby"));
        babyPunkCategory.recordings.add(new Recording("I hate you too dad WAAAHHHH", "hopeless baby"));
        babyPunkCategory.recordings.add(new Recording("I think I NEED A NEW DIAPER", "nappy/changers"));

        // Creating the Association Rock < Punk < Baby Punk
        rockCategory.subCategories.add(punkCategory);
        punkCategory.subCategories.add(babyPunkCategory);

        // Displaying all songs recursively 
        printSongsInCategory(rockCategory);
    }
    
    // A recursive function to display a categories' songs, and all the songs
    // within it's subCategories.
    public static void printSongsInCategory(RecordingCategory category){
        // Display the category being printed currently
        System.out.println("------- Songs in "+category.label+" -------");
        // Display songs in this category
        category.recordings.forEach((song) -> System.out.println(song.title+" - "+song.artist));
        // Iterate through subCategories and call the function again.
        category.subCategories.forEach((subCat) -> printSongsInCategory(subCat));
    }
}
