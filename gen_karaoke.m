% Generate Karaoke Sound

[data,fs] = wavread('./input.wav');
bgm=data-circshift(data,[0,1]);
voc=data-bgm;
wavwrite(bgm,fs,'./out_bgm.wav');
wavwrite(voc,fs,'./out_voc.wav');