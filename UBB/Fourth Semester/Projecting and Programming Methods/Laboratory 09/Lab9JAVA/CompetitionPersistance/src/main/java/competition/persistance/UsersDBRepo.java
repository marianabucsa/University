package competition.persistance;

import competition.model.User;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class UsersDBRepo implements UsersInterface {

    public JdbcUtils dbUtils;


    public static final Logger logger = LogManager.getLogger();

    public UsersDBRepo(Properties properties) {
        logger.info("Initializing UsersDBRepo with properties: {} ", properties);
        this.dbUtils = new JdbcUtils(properties);
    }

    @Override
    public User findOne(Long id) {
        logger.traceEntry("finding by id task {}", id);
        Connection con = dbUtils.getConnection();
        User user = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from users where id = ?")
        ) {
            preStmt.setLong(1, id);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    String username = result.getString("username");
                    String password = result.getString("password");
                    user = new User(id,firstname, lastname, username, password,false);
                   // user.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(user);
        return user;
    }

    @Override
    public Iterable<User> findAll() {
        logger.traceEntry("finding all task");
        Connection con = dbUtils.getConnection();
        List<User> users = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select * from users ")
        ) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    String username = result.getString("username");
                    String password = result.getString("password");
                    User user = new User(id,firstname, lastname, username, password,false);
                    //user.setId(id);
                    users.add(user);
                }
                logger.trace("Found {} instances", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(users);
        return users;
    }

    @Override
    public User save(User entity) {
        logger.traceEntry("saving task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("insert into users (firstname,lastname,username,password) values (?,?,?,?)")) {
            preStmt.setString(1, entity.getFirstName());
            preStmt.setString(2, entity.getLastName());
            preStmt.setString(3, entity.getUsername());
            preStmt.setString(4, entity.getPassword());
            int result = preStmt.executeUpdate();
            logger.trace("Saved {} instance", result);

        } catch (SQLException ex) {
            logger.error(ex);
            System.err.println("Error DB" + ex);
        }
        logger.traceExit();
        return null;
    }


    @Override
    public User delete(Long id) {
        logger.traceEntry("deleting task {}", id);
        Connection con = dbUtils.getConnection();
        User user = findOne(id);
        try (PreparedStatement preStmt = con.prepareStatement("delete from users where id = ?")
        ) {
            preStmt.setLong(1, id);
            preStmt.executeUpdate();
            logger.trace("Deleted {} instance", id);
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(user);
        return user;
    }

    @Override
    public User update(User entity) {
        logger.traceEntry("updating task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("update users set firstname=?, lastname=?, username=?,password=? where id=? ")) {
            preStmt.setString(1, entity.getFirstName());
            preStmt.setString(2, entity.getLastName());
            preStmt.setString(3, entity.getUsername());
            preStmt.setString(4, entity.getPassword());
            preStmt.setLong(5, entity.getId());
            int result = preStmt.executeUpdate();
            logger.trace("updated {} instance", result);

        } catch (SQLException ex) {
            logger.error(ex);
            System.err.println("Error DB" + ex);
        }
        logger.traceExit();
        return null;
    }


    @Override
    public User findOneName(String firstName, String lastName) {
        logger.traceEntry("finding by name task {}", firstName, lastName);
        Connection con = dbUtils.getConnection();
        User user = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from users where firstname = ? and lastname = ?")
        ) {
            preStmt.setString(1, firstName);
            preStmt.setString(2, lastName);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    String username = result.getString("username");
                    String password = result.getString("password");
                    user = new User(id,firstName, lastName, username, password,false);
                    //user.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(user);
        return user;
    }

    @Override
    public User findUser(String username, String password) {
        logger.traceEntry("finding by username and password task {}", username, password);
        Connection con = dbUtils.getConnection();
        User user = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from users where username = ? and password = ?")
        ) {
            preStmt.setString(1, username);
            preStmt.setString(2, password);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    String firstName = result.getString("firstname");
                    String lastName = result.getString("lastname");
                    user = new User(id,firstName, lastName, username, password,false);
                    //user.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(user);
        return user;
    }
}
