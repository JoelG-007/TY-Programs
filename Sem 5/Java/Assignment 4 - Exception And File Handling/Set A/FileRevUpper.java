/*
b)  Write a program to read a text file “sample.txt” and display the contents of a file in 
    reverse order and also original contents change the case (display in upper case).
*/

import java.io.*;
public class FileRevUpper {
    public static void main(String[] args){
        try{
            FileReader fr = new FileReader("sample.txt");
            BufferedReader br = new BufferedReader(fr);

            String content = "";
            String line;
            while((line = br.readLine()) != null){
                content += line + "\n";
            }
            System.out.println("\n--- Original Content ---");
            System.out.println(content);
            
            StringBuilder sb = new StringBuilder(content);  // Display reverse
            System.out.println("\n--- Reverse Content ---");
            System.out.println(sb.reverse().toString());
            
            System.out.println("\n--- Uppercase Content ---"); // Display in uppercase
            System.out.println(content.toUpperCase());
            br.close();
            fr.close();
        }catch (IOException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}
