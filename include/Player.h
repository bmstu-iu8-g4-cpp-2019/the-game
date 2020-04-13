#pragma once

#include "Movable.h"

namespace rtf {

class Player : public Movable {

 public:
  Player(const std::string& filename);
  
  bool CanAttack() const;

  void Attack();

  void Update(sf::RenderWindow* window, sf::Time time) override
    ;
 private:
  sf::Clock timer_;
  sf::Time cd_;
};
}  // namespace rtf
