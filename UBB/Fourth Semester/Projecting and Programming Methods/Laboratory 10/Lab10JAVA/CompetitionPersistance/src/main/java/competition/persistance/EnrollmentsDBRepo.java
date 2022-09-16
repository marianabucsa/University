package competition.persistance;

import competition.model.Child;
import competition.model.Enrollment;
import competition.model.Round;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class EnrollmentsDBRepo implements EnrollmentsInterface {

    private JdbcUtils dbUtils;


    private static final Logger logger = LogManager.getLogger();

    public EnrollmentsDBRepo(Properties properties) {
        logger.info("Initializing EnrollmentsDBRepo with properties: {} ", properties);
        this.dbUtils = new JdbcUtils(properties);
    }

    @Override
    public Enrollment findOne(Pair id) {
        logger.traceEntry("finding by id task {}", id);
        Connection con = dbUtils.getConnection();
        Enrollment enrollment = null;
        try (PreparedStatement preStmt1 = con.prepareStatement("select E.id,C.firstname,C.lastname,C.age,R.name from children C inner join enrollments E on E.idChild=C.id inner join Rounds r on E.idRound=R.id  where idChild = ? and idRound=?")
        ) {
            preStmt1.setLong(1, id.getFirst());
            preStmt1.setLong(2, id.getSecond());
            try (ResultSet result = preStmt1.executeQuery()) {
                while (result.next()) {
                    Long idE = result.getLong("id");
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    int age = result.getInt("age");
                    Child child = new Child(firstname, lastname, age);
                    child.setId(id.getFirst());

                    String name = result.getString("name");
                    Round round = new Round(name);
                    round.setId(id.getSecond());
                    enrollment= new Enrollment(child,round);
                    enrollment.setId(idE);

                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(enrollment);
        return enrollment;
    }

    @Override
    public Iterable<Enrollment> findAll() {
        logger.traceEntry("finding all task");
        Connection con = dbUtils.getConnection();
        List<Enrollment> enrollments = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select E.id,C.id,C.firstname,C.lastname,C.age,R.id,R.name from children C inner join enrollments E on E.idChild=C.id inner join Rounds r on E.idRound=R.id ")
        ) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long idE = result.getLong(1);
                    Long idC = result.getLong(2);
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    int age = result.getInt("age");
                    Child child = new Child(firstname, lastname, age);
                    child.setId(idC);

                    Long idR = result.getLong(6);
                    String name = result.getString("name");
                    Round round = new Round(name);
                    round.setId(idR);
                    Enrollment enrollment= new Enrollment(child,round);
                    enrollment.setId(idE);
                    enrollments.add(enrollment);
                }
                logger.trace("Found {} instances", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(enrollments);
        return enrollments;
    }

    @Override
    public Enrollment save(Enrollment entity) {
        logger.traceEntry("saving task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("insert into enrollments (idchild,idround) values (?,?)")) {
            preStmt.setLong(1, entity.getChild().getId());
            preStmt.setLong(2, entity.getRound().getId());
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
    public Enrollment delete(Pair id) {
        logger.traceEntry("deleting task {}", id);
        Connection con = dbUtils.getConnection();
        Enrollment enrollment = findOne(id);
        try (PreparedStatement preStmt = con.prepareStatement("delete from enrollments where idchild = ? and idround = ?")
        ) {
            preStmt.setLong(1, id.getFirst());
            preStmt.setLong(2,id.getSecond());
            preStmt.executeUpdate();
            logger.trace("Deleted {} instance", id);
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit();
        return enrollment;
    }

    @Override
    public Enrollment update(Enrollment entity) {
        logger.traceEntry("updating task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("update enrollments set idchild=?, idround=? where id=? ")) {
            preStmt.setLong(1, entity.getChild().getId());
            preStmt.setLong(2, entity.getRound().getId());
            preStmt.setLong(3, entity.getId());
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
    public Iterable<Child> findChildrenForRound(Long roundId) {
        logger.traceEntry("finding all task");
        Connection con = dbUtils.getConnection();
        List<Child> children = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select C.id,C.firstname,C.lastname,C.age from children C inner join enrollments E on E.idChild=C.id inner join Rounds r on E.idRound=R.id  where idRound = ? ")
        ) {
            preStmt.setLong(1, roundId);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long idC = result.getLong("id");
                    String firstname = result.getString("firstname");
                    String lastname = result.getString("lastname");
                    int age = result.getInt("age");
                    Child child = new Child(firstname, lastname, age);
                    child.setId(idC);

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
    public Iterable<Round> findRoundsForChild(Long childId) {
        logger.traceEntry("finding all task");
        Connection con = dbUtils.getConnection();
        List<Round> rounds = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select R.id,R.name from rounds R inner join enrollments E on E.idRound=R.id inner join children C on E.idChild=C.id where idChild = ? ")
        ) {
            preStmt.setLong(1, childId);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long idR = result.getLong("id");
                    String name = result.getString("name");
                    Round round = new Round(name);
                    round.setId(idR);

                    rounds.add(round);
                }
                logger.trace("Found {} instances", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(rounds);
        return rounds;
    }
}
