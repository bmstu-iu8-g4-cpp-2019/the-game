#pragma once

#include "Moveable.h"

namespace rtf {

class Enemy : public Moveable {
  bool is_alive = true;
  GameObject* target_ = nullptr;

 public:
  Enemy(const std::string& filename);

  void set_target(GameObject* target) { target_ = target; }

  void Update(sf::RenderWindow* window, sf::Time) override;

  void Die();
};

}  // namespace rtf
