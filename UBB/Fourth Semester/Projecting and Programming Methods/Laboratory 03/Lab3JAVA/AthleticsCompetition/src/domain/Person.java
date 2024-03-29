package domain;

public class Person {
    Integer id;
    String firstName;
    String lastName;


    /**
     * constructor for perosn
     *
     * @param firstName - string
     * @param lastName  - string
     */
    public Person(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    /**
     * getter methode for id
     *
     * @return - integer , id of the child
     */
    public Integer getId() {
        return id;
    }

    /**
     * getter methode for firstName
     *
     * @return - string, first name of the child
     */
    public String getFirstName() {
        return firstName;
    }

    /**
     * setter methode for firstName
     *
     * @param firstName - string, represents the first name of the child
     */
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    /**
     * getter methode for lastName
     *
     * @return - string, represents the last name of the child
     */
    public String getLastName() {
        return lastName;
    }

    /**
     * setter methode for lastName
     *
     * @param lastName -  string, represents the last name of the chila
     */
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

}
