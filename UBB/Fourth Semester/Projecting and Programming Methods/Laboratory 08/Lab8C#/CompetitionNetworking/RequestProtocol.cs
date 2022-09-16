using CompetitionModel.domain;
using System;


namespace CompetitionNetworking
{
    public interface Request
    {
    }

    [Serializable]
    public class LoginRequest : Request
    {
        private string username;
        private string password;

        public LoginRequest(string username, string password)
        {
            this.username = username;
            this.password = password;
        }

        public virtual string Username
        {
            get
            {
                return this.username;
            }
        }
        public virtual string Password
        {
            get
            {
                return this.password;
            }
        }
    }

    [Serializable]
    public class LogoutRequest : Request
    {
        private User user;

        public LogoutRequest(User user)
        {
            this.user = user;
        }

        public virtual User User
        {
            get
            {
                return user;
            }
        }
    }

    [Serializable]
    public class GetNrChildrenRoundRequest : Request
    {
        private string roundName;
        public GetNrChildrenRoundRequest(string roundName)
        {
            this.roundName = roundName;
        }
        public virtual string RoundName
        {
            get
            {
                return roundName;
            }
        }

    }

    [Serializable]
    public class GetAllRoundsRequest : Request
    {

    }

    [Serializable]
    public class FindEnByChildRoundRequest : Request
    {
        private string firstname;
        private string lastname;
        private string roundName;

        public FindEnByChildRoundRequest(string firstname, string lastname, string roundName)
        {
            this.firstname = firstname;
            this.lastname = lastname;
            this.roundName = roundName;
        }

        public virtual string RoundName
        {
            get
            {
                return roundName;
            }
        }

        public virtual string Firstname
        {
            get
            {
                return firstname;
            }
        }

        public virtual string Lastname
        {
            get
            {
                return lastname;
            }
        }
    }


    [Serializable]
    public class SaveChildRequest : Request
    {
        private string firstname;
        private string lastname;
        private int age;

        public SaveChildRequest(string firstname, string lastname, int age)
        {
            this.firstname = firstname;
            this.lastname = lastname;
            this.age = age;
        }

        public virtual string Firstname
        {
            get
            {
                return firstname;
            }
        }

        public virtual string Lastname
        {
            get
            {
                return lastname;
            }
        }

        public virtual int Age
        {
            get
            {
                return age;
            }
        }

    }

    [Serializable]
    public class FindChildrenForRoundRequest : Request
    {
        private string roundName;
        public FindChildrenForRoundRequest(string roundName)
        {
            this.roundName = roundName;
        }
        public virtual string RoundName
        {
            get
            {
                return roundName;
            }
        }
    }

    [Serializable]
    public class FindChildByNameRequest : Request
    {
        private string firstname;
        private string lastname;

        public FindChildByNameRequest(string firstname, string lastname)
        {
            this.firstname = firstname;
            this.lastname = lastname;
        }

        public virtual string Firstname
        {
            get
            {
                return firstname;
            }
        }

        public virtual string Lastname
        {
            get
            {
                return lastname;
            }
        }
    }

    [Serializable]
    public class FindChildrenByAgeGroupRequest : Request
    {
        private string ageGroup;

        public FindChildrenByAgeGroupRequest(string ageGroup)
        {
            this.ageGroup = ageGroup;
        }

        public virtual string AgeGroup
        {
            get
            {
                return ageGroup;
            }
        }
    }


    [Serializable]
    public class SaveEnrollmentRequest : Request
    {
        private string firstname;
        private string lastname;
        private int age;
        private string roundName;

        public SaveEnrollmentRequest(string firstname, string lastname, int age, string roundName)
        {
            this.firstname = firstname;
            this.lastname = lastname;
            this.age = age;
            this.roundName = roundName;
        }

        public virtual string Firstname
        {
            get
            {
                return firstname;
            }
        }

        public virtual string Lastname
        {
            get
            {
                return lastname;
            }
        }

        public virtual int Age
        {
            get
            {
                return age;
            }
        }

        public virtual string RoundName
        {
            get
            {
                return roundName;
            }
        }

    }

    [Serializable]
    public class FindNumberOfEnrollmentsForChildRequest : Request
    {
        private string firstname;
        private string lastname;

        public FindNumberOfEnrollmentsForChildRequest(string firstname, string lastname)
        {
            this.firstname = firstname;
            this.lastname = lastname;
        }

        public virtual string Firstname
        {
            get
            {
                return firstname;
            }
        }

        public virtual string Lastname
        {
            get
            {
                return lastname;
            }
        }
    }

}
