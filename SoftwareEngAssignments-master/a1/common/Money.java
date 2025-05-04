/*
 * Money.java
 * 
 * A simple serialized wrapper class for a double, the account balance of a user.
 * By default this object when created will try to read the balance data from a local file
 * and instantiate it's 'amount' with that value. If not found, it will set to 0.0
 */

package a1.common;

import java.io.BufferedWriter; // for writing serialized data
import java.io.File; // for reading serialized data
import java.io.FileNotFoundException; // in case file doesn't exist use default value
import java.io.FileWriter; // for writing serialized data
import java.io.IOException; // in case writing to a file fails
import java.util.Scanner; // for reading serialized data

public class Money {
    // the primitive data of the amount of money in a user's account
    public double amount;

    // file path to where amount data is saved and read
    private final String filePath = "MoneyBalance.dat";

    // the default instantiantion of a Money object scans for a local file with the
    // serialized balance.
    public Money() {
        this.readFromFile();
    }

    // Write amount data to filePath for data persistance
    public void saveToFile() {
        try {
            // writer to the file for amount
            BufferedWriter writer = new BufferedWriter(new FileWriter(filePath));
            writer.write(Double.toString(this.amount));

            writer.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    // Attempt to read amount data from filePath, if FNF set amount to 0.0
    public void readFromFile() {
        try {
            // file where amount is saved
            File moneyBalance = new File(filePath);
            // reader for the amount data in the file
            Scanner fileReader = new Scanner(moneyBalance);
            while (fileReader.hasNextLine()) {
                this.amount = Double.parseDouble(fileReader.nextLine());
            }
            fileReader.close();

        } catch (FileNotFoundException e) {
            // if the file is not found, set the amount to it's default 0.0
            this.amount = 0.0;
        }
    }
}
