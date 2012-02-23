function out = gen_signal(A,B,freq,Fs,Samples);
% A    = Amplitude for sine;
% B    = Amplitude for cosine;
% freq = frequency;
% FS   = Sampling frequency;
% Time = Signal time;

t=0:1/Fs:((Samples-1)/Fs);
out_tmp=A*sin(2*pi*freq*t)+B*cos(2*pi*freq*t);
out=out_tmp';

%% Old Codes %%
% out=zeros(1,Fs*Time);
% for i=1:length(out);
%     out(i)=A*sin(2*pi*freq*(i-1)/Fs)+B*cos(2*pi*freq*(i-1)/Fs);
% end;
