package org.elsys.belt;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		int counter = 0;
		LinkedList<BarAndPie> itemList = 
				new LinkedList<BarAndPie>();
		 BufferedReader reader
		   = new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{
			String value = reader.readLine(); 
			if(!value.equals("a"))
			{
				if(counter%2 == 0)
				{
					itemList.add(new PieChart(Integer.parseInt(value)*2,Integer.parseInt(value)*4));
				}
				else
				{
					itemList.add(new BarChart(Integer.parseInt(value)*3,Integer.parseInt(value)*5));
				}
				counter++;				
			}
			else
			{
				break;
			}
		}
		
		for(BarAndPie bap : itemList)
		{
			System.out.println(bap.getVal1());
			System.out.println(bap.getVal2());
		}
		
		for(BarAndPie pie : itemList)
		{
			if(pie.getClass().getName() == "org.elsys.belt.BarChart")
			{
				((BarChart) pie).kaloyan();
			}
		}
		
		for(BarAndPie bap : itemList)
		{
			System.out.println(bap.getVal1() + bap.getVal2());
		}
	}
}
