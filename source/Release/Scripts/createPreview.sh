#!/bin/bash
# 
# $1 - имя файла
# $2 - время кадра в формате 00:00:00
# $3 - имя картинки для превью

ffmpeg -ss $2 -i $1 -f image2 -vframes 1 $3

echo 0