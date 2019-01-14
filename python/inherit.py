#!/usr/bin/python

class Parent:       #define parent class
    parentAttr = 100

    def __init(self):
        print "Calling parent constructor"

    def parentMethod(self):
        print "Calling parent method"

    def setAttr(self, attr):
        Parent.parentAttr = attr

    def getAttr(self):
        print "Parent attribute :", Parent.parentAttr

class SParent:
    def __init__(self):
        print "SParent constructor"

    def SParentMethod(self):
        print "SParent method"

class Child(Parent, SParent): #define child class
    def __init__(self):
        print "calling child constructor"

    def childMethod(self):
        print "Calling child method"

c = Child()         #instance of child
c.childMethod()     #child calls its method
c.parentMethod()    #calls parent's method
c.setAttr(200)      #again call parent's method
c.getAttr()         #again call parent's method
c.SParentMethod()   #calling second parent method

