import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class PrintJob implements Runnable{
    String employee;
    int jobId;

    PrintJob(String employee, int jobId){
        this.employee = employee;
        this.jobId = jobId;
    }

    public void run(){
        System.out.println("Printer " + Thread.currentThread().getName() +
            " printing job #" + jobId + " for " + employee);
        try{
            Thread.sleep(500);
        } catch(InterruptedException e){}
        System.out.println("Job #" + jobId + " done.");
    }
}

public class PrintPoolDemo{
    public static void main(String[] args){
        ExecutorService pool = Executors.newFixedThreadPool(3);

        String[] employees ={"Alice", "Bob", "Charlie", "Dave", "Eve", "Frank"};

        for(int i = 0; i < employees.length; i++)
            pool.submit(new PrintJob(employees[i], i + 1));

        pool.shutdown();
    }
}
