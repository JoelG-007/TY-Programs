class NumberDisplay extends Thread{
    public void run(){
        for(int i = 1; i <= 10; i++){
            System.out.println("Child Thread " + i + " Name -> " + Thread.currentThread().getName());
            try{
                Thread.sleep(500);
            } catch(InterruptedException e){
                System.out.println(getName() + " interrupted");
            }
        }
    }
}

public class NumberThread{
    public static void main(String[] args){
        NumberDisplay t = new NumberDisplay();
        t.setName("New Child");
        t.start();
    }
}
