using CompetitionModel.domain;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitionNetworking
{

    public interface Response
    {
    }

    [Serializable]
    public class LoginResponse : Response
    {
        private User user;

        public LoginResponse(User user)
        {
            this.user = user;
        }

        public virtual User User
        {
            get { return user; }
        }
    }

    [Serializable]
    public class GetNrChildrenRoundResponse : Response
    {
        private long nr;

        public GetNrChildrenRoundResponse(long nr)
        {
            this.nr = nr;
        }

        public virtual long Nr
        {
            get { return nr; }
        }
    }

    [Serializable]
    public class GetAllRoundsResponse : Response
    {
        private IEnumerable<Round> rounds;

        public GetAllRoundsResponse(IEnumerable<Round> rounds)
        {
            this.rounds = rounds;
        }

        public virtual IEnumerable<Round> Rounds
        {
            get { return rounds; }
        }
    }


    [Serializable]
    public class FindEnByChildRoundResponse : Response
    {
        private Enrollment enrollment;

        public FindEnByChildRoundResponse(Enrollment enrollment)
        {
            this.enrollment = enrollment;
        }

        public virtual Enrollment Enrollment
        {
            get { return enrollment; }
        }
    }

    [Serializable]
    public class SaveChildResponse : Response
    {
        private Child child;

        public SaveChildResponse(Child child)
        {
            this.child = child;
        }

        public virtual Child Child
        {
            get { return child; }
        }
    }

    [Serializable]
    public class GetChildrenForRoundResponse : Response
    {
        private IEnumerable<Child> children;

        public GetChildrenForRoundResponse(IEnumerable<Child> children)
        {
            this.children = children;
        }

        public virtual IEnumerable<Child> Children
        {
            get { return children; }
        }
    }

    [Serializable]
    public class GetChildByNameResponse : Response
    {
        private Child child;

        public GetChildByNameResponse(Child child)
        {
            this.child = child;
        }

        public virtual Child Child
        {
            get { return child; }
        }
    }

    [Serializable]
    public class GetChildrenByAgeGroupResponse : Response
    {
        private IEnumerable<Child> children;

        public GetChildrenByAgeGroupResponse(IEnumerable<Child> children)
        {
            this.children = children;
        }

        public virtual IEnumerable<Child> Children
        {
            get { return children; }
        }
    }

    [Serializable]
    public class SaveEnrollmentResponse : Response
    {
        private Enrollment enrollment;

        public SaveEnrollmentResponse(Enrollment enrollment)
        {
            this.enrollment = enrollment;
        }

        public virtual Enrollment Enrollment
        {
            get { return enrollment; }
        }
    }

    [Serializable]
    public class GetNrEnForChildResponse : Response
    {
        private long nr;

        public GetNrEnForChildResponse(long nr)
        {
            this.nr = nr;
        }

        public virtual long Nr
        {
            get { return nr; }
        }
    }

    [Serializable]
    public class ErrorResponse : Response
    {
        private string message;

        public ErrorResponse(string message)
        {
            this.message = message;
        }

        public virtual string Message
        {
            get
            {
                return message;
            }
        }
    }

    [Serializable]
    public class OkResponse : Response
    {

    }

    [Serializable]
    public class UpdateResponse : Response
    {
    }
}
