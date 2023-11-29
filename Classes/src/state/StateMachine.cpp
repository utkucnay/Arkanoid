#include "state/StateMachine.h"

Arkanoid::State::StateMachine::StateMachine() {

}

Arkanoid::State::StateMachine::~StateMachine() {

}

void
Arkanoid::State::StateMachine::addState(Ref<IState> state) {
  assert(nullptr != state.get());
  m_stateMap[state->getName()] = state;
};


void
Arkanoid::State::StateMachine::removeState(Ref<IState> state) {
  assert(nullptr != state.get());
  m_stateMap.erase(state->getName());
};

void
Arkanoid::State::StateMachine::changeState(Ref<IState> state) {
  assert(nullptr != state.get());
  assert(nullptr != currentState.lock().get());
  currentState.lock()->onEnter();
  currentState = m_stateMap[state->getName()];
  currentState.lock()->onEnter();
};
