package com.company;

import java.io.*;
import java.net.*;
import java.net.ServerSocket;


class Server{

    enum Operations {
        ADD,
        SUBTRACT
    }

    public static void main(String[]args) throws IOException {



        final int PORT = 7000;
        ServerSocket ss = new ServerSocket(PORT);
        System.out.println("Server is running on port " + PORT);
        Socket connection = ss.accept(); //Maybe thread this?


        InputStreamReader readConnection = new InputStreamReader(connection.getInputStream());
        BufferedReader reader = new BufferedReader(readConnection);
        PrintWriter writer = new PrintWriter(connection.getOutputStream(), true);


        writer.println("You are connected to the socket server");

        String msg = reader.readLine();


        while(msg != null){
           String[] result = msg.split(" ");
           Operations op = null;
           try{
               op = Operations.valueOf(result[0].toUpperCase());
           } catch (IllegalArgumentException e){
               writer.println(e);
           }


           switch (op){
               case ADD:
                   System.out.println("add");
                   try{
                       int no1 = Integer.parseInt(result[1]);
                       int no2 = Integer.parseInt(result[2]);
                       int resultOfOperation = addNumbers(no1, no2);
                       writer.println(resultOfOperation);
                   } catch (NumberFormatException e){
                       writer.println(e);
                   }
                   break;

               case SUBTRACT:
                   System.out.println("subtract");
                   try{
                       int no1 = Integer.parseInt(result[1]);
                       int no2 = Integer.parseInt(result[2]);
                       int resultOfOperation = subtractNumbers(no1,no2);
                       writer.println(resultOfOperation);
                   } catch(NumberFormatException e){
                       writer.println(e);
                   }
                   break;

           }


           msg = reader.readLine();

        }




        connection.close();

    }

    public static int addNumbers(int no1, int no2){
        return no1+no2;
    }

    public static int subtractNumbers(int no1, int no2){
        return no1-no2;
    }

}