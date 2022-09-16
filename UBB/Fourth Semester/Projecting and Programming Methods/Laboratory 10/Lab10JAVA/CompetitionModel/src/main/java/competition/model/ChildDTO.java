package competition.model;

import java.io.Serializable;

public class ChildDTO implements Serializable {
    String firstname;
    String lastname;
    int age;
    int nrOfRounds;

    public ChildDTO(String firstname, String lastname, int age, int nrOfRounds) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.age = age;
        this.nrOfRounds = nrOfRounds;
    }

    public String getFirstname() {
        return firstname;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getNrOfRounds() {
        return nrOfRounds;
    }

    public void setNrOfRounds(int nrOfRounds) {
        this.nrOfRounds = nrOfRounds;
    }
}
