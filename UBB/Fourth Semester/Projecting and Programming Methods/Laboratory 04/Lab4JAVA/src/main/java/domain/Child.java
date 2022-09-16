package domain;

public class Child extends Person {
    int age;

    /**
     * constructor of object of type Child
     *
     * @param firstName - string
     * @param lastName  - string
     * @param age       - integer
     */
    public Child(String firstName, String lastName, int age) {
        super(firstName, lastName);
        this.age = age;
    }

    /**
     * getter for ageGroup
     *
     * @return - string, represents the age group for the child
     */
    public String getAgeGroup() {
        if (this.age >= 6 && this.age <= 8)
            return "6-8 years";
        if (this.age >= 9 && this.age <= 11)
            return "9-11 years";
        else
            return "12-15 years";
    }

    /**
     * getter methode for age
     *
     * @return - integer, represents the age of the child
     */
    public int getAge() {
        return age;
    }

    /**
     * setter methode for age
     *
     * @param age - integer , represents the age of the child
     */
    public void setAge(int age) {
        this.age = age;
    }
}
