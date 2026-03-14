class EvenRunnable implements Runnable{
    public void run(){
        for(int i = 2; i <= 20; i += 2)
            System.out.println("Even: " + i);
    }
}

class OddRunnable implements Runnable{
    public void run(){
        for(int i = 1; i <= 19; i += 2)
            System.out.println("Odd: " + i);
    }
}

public class EvenOddRunnable{
    public static void main(String[] args){
        new Thread(new EvenRunnable()).start();
        new Thread(new OddRunnable()).start();
    }
}
