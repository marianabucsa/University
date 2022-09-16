package rpcprotocol;

import competition.model.Bug;
import competition.model.Step;
import competition.model.User;
import competition.services.ObserverInterface;
import competition.services.ServerInterface;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.Socket;


public class ClientRpcReflectionWorker1 implements Runnable, ObserverInterface {
    private static Response okResponse = new Response.Builder().type(ResponseType.OK).build();
    private ServerInterface server;
    private Socket connection;
    private ObjectInputStream input;
    private ObjectOutputStream output;
    private volatile boolean connected;

    public ClientRpcReflectionWorker1(ServerInterface server, Socket connection) {
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
                Thread.sleep(1000);
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

    private Response handleFIND_ALL_USERS(Request request) {
        System.out.println("FindAllUsers Request ...");
        try {
            Iterable<User> users=server.findAllUsers();
            return new Response.Builder().type(ResponseType.FIND_ALL_USERS).data(users).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleFIND_ALL_BUGS(Request request) {
        System.out.println("FindAllBugs Request ...");
        try {
            Iterable<Bug> bugs=server.findAllBugs();
            return new Response.Builder().type(ResponseType.FIND_ALL_BUGS).data(bugs).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleFIND_ALL_BUGS_PROGRAMMER(Request request) {
        System.out.println("FindAllBugsProgrammer Request ...");
        String username = (String) request.data();
        try {
            Iterable<Bug> bugs=server.findAllBugsProgrammer(username);
            return new Response.Builder().type(ResponseType.FIND_ALL_BUGS_PROGRAMMER).data(bugs).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleFIND_ALL_STEPS_BUG(Request request) {
        System.out.println("FindAllStepsBug Request ...");
        Integer id = (Integer) request.data();
        try {
            Iterable<Step> steps=server.findAllStepsForBug(id);
            return new Response.Builder().type(ResponseType.FIND_ALL_STEPS_BUG).data(steps).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleREPAIR_BUG(Request request) {
        System.out.println("RepairBug Request ...");
        Bug bug = (Bug) request.data();
        try {
            server.repairBug(bug);
            return new Response.Builder().type(ResponseType.REPAIR_BUG).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleSAVE_BUG(Request request) {
        System.out.println("SaveBug Request ...");
        Bug bug = (Bug) request.data();
        try {
            server.saveBug(bug);
            return new Response.Builder().type(ResponseType.SAVE_BUG).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleSAVE_USER(Request request) {
        System.out.println("SaveUser Request ...");
        User user = (User) request.data();
        try {
            server.saveUser(user);
            return new Response.Builder().type(ResponseType.SAVE_USER).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }


    private Response handleSAVE_STEP(Request request) {
        System.out.println("SaveUser Request ...");
        Step step = (Step) request.data();
        try {
            server.saveStep(step);
            return new Response.Builder().type(ResponseType.SAVE_STEP).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleUPDATE_BUG(Request request) {
        System.out.println("UpdateBug Request ...");
        Bug bug = (Bug) request.data();
        try {
            server.updateBug(bug);
            return new Response.Builder().type(ResponseType.UPDATE_BUG).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleUPDATE_USER(Request request) {
        System.out.println("UpdateUser Request ...");
        User user = (User) request.data();
        try {
            server.updateUser(user);
            return new Response.Builder().type(ResponseType.UPDATE_USER).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleDELETE_USER(Request request) {
        System.out.println("DeleteUser Request ...");
        String username = (String) request.data();
        try {
            server.deleteUser(username);
            return new Response.Builder().type(ResponseType.DELETE_USER).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleUPDATE_STEP(Request request) {
        System.out.println("UpdateStep Request ...");
        Step step = (Step) request.data();
        try {
            server.updateStep(step);
            return new Response.Builder().type(ResponseType.UPDATE_STEP).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleDELETE_STEP(Request request) {
        System.out.println("DeleteStep Request ...");
        Integer id = (Integer) request.data();
        try {
            server.deleteStep(id);
            return new Response.Builder().type(ResponseType.DELETE_STEP).build();
        } catch (Exception ae) {
            return new Response.Builder().type(ResponseType.ERROR).data(ae.getMessage()).build();
        }
    }

    private Response handleDELETE_BUG(Request request) {
        System.out.println("DeleteBug Request ...");
        Integer id = (Integer) request.data();
        try {
            server.deleteBug(id);
            return new Response.Builder().type(ResponseType.DELETE_BUG).build();
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
    public void update() {
        sendResponse(new Response.Builder().type(ResponseType.UPDATE).build());
    }
}

