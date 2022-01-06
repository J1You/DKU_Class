function [mean, stdev] = stat(x)

% Calculate mean and standard deviation of vector x

[m n] = size(x);

mean = sum(x)/n;

stdev = sqrt(sum(x.^2)/m - mean.^2);
