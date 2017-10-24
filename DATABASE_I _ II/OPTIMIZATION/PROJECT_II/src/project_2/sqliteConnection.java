package project_2;

import java.sql.*;
import javax.swing.*;
  public class sqliteConnection {

	   Connection conn=null;
	public static Connection dbConnector()
	{
		try{
			Class.forName("org.sqlite.JDBC");
			Connection conn=DriverManager.getConnection("jdbc:sqlite:C:\\Users\\archana\\Desktop\\New folder (2)\\db_2 try\\src\\project_2\\1.db");
		    JOptionPane.showMessageDialog(null, "connection successful");
			return conn;
		}
		
		catch(Exception e1)
		{
			JOptionPane.showMessageDialog(null, e1);
			return null;
		}
	}
	
}

/*select description,qty_sold,date_sold,cost
 *  from stock,sales
 *   where cost>199 and cost>299 and sales.prodno=stock.prodno
 *   
  */