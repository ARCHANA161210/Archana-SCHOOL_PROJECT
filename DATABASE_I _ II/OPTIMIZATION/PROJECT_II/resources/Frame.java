package project_2;
import java.awt.GridLayout;

import javax.swing.JFrame;

import com.sun.glass.ui.Screen;
public class Frame extends JFrame {
	Screen s;
	public Frame(){
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(800,800);
		setResizable(false);
		setTitle("Optimized tree");
		init();
	}

	public void init()
	{
		setLocationRelativeTo(null);
		setLayout(new GridLayout(1,1,0,0));
		//s= new Screen();
		//add(s);
		setVisible(true);
	}
	public static void main(String[] args)
	{
		new Frame();
	}
}
