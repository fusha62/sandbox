function [ out_data ] = gen_sin( freq,Fs,Samples )
%   Generate sine wave
%   
%   input args
%   freq     : frequency
%   Fs       : Sampling rate
%   Samples  : number of sumples

t=0:1/Fs:((Samples-1)/Fs);
out_tmp=A*sin(2*pi*freq*t)+B*cos(2*pi*freq*t);
out_data=out_tmp';

end

