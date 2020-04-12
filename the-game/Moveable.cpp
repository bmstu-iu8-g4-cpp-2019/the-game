#include "Moveable.h"

using namespace rtf;

Moveable::Moveable(const std::string& textureFile) : GameObject(textureFile) {}

void Moveable::ResetMoveDirection() { direction_ = sf::Vector2f{}; }

void Moveable::MoveUp() { direction_.y += -speed_; }
void Moveable::MoveDown() { direction_.y += speed_; }
void Moveable::MoveLeft() { direction_.x += -speed_; }
void Moveable::MoveRight() { direction_.x += speed_; }

void Moveable::MoveTo(const GameObject& target) {
  // Направление к движению.
  auto direction = target.Sprite().getPosition() - Sprite().getPosition();
  // Длина вектора.
  auto len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
  // Вектор длины 1, по направлению к цели.
  direction /= len;

  // Еще и скорость задействуем.
  direction_ = direction * speed_;
}

void Moveable::Draw(sf::RenderWindow* window) {
  sprite_.move(direction_);
  GameObject::Draw(window);
}
