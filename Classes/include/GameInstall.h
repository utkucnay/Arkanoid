#ifndef __GAME_INNSTALL_H__
#define __GAME_INNSTALL_H__

#include "diContainer/DIContainer.h"
#include "manager/GameManager.h"
#include "manager/LevelManager.h"
#include "manager/SceneManager.h"
#include "manager/TagManager.h"
#include "scene/ActionScene.h"
#include "scene/TitleScene.h"

inline DI::DIContainer gameDIContainer;

class GameInstall {
  public:
    GameInstall() {
      using namespace Arkanoid::Manager;

      gameDIContainer.addSingle<TagManager, TagManager>();
      gameDIContainer.addSingle<SceneManager, SceneManager>();
      gameDIContainer.addSingle<LevelManager, LevelManager>();
      gameDIContainer.addSingle<GameManager, GameManager>();

      {
        auto tagManager = gameDIContainer.getSingle<TagManager>();
        tagManager->setTag("Vaus");
        tagManager->setTag("Column");
        tagManager->setTag("EnergyBall");
        tagManager->setTag("EndArea");
      }

      {
        auto sceneManager = gameDIContainer.getSingle<SceneManager>();
        sceneManager->addScene<Arkanoid::TitleScene>();
        sceneManager->addScene<Arkanoid::ActionScene>();
        sceneManager->inject(gameDIContainer);
        sceneManager->setScene();
      }

      {
        gameDIContainer.getSingle<LevelManager>()->inject(gameDIContainer);
      }

      {
        gameDIContainer.getSingle<GameManager>()->inject(gameDIContainer);
      }
    }
};

#endif
