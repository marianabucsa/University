package domain;

public class Enrollment {
    Long id;
    Child child;
    Round round;

    /**
     * constructor for enrollment
     *
     * @param child -  child
     * @param round -  round
     */
    public Enrollment(Child child, Round round) {
        this.child = child;
        this.round = round;
    }

    /**
     * getter for child
     *
     * @return - Child object
     */
    public Child getChild() {
        return child;
    }

    /**
     * setter for child
     *
     * @param child - Child object
     */
    public void setChild(Child child) {
        this.child = child;
    }

    /**
     * getter for round
     *
     * @return - Round object
     */
    public Round getRound() {
        return round;
    }

    /**
     * setter for round
     *
     * @param round - Round object
     */
    public void setRound(Round round) {
        this.round = round;
    }

    /**
     * getter methode for id
     *
     * @return - a long
     */
    public Long getId() {
        return id;
    }

    /**
     * setter methode for id
     *
     * @param id - a long
     */
    public void setId(Long id) {
        this.id = id;
    }
}
