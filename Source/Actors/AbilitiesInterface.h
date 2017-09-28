#pragma once
using namespace std;
class AbilitiesInterface : public ActorComponent
{
public:
	const static ComponentId COMPONENT_ID;
	virtual ComponentId VGetComponentId(void) const
	{
		return COMPONENT_ID;
	}
	// Ability interface
	virtual void VApply(WeakActorPtr pActor) = 0;
};
