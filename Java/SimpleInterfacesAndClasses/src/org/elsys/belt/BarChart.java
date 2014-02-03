package org.elsys.belt;

public class BarChart extends BarAndPie implements KaloyanPavlov3{

	public BarChart(int val1, int val2) {
		super(val1, val2);
	}

	@Override
	public void kaloyan() {
		setVal2(getVal2() + (getVal1()*2) );		
	}	
}
