class PriorityThread extends Thread{
    public PriorityThread(String name){
        setName(name);
    }

    public void run(){
        System.out.println(getName() + " Priority: " + getPriority());
        try{
            Thread.sleep(500);
        } catch(InterruptedException e){}
    }
}

public class PriorityDemo{
    public static void main(String[] args){
        PriorityThread t1 = new PriorityThread("Thread-A");
        PriorityThread t2 = new PriorityThread("Thread-B");

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);

        t1.start();
        t2.start();
    }
}
