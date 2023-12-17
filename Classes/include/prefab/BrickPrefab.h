#ifndef __BRICK_PREFAB_H__
#define __BRICK_PREFAB_H__

#include "cocos2d.h"
#include "actor/Brick.h"
#include "actor/AnimatedBrick.h"
#include "component/AnimationComponent.h"
#include "component/Component.h"
#include "component/HealthComponent.h"
#include "component/ImmuneHealthComponent.h"
#include "config/Cocos2dConfig.h"
#include "config/actorConfig/BrickConfig.h"
#include "diContainer/DIContainer.h"
#include "resource/BlockResource.h"
#include "scene/Scene.h"

namespace Arkanoid::Prefab {
  class GoldBrickPrefab {
  public:
    static Brick* create() {
      auto goldBrick = AnimatedBrick::create();
      goldBrick->inject(createDI());
      goldBrick->setAnimAndSprite(
          *Resource::createGoldHitAnim(),
          *Resource::createGoldBlock());
      Scene::setPhysicConfig(goldBrick, getConfig().physicConfig);
      return goldBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::ImmuneHealthComponent>();
      diContainer.addFactory<
        Components::AnimationComponent,
        Components::AnimationComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };

  class SilverBrickPrefab {
  public:
    static Brick* create() {
      auto silverBrick = AnimatedBrick::create();
      silverBrick->inject(createDI());
      silverBrick->setAnimAndSprite(
          *Resource::createSilverHitAnim(),
          *Resource::createSilverBlock());
      Scene::setPhysicConfig(silverBrick, getConfig().physicConfig);
      return silverBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      diContainer.addFactory<
        Components::AnimationComponent,
        Components::AnimationComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class RedBrickPrefab {
  public:
    static Brick* create() {
      auto redBrick = Brick::create();
      redBrick->inject(createDI());
      redBrick->setSprite(*Resource::createRedBlock());
      Scene::setPhysicConfig(redBrick, getConfig().physicConfig);
      return redBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class BlueBrickPrefab {
  public:
    static Brick* create() {
      auto blueBrick = Brick::create();
      blueBrick->inject(createDI());
      blueBrick->setSprite(*Resource::createBlueBlock());
      Scene::setPhysicConfig(blueBrick, getConfig().physicConfig);
      return blueBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class GreenBrickPrefab {
  public:
    static Brick* create() {
      auto greenBrick = Brick::create();
      greenBrick->inject(createDI());
      greenBrick->setSprite(*Resource::createGreenBlock());
      Scene::setPhysicConfig(greenBrick, getConfig().physicConfig);
      return greenBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class OrangeBrickPrefab {
  public:
    static Brick* create() {
      auto orangeBrick = Brick::create();
      orangeBrick->inject(createDI());
      orangeBrick->setSprite(*Resource::createOrangeBlock());
      Scene::setPhysicConfig(orangeBrick, getConfig().physicConfig);
      return orangeBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class VioletBrickPrefab {
  public:
    static Brick* create() {
      auto violetBrick = Brick::create();
      violetBrick->inject(createDI());
      violetBrick->setSprite(*Resource::createVioletBlock());
      Scene::setPhysicConfig(violetBrick, getConfig().physicConfig);
      return violetBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class WhiteBrickPrefab {
  public:
    static Brick* create() {
      auto whiteBrick = Brick::create();
      whiteBrick->inject(createDI());
      whiteBrick->setSprite(*Resource::createWhiteBlock());
      Scene::setPhysicConfig(whiteBrick, getConfig().physicConfig);
      return whiteBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class YellowBrickPrefab {
  public:
    static Brick* create() {
      auto yellowBrick = Brick::create();
      yellowBrick->inject(createDI());
      yellowBrick->setSprite(*Resource::createYellowBlock());
      Scene::setPhysicConfig(yellowBrick, getConfig().physicConfig);
      return yellowBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
  class CyanBrickPrefab {
  public:
    static Brick* create() {
      auto cyanBrick = Brick::create();
      cyanBrick->inject(createDI());
      cyanBrick->setSprite(*Resource::createCyanBlock());
      Scene::setPhysicConfig(cyanBrick, getConfig().physicConfig);
      return cyanBrick;
    }

  private:
    static DI::DIContainer createDI() {
      DI::DIContainer diContainer;
      diContainer.addFactory<
        Components::HealthComponent,
        Components::HealthComponent>();
      return diContainer;
    }
    static BrickConfig getConfig() {
      BrickConfig brickConfig;
      brickConfig.physicConfig.bitmask = 0xFFFFFFFF;
      brickConfig.physicConfig.sizeBox = cocos2d::Size(16, 8);
      brickConfig.physicConfig.isDynamic = false;
      return brickConfig;
    }
  };
}

#endif
