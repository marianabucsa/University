package competition.model;

import javax.persistence.*;
import java.io.Serializable;

@Entity
@Table(name = "bugs")
public class Bug implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Integer id;

    @Column(name = "naming")
    private String naming;

    @Column(name = "description")
    private String description;

    @Enumerated(EnumType.STRING)
    @Column(name = "stage")
    private Stage stage;

    @ManyToOne
    @JoinColumn(name = "responsibleProgrammer")
    private User responsibleProgrammer;

    @ManyToOne
    @JoinColumn(name = "solvedBy")
    private User solvedBy;

    public Bug() {

    }

    public Bug(String naming, String description, Stage stage) {
        this.naming = naming;
        this.description = description;
        this.stage = stage;
    }

    public Bug(Integer id, String naming, String description, Stage stage) {
        this.id = id;
        this.naming = naming;
        this.description = description;
        this.stage = stage;
    }

    public Bug(Integer id, String naming, String description, Stage stage, User responsibleProgrammer, User solvedBy) {
        this.id = id;
        this.naming = naming;
        this.description = description;
        this.stage = stage;
        this.responsibleProgrammer = responsibleProgrammer;
        this.solvedBy = solvedBy;
    }

    public String getNaming() {
        return naming;
    }

    public void setNaming(String naming) {
        this.naming = naming;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Stage getStage() {
        return stage;
    }

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getResponsibleProgrammer() {
        if(responsibleProgrammer!=null)
            return responsibleProgrammer.getUsername();
        return "";
    }

    public void setResponsibleProgrammer(User responsibleProgrammer) {
        this.responsibleProgrammer = responsibleProgrammer;
    }

    public String getSolvedBy() {
        if(solvedBy!=null)
            return solvedBy.getUsername();
        return "";
    }

    public void setSolvedBy(User solvedBy) {
        this.solvedBy = solvedBy;
    }
}