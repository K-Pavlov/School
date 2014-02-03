a = input("Enter a: ");
b = input("Enter b: ");
c = input("Enter c: ");
d = input("Enter d: ");
p = [a,b,c,d];
xcoor = -286:200;
xcoor = xcoor*pi/180;
plot(xcoor,polyval(p,xcoor));
