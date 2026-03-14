import java.util.Scanner;

class SleepThread extends Thread{
    int delay;

    SleepThread(int delay){
        this.delay = delay;
    }

    public void run(){
        try{
            for(int i = 1; i <= 5; i++){
                System.out.println("Child Thread: " + i);
                Thread.sleep(delay);
            }
        } catch(InterruptedException e){}
    }
}

public class SleepDemo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter delay(ms): ");
        int d = sc.nextInt();

        new SleepThread(d).start();

        for(int i = 1; i <= 5; i++)
            System.out.println("Main Thread: " + i);
    }
}
