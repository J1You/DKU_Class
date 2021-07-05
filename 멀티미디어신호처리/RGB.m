% R, G, B separation
myImage = imread('C:\Users\Jiyun\OneDrive\바탕 화면\최지윤\사진\개발자.png');

% read each R, G, B as an array
redChannel = myImage(:, :, 1);
blueChannel = myImage(:, :, 2);
greenChannel = myImage(:, :, 3);

% Display
figure(1)
subplot(221);
imshow(myImage); 
title('Original');

subplot(222);
imshow(redChannel); 
title('Red component');

subplot(223);
imshow(blueChannel); 
title('Blue component');

subplot(224);
imshow(greenChannel); 
title('Green component');