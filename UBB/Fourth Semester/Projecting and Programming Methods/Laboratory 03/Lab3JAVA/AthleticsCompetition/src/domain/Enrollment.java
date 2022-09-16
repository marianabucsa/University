package domain;

public class Enrollment {
    Integer idChild;
    Integer idRound;

    /**
     * constructor for enrollment
     * @param idChild - integer, id of the child
     * @param idRound - integer, id of the round
     */
    public Enrollment(Integer idChild, Integer idRound) {
        this.idChild = idChild;
        this.idRound = idRound;
    }

    /**
     * getter for child id
     * @return - integer
     */
    public Integer getIdChild() {
        return idChild;
    }

    /**
     * setter for child id
     * @param idChild - integer
     */
    public void setIdChild(Integer idChild) {
        this.idChild = idChild;
    }

    /**
     * getter for round id
     * @return - integer
     */
    public Integer getIdRound() {
        return idRound;
    }

    /**
     * setter for round id
     * @param idRound - integer
     */
    public void setIdRound(Integer idRound) {
        this.idRound = idRound;
    }
}
