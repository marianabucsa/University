using CompetitionModel.domain;
using CompetitionServices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CompetitionNetworking
{
    class ClientWorker : IObserver
    {
        private IServer server;
        private TcpClient connection;

        private NetworkStream stream;
        private IFormatter formatter;
        private volatile bool connected;
        public ClientWorker(IServer server, TcpClient connection)
        {
            this.server = server;
            this.connection = connection;
            try
            {

                stream = connection.GetStream();
                formatter = new BinaryFormatter();
                connected = true;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }

        public virtual void run()
        {
            while (connected)
            {
                try
                {
                    object request = formatter.Deserialize(stream);
                    object response = HandleRequest((Request)request);
                    if (response != null)
                    {
                        SendResponse((Response)response);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }

                try
                {
                    Thread.Sleep(1000);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }
            }
            try
            {
                stream.Close();
                connection.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Error " + e);
            }
        }


        private Response HandleRequest(Request request)
        {
            Response response = null;
            if (request is LoginRequest)
            {
                Console.WriteLine("Login request ...");
                LoginRequest logReq = (LoginRequest)request;
                string username = logReq.Username;
                string password = logReq.Password;
                try
                {
                    User user;
                    lock (server)
                    {
                        user = server.login(username, password, this);
                    }
                    return new LoginResponse(user);
                }
                catch (Exception e)
                {
                    connected = false;
                    return new ErrorResponse(e.Message);
                }
            }
            if (request is LogoutRequest)
            {
                Console.WriteLine("Logout request");
                LogoutRequest logReq = (LogoutRequest)request;
                User user = logReq.User;
                try
                {
                    lock (server)
                    {

                        server.logout(user, this);
                    }
                    connected = false;
                    return new OkResponse();

                }
                catch (Exception e)
                {
                    return new ErrorResponse(e.Message);
                }
            }
            if (request is GetNrChildrenRoundRequest)
            {
                Console.WriteLine("GetNrChildrenRound request");
                GetNrChildrenRoundRequest nrReq = (GetNrChildrenRoundRequest)request;
                string roundName = nrReq.RoundName;
                try
                {
                    long nr;
                    lock (server)
                    {
                        nr = server.getNrChildrenForRound(roundName);
                    }
                    return new GetNrChildrenRoundResponse(nr);
                }
                catch (Exception err)
                {
                    return new ErrorResponse(err.Message);
                }
            }
            if (request is GetAllRoundsRequest)
            {
                Console.WriteLine("GetAllRounds Request");
                GetAllRoundsRequest req = (GetAllRoundsRequest)request;
                try
                {
                    IEnumerable<Round> rounds;
                    lock (server)
                    {
                        rounds = server.findAllRounds();
                    }
                    return new GetAllRoundsResponse(rounds);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is FindEnByChildRoundRequest)
            {
                Console.WriteLine("FindEnByChildRound Request");
                FindEnByChildRoundRequest req = (FindEnByChildRoundRequest)request;
                try
                {
                    Enrollment enrollment;
                    lock (server)
                    {
                        enrollment = server.FindEnrollmentByChildAndRound(req.Firstname, req.Lastname, req.RoundName);
                    }
                    return new FindEnByChildRoundResponse(enrollment);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is SaveChildRequest)
            {
                Console.WriteLine("SaveChild Request");
                SaveChildRequest req = (SaveChildRequest)request;
                try
                {
                    Child child;
                    lock (server)
                    {
                        child = server.SaveChild(req.Firstname, req.Lastname, req.Age);
                    }
                    return new SaveChildResponse(child);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is FindChildrenForRoundRequest)
            {
                Console.WriteLine("FindChildrenForRound Request");
                FindChildrenForRoundRequest req = (FindChildrenForRoundRequest)request;
                try
                {
                    IEnumerable<Child> children;
                    lock (server)
                    {
                        children = server.findChildrenForRound(req.RoundName);
                    }
                    return new GetChildrenForRoundResponse(children);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is FindChildByNameRequest)
            {
                Console.WriteLine("FindChildByName Request");
                FindChildByNameRequest req = (FindChildByNameRequest)request;
                try
                {
                    Child child;
                    lock (server)
                    {
                        child = server.FindChildByName(req.Firstname, req.Lastname);
                    }
                    return new GetChildByNameResponse(child);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is FindChildrenByAgeGroupRequest)
            {
                Console.WriteLine("FindChildrenByAgeGroup Request");
                FindChildrenByAgeGroupRequest req = (FindChildrenByAgeGroupRequest)request;
                try
                {
                    IEnumerable<Child> children;
                    lock (server)
                    {
                        children = server.FindChildrenByAgeGroup(req.AgeGroup);
                    }
                    return new GetChildrenByAgeGroupResponse(children);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is SaveEnrollmentRequest)
            {
                Console.WriteLine("SaveEnrollment Request");
                SaveEnrollmentRequest req = (SaveEnrollmentRequest)request;
                try
                {
                    Enrollment enrollment;
                    lock (server)
                    {
                        enrollment = server.SaveEnrollment(req.Firstname, req.Lastname, req.Age, req.RoundName);
                    }
                    return new SaveEnrollmentResponse(enrollment);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            if (request is FindNumberOfEnrollmentsForChildRequest)
            {
                Console.WriteLine("FindNumberOfEnrollmentsForChild Request");
                FindNumberOfEnrollmentsForChildRequest req = (FindNumberOfEnrollmentsForChildRequest)request;
                try
                {
                    long nr;
                    lock (server)
                    {
                        nr = server.FindNumberOfEnrollmentsForChild(req.Firstname, req.Lastname);
                    }
                    return new GetNrEnForChildResponse(nr);
                }
                catch (Exception ex)
                {
                    return new ErrorResponse(ex.Message);
                }
            }

            return response;
        }

        private void SendResponse(Response response)
        {
            Console.WriteLine("sending response " + response);
            lock (stream)
            {
                formatter.Serialize(stream, response);
                stream.Flush();
            }
        }

        public void Update()
        {
            SendResponse(new UpdateResponse());
        }
    }
}
