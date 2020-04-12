#include "Enemy.h"

using namespace rtf;

Enemy::Enemy(const std::string& filename) : Moveable(filename) {}

void Enemy::Update(sf::RenderWindow* window, sf::Time) {
  if (!is_alive) {
    GameObject::Draw(window);
    return;
  }

  if (target_) {
    MoveTo(*target_);
  }

  Moveable::Draw(window);
}

void Enemy::Die() {
  if (is_alive) {
    LoadNewTexture("res/knight/black_knight/dead_6.png");
  }
  is_alive = false;
}
