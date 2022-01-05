% sinusoidal signal 
n = 0:20;
x = 2*cos(0.2*pi*n+pi/3) + 2*sin(0.2*pi*n);

% complex exponential
n = 0:20;
y = exp((3+2*i)*n);

figure(1)
subplot(212)
stem(n,x)
subplot(222)
stem(n, abs(y))