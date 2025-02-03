#!/bin/sh

set -xe

:> file1

echo "hello world" > file1

cc -o copy copy.c

./copy file1 file2
