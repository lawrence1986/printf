#!/bin/bash

# Set the value of IO_SIZE
IO_SIZE=IO_SIZE

# Use find command to locate all the files in the printf repository
# and run sed to replace "IO_SIZE" with the value of IO_SIZE in each file
find printf -type f -exec sed -i "s/IO_SIZE/$IO_SIZE/g" {} \;

# Open Vim to check the changes
vim -R $(grep -rl "IO_SIZE" printf)
