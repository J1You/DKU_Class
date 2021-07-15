% Sound synthesis for 1 octave

fs = 8000;
dur = 1;
tt = 0:1/fs:dur;
freq = [264 297 330 352 396 440 495 528];

% initialize the output vector
xx = zeros(1, 8*fs+length(freq));

n1 = 1;
for kk = 1:length(freq)
    n2 = n1 + length(tt)-1;
    xx(n1:n2) = xx(m1:n2) + cos(2*pi*freq(kk)*tt);
    n1 = n2 + 1;
end

soundsc(xx, fs) % play sound