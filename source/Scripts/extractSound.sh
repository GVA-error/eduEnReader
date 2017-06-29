#!/bin/bash

ffmpeg -i $1 -vn -ar 16000 -ac 1 -ab 16 -f wav $2
