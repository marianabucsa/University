using CompetitionModel.domain;
using CompetitionPersistance.repository;
using CompetitionServices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CompetitionServer
{
    public class Server : IServer
    {
        private IUsers usersRepo;
        private IRounds roundsRepo;
        private IEnrollments enrollmentsRepo;
        private IChildren childrenRepo;
        private readonly IDictionary<String, IObserver> loggedClients;

        public Server(IUsers usersDBRepo, IRounds roundsDBRepo, IChildren childrenDBRepo, IEnrollments enrollmentsDBRepo)
        {
            this.childrenRepo = childrenDBRepo;
            this.enrollmentsRepo = enrollmentsDBRepo;
            this.roundsRepo = roundsDBRepo;
            this.usersRepo = usersDBRepo;
            loggedClients = new Dictionary<String, IObserver>();
        }

        public User login(String username, String password, IObserver o)
        {
            User user = usersRepo.FindUser(username, password);
            if (user != null)
                loggedClients.Add(user.Id.ToString(), o);
            return user;
        }

        public void logout(User u, IObserver o)
        {
            loggedClients.Remove(u.Id.ToString());
        }
        public long getNrChildrenForRound(string name)
        {
            Round round = roundsRepo.FindOneName(name);
            return enrollmentsRepo.FindChildrenForRound(round.Id).Count;
        }

        public IEnumerable<Round> findAllRounds()
        {
            return roundsRepo.FindAll();
        }

        public Enrollment FindEnrollmentByChildAndRound(string firstname, string lastname, string roundName)
        {
            Child child = childrenRepo.FindOneName(firstname, lastname);
            Round round = roundsRepo.FindOneName(roundName);
            return enrollmentsRepo.FindOne(Tuple.Create(child.Id, round.Id));
        }


        public Child SaveChild(string firstname, string lastname, int age)
        {
            Child child = new Child(firstname, lastname, age);
            return childrenRepo.Save(child);

        }

        public IEnumerable<Child> findChildrenForRound(String roundName)
        {
            return enrollmentsRepo.FindChildrenForRound(roundsRepo.FindOneName(roundName).Id);
        }

        public Child FindChildByName(string firstname, string lastname)
        {
            return childrenRepo.FindOneName(firstname, lastname);
        }

        public IEnumerable<Child> FindChildrenByAgeGroup(string ageGroup)
        {
            List<Child> children = childrenRepo.FindAll();
            List<Child> e = new List<Child>();
            foreach (Child child in children)
            {
                if (child.GetAgeGroup() == ageGroup)
                    e.Add(child);
            }
            return e;
        }

        public Enrollment SaveEnrollment(string firstname, string lastname, int age, string roundName)
        {
            Child child = childrenRepo.FindOneName(firstname, lastname);
            Round round = roundsRepo.FindOneName(roundName);
            Enrollment enrollment = new Enrollment(child, round);
            Enrollment en = enrollmentsRepo.Save(enrollment);
            NotifyObservers();
            return en;
        }

        public long FindNumberOfEnrollmentsForChild(string firstname, string lastname)
        {
            Child child = childrenRepo.FindOneName(firstname, lastname);
            List<Round> roundsForChild = enrollmentsRepo.FindRoundsForChild(child.Id);
            return roundsForChild.Count;
        }

        public void NotifyObservers()
        {
            Task.Run(() => loggedClients.Values.ToList().ForEach(x => x.Update()));
        }
    }
}
