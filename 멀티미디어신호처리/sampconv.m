x = [-1 3 1 4 0 2]; % input
h = [2 6 0 3 4 1]; % impulse response

y = conv(h, x); % output

z = [zeros(1, 3), y, zeros(1, 3)];
n = -8:8;
stem(n, z);
title('convolution output');