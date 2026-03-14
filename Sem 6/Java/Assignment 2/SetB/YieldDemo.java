class YieldThread extends Thread{
    public void run(){
        for(int i = 1; i <= 5; i++){
            System.out.println("Child Thread: " + i);
            Thread.yield();
        }
    }
}

public class YieldDemo{
    public static void main(String[] args){
        YieldThread t = new YieldThread();
        t.start();

        for(int i = 1; i <= 5; i++)
            System.out.println("Main Thread: " + i);
    }
}
