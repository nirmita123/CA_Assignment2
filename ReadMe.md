# Inverse Matrix SimObject

In this assignment, we create a SimObject to find inverse of a matrix. We use Debug Flags MATRIX and RESULT to print the given matrix. For this assignment we took a 3x3 matrix: {{-7,-10,4}, {12,-2,-8}, {1,5,6}}.

## Calculation of inverse of a matrix using SimObject

Using the determinant and adjacency matrix we further get the inverse matrix, in "hello.cc" file. 

inverse_mat=1/determinant_of_A*adjacency_matrix

For calculating determinant
```bash
for(i = 0; i < 3; i++)
   determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
```
For calculating inverse
```bash
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++)
          inv[i][j]=((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
        }
```
## Header file

In the header file of our program, "hello.hh", we add the private function "processEvent()", which calculates the inverse matrix along with an "EventFunctionWrapper". And SimObject ("Hello" and "startup()" under the public access modifier.

```c++
public:
    Hello(HelloParams *p);
    void startup();

private:
    void processEvent();
    EventFunctionWrapper event;
```

## Python file for Simulation

Since, each SimObject has its Python class that describes the parameters of a SimObject, which can be controlled from the Python configuration files. However, for our inverse matrix assignment we do not need to assign any parameter thus we simply declare a class for the"Hello" SimObject. 

## SConscript

For the files to be parsed and compiled by the build system we define a SConscript. In addition to importing all the files, we add our Debug Flags here. I added the debug flag "MATRIX" and "RESULT".

```python
Import('*')

SimObject('Hello.py')
Source('hello.cc')

DebugFlag('HelloDebug')
DebugFlag('MATRIX','It is used to display the size of the matrix, the size of the given matrix is 3x3')
DebugFlag('RESULT','It displays the result of the inverse matrix of size of the given MATRIX. It is calculated using the determinant of the matrix')
```
## Config Script 

This script (in python) is used to instantiate and simulate our SimObject ("Hello") using root. Since the assignment did not require use of CPUs and Caches a system object was not required.


```python
root = Root(full_system = False)

root.hello = Hello()

m5.instantiate()

print ("Beginning simulation!")
exit_event = m5.simulate()
print ('Exiting @ tick %i because %s' % (m5.curTick(), exit_event.getCause()))
```
## Output
![alt text](Output.png?raw=true)

### This assignment can be accessed on github

