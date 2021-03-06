#pragma once

#include "Actor.h"

class FollowActor : public Actor {
public:
	FollowActor(Game* inGame);
	void ActorInput(const InputState& inputState) override;
	void SetVisible(bool visible);

private:
	class MoveComponent* move;
	class FollowCamera* camera;
	class SkeletalMeshComponent* mesh;
	bool isMoving;
};