/*
b)  Define a class CricketPlayer (name,no_of_innings,no_of_times_notout, totatruns, 
    bat_avg). Create an array of n player objects .Calculate the batting average for each 
    player using static method avg(). Define a static sort method which sorts the array on 
    the basis of average. Display the player details in sorted order.
*/

//Using Static Methods, Print formatting and User defined error handling

import java.util.Scanner;
class InvalidCricketDataException extends Exception{
    public InvalidCricketDataException(String message){
        super(message);
    }
}

class CricketPlayer{
    String name;
    int no_of_innings;
    int no_of_times_notout;
    int total_runs;
    double bat_avg;

    CricketPlayer(String name, int innings, int notout, int runs) throws InvalidCricketDataException{
        if (innings < 0 || notout < 0 || runs < 0) {
            throw new InvalidCricketDataException("Values cannot be negative.");
        }
        if (notout > innings) {
            throw new InvalidCricketDataException("Times not out cannot exceed number of innings.");
        }

        this.name = name;
        this.no_of_innings = innings;
        this.no_of_times_notout = notout;
        this.total_runs = runs;
        this.bat_avg = avg(this);
    }

    static double avg(CricketPlayer p){
        int timesOut = p.no_of_innings - p.no_of_times_notout;
        if (timesOut == 0)
            return p.total_runs; // if never out
        return (double) p.total_runs / timesOut;
    }

    static void sort(CricketPlayer[] players){
        for (int i = 0; i < players.length - 1; i++){
            for (int j = i + 1; j < players.length; j++) {
                if (players[j].bat_avg > players[i].bat_avg){
                    CricketPlayer temp = players[i];
                    players[i] = players[j];
                    players[j] = temp;
                }
            }
        }
    }

    void display(){
        System.out.printf("%-15s %-10d %-10d %-10d %-10.2f\n",
                name, no_of_innings, no_of_times_notout, total_runs, bat_avg);
    }
}

public class CricketPlayerAdv{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of players: ");
        int n = sc.nextInt();
        sc.nextLine();

        CricketPlayer[] players = new CricketPlayer[n];
        int count = 0;

        for (int i = 0; i < n; i++){
            try {
                System.out.println("\nEnter details for Player " + (i + 1));
                System.out.print("Name: ");
                String name = sc.nextLine();

                System.out.print("Number of innings: ");
                int innings = sc.nextInt();
                System.out.print("Number of times not out: ");
                int notout = sc.nextInt();
                System.out.print("Total runs: ");
                int runs = sc.nextInt();
                sc.nextLine();

                //Create player object (may throw exception)
                players[count] = new CricketPlayer(name, innings, notout, runs);
                count++;

            }catch (InvalidCricketDataException e){
                System.out.println("Error: " + e.getMessage());
                System.out.println("Please re-enter valid details for this player.");
                sc.nextLine(); // clear scanner buffer
                i--; // retry the same player index
            }
        }

        CricketPlayer.sort(players);

        System.out.println("\nPlayer Details (Sorted by Batting Average):");
        System.out.printf("%-15s %-10s %-10s %-10s %-10s\n",
                "Name", "Innings", "NotOut", "Runs", "Average");
        System.out.println("-------------------------------------------------------------");

        for (CricketPlayer p : players){
            p.display();
        }
    }
}
