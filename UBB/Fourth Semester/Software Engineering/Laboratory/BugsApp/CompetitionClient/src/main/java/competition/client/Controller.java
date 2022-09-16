package competition.client;

import competition.model.*;
import competition.services.ObserverInterface;
import competition.services.ServerInterface;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;

import java.io.IOException;
import java.util.Objects;

public class Controller implements ObserverInterface {
    private ServerInterface service;
    private ObservableList<User> userModel;
    private ObservableList<Bug> bugProgModel;
    private ObservableList<Bug> bugTesterModel;
    private ObservableList<Step> stepsModel;
    private ObservableList<String> choiceBoxList;
    @FXML
    TextField usernameText;
    @FXML
    PasswordField passwordText;
    @FXML
    TextField stepOrder;
    @FXML
    TextField stepText;
    @FXML
    TextField bugNameText;
    @FXML
    TextField bugDescriptionText;
    @FXML
    TextField bugStageText;
    @FXML
    TextField bugRProgText;
    @FXML
    TextField bugSolvedByText;
    @FXML
    TableView viewBugsTable;
    @FXML
    TableColumn nameTableColumn;
    @FXML
    TableColumn stageTableColumn;
    @FXML
    TableColumn assProgTableColumn;
    @FXML
    TableColumn solvedByTableColumn;
    @FXML
    TableColumn descriptionTableColumn;
    @FXML
    TableColumn idTableColumn;
    @FXML
    TextArea bugDescriptionTable;

    String usernamePro;
    Integer idBug;

    @FXML
    TableView viewUsersTable;
    @FXML
    TableColumn firstnameTableColumn;
    @FXML
    TableColumn lastnameTableColumn;
    @FXML
    TableColumn usenameTableColumn;
    @FXML
    TableColumn statusTableColumn;
    @FXML
    TableColumn orderTableColumn;
    @FXML
    TableColumn textTableColumn;
    @FXML
    TableColumn idStepTableColumn;
    @FXML
    TableColumn idBugStepTableColumn;
    @FXML
    TableView viewStepsTable;
    @FXML
    TextField userFirstnameText;
    @FXML
    TextField userLastnameText;
    @FXML
    TextField userUsernameText;
    @FXML
    ChoiceBox userStatusChoiceBox;


    public Controller(ServerInterface service) {
        this.service = service;
        this.userModel = FXCollections.observableArrayList();
        this.bugProgModel = FXCollections.observableArrayList();
        this.bugTesterModel = FXCollections.observableArrayList();
        this.stepsModel = FXCollections.observableArrayList();
        this.choiceBoxList = FXCollections.observableArrayList();
        choiceBoxList.add("Admin");
        choiceBoxList.add("Programmer");
        choiceBoxList.add("Verifier");
    }

    private void populateUserList() throws Exception {
        userModel.clear();
        service.findAllUsers().forEach(x -> userModel.add(x));
    }

    public ObservableList<User> getUserModel() throws Exception {
        populateUserList();
        return userModel;
    }

    private void populateStepsList(Integer id) throws Exception {
        stepsModel.clear();
        service.findAllStepsForBug(id).forEach(x -> stepsModel.add(x));
    }

    public ObservableList<Step> getStepsModel(Integer id) throws Exception {
        populateStepsList(id);
        return stepsModel;
    }

    private void populateBugProgList() throws Exception {
        bugProgModel.clear();
        service.findAllBugsProgrammer(usernamePro).forEach(x -> bugProgModel.add(x));
    }

    public ObservableList<Bug> getBugProgModel() throws Exception {
        populateBugProgList();
        return bugProgModel;
    }

    private void populateBugTesterList() throws Exception {
        bugTesterModel.clear();
        service.findAllBugs().forEach(x -> bugTesterModel.add(x));
    }

    public ObservableList<Bug> getBugTesterModel() throws Exception {
        populateBugTesterList();
        return bugTesterModel;
    }


    public void repairBug(Bug bug) throws Exception {
        bug.setSolvedBy(new User(usernamePro, usernamePro));
        service.repairBug(bug);
    }

    public boolean testCodeSolvedBug(Bug bug) throws Exception {
        boolean solved;
        if (Math.random() < 0.5) {
            bug.setStage(Stage.Inchis);
            solved = true;
        } else {
            bug.setStage(Stage.Redeschis);
            solved = false;
        }
        service.updateBug(bug);
        return solved;
    }

    public void onTestSolutionClick() {
        try {
            Bug bug = (Bug) viewBugsTable.getSelectionModel().getSelectedItem();
            if (bug.getStage() == Stage.Reparat)
                testCodeSolvedBug(bug);
            else throw new Exception("The bug is not repaired!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void addBug(String naming, String description) throws Exception {
        Bug bug = new Bug(naming, description, Stage.Nou);
        service.saveBug(bug);
    }

    public void updateBug(Integer id, String naming, String description, Stage stage, String responsibleProgrammer, String solvedBy) throws Exception {
        Bug bug = new Bug(id, naming, description, stage);
        if (responsibleProgrammer != null)
            bug.setResponsibleProgrammer(new User(responsibleProgrammer, responsibleProgrammer));
        if (solvedBy != null)
            bug.setSolvedBy(new User(solvedBy, solvedBy));
        service.updateBug(bug);
    }

    public void onDeleteBugClick() {
        Bug bug = (Bug) viewBugsTable.getSelectionModel().getSelectedItem();
        try {
            deleteBug(bug.getId());
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void deleteBug(Integer id) throws Exception {
        try {
            service.deleteBug(id);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void update() {
        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                try {
                    populateBugProgList();
                    populateBugTesterList();
                    populateUserList();
                    populateStepsList(idBug);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public void onLoginClick() {
        String username = usernameText.getText();
        String password = passwordText.getText();
        try {
            User user = service.login(username, password, this);
            if (user != null) {
                if (user.getRole() == Role.Administrator) {
                    FXMLLoader loader = new FXMLLoader();
                    loader.setLocation(

                            getClass().

                                    getResource("/competition/adminFirstPage.fxml"));
                    AnchorPane root = null;
                    try {
                        loader.setController(this);
                        root = (AnchorPane) loader.load();
                        javafx.stage.Stage dialogStage = new javafx.stage.Stage();
                        Scene scene = new Scene(root);
                        dialogStage.setScene(scene);

                        dialogStage.show();
                        usernamePro = user.getUsername();
                        onViewUsersClick();

                        userStatusChoiceBox.setItems(choiceBoxList);
                    } catch (
                            IOException e) {
                        e.printStackTrace();
                    }
                } else {
                    if (user.getRole() == Role.Programator) {
                        FXMLLoader loader = new FXMLLoader();
                        loader.setLocation(

                                getClass().

                                        getResource("/competition/programmerFirstPage.fxml"));
                        AnchorPane root = null;
                        try {
                            loader.setController(this);
                            root = (AnchorPane) loader.load();
                            javafx.stage.Stage dialogStage = new javafx.stage.Stage();
                            Scene scene = new Scene(root);
                            dialogStage.setScene(scene);

                            dialogStage.show();
                            usernamePro = user.getUsername();
                            viewAllBugsVerifierClick();
                        } catch (
                                IOException e) {
                            e.printStackTrace();
                        }
                    } else {
                        if (user.getRole() == Role.Verificator) {
                            FXMLLoader loader = new FXMLLoader();
                            loader.setLocation(

                                    getClass().

                                            getResource("/competition/verifierFirstPage.fxml"));
                            AnchorPane root = null;
                            try {
                                loader.setController(this);
                                root = (AnchorPane) loader.load();
                                javafx.stage.Stage dialogStage = new javafx.stage.Stage();
                                Scene scene = new Scene(root);
                                dialogStage.setScene(scene);

                                dialogStage.show();
                                usernamePro = user.getUsername();
                                viewAllBugsVerifierClick();
                            } catch (
                                    IOException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                }

            } else {
                throw new Exception("User not found!");
            }
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onAddBugClick() {
        String name = bugNameText.getText();
        String description = bugDescriptionText.getText();
        try {
            if (Objects.equals(name, "")) {
                throw new Exception("Field name should be filled");
            }
            if (Objects.equals(description, "")) {
                throw new Exception("Field description should be filled");
            }
            addBug(name, description);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onUpdateBugClick() {
        String name = bugNameText.getText();
        String description = bugDescriptionText.getText();
        String responsibleProgrammer = bugRProgText.getText();
        String solvedBy = bugSolvedByText.getText();
        Stage stage;
        if (Objects.equals(bugStageText.getText(), "Nou"))
            stage = Stage.Nou;
        else {
            if (Objects.equals(bugStageText.getText(), "Reparat"))
                stage = Stage.Reparat;
            else {
                if (Objects.equals(bugStageText.getText(), "Redeschis"))
                    stage = Stage.Redeschis;
                else stage = Stage.Inchis;
            }
        }

        try {
            if (Objects.equals(name, "")) {
                throw new Exception("Field name should be filled");
            }
            if (Objects.equals(description, "")) {
                throw new Exception("Field description should be filled");
            }
            if (Objects.equals(bugStageText.getText(), "")) {
                throw new Exception("Field stage should be filled");
            }

            if (Objects.equals(bugSolvedByText.getText(), "")) {
                solvedBy = null;
            }
            if (Objects.equals(bugRProgText.getText(), "")) {
                responsibleProgrammer = null;
            }
            updateBug(idBug, name, description, stage, responsibleProgrammer, solvedBy);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onAddStepClick() {
        Integer order = Integer.parseInt(stepOrder.getText());
        String text = stepText.getText();
        Integer bugid = idBug;
        try {
            if (Objects.equals(order, null)) {
                throw new Exception("Field should be filled");
            }
            if (Objects.equals(text, "")) {
                throw new Exception("Field should be filled");
            }

            if (Objects.equals(bugid, null)) {
                throw new Exception("Field should be filled");
            }
            Step step = new Step(order,text,bugid);
            service.saveStep(step);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onAddUserClick() {
        String firstname = userFirstnameText.getText();
        String lastname = userLastnameText.getText();
        String username = userUsernameText.getText();
        String status = userStatusChoiceBox.getSelectionModel().getSelectedItem().toString();
        try {
            if (Objects.equals(firstname, "")) {
                throw new Exception("Field should be filled");
            }
            if (Objects.equals(lastname, "")) {
                throw new Exception("Field should be filled");
            }

            if (Objects.equals(username, "")) {
                throw new Exception("Field should be filled");
            }
            if (Objects.equals(status, "")) {
                throw new Exception("Field should be filled");
            }
            User user = null;
            if (status.equals("Admin")) {
                user = new User(username, username, Role.Administrator, firstname, lastname);
            } else {
                if (status.equals("Programmer")) {
                    user = new User(username, username, Role.Programator, firstname, lastname);
                } else {
                    user = new User(username, username, Role.Verificator, firstname, lastname);
                }
            }
            service.saveUser(user);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }
    private Integer stepId;
    private Integer bugId;

    public void onSelectStepClick() {
        Step step = (Step) viewStepsTable.getSelectionModel().getSelectedItem();
        stepOrder.setText(step.getOrder().toString());
        stepText.setText(step.getText());
        stepId = step.getId();
        bugId = step.getId();
    }

    public void onUpdateStepClick(){
        Integer order = Integer.parseInt(stepOrder.getText());
        String text = stepText.getText();
        try {
            if (Objects.equals(order, null)) {
                throw new Exception("Field should be filled");
            }
            if (Objects.equals(text, "")) {
                throw new Exception("Field should be filled");
            }


            Step step = new Step(stepId,order,text,bugId);
            service.updateStep(step);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onDeleteStepClick(){
        Integer id = ((Step) viewStepsTable.getSelectionModel().getSelectedItem()).getId();
        try {
            if (Objects.equals(id, null)) {
                throw new Exception("Field should be filled");
            }
            service.deleteStep(id);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }
    public void onSelectUserClick() {
        User user = (User) viewUsersTable.getSelectionModel().getSelectedItem();
        userFirstnameText.setText(user.getFirstname());
        userLastnameText.setText(user.getLastname());
        userUsernameText.setText(user.getUsername());
        if (user.getRole().equals(Role.Administrator)) {
            userStatusChoiceBox.getSelectionModel().select(0);
        } else {
            if (user.getRole().equals(Role.Programator)) {
                userStatusChoiceBox.getSelectionModel().select(1);
            } else {
                userStatusChoiceBox.getSelectionModel().select(2);
            }
        }

    }

    public void onDeleteUserClick() {
        String username = userUsernameText.getText();
        try {
            if (Objects.equals(username, "")) {
                throw new Exception("Field should be filled");
            }
            service.deleteUser(username);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onUpdateUserClick() {
        String firstname = userFirstnameText.getText();
        String lastname = userLastnameText.getText();
        String username = userUsernameText.getText();
        String status = userStatusChoiceBox.getSelectionModel().getSelectedItem().toString();
        try {
            if (Objects.equals(firstname, "")) {
                throw new Exception("Field should be filled");
            }
            if (Objects.equals(lastname, "")) {
                throw new Exception("Field should be filled");
            }

            if (Objects.equals(username, "")) {
                throw new Exception("Field should be filled");
            }
            if (Objects.equals(status, "")) {
                throw new Exception("Field should be filled");
            }
            User user = null;
            if (status.equals("Admin")) {
                user = new User(username, username, Role.Administrator, firstname, lastname);
            } else {
                if (status.equals("Programmer")) {
                    user = new User(username, username, Role.Programator, firstname, lastname);
                } else {
                    user = new User(username, username, Role.Verificator, firstname, lastname);
                }
            }
            service.updateUser(user);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onAssignBugClick() {
        try {
            Bug bug = (Bug) viewBugsTable.getSelectionModel().getSelectedItem();
            String responsibleProgrammer = bugRProgText.getText();
            bug.setResponsibleProgrammer(new User(responsibleProgrammer, responsibleProgrammer));
            service.updateBug(bug);
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onRepairBugClick() {
        try {
            Bug bug = (Bug) viewBugsTable.getSelectionModel().getSelectedItem();
            if (bug.getStage() == Stage.Nou || bug.getStage() == Stage.Redeschis)
                repairBug(bug);
            else throw new Exception("Bug cannot be repaired!");
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void viewAllBugsVerifierClick() {
        try {
            nameTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("naming"));
            descriptionTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("description"));
            stageTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("stage"));
            assProgTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("responsibleProgrammer"));
            solvedByTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("solvedBy"));
            idTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, Integer>("id"));
            viewBugsTable.setItems(getBugTesterModel());
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void viewAllSteps(Integer id) {
        try {
            orderTableColumn.setCellValueFactory(new PropertyValueFactory<Step, String>("order"));
            textTableColumn.setCellValueFactory(new PropertyValueFactory<Step, String>("text"));
            idStepTableColumn.setCellValueFactory(new PropertyValueFactory<Step, Integer>("id"));
            idBugStepTableColumn.setCellValueFactory(new PropertyValueFactory<Step, Integer>("idbug"));
            viewStepsTable.setItems(getStepsModel(id));
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void viewAllBugsProgrammerClick() {
        try {
            nameTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("naming"));
            descriptionTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("description"));
            stageTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("stage"));
            assProgTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("responsibleProgrammer"));
            solvedByTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("solvedBy"));
            idTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, Integer>("id"));
            viewBugsTable.setItems(getBugProgModel());
        } catch (Exception re) {
            re.printStackTrace();
        }
    }


    public void onViewUsersClick() {
        try {
            firstnameTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("firstname"));
            lastnameTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("lastname"));
            usenameTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("username"));
            statusTableColumn.setCellValueFactory(new PropertyValueFactory<Bug, String>("role"));
            viewUsersTable.setItems(getUserModel());
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

    public void onViewTableBugsMouseClicked() {
        try {
            Bug bug = (Bug) viewBugsTable.getSelectionModel().getSelectedItem();
            if (bug != null) {
                bugDescriptionTable.setText(bug.getDescription());
                if (Objects.equals(usernamePro, "verificator")) {
                    idBug = bug.getId();
                    bugNameText.setText(bug.getNaming());
                    bugDescriptionText.setText(bug.getDescription());
                    bugStageText.setText(bug.getStage().toString());
                    bugRProgText.setText(bug.getResponsibleProgrammer());
                    bugSolvedByText.setText(bug.getSolvedBy());
                }
                viewAllSteps(bug.getId());
            }
        } catch (Exception re) {
            re.printStackTrace();
        }
    }

}


