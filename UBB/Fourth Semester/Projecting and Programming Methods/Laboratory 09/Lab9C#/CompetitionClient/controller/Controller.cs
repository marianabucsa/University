using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Threading;
using Thrift.Server;
using Thrift.Transport;

namespace CompetitionClient.controller
{
    public class Controller : IObserver.Iface
    {

        public event EventHandler<UserEventArgs> UpdateEvent;
        private IServer.Iface service;
        private User user;
        private int port;
        public IList<Object> roundsNumberChildren;


        public Controller(IServer.Iface service)
        {
            this.service = service;
            roundsNumberChildren = new List<object>();
            // roundsNumberChildren = getRoundsNumberChildren();
        }


        public IList<Object> getRoundsNumberChildren()
        {
            roundsNumberChildren.Clear();
            service.findAllRounds().ToList().ForEach(x => roundsNumberChildren.Add(new { RoundName = x.Name, NumberOfChildren = service.getNrChildrenForRound(x.Name) }));
            return roundsNumberChildren;
        }

        public IList<Object> SearchForChildren(String firstname, String lastname)
        {
            IList<Object> childrenSearch = new List<object>();
            Child child = service.FindChildByName(firstname, lastname);
            if (child.IsNull == false)
            {
                childrenSearch.Add(new { FirstName = child.FirstName, LastName = child.LastName, Age = child.Age.ToString(), RoundsNr = FindNumberOfEnrollments(firstname, lastname).ToString() });

            }
            roundsNumberChildren = childrenSearch;
            return childrenSearch;
        }


        public User FindUser(String username, String password)
        {
            User user = new User(1, "Ana", "Maria", username, password, false);
            int p = service.login(username, password);
            if (p == -1)
            {
                throw new Exception("User not found!");
            }
            this.user = user;
            this.port = p;
            new Thread(ClientServ).Start();
            return user;
        }

        public IList<Object> SearchChildrenInRounds(string roundName)
        {
            IList<Object> childrenSearch = new List<object>();
            service.findChildrenForRound(roundName).ToList().ForEach(x => childrenSearch.Add(new { FirstName = x.FirstName, LastName = x.LastName, Age = x.Age.ToString(), RoundsNr = FindNumberOfEnrollments(x.FirstName, x.LastName).ToString() }));
            roundsNumberChildren = childrenSearch;
            return childrenSearch;
        }

        public IList<Object> SearchAgeGroup(string ageGroup)
        {
            IList<Object> childrenSearch = new List<object>();
            service.FindChildrenByAgeGroup(ageGroup).ToList().ForEach(x => childrenSearch.Add(new { FirstName = x.FirstName, LastName = x.LastName, Age = x.Age.ToString(), RoundsNr = FindNumberOfEnrollments(x.FirstName, x.LastName).ToString() }));
            roundsNumberChildren = childrenSearch;
            return childrenSearch;
        }

        public Enrollment FindExistingEnrollment(string firstname, string lastname, string roundName)
        {
            Enrollment en = service.FindEnrollmentByChildAndRound(firstname, lastname, roundName);
            if (en.IsNull == true)
                return null;
            return en;
        }

        public Child FindChild(string firstname, string lastname)
        {
            Child ch = service.FindChildByName(firstname, lastname);
            if (ch.IsNull == true)
            {
                return null;
            }
            return ch;
        }

        public void SaveChild(string firstname, string lastname, int age)
        {
            service.SaveChild(firstname, lastname, age);

        }

        public Enrollment SaveEnrollment(string firstname, string lastname, int age, string roundName)
        {
            Enrollment ch = service.SaveEnrollment(firstname, lastname, age, roundName);
            if (ch.IsNull == true)
            {
                return null;
            }
            return ch;
        }

        public long FindNumberOfEnrollments(string firstname, string lastname)
        {
            return service.FindNumberOfEnrollmentsForChild(firstname, lastname);
        }

        protected virtual void OnUserEvent(UserEventArgs e)
        {
            if (UpdateEvent == null)
                return;
            UpdateEvent(this, e);
            Console.WriteLine("Update event called");
        }

        public void update()
        {
            Console.WriteLine("Controller update");
            UserEventArgs userArgs = new UserEventArgs();
            OnUserEvent(userArgs);
        }


        public void ClientServ()
        {
            IObserver.Processor processor = new IObserver.Processor(this);
            TServerTransport serverTransport = new TServerSocket(port);
            TServer serverc = new TThreadPoolServer(processor, serverTransport);
            serverc.Serve();
        }
    }

    public class UserEventArgs : EventArgs
    {

    }
}
