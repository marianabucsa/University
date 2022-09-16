package utils;

import competition.services.ServerInterface;
import rpcprotocol.ClientRpcReflectionWorker1;

import java.net.Socket;

public class RpcConcurrentServer extends AbstractConcurrentServer {
    private ServerInterface server;

    public RpcConcurrentServer(int port, ServerInterface server) {
        super(port);
        this.server = server;
        System.out.println("Chat- ChatRpcConcurrentServer");
    }

    @Override
    protected Thread createWorker(Socket client) {
        //ClientRpcWorker worker=new ClientRpcWorker(server, client);
        ClientRpcReflectionWorker1 worker = new ClientRpcReflectionWorker1(server, client);

        Thread tw = new Thread(worker);
        return tw;
    }
}
