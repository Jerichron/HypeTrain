#pragma once
#include "AbilitiesInterface.h"
using namespace std;

class MagicMissle : AbilitiesInterface 
{
public:
	virtual bool VInit(TiXmlElement* pData);
	virtual void VApply(WeakActorPtr pActor);
};