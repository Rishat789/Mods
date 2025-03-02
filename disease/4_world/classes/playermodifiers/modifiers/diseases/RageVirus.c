
class RageVirusMdfr: ModifierBase
{
	
	
	static const int RAGE_AGENT_THRESHOLD_ACTIVATE = 120;
	static const int RAGE_AGENT_THRESHOLD_DEACTIVATE = 10;
	static const int mPAIN_EVENT_INTERVAL_MIN = 18;
	static const int mPAIN_EVENT_INTERVAL_MAX = 56;
	float Rage_Damage = 65;
	float Rage_DamageH = 0.5;
	float m_Time = 1000;
	bool m_IsVomiting;
	protected float m_NextEventm;
	protected float m_Timem;
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 			= RageModifiers.MDF_RAGEVIRUS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 10;
	}
	
	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(RageAgents.RAGEVIRUS) > RAGE_AGENT_THRESHOLD_ACTIVATE) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	override protected void OnActivate(PlayerBase player)
	{
		m_IsVomiting = false;
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.AttachByType(eNotifiers.NTF_SICK);
		player.IncreaseDiseaseCount();
		
		player.PlayerRage();
		m_NextEventm = Math.RandomFloatInclusive( mPAIN_EVENT_INTERVAL_MIN, mPAIN_EVENT_INTERVAL_MAX );
		
		SymptomBase shivers = player.GetSymptomManager().QueueUpSecondarySymptomEx(SymptomIDs.SYMPTOM_HAND_SHIVER);
			if ( shivers )
			{
				CachedObjectsParams.PARAM1_INT.param1 = 3;
				shivers.SetParam(CachedObjectsParams.PARAM1_INT);
			}
		
		
		
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs.SYMPTOM_HAND_SHIVER);
		player.HasRage = false;
		
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(RageAgents.RAGEVIRUS) < RAGE_AGENT_THRESHOLD_DEACTIVATE) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		
		m_Timem += deltaT;
		
		if ( m_Timem >= m_NextEventm )
		{
			player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
			m_Timem = 0;
			m_NextEventm = Math.RandomFloatInclusive( mPAIN_EVENT_INTERVAL_MIN, mPAIN_EVENT_INTERVAL_MAX );
		}
		
		if(player.GetSingleAgentCount(RageAgents.RAGEVIRUS)>1)
		{
		
			//player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_SNEEZE);
			float currenthealthH = player.GetHealth("", "Health");
			float currenthealthB = player.GetHealth("", "Blood");
			if( player.IsAntibioticsActive() )
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
			}
			else
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_HEAVY);
			}
		
		
		
		if (currenthealthB > 2650 )
		{		
			if (currenthealthH >= 16 )
				{	
					
					//currenthealthB = 2800;
					currenthealthH = currenthealthH - Rage_DamageH;
					currenthealthB = currenthealthB - 15;
					//player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
					
				}
				else
				{
					//currenthealthH = 15;
					currenthealthH = currenthealthH - 0.03;
					currenthealthB = currenthealthB - Rage_Damage;
					int chanceb = Math.RandomInt(0,100);  
					if(chanceb <= 3)
					{
						SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
						if( symptom )
						{ 
							symptom.SetDuration(Math.RandomIntInclusive(4,8));
						}
					}
				}
		}
		else
		{
			currenthealthH = currenthealthH - 0.1;
			currenthealthB = currenthealthB - 30;
			
		}
		player.SetHealth("", "Health" ,  currenthealthH );
		player.SetHealth("", "Blood" ,  currenthealthB );
		
		
			
		}
	}
};