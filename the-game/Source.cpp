#include <SFML/Graphics.hpp>
#include <list>

#include "Bullet.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Moveable.h"
#include "Player.h"
#include "Scene.h"

// https://www.sfml-dev.org/tutorials/2.5/

// Картинки качал отсюда
// https://opengameart.org/content/2d-game-mage-character-sprite
// https://opengameart.org/content/2d-game-orcs-sprite
// https://opengameart.org/content/2d-game-knight-character-sprite

int main() {
  rtf::Scene scene(2000, 2000);

  scene.Run();

  return 0;
}