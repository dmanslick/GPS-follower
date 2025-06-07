#ifndef Updater_H
#define Updater_H

#include "Updatable.h"

class Updater {
  public:
    Updater();
    void run();
    void registerUpdatable(Updatable* updatable);
  private:
    Updatable* updatables[20];
    int count;
};

#endif