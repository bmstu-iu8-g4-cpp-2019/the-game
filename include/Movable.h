#pragma once

#include "GameObject.h"

namespace rtf {
  
class Movable : public GameObject {
 public:
   Movable(const std::string& textureFile);

  void ResetMoveDirection();

  void MoveUp();
  void MoveDown();
  void MoveLeft();
  void MoveRight();

  void MoveTo(const GameObject& target);

  void set_speed(float speed) { speed_ = speed; }

  void Draw(sf::RenderWindow* window) override;

 private:
  float speed_ = 0.5;
  sf::Vector2f direction_;
};

}  // namespace rtf