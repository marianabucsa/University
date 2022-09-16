package competition.persistance;

import competition.model.Child;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class ChildrenDBRepo implements ChildrenInterface {

    public JdbcUtils dbUtils;


    public static final Logger logger = LogManager.getLogger();

    public ChildrenDBRepo(Properties properties) {
        logger.info("Initializing ChildrenDBRepo with properties: {} ", properties);
        this.dbUtils = new JdbcUtils(properties);
    }

    @Override
    public Child findOneName(String firstName, String lastName) {
        logger.traceEntry("finding by name task {}", firstName, lastName);
        Connection con = dbUtils.getConnection();
        Child child = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from children where firstname = ? and lastname = ?")
        ) {
            preStmt.setString(1, firstName);
            preStmt.setString(2, lastName);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    int age = result.getInt("age");
                    child = new Child(id,firstName, lastName, age, false);
                    //child.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(child);
        return child;
    }

    @Override
    public Child findOne(Long id) {
        logger.traceEntry("finding by id task {}", id);
        Connection con = dbUtils.getConnection();
        Child child = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from children where id = ?")
        ) {
            preStmt.setLong(1, id);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    int age = result.getInt("age");
                    child = new Child(id,firstname, lastname, age,false);
                    //child.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(child);
        return child;
    }

    @Override
    public Iterable<Child> findAll() {
        logger.traceEntry("finding all task");
        Connection con = dbUtils.getConnection();
        List<Child> children = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select * from children ")
        ) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    int age = result.getInt("age");
                    Child child = new Child(id,firstname, lastname, age,false);
                    //child.setId(id);
                    children.add(child);
                }
                logger.trace("Found {} instances", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(children);
        return children;
    }

    @Override
    public Child save(Child entity) {
        logger.traceEntry("saving task {}", entity);
        Connection con = dbUtils.getConnection();
        if (findOneName(entity.getFirstName(), entity.getLastName()) != null) {
            Child c = findOneName(entity.getFirstName(), entity.getLastName());
            entity.setId(c.getId());
            update(entity);
        }
        else {
            try (PreparedStatement preStmt = con.prepareStatement("insert into children (firstname,lastname,age) values (?,?,?)")) {
                preStmt.setString(1, entity.getFirstName());
                preStmt.setString(2, entity.getLastName());
                preStmt.setInt(3, entity.getAge());
                int result = preStmt.executeUpdate();
                logger.trace("Saved {} instance", result);
            } catch (SQLException ex) {
                logger.error(ex);
                System.err.println("Error DB" + ex);
            }
        }
        logger.traceExit();
        return null;
    }

    @Override
    public Child delete(Long id) {
        logger.traceEntry("deleting task {}", id);
        Connection con = dbUtils.getConnection();
        Child child = findOne(id);
        try (PreparedStatement preStmt = con.prepareStatement("delete from children where id = ?")
        ) {
            preStmt.setLong(1, id);
            preStmt.executeUpdate();
            logger.trace("Deleted {} instance", id);
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit();
        return child;
    }

    @Override
    public Child update(Child entity) {
        logger.traceEntry("updating task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("update children set firstname=?, lastname=?, age=? where id=? ")) {
            preStmt.setString(1, entity.getFirstName());
            preStmt.setString(2, entity.getLastName());
            preStmt.setInt(3, entity.getAge());
            preStmt.setLong(4, entity.getId());
            int result = preStmt.executeUpdate();
            logger.trace("updated {} instance", result);

        } catch (SQLException ex) {
            logger.error(ex);
            System.err.println("Error DB" + ex);
        }
        logger.traceExit();
        return null;
    }
}
