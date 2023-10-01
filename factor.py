#!/usr/bin/env python3
import sys

text_file = open(sys.argv[1],'r')
def factorize(line):
    num = int(line)
    i = 2
    while(i < num):
        
        if num % i == 0:
            print("{}={}*{}".format(num, int(num/i), i))
            break
        i=i+1


while(1):
    
        line = text_file.readline()
        if  line == "":
            
            break
        factorize(line)
        
        

	
