import random
import math
import numpy as np

#Number of roulette wheel spins
MAX=10000000 

#temp
count=0

#First spin
rnd=random.randrange(0,2)

#Number of times same color has occured (sequence length)
seq=1

#Counting hits for each color (Green is ignored)
vals={0:0,1:0}

#Storing sequence lengths
seqs={}

print "Simulating ",MAX,"rounds of roulette"

while count<MAX:
    count+=1     
    #Count black/red
    vals[rnd]+=1
    #Remember this rounds result
    prevRnd=rnd
    #Roll again
    rnd=random.randrange(0,2)
    #If it's the same, sequence lenght increased
    if rnd==prevRnd:
        seq+=1
    else: #Otherwise, the sequence was done, and this is a new one
        seqs[seq]=1 if not seqs.has_key(seq) else seqs[seq]+1
        seq=1
        
print "\nR E S U L T S:\n"
print "Len.\tCount"
for k in seqs.keys():
    print k,"\t",seqs[k]

#Plotting. Comment out this section if you don't have (want)  matplotlib
import matplotlib.pyplot as plt
plt.ion()

#Set up plot
plt.title("Sequence lengths")
plt.ylabel("Number of sequences")
plt.xlabel("Length")
plt.clf()

#Plot collected data
plt.plot(seqs.values(),'ob--')
plt.draw()
