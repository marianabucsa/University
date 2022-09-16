package competition.model;

import java.io.Serializable;

public class EnrollmentDTO implements Serializable {
    String roundName;
    long numberOfChildren;

    public EnrollmentDTO(String roundName, long numberOfChildren) {
        this.roundName = roundName;
        this.numberOfChildren = numberOfChildren;
    }

    public String getRoundName() {
        return roundName;
    }

    public void setRoundName(String roundName) {
        this.roundName = roundName;
    }

    public long getNumberOfChildren() {
        return numberOfChildren;
    }

    public void setNumberOfChildren(long numberOfChildren) {
        this.numberOfChildren = numberOfChildren;
    }
}
