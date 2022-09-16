package competition.model;

public class User extends Person{
    String username;
    String password;

    /**
     * constructor methode for employee
     * @param firstName - string
     * @param lastName - string
     */
    public User(String firstName, String lastName, String username, String password) {
        super(firstName, lastName);
        this.username = username;
        this.password = password;
    }

    /**
     * getter methode for username
     * @return - string, represents the username of the employee
     */
    public String getUsername() {
        return username;
    }

    /**
     * setter methode for username
     * @param username - string, represents the username of the  employee
     */
    public void setUsername(String username) {
        this.username = username;
    }

    /**
     * getter methode for password
     * @return - string, represents the password of the employee
     */
    public String getPassword() {
        return password;
    }

    /**
     * setter methode for password
     * @param password - string, represents the password of the employee
     */
    public void setPassword(String password) {
        this.password = password;
    }
}
