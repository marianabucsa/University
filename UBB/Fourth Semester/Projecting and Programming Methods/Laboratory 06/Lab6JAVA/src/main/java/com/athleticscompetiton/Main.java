package com.athleticscompetiton;

import com.athleticscompetiton.controller.Controller;
import com.athleticscompetiton.repository.ChildrenDBRepo;
import com.athleticscompetiton.repository.EnrollmentsDBRepo;
import com.athleticscompetiton.repository.RoundsDBRepo;
import com.athleticscompetiton.repository.UsersDBRepo;
import com.athleticscompetiton.service.Service;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import javafx.stage.StageStyle;


import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class Main extends Application {


    Service service;

    public static void main(String[] args)  {
        launch();
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        Properties props=new Properties();
        try {
            props.load(new FileReader("bd.config"));
        } catch (IOException e) {
            System.out.println("Cannot find bd.config "+e);
        }

        ChildrenDBRepo childrenDBRepo=new ChildrenDBRepo(props);
        EnrollmentsDBRepo enrollmentsDBRepo=new EnrollmentsDBRepo(props);
        RoundsDBRepo roundsDBRepo=new RoundsDBRepo(props);
        UsersDBRepo usersDBRepo=new UsersDBRepo(props);
        service = new Service(usersDBRepo,roundsDBRepo,childrenDBRepo,enrollmentsDBRepo);

        initView(primaryStage);
        primaryStage.show();
    }

    private void initView(Stage primaryStage) throws IOException {

        FXMLLoader startupLoader = new FXMLLoader();
        startupLoader.setLocation(getClass().getResource("/com/athleticscompetiton/Login.fxml"));


        AnchorPane startTaskLayout = startupLoader.load();
        primaryStage.setScene(new Scene(startTaskLayout));
        Controller startupController = startupLoader.getController();
        startupController.setService(service);

        primaryStage.setResizable(false);

    }
}