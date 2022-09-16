package competition.persistance;


import competition.model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.util.ArrayList;
import java.util.List;


public class BugsDBRepo implements BugsInterface {
    private static final Logger logger = LogManager.getLogger();
    private SessionFactory sessionFactory;
    private Validator<Bug> valid;

    public BugsDBRepo(SessionFactory sf, BugValidator valid) {
        this.sessionFactory = sf;
        this.valid = valid;
    }

    @Override
    public Bug findOne(Integer integer) {
        throw new RepositoryException("Methode findOne bug is not implemented");
    }

    @Override
    public Iterable<Bug> findAll() {
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                List<Bug> bugs = session.createQuery("from Bug").list();
                transaction.commit();
                logger.trace("Found {} instance", bugs);
                logger.traceExit(bugs);
                return bugs;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }

    @Override
    public Bug save(Bug bug) throws ValidationException {
        logger.traceEntry("Saving bug {} ", bug);
        valid.validate(bug);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                session.save(bug);
                session.getTransaction().commit();
                logger.trace("Deleted {} instance", bug);
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return bug;
    }

    @Override
    public Bug update(Bug bug) {
        logger.traceEntry("updating bug {}", bug);
        valid.validate(bug);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                Bug b = session.load(Bug.class, bug.getId());
                b.setStage(bug.getStage());
                b.setDescription(bug.getDescription());
                b.setNaming(bug.getNaming());
                if (bug.getResponsibleProgrammer() != null)
                    b.setResponsibleProgrammer(new User(bug.getResponsibleProgrammer(), bug.getResponsibleProgrammer()));
                if (bug.getSolvedBy() != null)
                    b.setSolvedBy(new User(bug.getSolvedBy(), bug.getSolvedBy()));
                session.update(b);
                session.getTransaction().commit();
                logger.trace("Saved {} instance", bug);
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }

    @Override
    public Iterable<Bug> findAllForProgrammer(String username) {
        logger.traceEntry();
        List<Bug> bugs = new ArrayList<>();
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                Query q = session.createQuery("from Bug where stage in (:nou,:red) and responsibleprogrammer=:rp", Bug.class);
                q.setParameter("nou", Stage.Nou);
                q.setParameter("red", Stage.Redeschis);
                q.setParameter("rp", username);
                bugs = q.getResultList();
                transaction.commit();
                return bugs;
            } catch (RuntimeException ex) {
                if (transaction != null)
                    transaction.rollback();
            }
            logger.traceExit(bugs);
            return bugs;
        }
    }

    @Override
    public Bug delete(Integer integer) {
        logger.traceEntry("deleting bug {}", integer);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                Bug b = session.load(Bug.class, integer);
                session.delete(b);
                session.getTransaction().commit();
                logger.trace("Deleted {} instance", integer);
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }

}

