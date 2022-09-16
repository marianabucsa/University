import model.ComputerRepairRequest;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class ComputerRepairRequestTest {
    @Test
    @DisplayName ("Test1")
    public void testExample(){
        ComputerRepairRequest computerRepairRequest= new ComputerRepairRequest();
        assertEquals("",computerRepairRequest.getOwnerAddress());
        assertEquals("",computerRepairRequest.getOwnerName());
    }
    @Test
    @DisplayName ("Test2")
    public void testExample2(){
        ComputerRepairRequest computerRepairRequest= new ComputerRepairRequest(1,"name","address","phoneNumber","model","date","problemDescription");
        assertEquals("address",computerRepairRequest.getOwnerAddress());
        assertEquals("name",computerRepairRequest.getOwnerName());
        assertEquals("date",computerRepairRequest.getDate());
        assertEquals(1,computerRepairRequest.getID());
        assertEquals("phoneNumber",computerRepairRequest.getPhoneNumber());

    }

      
}
