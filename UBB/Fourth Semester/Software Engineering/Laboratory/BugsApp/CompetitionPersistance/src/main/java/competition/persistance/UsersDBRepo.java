package competition.persistance;

import competition.model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.security.cert.CertPathValidatorException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Properties;

public class UsersDBRepo implements UsersInterface {

    private UserValidator validator;
    private SessionFactory sessionFactory;
    private static final Logger logger = LogManager.getLogger();

    public UsersDBRepo(SessionFactory sessionFactory, UserValidator validator) {
        logger.info("Initializing UsersDBRepo with properties: {} ", sessionFactory);
        this.sessionFactory=sessionFactory;
        this.validator=validator;
    }

    @Override
    public User findOne(String username) {
        logger.traceEntry("finding by username task {}", username);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                Query query = session.createQuery("FROM User WHERE username = :usrname");
                query.setParameter("usrname", username);
                List<User> users = (List<User>)query.list();
                logger.trace("Found {} instance", users.get(0) );
                logger.traceExit( users.get(0));
                return  users.get(0);
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }

    @Override
    public Iterable<User> findAll() {
        logger.traceEntry("finding all task");
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                List<User> users = session.createQuery("from User").list();
                transaction.commit();
                logger.trace("Found {} instance", users );
                logger.traceExit(users);
                return users;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }


    @Override
    public User save(User entity) throws ValidationException {
        logger.traceEntry("saving task {}", entity);
        User user= null;
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
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
    public User delete(String id) {

        logger.traceEntry("deleting task {}", id);
        User user= null;
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                user = (User) session.get(User.class, id);
                session.beginTransaction();
                session.delete(user);
                session.getTransaction().commit();
                logger.trace("Deleted {} instance", user );
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return user;

    }

    @Override
    public User update(User entity) {
        logger.traceEntry("updating task {}", entity);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                User u = session.load( User.class, entity.getId() );
                u.setFirstname(entity.getFirstname());
                u.setLastname(entity.getLastname());
                u.setRole(entity.getRole());
                session.update(u);
                session.getTransaction().commit();
                logger.trace("Updated {} instance", u);
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return entity;

    }


}
