package competition.model;

import javax.persistence.*;
import java.io.Serializable;
import java.util.HashSet;
import java.util.Set;

@Entity
@Table(name = "users")
public class User implements Serializable {
    @Id
    @Column(name = "username")
    private String username;

    @Column(name = "password")
    private String password;

    @Enumerated(EnumType.STRING)
    @Column(name = "role")
    private Role role;

    @Column(name = "firstname")
    private String firstname;

    @Column(name = "lastname")
    private String lastname;

    @OneToMany(mappedBy = "responsibleProgrammer")
    private Set<Bug> bugsToResolve = new HashSet<>();

    @OneToMany(mappedBy = "solvedBy")
    private Set<Bug> solvedBugs = new HashSet<>();


    public User() {

    }

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public User(String username, String password, Role role, String firstName, String lastName) {
        this.username = username;
        this.password = password;
        this.role = role;
        this.firstname = firstName;
        this.lastname = lastName;
    }

    public String getId() {
        return username;
    }

    public void setId(String s) {
        this.username = s;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String p) {
        this.password = p;
    }

    public Role getRole() {
        return role;
    }

    public void setRole(Role role) {
        this.role = role;
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

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public Set<Bug> getBugsToResolve() {
        return bugsToResolve;
    }

    public void setBugsToResolve(Set<Bug> bugsToResolve) {
        this.bugsToResolve = bugsToResolve;
    }

    public Set<Bug> getSolvedBugs() {
        return solvedBugs;
    }

    public void setSolvedBugs(Set<Bug> solvedBugs) {
        this.solvedBugs = solvedBugs;
    }
}
