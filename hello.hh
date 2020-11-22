#ifndef __TUTORIAL_HELLO_HH__
#define __TUTORIAL_HELLO_HH__

#include "params/Hello.hh"
#include "sim/sim_object.hh"

class Hello : public SimObject
{
  public:
    Hello(HelloParams *p);
    void startup();

  private:
    void processEvent();

    EventFunctionWrapper event;

};

#endif // __TUTORIAL_HELLO_HH__
