class ActionInjectRageCureSelf: ActionInjectSelf
{
	/*override int GetType()
	{
		return AT_INJECT_RAGECURE_S;
	}*/
		
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_Player.m_ModifiersManager.DeactivateModifier(RageModifiers.MDF_RAGEVIRUS);
		action_data.m_Player.SetHealth("","Shock",15);
		//action_data.m_Player.SetHealth("","Health",100);
		//action_data.m_Player.SetHealth("","Blood",5000);
		action_data.m_Player.RemoveAgent(RageAgents.RAGEVIRUS);
		
	}
};