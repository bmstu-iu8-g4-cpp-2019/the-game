#include "Player.h"

using namespace rtf;

Player::Player(const std::string& filename) : Moveable(filename) {
  cd_ = sf::milliseconds(1000);
}

bool Player::CanAttack() const { return timer_.getElapsedTime() > cd_; }

void Player::Attack() { timer_.restart(); }

void Player::Update(sf::RenderWindow* window, sf::Time time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    MoveUp();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    MoveDown();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    MoveRight();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    MoveLeft();
  }

  Draw(window);

  ResetMoveDirection();
}
