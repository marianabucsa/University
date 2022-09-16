module com.athleticscompetiton {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires org.kordamp.bootstrapfx.core;
    requires org.apache.logging.log4j;
    requires java.sql;

    opens com.athleticscompetiton to javafx.fxml;
    exports com.athleticscompetiton to javafx.graphics;
    exports com.athleticscompetiton.controller to javafx.fxml;
    opens com.athleticscompetiton.controller to javafx.fxml;
    opens com.athleticscompetiton.domain to javafx.base;
}