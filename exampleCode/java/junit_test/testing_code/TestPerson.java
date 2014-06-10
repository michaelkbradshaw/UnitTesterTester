import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

//import test1.wrong.functions.Person;
//import TEST_LIB;

public class TestPerson
{	
	Person A;
	@Before
	public void setUp() throws Exception
	{
		A = new Person("fred","Flinstone");
			
	}

	@Test
	public void testGetFname()
	{
		assertEquals("fred",A.getFname());
	}

	@Test
	public void testSetFname()
	{
		A.setFname("sam");
		assertEquals("sam",A.getFname());
	}

	@Test
	public void testGetLname()
	{
		assertEquals("Flinstone",A.getLname());
	}

	@Test
	public void testSetLname()
	{
		A.setLname("Tony");
		assertEquals("Tony",A.getLname());
	}

}
