#pragma once

#include "Moveable.h"

namespace rtf {

class Scene;

class Player : public Moveable {

 public:
  Player(const std::string& filename);
  
  bool CanAttack() const;

  void Attack();

  void Controls(Scene& scene);

  void Update(sf::RenderWindow* window, sf::Time time) override;

  void OnCollision(GameObject&) override;
 private:
  sf::Clock timer_;
  sf::Time cd_;
};
}  // namespace rtf
