import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        String serverAddress = "localhost";
        int serverPort = 12345;
        Socket socket = new Socket(serverAddress, serverPort);
        System.out.println("Connected to server " + serverAddress + " with port " + serverPort);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
        String userInput;
        while ((userInput = stdIn.readLine()) != null) {
            out.println(userInput);
            System.out.println("Server response: " + in.readLine());
        }
        socket.close();
    }
}
