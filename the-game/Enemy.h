#pragma once

#include "Moveable.h"

namespace rtf {

class Enemy : public Moveable {
  bool is_alive_ = true;
  GameObject* target_ = nullptr;
  
 public:
  Enemy(const std::string& filename);

  void set_target(GameObject* target) { target_ = target; }

  void Update(sf::RenderWindow* window, sf::Time) override;

  void OnCollision(GameObject& obj) override;

  void Die();

  bool is_alive() const { return is_alive_; }
};

}  // namespace rtf
