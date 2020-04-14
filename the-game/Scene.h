#pragma once

#include <list>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <memory>

namespace rtf {
class Scene {
 public:
  Scene(int w, int h);
  void Run();
  void AddObject(std::unique_ptr<GameObject> obj);

  private:
  sf::RenderWindow window_;
  
  std::list<std::unique_ptr<GameObject>> objects_;
  Player* player_ = nullptr;
  sf::Clock clock_;
};

}  // namespace rtf