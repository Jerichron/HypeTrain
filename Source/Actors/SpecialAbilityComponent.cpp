#include "SpecialAbilityComponent.h"
#include "iostream"
using namespace std;

const char* MagicMissle::g_Name = "MagicMissle";
bool MagicMissle::VInit(TiXmlElement* pData)
{
	return true;
}
void MagicMissle::VApply(WeakActorPtr pActor)
{
	StrongActorPtr pStrongActor = MakeStrongPtr(pActor);
	if (pStrongActor)
	{
		cout << "Applying ability affects" << (string)(pStrongActor->GetId());
	}
}