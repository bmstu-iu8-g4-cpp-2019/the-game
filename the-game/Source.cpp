#include <SFML/Graphics.hpp>
#include <list>

#include "Bullet.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Moveable.h"
#include "Player.h"

// https://www.sfml-dev.org/tutorials/2.5/

// Картинки качал отсюда
// https://opengameart.org/content/2d-game-mage-character-sprite
// https://opengameart.org/content/2d-game-orcs-sprite
// https://opengameart.org/content/2d-game-knight-character-sprite

using namespace rtf;

int main() {
  sf::RenderWindow window(sf::VideoMode(2000, 2000), "SFML works!");

  std::vector<Bullet> bullets;
  Player player("res/wizard/wizard/idle_1.png");
  player.SetPosition(1000.f, 500.f);

  Enemy enemy("res/knight/black_knight/idle_1.png");
  enemy.set_target(&player);
  enemy.set_speed(0.7f);
  enemy.SetPosition(100.f, 100.f);

  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      // Window closed or escape key pressed: exit
      if ((event.type == sf::Event::Closed) ||
          ((event.type == sf::Event::KeyPressed) &&
           (event.key.code == sf::Keyboard::Escape))) {
        window.close();
        break;
      }
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code)
        default:
          break;
      }
    }

    sf::Time elapsed = clock.restart();
    auto pos = player.Sprite().getPosition();

    // Добавить класс Scene

    // Унести в класс Player
    if (player.CanAttack()) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        bullets.push_back(
            Bullet("res/blast/laser-blast-png-4-original.png", pos));
        bullets.back().MoveUp();
        player.Attack();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        bullets.push_back(
            Bullet("res/blast/laser-blast-png-4-original.png", pos));
        bullets.back().MoveDown();
        player.Attack();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        bullets.push_back(
            Bullet("res/blast/laser-blast-png-4-original.png", pos));
        bullets.back().MoveRight();
        player.Attack();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        bullets.push_back(
            Bullet("res/blast/laser-blast-png-4-original.png", pos));
        bullets.back().MoveLeft();
        player.Attack();
      }
    }

    // Враг столкнулся со снарядом
    // Переписать на OnCollision(GameObject* a, GameObject* b);
    for (const auto& bullet : bullets) {
      if (bullet.Sprite().getGlobalBounds().intersects(
              enemy.Sprite().getGlobalBounds())) {
        enemy.Die();
      }
    }

    window.clear();

    enemy.Update(&window, elapsed);
    player.Update(&window, elapsed);
    for (auto& bullet : bullets) {
      bullet.Update(&window, elapsed);
    }
    /*
    for (auto& game_object : all_objects) {
      game_object.Update(&window, elapsed);
    } */

    window.display();
  }

  return 0;
}