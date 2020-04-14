#include "Player.h"
#include "Scene.h"

using namespace rtf;

Player::Player(const std::string& filename) : Moveable(filename) {
  cd_ = sf::milliseconds(1000);
}

bool Player::CanAttack() const { return timer_.getElapsedTime() > cd_; }

void Player::Attack() { timer_.restart(); }

void rtf::Player::Controls(Scene& scene) {
  if (CanAttack()) {
    auto& pos = Sprite().getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      auto bullet = std::make_unique<Bullet>("res/blast/laser-blast-png-4-original.png", pos);
      bullet->MoveUp();
      scene.AddObject(std::move(bullet));
      Attack();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      auto bullet = std::make_unique<Bullet>("res/blast/laser-blast-png-4-original.png", pos);
      bullet->MoveDown();
      scene.AddObject(std::move(bullet));
      Attack();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      auto bullet = std::make_unique<Bullet>("res/blast/laser-blast-png-4-original.png", pos);
      bullet->MoveRight();
      scene.AddObject(std::move(bullet));
      Attack();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      auto bullet = std::make_unique<Bullet>("res/blast/laser-blast-png-4-original.png", pos);
      bullet->MoveLeft();
      scene.AddObject(std::move(bullet));
      Attack();
    }
  }
}

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

void rtf::Player::OnCollision(GameObject& obj) {
  // Если столкнулся с врагом, то уменьшаем жизни.

  // Если столкнулся с баффом, то увечивем жизни/уменьшаем Cooldown/ускоряемся/баффы и etc.

  // Если столкнулся с дебаффом...

}
