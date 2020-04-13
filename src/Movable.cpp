#include "Movable.h"
#include <cmath>

using namespace rtf;

Movable::Movable(const std::string& textureFile) : GameObject(textureFile) {}

void Movable::ResetMoveDirection() { direction_ = sf::Vector2f{}; }

void Movable::MoveUp() { direction_.y += -speed_; }
void Movable::MoveDown() { direction_.y += speed_; }
void Movable::MoveLeft() { direction_.x += -speed_; }
void Movable::MoveRight() { direction_.x += speed_; }

void Movable::MoveTo(const GameObject& target) {
  // ����������� � ��������.
  auto direction = target.Sprite().getPosition() - Sprite().getPosition();
  // ����� �������.
  auto len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
  // ������ ����� 1, �� ����������� � ����.
  direction /= len;

  // ��� � �������� �����������.
  direction_ = direction * speed_;
}

void Movable::Draw(sf::RenderWindow* window) {
  sprite_.move(direction_);
  GameObject::Draw(window);
}
