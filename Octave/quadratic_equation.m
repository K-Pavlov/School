a = input("Enter a: ");
b = input("Enter b: ");
c = input("Enter c: ");
p2 = [a,b,c];
r2 = roots(p2);
if(isreal(r2))
	disp("x1 = "), disp(r2(1));
	disp("x2 = "), disp(r2(2));
else
	disp("No real roots");
endif



