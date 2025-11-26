/*
c)  Accept the names of two files and copy the contents of the first to the second. 
    First file having Book name and Author name in file. Second file having the contents 
    of First file and also add the comment ‘end of file’ at the end. 
*/

import java.io.*;
public class CopyFile{
    public static void main(String[] args){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter source file name: ");
            String source = br.readLine();
            System.out.print("Enter destination file name: ");
            String dest = br.readLine();

            FileReader fr = new FileReader(source);
            BufferedReader reader = new BufferedReader(fr); //book.txt
            FileWriter fw = new FileWriter(dest);
            BufferedWriter writer = new BufferedWriter(fw); //copy.txt

            String line;
            while((line = reader.readLine()) != null){
                writer.write(line);
                writer.newLine();
            }

            writer.write("EOF");
            writer.close();
            reader.close();

            System.out.println("File copied successfully with 'EOF' added.");
        }catch (IOException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}
