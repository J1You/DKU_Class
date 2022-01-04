% signal with gaussian noise

n = 0:100;
x = sin(0.04*pi*n);
w = 0.3*randn(size(n));
y = x + w;

figure(1)
subplot(311)
stem(n,x);
title('x[n]');
subplot(312)
stem(n,w);
title('gaussian noise');
subplot(313)
stem(n,y);
title('noisy signal');
