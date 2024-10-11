/*
For statues = [6, 2, 3, 8], the output should be
makeArrayConsecutive2(statues) = 3.

Ratiorg needs statues of sizes 4, 5 and 7.

verilen dizinin tam sıralı olması için kaç eleman gerekir

*/

def makeArrayConsecutive2(statues):
    """
    statues.sort()
    s=0
    for i in range(0,len(statues)-1):
        temp = statues[i+1]-statues[i]
        if( temp !=1 ):
            s+=temp-1
    return s
    """
    return max(statues) - min(statues) - len(statues) + 1