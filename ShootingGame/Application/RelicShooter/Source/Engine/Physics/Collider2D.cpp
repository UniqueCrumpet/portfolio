#include "Collider2D.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"

#include "../../Engine/System/Context/SysContextProvider.h"
#include "../../Engine/System/GameState/GameStateManager.h"
#include "../../Engine/System/GameState/GameState.h"

#include <cmath>
#include "../Core/MathHelpers.h"

Collider2D::Collider2D()
{
	auto* pGameStateManager = C_SysContext::Get<GameStateManager>();
	GameState* pCurrentGameState = pGameStateManager->GetCurrentGameState();

    pCurrentGameState->AddCollider(this);
}

Collider2D::~Collider2D()
{
	auto* pGameStateManager = C_SysContext::Get<GameStateManager>();
	GameState* pCurrentGameState = pGameStateManager->GetCurrentGameState();

	pCurrentGameState->RemoveCollider(this);
}

bool Collider2D::CircleCircleCollision(const CircleCollider2D* pCircleA, const CircleCollider2D* pCircleB)
{
	const sf::Vector2f difference = pCircleB->m_CentrePosition - pCircleA->m_CentrePosition;

	const float distanceSquared = fabsf(MathHelpers::LengthSquared(difference));
	float radiusSquared = pCircleA->m_Radius + pCircleB->m_Radius;
	radiusSquared *= radiusSquared;

	if (distanceSquared < radiusSquared)
	{
		return true;
	}

	return false;
}

bool Collider2D::RectangleRectangleCollision(const BoxCollider2D* pBoxA, const BoxCollider2D* pBoxB)
{
	if (pBoxA->m_CollisionRect.left <= pBoxB->m_CollisionRect.left + pBoxB->m_CollisionRect.width && pBoxA->m_CollisionRect.left + pBoxA->m_CollisionRect.width >= pBoxB->m_CollisionRect.left &&
		pBoxA->m_CollisionRect.top <= pBoxB->m_CollisionRect.top + pBoxB->m_CollisionRect.height && pBoxA->m_CollisionRect.top + pBoxA->m_CollisionRect.height >= pBoxB->m_CollisionRect.top)
	{
		return true;
	}

	return false;
}

bool Collider2D::RctangleCircleCollision(BoxCollider2D* pBoxA, CircleCollider2D* pCircleA)
{
	//This is left for you to figure out!

	return false;
}

