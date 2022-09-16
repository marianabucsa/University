package competition.model;

public class Notification {
    private NotificationType type;
    private String text;

    public Notification() {
    }


    public Notification(NotificationType type, String text) {
        this.type = type;
        this.text = text;
    }

    @Override
    public String toString() {
        return "Notification{ " +
                "type=" + type +
                '}';
    }

    public NotificationType getType() {
        return type;
    }

    public void setType(NotificationType type) {
        this.type = type;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }
}

