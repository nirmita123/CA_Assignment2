##include "base/trace.hh"
#include "debug/MATRIX.hh"
#include "debug/RESULT.hh"
#include "debug/HelloDebug.hh"
#include "tutorial/hello.hh"
#include <iostream>

using namespace std;
Hello::Hello(HelloParams *params) : SimObject(params), event([this]{processEvent();}, name())
{
   DPRINTF(HelloDebug, "created simObject\n");
}
void Hello::processEvent()
{
   // std::cout << "Hello World! From a SimObject! I'm making inverse matrix" << std::endl;
    DPRINTF(HelloDebug, "Hello World! From a SimObject! I'm making inverse matrix \n");
    int i, j;
    float mat[3][3]={{-7,-10,4}, {12,-2,-8}, {1,5,6}};

    float inv[3][3];
    /*printf("\nGiven matrix is:");
    for(i = 0; i < 3; i++){
        std::cout<<"\n";
        for(j = 0; j < 3; j++)
          std::cout<<mat[i][j]<<"\t";
    }*/
    float determinant = 0;
    //finding determinant
    for(i = 0; i < 3; i++)
       determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    //std::cout<<"\n\ndeterminant: "<<determinant;
    //std::cout<<"\n\nInverse of matrix is: \n";
    for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++)
           inv[i][j]=((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
                  //std::cout<<"\n";
                   }
   DPRINTF(MATRIX,  "Given Matrix: \n %f %f %f \n %f %f %f \n %f %f %f \n\n", mat[0][0],mat[0][1],mat[0][2],mat[1][0],mat[1][1],mat[1][2],mat[2][0],mat[2][1], mat[2][2]);
   DPRINTF(RESULT, "Resultant inverse Matrix:  \n %f %f %f \n %f %f %f \n %f %f %f \n\n", inv[0][0],inv[0][1],inv[0][2],inv[1][0],inv[1][1],inv[1][2],inv[2][0],inv[2][1], inv[2][2]);


       //dprintf(MATRIX,"newtry");

}
void
Hello::startup()
{
   schedule(event, 1000);
}

Hello*
HelloParams::create()
{
   return new Hello(this);
}
                                
