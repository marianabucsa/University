package domain;

public class Round {
    Integer id;
    String name;

    /**
     * constructor for round
     * @param name - string, represents the name of the round
     */
    public Round(String name) {
        this.name = name;
    }

    /**
     * getter methode for id
     * @return - integer, represents the round's id
     */
    public Integer getId() {
        return id;
    }

    /***
     * setter methode for id
     * @param id - integer, represents the round's id
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /***
     * getter methode for round's name
     * @return - string, represents the round's name
     */
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
}
