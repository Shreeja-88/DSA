class MyThread extends Thread {

    MyThread() {
        super("My Child Thread");
        start();
    }

    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Child Thread: " + i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            System.out.println("Child thread interrupted");
        }
    }
}

public class MainThreadDemo {

    public static void main(String[] args) {

        new MyThread();

        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Main Thread: " + i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted");
        }
    }
}