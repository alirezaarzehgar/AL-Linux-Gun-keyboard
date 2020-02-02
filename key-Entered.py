#!/usr/bin/python3

from pynput import mouse, keyboard
import sys

mouse.Controller().position = ( int(sys.argv[3]), int(sys.argv[4]) )
m = mouse.Controller()

m.click( mouse.Button.left , 1 )

m = keyboard.Controller()

f = open(sys.argv[1], 'r')
str = ' '
i = 0
while i < int(sys.argv[2]):
        str = f.read()
        m.type (str)
        if str == '':
                f.close()
        f = open(sys.argv[1], 'r')
        i+=1

