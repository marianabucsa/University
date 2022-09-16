package com.athleticscompetiton.service;

import com.athleticscompetiton.domain.Child;
import com.athleticscompetiton.domain.Enrollment;
import com.athleticscompetiton.domain.Round;
import com.athleticscompetiton.domain.User;
import com.athleticscompetiton.repository.ChildrenInterface;
import com.athleticscompetiton.repository.EnrollmentsInterface;
import com.athleticscompetiton.repository.RoundsInterface;
import com.athleticscompetiton.repository.UsersInterface;
import utils.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.StreamSupport;

public class Service {
    private UsersInterface users_repo;
    private RoundsInterface rounds_repo;
    private ChildrenInterface children_repo;
    private EnrollmentsInterface enrollments_repo;

    public Service(UsersInterface users, RoundsInterface rounds, ChildrenInterface children, EnrollmentsInterface enrollments)
    {
        this.users_repo = users;
        this.rounds_repo = rounds;
        this.children_repo = children;
        this.enrollments_repo = enrollments;
    }

    public User findUser(String username, String password)
    {
        return users_repo.findUser(username, password);
    }

    public long getNrChildrenForRound(String name)
    {
        Round round = rounds_repo.findOneName(name);
        return StreamSupport.stream(enrollments_repo.findChildrenForRound(round.getId()).spliterator(),false).count();
    }

    public Iterable<Round> findAllRounds()
    {
        return rounds_repo.findAll();
    }

    public Enrollment FindEnrollmentByChildAndRound(String firstname, String lastname, String roundName)
    {
        Child child = children_repo.findOneName(firstname, lastname);
        Round round = rounds_repo.findOneName(roundName);
        return enrollments_repo.findOne(new Pair(child.getId(), round.getId()));
    }

    public void SaveChild(String firstname, String lastname, int age)
    {
        Child child = new Child(firstname, lastname, age);
        children_repo.save(child);
    }

    public Iterable<Child> findChildrenForRound(String roundName)
    {
        return enrollments_repo.findChildrenForRound(rounds_repo.findOneName(roundName).getId());
    }

    public Child FindChildByName(String firstname, String lastname)
    {
        return children_repo.findOneName(firstname, lastname);
    }

    public Iterable<Child> FindChildrenByAgeGroup(String ageGroup)
    {
        Iterable<Child> children = children_repo.findAll();
        List<Child> e = new ArrayList<Child>();
        for(Child child :  children)
            if (child.getAgeGroup() == ageGroup)
                 e.add(child);
        return e;
    }

    public Enrollment SaveEnrollment(String firstname, String lastname, int age, String roundName)
    {
        Child child = children_repo.findOneName(firstname, lastname);
        Round round = rounds_repo.findOneName(roundName);
        Enrollment enrollment = new Enrollment(child, round);
        return enrollments_repo.save(enrollment);
    }

    public long FindNumberOfEnrollmentsForChild(String firstname, String lastname)
    {
        Child child = children_repo.findOneName(firstname, lastname);
        Iterable<Round> roundsForChild = enrollments_repo.findRoundsForChild(child.getId());
        return StreamSupport.stream(roundsForChild.spliterator(),false).count();
    }
}
