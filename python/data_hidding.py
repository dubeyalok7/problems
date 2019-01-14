#!/usr/bin/python

class JustCounter:
    cnt = 11
    # underscore for making attribute private
    __secretCount  = 11

    def count(self):
        self.__secretCount += 1
        print self.__secretCount

counter = JustCounter()
counter.count()
counter.count()
print counter.cnt
#print counter.__secretCount
 
"Python protects those members by"
"internally changing the name to include the class name."
"You can access such attributes as object._className__attrName."
"If you would replace your last line as following, then it works for you"
 
print counter._JustCounter__secretCount

