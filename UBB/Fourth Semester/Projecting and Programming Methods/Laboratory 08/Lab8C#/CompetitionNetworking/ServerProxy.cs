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
    public class ServerProxy : IServer
    {
        private string host;
        private int port;

        private IObserver client;

        private NetworkStream stream;

        private IFormatter formatter;
        private TcpClient connection;

        private Queue<Response> responses;
        private volatile bool finished;
        private EventWaitHandle _waitHandle;
        public ServerProxy(string host, int port)
        {
            this.host = host;
            this.port = port;
            responses = new Queue<Response>();
        }

        public User login(string username, string password, IObserver client)
        {
            InitializeConnection();
            SendRequest(new LoginRequest(username, password));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                CloseConnection();
                throw new Exception(err.Message);
            }
            LoginResponse loginResponse = (LoginResponse)response;
            this.client = client;
            return loginResponse.User;
        }

        public void logout(User user, IObserver client)
        {
            SendRequest(new LogoutRequest(user));
            Response response = ReadResponse();
            CloseConnection();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
        }

        public long getNrChildrenForRound(string name)
        {
            SendRequest(new GetNrChildrenRoundRequest(name));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            GetNrChildrenRoundResponse nrResponse = (GetNrChildrenRoundResponse)response;
            return nrResponse.Nr;
        }

        public IEnumerable<Round> findAllRounds()
        {
            SendRequest(new GetAllRoundsRequest());
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            GetAllRoundsResponse roundsResponse = (GetAllRoundsResponse)response;
            return roundsResponse.Rounds;
        }

        public Enrollment FindEnrollmentByChildAndRound(string firstname, string lastname, string roundName)
        {
            SendRequest(new FindEnByChildRoundRequest(firstname, lastname, roundName));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            FindEnByChildRoundResponse enResponse = (FindEnByChildRoundResponse)response;
            return enResponse.Enrollment;
        }

        public Child SaveChild(string firstname, string lastname, int age)
        {
            SendRequest(new SaveChildRequest(firstname, lastname, age));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            SaveChildResponse childResponse = (SaveChildResponse)response;
            return childResponse.Child;
        }

        public IEnumerable<Child> findChildrenForRound(string roundName)
        {
            SendRequest(new FindChildrenForRoundRequest(roundName));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            GetChildrenForRoundResponse childResponse = (GetChildrenForRoundResponse)response;
            return childResponse.Children;
        }

        public Child FindChildByName(string firstname, string lastname)
        {
            SendRequest(new FindChildByNameRequest(firstname, lastname));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            GetChildByNameResponse childResponse = (GetChildByNameResponse)response;
            return childResponse.Child;

        }

        public IEnumerable<Child> FindChildrenByAgeGroup(string ageGroup)
        {
            SendRequest(new FindChildrenByAgeGroupRequest(ageGroup));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            GetChildrenByAgeGroupResponse childResponse = (GetChildrenByAgeGroupResponse)response;
            return childResponse.Children;
        }

        public Enrollment SaveEnrollment(string firstname, string lastname, int age, string roundName)
        {
            SendRequest(new SaveEnrollmentRequest(firstname, lastname, age, roundName));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            SaveEnrollmentResponse enResponse = (SaveEnrollmentResponse)response;
            return enResponse.Enrollment;
        }

        public long FindNumberOfEnrollmentsForChild(string firstname, string lastname)
        {
            SendRequest(new FindNumberOfEnrollmentsForChildRequest(firstname, lastname));
            Response response = ReadResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new Exception(err.Message);
            }
            GetNrEnForChildResponse nrResponse = (GetNrEnForChildResponse)response;
            return nrResponse.Nr;
        }

        private void CloseConnection()
        {
            finished = true;
            try
            {
                stream.Close();
                //output.close();
                connection.Close();
                _waitHandle.Close();
                client = null;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }

        }

        private void SendRequest(Request request)
        {
            try
            {
                lock (stream)
                {
                    formatter.Serialize(stream, request);
                    stream.Flush();
                }
            }
            catch (Exception e)
            {
                throw new Exception("Error sending object " + e);
            }

        }

        private Response ReadResponse()
        {
            Response response = null;
            try
            {
                _waitHandle.WaitOne();
                lock (responses)
                {
                    //Monitor.Wait(responses); 
                    response = responses.Dequeue();

                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
            return response;
        }

        private void InitializeConnection()
        {
            try
            {
                connection = new TcpClient(host, port);
                stream = connection.GetStream();
                formatter = new BinaryFormatter();
                finished = false;
                _waitHandle = new AutoResetEvent(false);
                startReader();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }

        private void startReader()
        {
            Thread tw = new Thread(run);
            tw.Start();
        }


        private void handleUpdate()
        {
            client.Update();
        }

        public virtual void run()
        {
            while (!finished)
            {
                try
                {
                    object response = formatter.Deserialize(stream);
                    Console.WriteLine("response received " + response);
                    if (response is UpdateResponse)
                    {
                        handleUpdate();
                    }
                    else
                    {
                        lock (responses)
                        {
                            responses.Enqueue((Response)response);
                        }
                        _waitHandle.Set();
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Reading error " + e);
                }

            }
        }

    }
}
