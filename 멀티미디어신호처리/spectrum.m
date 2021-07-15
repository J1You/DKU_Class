% Sampling frequency Fs=8000Hz
% Generate two sinusoid with frequency 1000Hz, and 5000Hz

% digital conversion with sampling frequency
fs = 8000;
t = 0:1/fs:1;
x1 = 3*sin(2*pi*1000*t);
x2 = 5*sin(2*pi*5000*t);

%Frequency spectrum 
y1 = abs(fft(x1, fs));
y2 = abs(fft(x2, fs));

% time-domain plot
figure(1)
subplot(321);
plot(t(1:100), x1(1:100));
xlabel('time');
ylabel('amplitude');
title('x1(t)=3sin(2pi(1000)t)');

subplot(322);
plot(t(1:100), x2(1:100));
xlabel('time');
ylabel('amplitude');
title('x2(t)=5sin(2pi(5000)t)');

% frequency spectrum plot (fi = 1:1:fs/2)
fi = 1:1:fs/2;
subplot(323);
plot(fi, y1(1:fs/2));
xlabel('frequency');
ylabel('magnitude');
title('frequency spectrum for x1');

subplot(324);
plot(fi, y2(1:fs/2));
xlabel('frequency');
ylabel('magnitude');
title('frequency spectrum for x2');

% frequency spectrum plot (fi = 1:1:fs)
fi = 1:1:fs;
subplot(325);
plot(fi, y1(1:fs));
xlabel('frequency');
ylabel('magnitude');
title('frequency spectrum for x1');

subplot(326);
plot(fi, y2(1:fs));
xlabel('frequency');
ylabel('magnitude');
title('frequency spectrum for x2');