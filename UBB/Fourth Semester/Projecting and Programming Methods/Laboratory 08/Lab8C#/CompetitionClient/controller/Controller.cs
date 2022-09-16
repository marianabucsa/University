using CompetitionModel.domain;
using CompetitionServices;
using System;
using System.Collections.ObjectModel;
using System.Linq;
namespace CompetitionClient.controller
{
    public class Controller : IObserver
    {

        public event EventHandler<UserEventArgs> UpdateEvent;
        private IServer service;
        public ObservableCollection<Object> roundsNumberChildren;


        public Controller(IServer service)
        {
            this.service = service;
            roundsNumberChildren = new ObservableCollection<object>();
            // roundsNumberChildren = getRoundsNumberChildren();
        }


        public ObservableCollection<Object> getRoundsNumberChildren()
        {
            roundsNumberChildren.Clear();
            service.findAllRounds().ToList().ForEach(x => roundsNumberChildren.Add(new { RoundName = x.Name, NumberOfChildren = service.getNrChildrenForRound(x.Name) }));
            return roundsNumberChildren;
        }

        public ObservableCollection<Object> SearchForChildren(String firstname, String lastname)
        {
            ObservableCollection<Object> childrenSearch = new ObservableCollection<object>();
            Child child = service.FindChildByName(firstname, lastname);
            if (child != null)
            {
                childrenSearch.Add(new { FirstName = child.FirstName, LastName = child.LastName, Age = child.Age.ToString(), RoundsNr = FindNumberOfEnrollments(firstname, lastname).ToString() });

            }
            roundsNumberChildren = childrenSearch;
            return childrenSearch;
        }


        public User FindUser(String username, String password)
        {
            return service.login(username, password, this);
        }

        public ObservableCollection<Object> SearchChildrenInRounds(string roundName)
        {
            ObservableCollection<Object> childrenSearch = new ObservableCollection<object>();
            service.findChildrenForRound(roundName).ToList().ForEach(x => childrenSearch.Add(new { FirstName = x.FirstName, LastName = x.LastName, Age = x.Age.ToString(), RoundsNr = FindNumberOfEnrollments(x.FirstName, x.LastName).ToString() }));
            roundsNumberChildren = childrenSearch;
            return childrenSearch;
        }

        public ObservableCollection<Object> SearchAgeGroup(string ageGroup)
        {
            ObservableCollection<Object> childrenSearch = new ObservableCollection<object>();
            service.FindChildrenByAgeGroup(ageGroup).ToList().ForEach(x => childrenSearch.Add(new { FirstName = x.FirstName, LastName = x.LastName, Age = x.Age.ToString(), RoundsNr = FindNumberOfEnrollments(x.FirstName, x.LastName).ToString() }));
            roundsNumberChildren = childrenSearch;
            return childrenSearch;
        }

        public Enrollment FindExistingEnrollment(string firstname, string lastname, string roundName)
        {
            return service.FindEnrollmentByChildAndRound(firstname, lastname, roundName);
        }

        public Child FindChild(string firstname, string lastname)
        {
            return service.FindChildByName(firstname, lastname);
        }

        public void SaveChild(string firstname, string lastname, int age)
        {
            service.SaveChild(firstname, lastname, age);
        }

        public Enrollment SaveEnrollment(string firstname, string lastname, int age, string roundName)
        {
            return service.SaveEnrollment(firstname, lastname, age, roundName);
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

        public void Update()
        {
            Console.WriteLine("Controller update");
            UserEventArgs userArgs = new UserEventArgs();
            OnUserEvent(userArgs);
        }
    }

    public class UserEventArgs : EventArgs
    {

    }
}
