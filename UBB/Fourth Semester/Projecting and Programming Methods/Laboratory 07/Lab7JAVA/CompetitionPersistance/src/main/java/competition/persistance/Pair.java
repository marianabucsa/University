package competition.persistance;

public class Pair {
    Long first;
    Long second;

    /**
     * constructor for pair object
     * @param first - first object from the pair
     * @param second - second object from the pair
     */
    public Pair(Long first, Long second) {
        this.first = first;
        this.second = second;
    }

    /**
     * getter methode for the first object
     * @return - an integer
     */
    public Long getFirst() {
        return first;
    }

    /**
     * setter methode for the first object
     * @param first - an integer
     */
    public void setFirst(Long first) {
        this.first = first;
    }

    /**
     * getter methode for the second object
     * @return - an integer
     */
    public Long getSecond() {
        return second;
    }

    /**
     * setter methode for the second object
     * @param second - an integer
     */
    public void setSecond(Long second) {
        this.second = second;
    }
}
