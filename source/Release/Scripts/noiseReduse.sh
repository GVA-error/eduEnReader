#!/bin/bash

#sox -t raw -r 16000 -e signed-int -c 1 -b 16 $1 discard.wav \
#	stat lowpass 300 highpass 3400 norm compand 0.05,0.2 6:-54,-84,-36,-36,-24,-24,0,-12 0 -84 0.2 \
#	vad -T 0.25 -p 0.2 -t 5 stat
#
#sox -t raw -r 16000 -e signed-int -c 1 -b 16 $1 discard.wav trim 10 5 noiseprof noise.profile
#
#sox -t raw -r 16000 -e signed-int -c 1 -b 16 $1 -C 80 ${2} \
#	noisered noise.profile 0.1 \
#	lowpass 300 highpass 3400 norm compand 0.05,0.2 6:-54,-84,-36,-36,-24,-24,0,-12 0 -84 0.2 \
#	vad -T 0.25 -p 0.2 -t 5 reverse vad -T 0.25 -p 0.25 -t 5 reverse \
#	norm 1.0 rate 16000 stat 

# 1 - input file
# 2 - output file
# 3 - noise file

sox "$1" "$2" lowpass 80 highpass 3200 norm compand 0.05,0.2 6:-54,-84,-36,-36,-24,-24,0,-12 0 -84 0.2
