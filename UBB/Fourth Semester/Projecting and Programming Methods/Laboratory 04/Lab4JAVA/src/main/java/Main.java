import domain.Child;
import domain.Enrollment;
import domain.Round;
import domain.User;
import repository.ChildrenDBRepo;
import repository.EnrollmentsDBRepo;
import repository.RoundsDBRepo;
import repository.UsersDBRepo;
import utils.Pair;

import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class Main {
    public static void main(String[] args) {

        Properties props=new Properties();
        try {
            props.load(new FileReader("bd.config"));
        } catch (IOException e) {
            System.out.println("Cannot find bd.config "+e);
        }

        //ChildrenDBRepo childrenDBRepo=new ChildrenDBRepo(props);
        //Child child = new Child("gggt","jjjj",9);
        //childrenDBRepo.save(child);
        //System.out.println(childrenDBRepo.findOne(1L).getFirstName());
        //System.out.println(childrenDBRepo.findOneName("gggt","jjjj").getAge());
        /*for(Child child1: childrenDBRepo.findAll()){
            System.out.println(child1.getAge());
        }*/
        /*
        Child child1= new Child("ttt","jjj",8);
        child1.setId(1L);
        childrenDBRepo.update(child1);
         */
        //childrenDBRepo.delete(3L);

        /*RoundsDBRepo roundsDBRepo=new RoundsDBRepo(props);
        Round round = new Round("gggt");*/
        //roundsDBRepo.save(round);
       // System.out.println(roundsDBRepo.findOne(1L).getName());
        //System.out.println(roundsDBRepo.findOneName("gggt").getName());
        /*for(Round round1: roundsDBRepo.findAll()){
            System.out.println(round1.getName());
        }*/
        /*Round round1= new Round("ttt");
        round1.setId(1L);
        roundsDBRepo.update(round1);*/
        //roundsDBRepo.delete(1L);

        EnrollmentsDBRepo enrollmentsDBRepo= new EnrollmentsDBRepo(props);
       // Enrollment enrollment= enrollmentsDBRepo.findOne(new Pair(5L,2L));
       // System.out.println(enrollment.getRound().getName());
        /*for(Round round1: enrollmentsDBRepo.findRoundsForChild(5L)) {
            System.out.println(round1.getId());
        }*/
        /*Child child = new Child("c","v",5);
        child.setId(6L);
        Round round = new Round("num");
        round.setId(3L);
        //enrollmentsDBRepo.save(new Enrollment(child,round));
        Enrollment en = new Enrollment(child,round);
        en.setId(2L);
        enrollmentsDBRepo.delete(new Pair(5L,2L));*/
    }
}
