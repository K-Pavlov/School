a = input("Enter a: ");
b = input("Enter b: ");
c = input("Enter c: ");
p2 = [a,b,c];
xcoor = -286:200;
xcoor = xcoor*pi/180;
plot(xcoor,polyval(p2,xcoor));

