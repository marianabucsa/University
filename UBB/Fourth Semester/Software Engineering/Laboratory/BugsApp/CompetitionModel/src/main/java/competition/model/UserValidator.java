package competition.model;

import competition.model.ValidationException;
import competition.model.Validator;

public class UserValidator implements Validator<User> {
    @Override
    public void validate(User entity) {
        String err = "";
        if (entity.getId().equals(""))
            err += "Username nu poate fi vid!";
        if (entity.getPassword().equals(""))
            err += "Parola nu poate fi vida";
        if (!err.equals(""))
            throw new ValidationException(err);
    }
}