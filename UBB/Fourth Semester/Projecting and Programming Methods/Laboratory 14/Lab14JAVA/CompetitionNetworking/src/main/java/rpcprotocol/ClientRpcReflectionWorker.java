package rpcprotocol;

import competition.model.*;
import competition.services.INotificationService;
import competition.services.ServerInterface;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.Socket;


public class ClientRpcReflectionWorker implements Runnable, INotificationService {
    private static Response okResponse = new Response.Builder().type(ResponseType.OK).build();
    private ServerInterface server;
    private Socket connection;
    private ObjectInputStream input;
    private ObjectOutputStream output;
    private volatile boolean connected;

    public ClientRpcReflectionWorker(ServerInterface server, Socket connection) {
        this.server = server;
        this.connection = connection;
        try {
            output = new ObjectOutputStream(connection.getOutputStream());
            output.flush();
            input = new ObjectInputStream(connection.getInputStream());
            connected = true;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        while (connected) {
            try {
                Object request = input.readObject();
                Response response = handleRequest((Request) request);
                if (response != null) {
                    sendResponse(response);
                }
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        try {
            input.close();
            output.close();
            connection.close();
        } catch (IOException e) {
            System.out.println("Error " + e);
        }
    }

    //  private static Response errorResponse=new Response.Builder().type(ResponseType.ERROR).build();
    private Response handleRequest(Request request) {
        Response response = null;
        String handlerName = "handle" + (request).type();
        System.out.println("HandlerName " + handlerName);
        try {
            Method method = this.getClass().getDeclaredMethod(handlerName, Request.class);
            response = (Response) method.invoke(this, request);
            System.out.println("Method " + handlerName + " invoked");
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

        return response;
    }

    private Response handleLOGIN(Request request) {
        System.out.println("Login request ..." + request.type());
        String[] userdata = (String[]) request.data();
        try {
            User user= server.login(userdata[0],userdata[1], this);
            return new Response.Builder().type(ResponseType.OK).data(user).build();
        } catch (Exception e) {
            connected = false;
            return new Response.Builder().type(ResponseType.ERROR).data(e.getMessage()).build();
        }
    }

    private Response handleLOGOUT(Request request) {
        System.out.println("Logout request...");
        User user = (User) request.data();
        try {
            server.logout(user, this);
            connected = false;
            return okResponse;

        } catch (Exception e) {
            return new Response.Builder().type(ResponseType.ERROR).data(e.getMessage()).build();
        }
    }

    private Response handleGET_NR_CHILDREN_ROUND(Request request) {
        System.out.println("GetNrChildrenRound Request ...");
        String roundName = (String) request.data();
        try {
            long nr = server.getNrChildrenForRound(roundName);
            return new Response.Builder().type(ResponseType.GET_NR_CHILDREN_ROUND).data(nr).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleGET_ALL_ROUNDS(Request request){
        System.out.println("GetAllRounds ...");
        try{
           Iterable<Round> rounds=server.findAllRounds();
            return new Response.Builder().type(ResponseType.GET_ALL_ROUNDS).data(rounds).build();
        }catch (Exception ae){
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleFIND_EN_BY_CHILD_ROUND(Request request) {
        System.out.println("FinnEnByChildRound Request ...");
        String[] objs=(String[])request.data();
        String firstname=(String)objs[0];
        String lastname=(String)objs[1];
        String roundName=(String)objs[2];
        try {
            Enrollment enrollment = server.FindEnrollmentByChildAndRound(firstname,lastname,roundName);
            return new Response.Builder().type(ResponseType.FIND_EN_BY_CHILD_ROUND).data(enrollment).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleSAVE_CHILD(Request request) {
        System.out.println("SaveChild Request ...");
        String[] objs=(String[])request.data();
        String firstname=(String)objs[0];
        String lastname=(String)objs[1];
        int age=Integer.parseInt(objs[2]);
        try {
            Child child = server.SaveChild(firstname,lastname,age);
            return new Response.Builder().type(ResponseType.SAVE_CHILD).data(child).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleGET_CHILDREN_FOR_ROUND(Request request) {
        System.out.println("GetChildrenForRound Request ...");
        String roundName=(String)request.data();
        try {
            Iterable<Child> children= server.findChildrenForRound(roundName);
            return new Response.Builder().type(ResponseType.GET_CHILDREN_FOR_ROUND).data(children).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleGET_CHILD_BY_NAME(Request request) {
        System.out.println("GetChildByName Request ...");
        String[] str=(String[])request.data();
        try {
            Child child = server.FindChildByName(str[0],str[1]);
            return new Response.Builder().type(ResponseType.GET_CHILD_BY_NAME).data(child).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleGET_CHILDREN_BY_AGEGROUP(Request request) {
        System.out.println("GetChildrenByAgeGroup Request ...");
        String ageGroup=(String)request.data();
        try {
            Iterable<Child> children = server.FindChildrenByAgeGroup(ageGroup);
            return new Response.Builder().type(ResponseType.GET_CHILDREN_BY_AGEGROUP).data(children).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleSAVE_ENROLLMENT(Request request) {
        System.out.println("SaveEnrollment Request ...");
        String[] str=(String[])request.data();
        String firstname= str[0];
        String lastname = str[1];
        int age = Integer.parseInt(str[2]);
        String roundName = str[3];
        try {
            Enrollment enrollment = server.SaveEnrollment(firstname,lastname,age,roundName);
            return new Response.Builder().type(ResponseType.SAVE_ENROLLMENT).data(enrollment).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleGET_NR_EN_FOR_CHILD(Request request) {
        System.out.println("GetNREnForChild Request ...");
        String[] str=(String[])request.data();
        try {
            long nr = server.FindNumberOfEnrollmentsForChild(str[0],str[1]);
            return new Response.Builder().type(ResponseType.GET_NR_EN_FOR_CHILD).data(nr).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private void sendResponse(Response response) {
        try {
            System.out.println("sending response " + response);
            synchronized (output) {
                output.writeObject(response);
                output.flush();
            }
        }catch(IOException e){
            System.out.println("Exception at sending response!");
        }
    }


    @Override
    public void addedEnrollment(Enrollment enrollment) throws Exception {
        Response resp=new Response.Builder().type(ResponseType.ADDED_ENROLLMENT).data(enrollment).build();
        System.out.println("Enrollment received "+enrollment);
        try {
            sendResponse(resp);
        } catch (Exception e) {
            throw new Exception("Sending error: "+e);
        }
    }

    @Override
    public void userLoggedIn(User user) {
        Response resp=new Response.Builder().type(ResponseType.USER_LOGGED_IN).data(user).build();
        System.out.println("User logged in "+user);
        try {
            sendResponse(resp);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

