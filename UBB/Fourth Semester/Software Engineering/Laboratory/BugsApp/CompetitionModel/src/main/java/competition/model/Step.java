package competition.model;

import javax.persistence.*;
import java.io.Serializable;

@Entity
@Table(name = "steps")
public class Step implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Integer id;

    @Column(name = "orderr")
    private Integer order;

    @Column(name = "textt")
    private String text;

    @Column(name = "idbug")
    private Integer idbug;

    public Step() {

    }

    public Step(Integer id, Integer order, String text) {
        this.id = id;
        this.order = order;
        this.text = text;
    }

    public Step(Integer order, String text) {
        this.order = order;
        this.text = text;
    }


    public Step(Integer id, Integer order, String text, Integer idbug) {
        this.id = id;
        this.order = order;
        this.text = text;
        this.idbug = idbug;
    }

    public Step(Integer order, String text, Integer idbug) {
        this.order = order;
        this.text = text;
        this.idbug = idbug;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getOrder() {
        return order;
    }

    public void setOrder(Integer order) {
        this.order = order;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public Integer getIdbug() {
        return idbug;
    }

    public void setIdbug(Integer idbug) {
        this.idbug = idbug;
    }
}