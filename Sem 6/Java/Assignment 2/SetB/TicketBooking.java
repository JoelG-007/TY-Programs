class TicketCounter{
    private int tickets = 50;

    public synchronized void bookTicket(String name, int count){
        tickets = tickets - count;
        if(tickets >= 0){
            System.out.println(name + " booked " + count + " ticket");
            System.out.println(tickets + " tickets remaining...\n");
        } else{
            System.out.println(name + " - No tickets available");
        }
    }
}

class BookingThread extends Thread{
    TicketCounter counter;
    int count;

    BookingThread(TicketCounter c, String name, int count){
        counter = c;
        setName(name);
        this.count = count;
    }

    public void run(){
        counter.bookTicket(getName(), count);
    }
}

public class TicketBooking{
    public static void main(String[] args){
        TicketCounter counter = new TicketCounter();

        new BookingThread(counter, "User-1", 5).start();
        new BookingThread(counter, "User-2", 6).start();
        new BookingThread(counter, "User-3", 1).start();
        new BookingThread(counter, "User-4", 12).start();
    }
}
