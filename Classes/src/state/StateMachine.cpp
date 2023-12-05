#include "state/StateMachine.h"

Arkanoid::StateMachine::StateMachine() {

}

Arkanoid::StateMachine::~StateMachine() {

}

void
Arkanoid::StateMachine::addState(std::shared_ptr<IState> state) {
  m_stateMap[state->getName()] = state;
};


void
Arkanoid::StateMachine::removeState(std::shared_ptr<IState> state) {
  m_stateMap.erase(state->getName());
};

void
Arkanoid::StateMachine::changeState(std::shared_ptr<IState> state) {
  currentState.lock()->onEnter();
  currentState = m_stateMap[state->getName()];
  currentState.lock()->onEnter();
};

void
Arkanoid::StateMachine::addFirstState(std::shared_ptr<IState> state) {
  addState(state);
  currentState = state;
}
