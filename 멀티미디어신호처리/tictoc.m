x = [2 1 -1 0 5]; % input
h = [1 0 7 0 3]; % impulse response

tic
y = conv(h, x); % output
toc

z = [zeros(1, 2), y, zeros(1, 2)];
n = -2:1:7;
stem(n, z);
title('convolution output')