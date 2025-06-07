#include "Updater.h"

Updater::Updater() {
  this->count = 0;
}

void Updater::run() {
  for (int i = 0; i < count; i++) {
    updatables[i]->update();
  }
}

void Updater::registerUpdatable(Updatable *updatable) {
  if (count < 20) {
    updatables[count] = updatable;
    count++;
  }
}