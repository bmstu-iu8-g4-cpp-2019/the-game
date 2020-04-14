#include "Enemy.h"
#include "Bullet.h"

using namespace rtf;


Enemy::Enemy(const std::string& filename) : Moveable(filename) {}

void Enemy::Update(sf::RenderWindow* window, sf::Time) {
  if (!is_alive_) {
    GameObject::Draw(window);
    return;
  }

  if (target_) {
    MoveTo(*target_);
  }

  Moveable::Draw(window);
}

void rtf::Enemy::OnCollision(GameObject& obj) { 
  
  // Если obj является Bullet, то p != nullptr;
  if (obj.is(Tag::Bullet)) {
    Die();
  }
}

void Enemy::Die() {
  if (is_alive_) {
    LoadNewTexture("res/knight/black_knight/dead_6.png");
  }
  is_alive_ = false;
}
