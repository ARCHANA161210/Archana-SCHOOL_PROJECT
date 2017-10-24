package project_2;
import java.sql.*;
import java.util.ArrayList;

import javax.swing.*;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;

import net.proteanit.sql.DbUtils;

import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class optimal_querry {

	private JFrame frame;
	private JTextField textField;
	private JTextField oq;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					optimal_querry window = new optimal_querry();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	Connection Connection=null;
	private JTable table;
	private JScrollPane scrollPane;
	private JLabel lblEnterYourQuerry;
	private JLabel lblQuerryOutput;
	private JTextField p1;
	private JTextField c1;
	private JTextField t1;
	private JLabel lblTables;
	private JLabel lblCondtions;
	private JLabel lblProjections;
	private JTextField p2;
	private JTextField p3;
	private JTextField c2;
	private JTextField c3;
	private JTextField t2;
	private JTextField t3;
	private JTextField p4;
	private JTextField c4;
	private JTextField t4;
	private JLabel lblNewLabel_1;
	private JLabel lblNewLabel_2;
	/**
	 * Create the application.
	 */
	public optimal_querry() {
		initialize();
		Connection=sqliteConnection.dbConnector();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 894, 554);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(20, 57, 405, 53);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		JButton btnConvert = new JButton("convert");
		btnConvert.addActionListener(new ActionListener() {
                    private Object DbUtils;
			public void actionPerformed(ActionEvent e) {

				String querry,result;
				querry=textField.getText();
				 int position=0;

				ArrayList<String> conditions= new ArrayList<String>();
				ArrayList<String> conditions1= new ArrayList<String>();

				 String genral_list[]=querry.split(" ");
				 String temp_projection=genral_list[1];
				 String temp_tables=genral_list[3];
				 String temp_conditions[] = null;
				 int size_of_conditions;

				 String projection[]=temp_projection.split(",");
				 String tables[]=temp_tables.split(",");
				 
				 for (int j=0;j<genral_list.length; j++)
				 {
					conditions.add(genral_list[j]);
					conditions1.add(genral_list[j]);

				 }
				 
				 for(int i=0;i<conditions.size();i++)
				 {
					//System.out.println(conditions.get(i));
					if(conditions.get(i).equals("where"))
					{
						 position=i;
					}
				 }
				for (int v=0; v < position; v++)
				 {
					 conditions.remove(0);
				 }		 
				 for(int i=0;i<conditions.size();i++)
				 {
					 if(conditions.get(i).equals("and") || conditions.get(i).equals("or") || conditions.get(i).equals("where"))
					 {
						 conditions.remove(i);
					 } 
				 }
				 
				 if (tables.length==4)
				 {
					 t1.setText(tables[0]);
					 t2.setText(tables[1]);
					 t3.setText(tables[2]);
					 t4.setText(tables[3]);					 
				 }
				 else if (tables.length==3)
				 {
					 t1.setText(tables[0]);
					 t2.setText(tables[1]);
					 t3.setText(tables[2]);
				 }
				 else if (tables.length==2)
				 {
					 t1.setText(tables[0]);
					 t2.setText(tables[1]);
				 }
				 else 
				 {
					 t1.setText(tables[0]);
				 }
				 if (projection.length==4)
				 {
					 p1.setText(projection[0]);
					 p2.setText(projection[1]);
					 p3.setText(projection[2]);
					 p3.setText(projection[3]);
				 }
				 else if (projection.length==3)
				 {
					 p1.setText(projection[0]);
					 p2.setText(projection[1]);
					 p3.setText(projection[2]);
				 }
				 else if (projection.length==2)
				 {
					 p1.setText(projection[0]);
					 p2.setText(projection[1]);
				 }
				 else 
				 {
					 p1.setText(projection[0]);
				 }
			if(conditions1.size()>4)
			{	 
				 
				 if (conditions.size()==4)
				 {
				 c1.setText(conditions.get(0));
				 c2.setText(conditions.get(1));
                 c3.setText(conditions.get(2));
				 c4.setText(conditions.get(3));
				 }
				 else  if (conditions.size()==3)
				 {
				 c1.setText(conditions.get(0));
				 c2.setText(conditions.get(1));
                 c3.setText(conditions.get(2));
				 }
				 else  if (conditions.size()==2)
				 {
				 c1.setText(conditions.get(0));
				 c2.setText(conditions.get(1));
				 }
				 else
				 {
					 c1.setText(conditions.get(0));
				 }
				 
			}	
///***********************************************************************//////
if (querry.contains("and")||querry.contains("or"))
{
			try{
				if (querry.contains("and"))
				{
					if(conditions.get(0).contains(">")&&conditions.get(1).contains(">"))
					   {
						  int index1= (conditions.get(0)).indexOf(">");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf(">");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						  
               try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);

							  if (result2<=result1)
							  {   
								  if (conditions.size()==3)
							  {
									  String third=conditions.get(2);
								  String post_querry=(querry.substring(0,querry.indexOf(two)+two.length())).concat(third);
								  oq.setText(post_querry);
							  }
								  String post_querry=querry.substring(0,querry.indexOf(two)+two.length());
								  oq.setText(post_querry);
							  } 
							  else
							  {
								  String post_querry1;
							      int index_of_where=querry.indexOf("where");
							      String befor_where=querry.substring(0,index_of_where+6);
								  if (conditions.size()==3)
								  {
									  String third=" "+conditions.get(2);
									  post_querry1=(befor_where.concat(conditions.get(1))).concat(third);
									  oq.setText(post_querry1);
								  }
								  else
								  {
							      post_querry1=befor_where.concat(conditions.get(1));	
							      oq.setText(post_querry1);
								  }
							  }
						  }
						  else
						  {
							  oq.setText(querry);
						  }
               		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
        }
					
    }
  }
catch(Exception e2)
			{
	System.out.println("no greather than in or ");
			}
			
//////////////////////////////////////////////////////////////////////////////
			try{
				if (querry.contains("or "))
				{
					if(conditions.get(0).contains(">")&&conditions.get(1).contains(">"))
					   {
						  int index1= (conditions.get(0)).indexOf(">");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf(">");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						  
               try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);

							  if (result2>=result1)
							  { if (conditions.size()==3)
							     {
								  String third=conditions.get(2);
							  String post_querry=(querry.substring(0,querry.indexOf(two)+two.length())).concat(third);
							  oq.setText(post_querry);
						         }
								  String post_querry=querry.substring(0,querry.indexOf(two)+two.length());
								  oq.setText(post_querry);
							  } 
							  else
							  {
								  String post_querry1;
							      int index_of_where=querry.indexOf("where");
							      String befor_where=querry.substring(0,index_of_where+6);
								  if (conditions.size()==3)
								  {
									  String third=" "+conditions.get(2);
									  post_querry1=(befor_where.concat(conditions.get(1))).concat(third);
									  oq.setText(post_querry1);
								  }
								  else
								  {
							      post_querry1=befor_where.concat(conditions.get(1));	
							      oq.setText(post_querry1);
								  }
							  }
						  }
						  else
						  {
							  oq.setText(querry);
						  }
               		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
        }
					
    }
  }
catch(Exception e2)
			{
	System.out.println("no greather than in or ");
			}
//////////////////////////////////////////////////////////////////////////////
			//****************#################################333		
try{
	if (querry.contains("and"))
				{
					   if(conditions.get(0).contains("<")&&conditions.get(1).contains("<"))
					   {
                          int index1= (conditions.get(0)).indexOf("<");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf("<");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						
				try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);
                     		  if (result1<=result2)
							  { if (conditions.size()==3)
							  {
								  String third=" "+conditions.get(2);
							  String post_querry=(querry.substring(0,querry.indexOf(two)+two.length())).concat(third);
							  oq.setText(post_querry);
						  }
								  String post_querry=querry.substring(0,querry.indexOf(two)+two.length());
								  oq.setText(post_querry);
							  } 
							  else
							  {
								  String post_querry1;
							      int index_of_where=querry.indexOf("where");
							      String befor_where=querry.substring(0,index_of_where+6);
								  if (conditions.size()==3)
								  {
									  String third=" "+conditions.get(2);
									  post_querry1=(befor_where.concat(conditions.get(1))).concat(third);
									  oq.setText(post_querry1);
								  }
								  else
								  {
							      post_querry1=befor_where.concat(conditions.get(1));	
							      oq.setText(post_querry1);
								  }
							  }
						  }
						  else
						  {
							  oq.setText(querry);
						  }
}
catch(Exception e3)
{
	System.out.println("no and statement");
}
					   }
				}
			}
catch(Exception e2)
			{
	System.out.println("no and or ");
			}
			
//////////////////////////////////////////////////////////////////////////////
			try{
				if (querry.contains("or "))
				{
					if(conditions.get(0).contains("<")&&conditions.get(1).contains("<"))
					   {
						  int index1= (conditions.get(0)).indexOf("<");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf("<");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						  
               try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);

							  if (result2<=result1)
							  { if (conditions.size()==3)
							  {
								  String third=" "+conditions.get(2);
							  String post_querry=(querry.substring(0,querry.indexOf(two)+two.length())).concat(third);
							  oq.setText(post_querry);
						  }
								  String post_querry=querry.substring(0,querry.indexOf(two)+two.length());
								  oq.setText(post_querry);
							  } 
							  else
							  {
								  String post_querry1;
							      int index_of_where=querry.indexOf("where");
							      String befor_where=querry.substring(0,index_of_where+6);
								  if (conditions.size()==3)
								  {
									  String third=conditions.get(2);
									  post_querry1=(befor_where.concat(conditions.get(1))).concat(third);
									  oq.setText(post_querry1);
								  }
								  else
								  {
							      post_querry1=befor_where.concat(conditions.get(1));	
							      oq.setText(post_querry1);
								  }
							  }
						  }
						  else
						  {
							  oq.setText(querry);
						  }
               		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
        }
					
    }
  }
catch(Exception e2)
			{
	System.out.println("no and or ");
			}
			 // oq.setText(querry);
//#######################################################################################
			try{
				if (querry.contains("and "))
				{
					if(conditions.get(0).contains("<")&& conditions.get(1).contains(">"))
					   {
						  int index1= (conditions.get(0)).indexOf("<");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf(">");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
               try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);

							  if (result1>=result2)
							  {
								  oq.setText(querry);
							  } 
							  else
							  {
								  JOptionPane.showMessageDialog(null, "uppssss.......wrong querry!");
							  }
						  }
						 
               		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
        }
		//////////////////////////////////////////////////////////////////////////////////
					if(conditions.get(0).contains(">")&& conditions.get(1).contains("<"))
					   {
						  int index1= (conditions.get(0)).indexOf(">");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf("<");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						  
            try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);

							  if (result1<=result2)
							  {
								  oq.setText(querry);
							  } 
							  else
							  {
								  JOptionPane.showMessageDialog(null, "uppssss.......wrong querry!");
							  }
						  }
						 
            		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
     }
					/////////////////////////////////////////////////////////////
    }
  }
catch(Exception e2)
			{
	System.out.println("no and or ");
			}
//###########################################################################################
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
			try{
				if (querry.contains("or"))
				{
					if(conditions.get(0).contains("<")&& conditions.get(1).contains(">"))
					   {
						  int index1= (conditions.get(0)).indexOf("<");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf(">");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						  
               try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);

								  oq.setText(querry);
							  
						  }
						 
               		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
        }
		//////////////////////////////////////////////////////////////////////////////////
					if(conditions.get(0).contains(">")&& conditions.get(1).contains("<"))
					   {
						  int index1= (conditions.get(0)).indexOf(">");
						  String one=conditions.get(0).substring(0,index1);
						  String two=conditions.get(0).substring(index1+1);
						  
						  int index2= (conditions.get(1)).indexOf("<");
						  String one1=conditions.get(1).substring(0,index2);
						  String two1=conditions.get(1).substring(index2+1);
						  
            try{
						  if (one1.equals(one))
						  {
							  int result1=Integer.parseInt(two);
							  int result2=Integer.parseInt(two1);
                              oq.setText(querry);
						
						  }
						 
            		}
					catch(Exception e3)
					{
						System.out.println("no or statement");
					}
     }
					/////////////////////////////////////////////////////////////
    }
  }
catch(Exception e2)
			{
	System.out.println("no and or ");
			}
}
else
{
	if(querry.contains("state"))
{
    oq.setText(querry);
}
	else 
	{
		oq.setText(querry);
	}
}
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
			String new_querry,redundancy_condition,trash,new_querry1,condition_1;
			int or_index=0,where_index=0,and_index=0;
			try{
				PreparedStatement pst= Connection.prepareStatement(querry);
				ResultSet rs=pst.executeQuery();
				table.setModel(((net.proteanit.sql.DbUtils) DbUtils).resultSetToTableModel(rs));
					
					rs.close();
					pst.close();
			}
				catch(Exception e1)
				{
					JOptionPane.showMessageDialog(null, "Database doesn't contain this table....please try again.!");
				}
			}
			
		});
		btnConvert.setBounds(336, 121, 89, 23);
		frame.getContentPane().add(btnConvert);
		
		oq = new JTextField();
		oq.setBounds(109, 210, 524, 53);
		frame.getContentPane().add(oq);
		oq.setColumns(10);
		
		JLabel lblOptimalquerry = new JLabel("optimal_querry");
		lblOptimalquerry.setBounds(20, 229, 89, 14);
		frame.getContentPane().add(lblOptimalquerry);
		
		scrollPane = new JScrollPane();
		scrollPane.setBounds(432, 57, 385, 142);
		frame.getContentPane().add(scrollPane);
		
		table = new JTable();
		scrollPane.setViewportView(table);
		
		lblEnterYourQuerry = new JLabel("Enter your querry here");
		lblEnterYourQuerry.setBounds(25, 26, 209, 14);
		frame.getContentPane().add(lblEnterYourQuerry);
		
		lblQuerryOutput = new JLabel("querry output");
		lblQuerryOutput.setBounds(434, 26, 94, 14);
		frame.getContentPane().add(lblQuerryOutput);
		
		p1 = new JTextField();
		p1.setBounds(108, 293, 104, 20);
		frame.getContentPane().add(p1);
		p1.setColumns(10);
		
		c1 = new JTextField();
		c1.setBounds(109, 324, 104, 20);
		frame.getContentPane().add(c1);
		c1.setColumns(10);
		
		t1 = new JTextField();
		t1.setBounds(104, 355, 110, 20);
		frame.getContentPane().add(t1);
		t1.setColumns(10);
		
		lblTables = new JLabel("Level 1 .............tables");
		lblTables.setBounds(576, 358, 188, 14);
		frame.getContentPane().add(lblTables);
		
		lblCondtions = new JLabel("Level 2............condtions");
		lblCondtions.setBounds(576, 324, 188, 14);
		frame.getContentPane().add(lblCondtions);
		
		lblProjections = new JLabel("Level 3 ...............projections");
		lblProjections.setBounds(576, 296, 209, 14);
		frame.getContentPane().add(lblProjections);
		
		p2 = new JTextField();
		p2.setBounds(234, 293, 86, 20);
		frame.getContentPane().add(p2);
		p2.setColumns(10);
		
		p3 = new JTextField();
		p3.setText("");
		p3.setBounds(351, 293, 86, 20);
		frame.getContentPane().add(p3);
		p3.setColumns(10);
		
		c2 = new JTextField();
		c2.setText("");
		c2.setBounds(234, 324, 86, 20);
		frame.getContentPane().add(c2);
		c2.setColumns(10);
		
		c3 = new JTextField();
		c3.setBounds(351, 324, 86, 20);
		frame.getContentPane().add(c3);
		c3.setColumns(10);
		
		t2 = new JTextField();
		t2.setBounds(234, 355, 86, 20);
		frame.getContentPane().add(t2);
		t2.setColumns(10);
		
		t3 = new JTextField();
		t3.setBounds(351, 355, 86, 20);
		frame.getContentPane().add(t3);
		t3.setColumns(10);
		
		p4 = new JTextField();
		p4.setBounds(459, 293, 86, 20);
		frame.getContentPane().add(p4);
		p4.setColumns(10);
		
		c4 = new JTextField();
		c4.setBounds(459, 324, 86, 20);
		frame.getContentPane().add(c4);
		c4.setColumns(10);
		
		t4 = new JTextField();
		t4.setBounds(469, 355, 86, 20);
		frame.getContentPane().add(t4);
		t4.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("* treat as every attribute in tables");
		lblNewLabel.setBounds(41, 470, 384, 14);
		frame.getContentPane().add(lblNewLabel);
		
		lblNewLabel_1 = new JLabel("select description,qty_sold,date_sold,cost from stock,sales where cost>199 and cost>299 and sales.prodno=stock.prodno");
		lblNewLabel_1.setBounds(41, 402, 598, 57);
		frame.getContentPane().add(lblNewLabel_1);
		
		lblNewLabel_2 = new JLabel("Try this querry");
		lblNewLabel_2.setBounds(23, 402, 110, 14);
		frame.getContentPane().add(lblNewLabel_2);
		
		
	}
}
