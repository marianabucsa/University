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

public class StepsDBRepo implements StepsInterface{
    private static final Logger logger = LogManager.getLogger();
    private SessionFactory sessionFactory;

    public StepsDBRepo(SessionFactory sf) {
        this.sessionFactory = sf;
    }

    @Override
    public Step findOne(Integer integer) {
        throw new RepositoryException("Methode findOne step is not implemented");
    }

    @Override
    public Iterable<Step> findAll() {
        throw new RepositoryException("Methode findAll step is not implemented");
    }

    @Override
    public Iterable<Step> findAllForBug(Integer id) {
        try (Session session = sessionFactory.openSession()) {
            List<Step> steps = new ArrayList<>();
            Transaction transaction = null;
            try {
                transaction = session.beginTransaction();
                Query query = session.createQuery("from Step where idbug = :idb",Step.class);
                query.setParameter("idb", id);
                steps = query.getResultList();
                transaction.commit();
                logger.trace("Found {} instance", steps );
                return steps;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return null;
    }


    @Override
    public Step save(Step step) throws ValidationException {
        logger.traceEntry("Saving step {} ", step);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                session.save(step);
                session.getTransaction().commit();
                logger.trace("Saved {} instance", step );
                return step;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return step;
    }

    @Override
    public Step update(Step step) {
        logger.traceEntry("updating step {}", step);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                Step b = session.load( Step.class, step.getId() );
                b.setOrder(step.getOrder());
                b.setText(step.getText());
                session.update(b);
                session.getTransaction().commit();
                logger.trace("Saved {} instance", step);
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return step;
    }

    @Override
    public Step delete(Integer integer) {
        logger.traceEntry("deleting step {}", integer);
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = null;
            try {
                session.beginTransaction();
                Step b = session.load( Step.class , integer);
                session.delete(b);
                session.getTransaction().commit();
                logger.trace("Saved {} instance", integer);
                return null;
            } catch (RuntimeException e) {
                logger.error(e);
                if (transaction != null)
                    transaction.rollback();
            }
        }
        return  null;
    }


}