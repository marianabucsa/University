package rpcprotocol;


import competition.model.Child;
import competition.model.Enrollment;
import competition.model.Round;
import competition.model.User;
import competition.services.ObserverInterface;
import competition.services.ServerInterface;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;


public class ServerRpcProxy implements ServerInterface {
    private String host;
    private int port;

    private ObserverInterface client;

    private ObjectInputStream input;
    private ObjectOutputStream output;
    private Socket connection;

    private BlockingQueue<Response> qresponses;
    private volatile boolean finished;

    public ServerRpcProxy(String host, int port) {
        this.host = host;
        this.port = port;
        qresponses = new LinkedBlockingQueue<Response>();
    }

    @Override
    public User login(String username, String password, ObserverInterface client) throws Exception {
        initializeConnection();
        String[] str = new String[2];
        str[0] = username;
        str[1] = password;
        Request req = new Request.Builder().type(RequestType.LOGIN).data(str).build();
        sendRequest(req);
        Response response = readResponse();
        User user = (User) response.data();
        if (response.type() == ResponseType.OK) {
            this.client = client;
            return user;
        }
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            closeConnection();
            throw new Exception(err);
        }
        return user;
    }
    @Override
    public long getNrChildrenForRound(String name) throws Exception {
        Request req = new Request.Builder().type(RequestType.GET_NR_CHILDREN_ROUND).data(name).build();
        sendRequest(req);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        long nr = (long) response.data();
        return nr;
    }

    @Override
    public Iterable<Round> findAllRounds() throws Exception {
        Request req = new Request.Builder().type(RequestType.GET_ALL_ROUNDS).build();
        sendRequest(req);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Iterable<Round> rounds = (Iterable<Round>) response.data();
        return rounds;
    }


    @Override
    public Enrollment FindEnrollmentByChildAndRound(String firstname, String lastname, String roundName) throws Exception {
        String[] objs = new String[3];
        objs[0] = firstname;
        objs[1] = lastname;
        objs[2] = roundName;
        Request request = new Request.Builder().type(RequestType.FIND_EN_BY_CHILD_ROUND).data(objs).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Enrollment enrollment= (Enrollment) response.data();
        return enrollment;
    }

    @Override
    public Child SaveChild(String firstname, String lastname, int age) throws Exception {
        String[] objs = new String[3];
        objs[0] = firstname;
        objs[1] = lastname;
        objs[2] = Integer.toString(age);
        Request request = new Request.Builder().type(RequestType.SAVE_CHILD).data(objs).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Child child = (Child) response.data();
        return child;
    }

    @Override
    public Iterable<Child> findChildrenForRound(String roundName) throws Exception {
        Request request = new Request.Builder().type(RequestType.GET_CHILDREN_FOR_ROUND).data(roundName).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Iterable<Child> children = (Iterable<Child>) response.data();
        return children;
    }
    @Override
    public Child FindChildByName(String firstname, String lastname) throws Exception {
        String[] str = new String[2];
        str[0] = firstname;
        str[1] = lastname;

        Request request = new Request.Builder().type(RequestType.GET_CHILD_BY_NAME).data(str).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Child child  = (Child) response.data();
        return child;
    }

    public void logout(User user, ObserverInterface client) throws Exception {
        Request req = new Request.Builder().type(RequestType.LOGOUT).data(user).build();
        sendRequest(req);
        Response response = readResponse();
        closeConnection();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
    }

    @Override
    public Iterable<Child> FindChildrenByAgeGroup(String ageGroup) throws Exception {
        Request request = new Request.Builder().type(RequestType.GET_CHILDREN_BY_AGEGROUP).data(ageGroup).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Iterable<Child> children= (Iterable<Child>) response.data();
        return children;
    }

    @Override
    public Enrollment SaveEnrollment(String firstname, String lastname, int age, String roundName) throws Exception {
        String[] strs = new String[4];
        strs[0] = firstname;
        strs[1] = lastname;
        strs[2] = Integer.toString(age);
        strs[3] = roundName;
        Request request = new Request.Builder().type(RequestType.SAVE_ENROLLMENT).data(strs).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        Enrollment enrollment = (Enrollment) response.data();
        return enrollment;
    }

    @Override
    public long FindNumberOfEnrollmentsForChild(String firstname, String lastname) throws Exception {
        String[] strs = new String[2];
        strs[0] = firstname;
        strs[1] = lastname;
        Request request = new Request.Builder().type(RequestType.GET_NR_EN_FOR_CHILD).data(strs).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        long  nr = (long) response.data();
        return nr;
    }

    private void closeConnection() {
        finished = true;
        try {
            input.close();
            output.close();
            connection.close();
            client = null;
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void sendRequest(Request request) throws Exception {
        try {
                output.writeObject(request);
                output.flush();
        } catch (IOException e) {
            throw new Exception("Error sending object " + e);
        }

    }

    private Response readResponse() {
        Response response = null;
        try {
            response = qresponses.take();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return response;
    }

    private void initializeConnection() {
        try {
            connection = new Socket(host, port);
            System.out.println(connection.toString());
            output = new ObjectOutputStream(connection.getOutputStream());
            output.flush();
            input = new ObjectInputStream(connection.getInputStream());
            finished = false;
            startReader();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void startReader() {
        Thread tw = new Thread(new ReaderThread());
        tw.start();
    }

    private void handleUpdate(Response response) {
        client.update();
    }


    private boolean isUpdate(Response response) {
        return response.type() == ResponseType.UPDATE;
    }

    @Override
    public void notifyObservers() {

    }

    private class ReaderThread implements Runnable {

        public void run() {
            while (!finished) {
                try {
                    Object response = input.readObject();
                    System.out.println("response received " + response);
                    if (isUpdate((Response) response)) {
                        handleUpdate((Response) response);
                    } else {
                        try {
                            qresponses.put((Response) response);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                } catch (IOException e) {
                    System.out.println("Reading error " + e);
                } catch (ClassNotFoundException e) {
                    System.out.println("Reading error " + e);
                }
            }
        }
    }
}