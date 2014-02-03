z = input("Enter range: ");
x = -z:0.01:z; 
y = cos(x).*sin(x);
plot(x,y)
