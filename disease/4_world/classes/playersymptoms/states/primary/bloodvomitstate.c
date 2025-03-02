class BloodVomitSymptom extends SymptomBase
{
	//просто для настройки параметров симптомов и вызывается, даже если симптом не выполняется, не помещайте сюда код игрового процесса
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.PRIMARY;
		m_Priority = 100;
		//m_ID = RageSymptomIDs.SYMPTOM_BLOODVOMIT;
		m_DestroyOnAnimFinish = true;
		m_SyncToClient = false;
		m_Duration = 5;
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime)
	{
			
				
			
	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{
			
	}
	
	override bool CanActivate()
	{
		return ( m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_MOVE || m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_ACTION );
	}	
	
	//!вызывается один раз на симптом, который активируется
	override void OnGetActivatedServer(PlayerBase player)
	{
		//timer.Run(10, this, "Destroy");
		
		Debug.Log("OnGetActivated VomitSymptom called", "PlayerSymptom");
		/*player.GetStatStomachVolume().Set(0);
		player.GetStatStomachWater().Set(0);
		player.GetStatStomachEnergy().Set(0);
		/*PlayAnimationFB(DayZPlayerConstants.CMD_ACTIONFB_VOMIT,DayZPlayerConstants.STANCEMASK_CROUCH, GetDuration() );
		
			int boneIdx = player.GetBoneIndexByName("Head");
			
			if( boneIdx != -1 )
			{
				BloodVomit eff = new BloodVomit();
				vector player_pos = player.GetPosition();
				eff.SetDecalOwner( player );
				SEffectManager.PlayInWorld( eff, "0 0 0" );
				Particle p = eff.GetParticle();
				p.SetOrientation("90 0 0");
				player.AddChild(p, boneIdx);
			}*/
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
	}

	override void OnGetDeactivatedClient(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
	}
	
	override SmptAnimMetaBase SpawnAnimMetaObject()
	{
		return new SmptAnimMetaFB();
	}
}