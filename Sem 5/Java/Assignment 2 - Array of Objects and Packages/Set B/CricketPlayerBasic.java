/*
a)  Define a class CricketPlayer (name,no_of_innings,no_of_times_notout, totatruns, 
    bat_avg). Create an array of n player objects .Calculate the batting average for each 
    player using static method avg(). Define a static sort method which sorts the array on 
    the basis of average. Display the player details in sorted order. 
*/
import java.util.Scanner;
class CricketPlayer{
    String name;
    int no_of_innings;
    int no_of_times_notout;
    int total_runs;
    double bat_avg;

    CricketPlayer(String n, int innings, int notout, int runs){
        name = n;
        no_of_innings = innings;
        no_of_times_notout = notout;
        total_runs = runs;
        bat_avg = calculateAverage();
    }

    double calculateAverage(){
        int timesOut = no_of_innings - no_of_times_notout;
        if (timesOut == 0)
            return total_runs; //if never out
        else
            return (double) total_runs / timesOut;
    }

    static void sort(CricketPlayer[] players){
        int n = players.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (players[j].bat_avg > players[i].bat_avg){
                    CricketPlayer temp = players[i];
                    players[i] = players[j];
                    players[j] = temp;
                }
            }
        }
    }

    void display(){
        System.out.println("Name: " + name);
        System.out.println("Innings: " + no_of_innings);
        System.out.println("Times Not Out: " + no_of_times_notout);
        System.out.println("Total Runs: " + total_runs);
        System.out.println("Batting Average: " + bat_avg);
        System.out.println("---------------------------------");
    }
}

public class CricketPlayerBasic{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of players: ");
        int n = sc.nextInt();
        sc.nextLine();

        CricketPlayer[] players = new CricketPlayer[n];

        for (int i = 0; i < n; i++){
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

            players[i] = new CricketPlayer(name, innings, notout, runs);
        }

        CricketPlayer.sort(players);

        System.out.println("\n--- Player Details (Sorted by Batting Average) ---");
        for (CricketPlayer p : players){
            p.display();
        }
    }
}
