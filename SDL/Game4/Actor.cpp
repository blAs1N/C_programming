#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game)
	:state(State::EActive),
	position(Vector2::Zero),
	scale(1.0f),
	rotation(0.0f),
	game(game) {

	game->AddActor(this);
}

Actor::~Actor() {
	game->RemoveActor(this);

	while (!components.empty())
		delete components.back();
}

void Actor::ProcessInput(const uint8_t* keyState) {
	if (state == State::EActive) {
		for (auto component : components)
			component->ProcessInput(keyState);

		ActorInput(keyState);
	}
}

void Actor::Update(float deltaTime) {
	if (state == State::EActive) {
		for (auto component : components)
			component->Update(deltaTime);

		UpdateActor(deltaTime);
	}
}

void Actor::AddComponent(Component* component) {
	int myOrder = component->GetUpdateOrder();

	auto iter = components.begin();
	for (; iter != components.end(); ++iter)
		if (myOrder < (*iter)->GetUpdateOrder())
			break;

	components.insert(iter, component);
}

void Actor::RemoveComponent(Component* component) {
	auto iter = std::find(components.begin(), components.end(), component);
	if (iter != components.end())
		components.erase(iter);
}