disp("Max 30 or it gets really ugly.");
disp("If range x is 10 then x is from -10 to 10, etc");
z = input("Enter range x: ");
k = input("Enter range y: ");
x = -z:z; 
t = -k:k;
y = cos(t)' *sin(x);
mesh(x, t, y); 
