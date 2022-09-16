namespace java CompetitionServer
namespace csharp CompetitionClient

typedef i64 int
struct Person{
    1:required int id;
    2:required string firstName;
    3:required string lastName;
    4:required bool isNull = false;
}

struct User{
    1:required int id;
    2:required string firstName;
    3:required string lastName;
    4:required string username;
    5:required string password;
    6:required bool isNull = false;
}

struct Round{
    1:required int id;
    2:required string name;
    3:required bool isNull = false;
}

struct Child{
    1:required int id;
    2:required string firstName;
    3:required string lastName;
    4:required i32 age;
    5:required bool isNull = false;
}

struct Enrollment{
    1:required int id;
    2:required Child child;
    3:required Round round;
    4:required bool isNull = false;
}

service IObserver{
    oneway void update();
}

service IServer{
        void logout(1:User u),

        i32 login(1:string username, 2:string password),

        int getNrChildrenForRound(1:string name),

        list<Round> findAllRounds(),

        Enrollment FindEnrollmentByChildAndRound(1:string firstname,2:string lastname,3:string roundName),

        Child SaveChild(1:string firstname, 2:string lastname, 3:i32 age),

        list<Child> findChildrenForRound(1:string roundName),

        Child FindChildByName(1:string firstname, 2:string lastname),

        list<Child> FindChildrenByAgeGroup(1:string ageGroup),

        Enrollment SaveEnrollment(1:string firstname, 2:string lastname, 3:i32 age, 4:string roundName),

        int FindNumberOfEnrollmentsForChild(1:string firstname, 2:string lastname);
}

