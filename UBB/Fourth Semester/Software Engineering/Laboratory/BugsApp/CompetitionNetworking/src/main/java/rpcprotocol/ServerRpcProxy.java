package rpcprotocol;


import competition.model.Bug;
import competition.model.Step;
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
    public Iterable<User> findAllUsers() throws Exception {
        Request req = new Request.Builder().type(RequestType.FIND_ALL_USERS).build();
        sendRequest(req);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (Iterable<User>) response.data();
    }

    @Override
    public Iterable<Bug> findAllBugs() throws Exception {
        Request req = new Request.Builder().type(RequestType.FIND_ALL_BUGS).build();
        sendRequest(req);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (Iterable<Bug>) response.data();
    }

    @Override
    public Iterable<Bug> findAllBugsProgrammer(String username) throws Exception {
        Request req = new Request.Builder().type(RequestType.FIND_ALL_BUGS_PROGRAMMER).data(username).build();
        sendRequest(req);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (Iterable<Bug>) response.data();
    }

    @Override
    public void repairBug(Bug bug) throws Exception {
        Request request = new Request.Builder().type(RequestType.REPAIR_BUG).data(bug).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
    }

    @Override
    public Bug saveBug(Bug bug) throws Exception {
        Request request = new Request.Builder().type(RequestType.SAVE_BUG).data(bug).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (Bug) response.data();

    }

    @Override
    public User saveUser(User user) throws Exception {
        Request request = new Request.Builder().type(RequestType.SAVE_USER).data(user).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (User) response.data();

    }

    @Override
    public Step saveStep(Step step) throws Exception {
        Request request = new Request.Builder().type(RequestType.SAVE_STEP).data(step).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (Step) response.data();

    }

    @Override
    public Bug updateBug(Bug bug) throws Exception {
        Request request = new Request.Builder().type(RequestType.UPDATE_BUG).data(bug).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return null;
    }

    @Override
    public Iterable<Step> findAllStepsForBug(Integer id) throws Exception {
        Request req = new Request.Builder().type(RequestType.FIND_ALL_STEPS_BUG).data(id).build();
        sendRequest(req);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return (Iterable<Step>) response.data();
    }

    @Override
    public Bug deleteBug(Integer id) throws Exception {
        Request request = new Request.Builder().type(RequestType.DELETE_BUG).data(id).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return null;
    }

    @Override
    public User updateUser(User user) throws Exception {
        Request request = new Request.Builder().type(RequestType.UPDATE_USER).data(user).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return null;
    }

    @Override
    public User deleteUser(String username) throws Exception {
        Request request = new Request.Builder().type(RequestType.DELETE_USER).data(username).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return null;
    }

    @Override
    public Step updateStep(Step step) throws Exception {
        Request request = new Request.Builder().type(RequestType.UPDATE_STEP).data(step).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return null;
    }

    @Override
    public Step deleteStep(Integer id) throws Exception {
        Request request = new Request.Builder().type(RequestType.DELETE_STEP).data(id).build();
        sendRequest(request);
        Response response = readResponse();
        if (response.type() == ResponseType.ERROR) {
            String err = response.data().toString();
            throw new Exception(err);
        }
        return null;
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