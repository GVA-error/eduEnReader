#!/bin/bash

cd /home/system/kaldi/egs/apiai_decode/s5/
/home/system/kaldi/egs/apiai_decode/s5/recognize-wav.sh $@ > tmp 2>&1 && 
grep -v "LOG" tmp |
grep -i ".wav" | 
grep -v "info" |
grep -v "//" 

