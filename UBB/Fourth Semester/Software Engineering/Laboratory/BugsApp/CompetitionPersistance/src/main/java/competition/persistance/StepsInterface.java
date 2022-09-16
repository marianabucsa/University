package competition.persistance;

import competition.model.Step;

public interface StepsInterface extends Repository<Integer, Step> {
    public Iterable<Step> findAllForBug(Integer id);
}
