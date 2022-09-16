package competition.model;

import org.hibernate.annotations.GenericGenerator;


import javax.persistence.*;
import java.io.Serializable;

@Entity
@Table(name = "rounds")
public class Round implements Serializable {
    Long id;
    String name;

    /**
     * constructor for round
     * @param name - string, represents the name of the round
     */
    public Round(String name) {
        this.name = name;
    }

    public Round(Long id, String name) {
        this.id = id;
        this.name = name;
    }

    public Round() {
    }

    /**
     * getter methode for id
     * @return - long, represents the round's id
     */

    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    @Column(name = "ID")
    public Long getId() {
        return id;
    }

    /***
     * setter methode for id
     * @param id - long, represents the round's id
     */
    public void setId(Long id) {
        this.id = id;
    }

    /***
     * getter methode for round's name
     * @return - string, represents the round's name
     */
    @Column(name = "NAME")
    public String getName() {
        return name;
    }

    /**
     * setter methode for round's name
     * @param name - string, represents the round's name
     */
    public void setName(String name) {
        this.name = name;
    }


    @Override
    public String toString() {
        return "Round{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}
