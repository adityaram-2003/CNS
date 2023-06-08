

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        int portNumber = 12345;
        ServerSocket serverSocket = new ServerSocket(portNumber);
        System.out.println("Server listening on port " + portNumber);
        Socket clientSocket = serverSocket.accept();
        System.out.println("Connection established with " + clientSocket.getInetAddress().getHostAddress());
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        String message;
        while ((message = in.readLine()) != null) {
            System.out.println("Receieved " + message + " from client ");
            out.println("Server echoes " + message);
        }
        serverSocket.close();
    }
}
