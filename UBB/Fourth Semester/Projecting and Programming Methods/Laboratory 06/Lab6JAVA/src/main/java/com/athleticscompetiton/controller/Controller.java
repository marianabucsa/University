package com.athleticscompetiton.controller;

import com.athleticscompetiton.domain.*;
import com.athleticscompetiton.service.Service;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Controller {
    @FXML
    public TableColumn roundColumn;
    @FXML
    public TableColumn nrEnColumn;
    @FXML
    public TextField firstnameText;
    @FXML
    public TextField lastnameText;
    @FXML
    public TableColumn nrOfRoundsColumn;
    @FXML
    public TableColumn ageColumn;
    @FXML
    public TableColumn lastnameColumn;
    @FXML
    public TableColumn firstnameColumn;
    @FXML
    public ComboBox searchRound;
    @FXML
    public ComboBox searchAgeGroups;
    @FXML
    public TableView searchTable;

    private Service service;
    private ObservableList<Object> enrollmentRound;
    private ObservableList<Object> enrollmentChildren;
    private ObservableList<Object> searchChildren;
    private ObservableList<Object> searchRoundObs;
    private ObservableList<Object> searchAgeGroupObs;


    @FXML
    TextField usernameText;
    @FXML
    PasswordField passwordText;
    @FXML
    Button loginButton;
    @FXML
    Button searchChildButton;
    @FXML
    Button enrollChildButton;
    @FXML
    TextField enrollmentFirstName;
    @FXML
    TextField enrollmentLastName;
    @FXML
    TextField enrollmentAge;
    @FXML
    ComboBox enrollmentRoundComboBox;
    @FXML
    TableView enrollmentsTable;

    public void setEnrollmentPage() {
        List<Object> list = new ArrayList<Object>();
        List<Object> list1 = new ArrayList<Object>();
        list.add("50 m Round");
        list.add("100 m Round");
        list.add("1000 m Round");
        list.add("1500 m Round");
        enrollmentRound = FXCollections.observableList(list);
        enrollmentChildren = FXCollections.observableList(list1);
        enrollmentRoundComboBox.setItems(enrollmentRound);
        addDataToEnrollmentsTable();
    }

    public void setSearchPage() {
        List<Object> list = new ArrayList<Object>();
        List<Object> list1 = new ArrayList<Object>();
        List<Object> list2 = new ArrayList<Object>();
        list.add("50 m Round");
        list.add("100 m Round");
        list.add("1000 m Round");
        list.add("1500 m Round");
        searchRoundObs = FXCollections.observableList(list);
        searchRound.setItems(searchRoundObs);
        list1.add("6-8 years old");
        list1.add("9-11 years old");
        list1.add("12-15 years old");
        searchAgeGroupObs = FXCollections.observableList(list1);
        searchAgeGroups.setItems(searchAgeGroupObs);
        searchChildren = FXCollections.observableList(list2);
        addDataToSearchTable();
    }

    private void addDataToSearchTable() {
        firstnameColumn.setCellValueFactory(new PropertyValueFactory<ChildDTO, String>("firstname"));
        lastnameColumn.setCellValueFactory(new PropertyValueFactory<ChildDTO, String>("lastname"));
        ageColumn.setCellValueFactory(new PropertyValueFactory<ChildDTO, Integer>("age"));
        nrOfRoundsColumn.setCellValueFactory(new PropertyValueFactory<ChildDTO, Integer>("nrOfRounds"));
        searchTable.setItems(searchChildren);
    }

    public void setService(Service service) {
        this.service = service;
    }


    public ObservableList<Object> getRoundsNumberChildren() {
        enrollmentChildren.clear();
        Iterable<Round> rounds = service.findAllRounds();
        for (Round round : rounds) {
            enrollmentChildren.add(new EnrollmentDTO(round.getName(), service.getNrChildrenForRound(round.getName())));
        }
        return enrollmentChildren;
    }


    public void onLoginClick() {
        String username = usernameText.getText();
        String password = passwordText.getText();
        try {
            User user = service.findUser(username, password);
            if (user != null) {
                FXMLLoader loader = new FXMLLoader();
                loader.setLocation(

                        getClass().

                                getResource("/com/athleticscompetiton/FirstPage.fxml"));
                AnchorPane root = null;
                try {
                    root = (AnchorPane) loader.load();
                } catch (
                        IOException e) {
                    e.printStackTrace();
                }


                Stage dialogStage = new Stage();
                Controller startupController = loader.getController();
                startupController.setService(service);
                Scene scene = new Scene(root);
                dialogStage.setScene(scene);

                dialogStage.show();
                this.ClearFields();

            } else {
                this.ClearFields();
                throw new Exception("User not found!");
            }
        } catch (Exception re) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(re.getMessage());
            System.out.println(re.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    loginButton.getScene().getWindow().showingProperty();
                }
            });
        }
    }

    private void ClearFields() {
        return;
    }

    public void onSearchButtonClicked(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(
                    getClass().
                            getResource("/com/athleticscompetiton/ChildSearchPage.fxml"));
            AnchorPane root = null;
            try {
                root = (AnchorPane) loader.load();
            } catch (
                    IOException e) {
                e.printStackTrace();
            }


            Stage dialogStage = new Stage();
            Controller startupController = loader.getController();
            startupController.setService(service);
            startupController.setSearchPage();
            Scene scene = new Scene(root);
            dialogStage.setScene(scene);

            dialogStage.show();
            this.ClearFields();

        } catch (Exception re) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(re.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    searchChildButton.getScene().getWindow().showingProperty();
                }
            });
        }
    }

    public void onEnrollButtonClicked(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(
                    getClass().
                            getResource("/com/athleticscompetiton/ChildEnrollPage.fxml"));
            AnchorPane root = null;
            try {
                root = (AnchorPane) loader.load();
            } catch (
                    IOException e) {
                e.printStackTrace();
            }
            Stage dialogStage = new Stage();
            Controller startupController = loader.getController();
            startupController.setService(service);
            startupController.setEnrollmentPage();
            Scene scene = new Scene(root);
            dialogStage.setScene(scene);

            dialogStage.show();
            this.ClearFields();

        } catch (Exception re) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(re.getMessage());
            System.out.println(re.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    enrollChildButton.getScene().getWindow().showingProperty();
                }
            });
        }
    }

    public void onSearchByNameClicked(ActionEvent actionEvent) {
        try {
            String firstname = firstnameText.getText();
            String lastname = lastnameText.getText();
            if (firstname == "" || lastname == "")
                throw new Exception("Enter information for child!");
            searchChildren = this.SearchForChildren(firstname, lastname);
            addDataToSearchTable();
        } catch (Exception re) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(re.getMessage());
            System.out.println(re.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    enrollChildButton.getScene().getWindow().showingProperty();
                }
            });
        }
    }

    private ObservableList<Object> SearchForChildren(String firstname, String lastname) {
        List<Object> childrenSearch = new ArrayList<Object>();
        Child child = service.FindChildByName(firstname, lastname);
        if (child != null) {
            childrenSearch.add(new ChildDTO(child.getFirstName(), child.getLastName(), child.getAge(), (int) FindNumberOfEnrollments(firstname, lastname)));
        }
        return FXCollections.observableList(childrenSearch);
    }

    public void roundsComboBox(ActionEvent actionEvent) {
        try {
            String roundName = (String) searchRound.getValue();
            if (roundName == "")
                throw new Exception("Enter information for child!");

            searchChildren = SearchChildrenInRounds(roundName);
            addDataToSearchTable();
        } catch (Exception ve) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(ve.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    enrollmentAge.getScene().getWindow().showingProperty();
                }
            });
        }
    }

    private ObservableList<Object> SearchChildrenInRounds(String roundName) {
        List<Object> childrenSearch = new ArrayList<>();
        for (Child child : service.findChildrenForRound(roundName))
            childrenSearch.add(new ChildDTO(child.getFirstName(), child.getLastName(), child.getAge(), (int) FindNumberOfEnrollments(child.getFirstName(), child.getLastName())));
        return FXCollections.observableList(childrenSearch);
    }

    public void ageGroupsComboBox(ActionEvent actionEvent) {
        try {
            String ageGroup = (String) searchAgeGroups.getValue();
            if (Objects.equals(ageGroup, ""))
                throw new Exception("Enter information for child!");
            searchChildren = SearchAgeGroup(ageGroup);
            addDataToSearchTable();
        } catch (Exception ve) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(ve.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    enrollmentAge.getScene().getWindow().showingProperty();
                }
            });
        }
    }

    private ObservableList<Object> SearchAgeGroup(String ageGroup) {
        List<Object> childrenSearch = new ArrayList<>();
        for (Child child : service.FindChildrenByAgeGroup(ageGroup))
            childrenSearch.add(new ChildDTO(child.getFirstName(), child.getLastName(), child.getAge(), (int) FindNumberOfEnrollments(child.getFirstName(), child.getLastName())));
        return FXCollections.observableList(childrenSearch);
    }

    public void onEnrollmentClick(ActionEvent actionEvent) throws Exception {
        try {
            if (enrollmentFirstName.getText() == "" || enrollmentLastName.getText() == "" || enrollmentAge.getText() == "")
                throw new Exception("Enter information for child!");
            if (((String) enrollmentRoundComboBox.getValue()) == null)
                throw new Exception("Enter round!");
            String firstname = enrollmentFirstName.getText();
            String lastname = enrollmentLastName.getText();
            int age = Integer.parseInt(enrollmentAge.getText());

            SaveChild(firstname, lastname, age);

            long numberEnrollments = FindNumberOfEnrollments(firstname, lastname);
            if (numberEnrollments >= 2)
                throw new Exception("Child is already enrolled to 2 rounds!");
            Enrollment enrollment = FindExistingEnrollment(firstname, lastname, (String) enrollmentRoundComboBox.getValue());
            if (enrollment != null) {
                throw new Exception(" The enrollment to " + (String) enrollmentRoundComboBox.getValue() + " already exists!");

            }

            if (((String) enrollmentRoundComboBox.getValue() == "1000 m Round" || (String) enrollmentRoundComboBox.getValue() == "1500 m Round") && Integer.parseInt(enrollmentAge.getText()) < 9)
                throw new Exception("Child is too small for that round!");
            else {
                Enrollment enrollment1 = SaveEnrollment(enrollmentFirstName.getText(), enrollmentLastName.getText(), Integer.parseInt(enrollmentAge.getText()), (String) enrollmentRoundComboBox.getValue());
            }
            addDataToEnrollmentsTable();
        } catch (Exception re) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error Message");
            alert.setContentText(re.getMessage());
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    alert.close();
                    enrollmentAge.getScene().getWindow().showingProperty();
                }
            });
        }

    }

    private void addDataToEnrollmentsTable() {
        getRoundsNumberChildren();
        roundColumn.setCellValueFactory(
                new PropertyValueFactory<EnrollmentDTO, String>("roundName")
        );
        nrEnColumn.setCellValueFactory(
                new PropertyValueFactory<EnrollmentDTO, Integer>("numberOfChildren")
        );
        enrollmentsTable.setItems(enrollmentChildren);
    }

    public Child FindChild(String firstname, String lastname) {
        return service.FindChildByName(firstname, lastname);
    }

    public void SaveChild(String firstname, String lastname, int age) {
        service.SaveChild(firstname, lastname, age);
    }

    public Enrollment SaveEnrollment(String firstname, String lastname, int age, String roundName) {
        return service.SaveEnrollment(firstname, lastname, age, roundName);
    }

    public long FindNumberOfEnrollments(String firstname, String lastname) {
        return service.FindNumberOfEnrollmentsForChild(firstname, lastname);
    }

    public Enrollment FindExistingEnrollment(String firstname, String lastname, String roundName) {
        return service.FindEnrollmentByChildAndRound(firstname, lastname, roundName);
    }
}


