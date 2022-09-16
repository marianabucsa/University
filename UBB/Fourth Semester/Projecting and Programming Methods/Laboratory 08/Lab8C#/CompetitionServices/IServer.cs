using CompetitionModel.domain;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionServices
{
    public interface IServer
    {
        void logout(User u, IObserver o);

        User login(string username, string password, IObserver o);

        long getNrChildrenForRound(string name);

        IEnumerable<Round> findAllRounds();

        Enrollment FindEnrollmentByChildAndRound(string firstname, string lastname, string roundName);

        Child SaveChild(string firstname, string lastname, int age);

        IEnumerable<Child> findChildrenForRound(string roundName);

        Child FindChildByName(string firstname, string lastname);

        IEnumerable<Child> FindChildrenByAgeGroup(string ageGroup);

        Enrollment SaveEnrollment(string firstname, string lastname, int age, string roundName);

        long FindNumberOfEnrollmentsForChild(string firstname, string lastname);

    }
}
