from m5.params import *
from m5.SimObject import SimObject

class Hello(SimObject):
    type = 'Hello'
    cxx_header = "tutorial/hello.hh"
