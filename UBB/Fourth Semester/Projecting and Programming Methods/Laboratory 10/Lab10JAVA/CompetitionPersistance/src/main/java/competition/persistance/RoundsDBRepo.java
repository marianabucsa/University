package competition.persistance;

import competition.model.Round;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Properties;

public class RoundsDBRepo implements RoundsInterface{
    private JdbcUtils dbUtils;
    private SessionFactory factory;


    private static final Logger logger = LogManager.getLogger();

    public RoundsDBRepo(Properties properties, SessionFactory factory) {
        logger.info("Initializing RoundsDBRepo with properties: {} ", properties);
        this.dbUtils = new JdbcUtils(properties);
        this.factory = factory;
    }
    @Override
    public Round findOne(Long id) {
        logger.traceEntry("finding by id task {}", id);
        try (Session session = factory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                List<Round> query = session.createQuery("from Round").list();
                Round round = null;
                for( Round r: query){
                    if(Objects.equals(r.getId(), id))
                        round=r;
                }
                transaction.commit();
                logger.trace("Found {} instance", round );
                logger.traceExit(round);
                return round;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }

    @Override
    public Iterable<Round> findAll() {
        logger.traceEntry("finding all task");
        try (Session session = factory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                List<Round> round = session.createQuery("from Round").list();
                transaction.commit();
                logger.trace("Found {} instance", round );
                logger.traceExit(round);
                return round;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }

    @Override
    public Round save(Round entity) {
        logger.traceEntry("saving task {}", entity);
        Round round= null;
        try (Session session = factory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                session.save(round);
                session.getTransaction().commit();
                logger.trace("Deleted {} instance", round );
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return round;
    }

    @Override
    public Round delete(Long id) {
        logger.traceEntry("deleting task {}", id);
        Round round= null;
        try (Session session = factory.openSession()) {
            Transaction transaction = null;
            try {
                round = (Round) session.get(Round.class, id);
                session.beginTransaction();
                session.delete(round);
                session.getTransaction().commit();
                logger.trace("Deleted {} instance", round );
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return round;
    }

    @Override
    public Round update(Round entity) {
        logger.traceEntry("updating task {}", entity);
        try (Session session = factory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                session.beginTransaction();
                session.save(entity);
                session.getTransaction().commit();
                logger.trace("Saved {} instance", entity );
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return entity;
    }

    @Override
    public Round findOneName(String name) {
        logger.traceEntry("finding by name task {}", name);
        try (Session session = factory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                List<Round> query = session.createQuery("from Round").list();
                Round round = null;
                for( Round r: query){
                    if(Objects.equals(r.getName(), name))
                        round=r;
                }
                transaction.commit();
                logger.trace("Found {} instance", round );
                logger.traceExit(round);
                return round;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }
}
