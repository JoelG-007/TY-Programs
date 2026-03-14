import java.util.Scanner;

class MessageRunnable implements Runnable{
    int n;

    MessageRunnable(int n){
        this.n = n;
    }

    public void run(){
        for(int i = 1; i <= n; i++)
            System.out.println("Message from Runnable Thread");
    }
}

public class RunnableThread{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter count: ");
        int n = sc.nextInt();
        Thread t = new Thread(new MessageRunnable(n));
        t.start();
    }
}
