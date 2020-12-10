import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class A8{
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args){
        String host;
        while (true){
            System.out.print("Host: ");
            host = scanner.nextLine();
            if(host.equalsIgnoreCase("exit()")) break;
            try{
                InetAddress address = InetAddress.getByName(host);
                System.out.println("IP Address:  "+address.getHostAddress());
                System.out.println("Domain Name: "+address.getHostName());
            } catch (UnknownHostException e){
                System.out.println(e.toString());
                System.out.println(e.getMessage());
            }
            System.out.println();
            System.out.println("Do you want to continue? (1 if YES/0 if NO)");
            int ch= scanner.nextInt();
            scanner.nextLine();
            System.out.println();
            if(ch==0){
                break;
            }
        }
    }
}