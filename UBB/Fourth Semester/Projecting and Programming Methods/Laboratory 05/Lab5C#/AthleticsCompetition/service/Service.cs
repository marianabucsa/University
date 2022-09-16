using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AthleticsCompetition.domain;
using AthleticsCompetition.repository;
using AthleticsCompetition.utils;

namespace AthleticsCompetition.service
{
    public class Service : Observable
    {

        private IUsers users_repo;
        private IRounds rounds_repo;
        private IChildren children_repo;
        private IEnrollments enrollments_repo;
        private IList<Observer> observers = new List<Observer>();

        public Service(IUsers users, IRounds rounds, IChildren children, IEnrollments enrollments)
        {
            this.users_repo = users;
            this.rounds_repo = rounds;
            this.children_repo = children;
            this.enrollments_repo = enrollments;
        }

        public User findUser(String username, String password)
        {
            return users_repo.FindUser(username, password);
        }

        internal object getNrChildrenForRound(string name)
        {
            Round round = rounds_repo.FindOneName(name);
            return enrollments_repo.FindChildrenForRound(round.Id).Count;
        }

        public IEnumerable<Round> findAllRounds()
        {
            return rounds_repo.FindAll();
        }

        public override void AddObserver(Observer o)
        {
            throw new NotImplementedException();
        }

        public override void NotifyObservers()
        {
            throw new NotImplementedException();
        }

        public Enrollment FindEnrollmentByChildAndRound(string firstname, string lastname, string roundName)
        {
            Child child = children_repo.FindOneName(firstname, lastname);
            Round round = rounds_repo.FindOneName(roundName);
            return enrollments_repo.FindOne(Tuple.Create(child.Id, round.Id));
        }

        internal void SaveChild(string firstname, string lastname, int age)
        {
            Child child = new Child(firstname, lastname, age);
            children_repo.Save(child);
        }

        public IEnumerable<Child> findChildrenForRound(String roundName)
        {
            return enrollments_repo.FindChildrenForRound(rounds_repo.FindOneName(roundName).Id);
        }

        public Child FindChildByName(string firstname, string lastname)
        {
            return children_repo.FindOneName(firstname, lastname);
        }

        public IEnumerable<Child> FindChildrenByAgeGroup(string ageGroup)
        {
            List<Child> children = children_repo.FindAll();
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
            Child child = children_repo.FindOneName(firstname, lastname);
            Round round = rounds_repo.FindOneName(roundName);
            Enrollment enrollment = new Enrollment(child, round);
            return enrollments_repo.Save(enrollment);
        }

        public int FindNumberOfEnrollmentsForChild(string firstname, string lastname)
        {
            Child child = children_repo.FindOneName(firstname, lastname);
            List<Round> roundsForChild = enrollments_repo.FindRoundsForChild(child.Id);
            return roundsForChild.Count;
        }
    }
}
