package competition.persistance;

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

public class RoundsDBRepo implements RoundsInterface{
    public JdbcUtils dbUtils;


    public static final Logger logger = LogManager.getLogger();

    public RoundsDBRepo(Properties properties) {
        logger.info("Initializing RoundsDBRepo with properties: {} ", properties);
        this.dbUtils = new JdbcUtils(properties);
    }
    @Override
    public Round findOne(Long id) {
        logger.traceEntry("finding by id task {}", id);
        Connection con = dbUtils.getConnection();
        Round round = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from rounds where id = ?")
        ) {
            preStmt.setLong(1, id);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    String name = result.getString("name");
                    round = new Round(id,name,false);
                   // round.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(round);
        return round;
    }

    @Override
    public Iterable<Round> findAll() {
        logger.traceEntry("finding all task");
        Connection con = dbUtils.getConnection();
        List<Round> rounds = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select * from rounds ")
        ) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    String name = result.getString("name");
                    Round round = new Round(id,name,false);
                   // round.setId(id);
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

    @Override
    public Round save(Round entity) {
        logger.traceEntry("saving task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("insert into rounds (name) values (?)")) {
            preStmt.setString(1, entity.getName());
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
    public Round delete(Long id) {
        logger.traceEntry("deleting task {}", id);
        Connection con = dbUtils.getConnection();
        Round round = findOne(id);
        try (PreparedStatement preStmt = con.prepareStatement("delete from rounds where id = ?")
        ) {
            preStmt.setLong(1, id);
            preStmt.executeUpdate();
            logger.trace("Deleted {} instance", id);
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(round);
        return round;
    }

    @Override
    public Round update(Round entity) {
        logger.traceEntry("updating task {}", entity);
        Connection con = dbUtils.getConnection();
        try (
                PreparedStatement preStmt = con.prepareStatement("update rounds set name=? where id=? ")) {
            preStmt.setString(1, entity.getName());
            preStmt.setLong(2, entity.getId());
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
    public Round findOneName(String name) {
        logger.traceEntry("finding by name task {}", name);
        Connection con = dbUtils.getConnection();
        Round round = null;
        try (PreparedStatement preStmt = con.prepareStatement("select * from rounds where name = ?")
        ) {
            preStmt.setString(1, name);
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    Long id = result.getLong("id");
                    round = new Round(id,name,false);
                    //round.setId(id);
                }
                logger.trace("Found {} instance", result);
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(round);
        return round;
    }
}
