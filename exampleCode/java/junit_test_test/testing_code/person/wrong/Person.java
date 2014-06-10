package person.wrong;

import person.BasePerson;

public class Person extends BasePerson
{

	public Person(String fname, String lname)
	{
		super(fname, lname);
		
	}

	/* (non-Javadoc)
	 * @see person.BasePerson#setLname(java.lang.String)
	 */
	@Override
	public void setLname(String lname)
	{
		super.setFname(lname);
	}

}
