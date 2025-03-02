
modded class PlayerBase extends ManBase
{
bool HasRage = false;
ref Timer Infectedsoundtimer;
ref Timer ragevignettetimer;	
	//////////////////SOUND///////////////
 
		
    ref SoundObject soundObjRage; //Sound for Vomit
    ref SoundObjectBuilder soundBuilderRage;
    AbstractWave PlayerRageSounds;
    
    private bool m_playStatus = true; //всегда будет воспроизводить звук, сделать сеттер/геттер, если вы хотите управлять этим через через другие классы
  
    AbstractWave MSaySoundSet(string name)
    {
        SoundParams soundParams = new SoundParams(name);
        soundBuilderRage            = new SoundObjectBuilder(soundParams);
        soundObjRage                = soundBuilderRage.BuildSoundObject();
        soundObjRage.SetPosition(this.GetPosition());
        return GetGame().GetSoundScene().Play3D(soundObjRage, soundBuilderRage);
    }
	
	
	//////////////////SOUND///////////////
	


	
	
	
void ragevignette()
	{
	
	if(GetSingleAgentCount(RageAgents.RAGEVIRUS)>1)
			{
			
			int Agents = GetSingleAgentCount(RageAgents.RAGEVIRUS);
			float clampedagents = Agents / 500;	
			PPEffects.SetVignette(Math.Clamp(clampedagents,0,0.8), 0, 255, 0, 0);
			//Print("vignetteON"+ clampedagents);
				
			}
			else
				{
				//Print("vignetteOFF");
				ragevignettetimer.Stop();
					
				}
			
	}
	
	
	
	
void PlayerRage()
	{
		
	runsoundtimer();
	Print("playerrage");
			
	}
	
		
void runsoundtimer()
	{
		
		
		float randomsound = Math.RandomFloat(2,5);
		Infectedsoundtimer = new Timer();
		Infectedsoundtimer.Run(randomsound, this ,"InfectedSounds",NULL ,true);
		Print("soundtimer");
		HasRage = true;
		
			
	}
	
void InfectedSounds()
	{
		
		 if (!GetGame().IsServer() && HasRage==true) //Check if its a client entity running this class and sounds is set to trigger
       		 {
           		PlayerRageSounds = MSaySoundSet("playerinfected_SoundSet"); //Hook sound to body
           		PlayerRageSounds.Loop(false);
			 	soundObjRage.SetPosition(GetPosition());
			
				
		 Print("infectedsounds");
        		 }
			if(HasRage==false)
			{
				Infectedsoundtimer.Stop();
			Print("infectedsoundtimerstopped");
				
			}
		
	}
	
void ~PlayerBase()
{
	if ( PlayerRageSounds )
	{
		PlayerRageSounds.Stop();
	}
}
	
	
	
	
	
override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{	
		if(source.IsZombie())
		{
			if(ragevignettetimer && ragevignettetimer.!IsRunning())
			{
			ragevignettetimer.Run(1, this ,"ragevignette",NULL ,true);
				Print("vignettetimerrestart");
			}
			else
			{
			ragevignettetimer = new Timer();
			ragevignettetimer.Run(1, this ,"ragevignette",NULL ,true);
				Print("vignettetimernew");
			}
				int chancer = Math.RandomInt(0,100);  // НЕ ИЗМЕНЯТЬ
				if(source.IsZombie() && (chancer <= 85))// Условие заражения первое - что бил зомби, второе - шанс заражения при ударе в процентах
				{
					this.GetBleedingManagerServer().AttemptAddBleedingSource(Math.RandomInt(0, 100));// появление царапины на рандомной части тела при ударе
				}
				
				if(GetBleedingManagerServer() && GetBleedingManagerServer().m_BleedingSources.Count() > 0)//условие налисие царапины
				{
					this.InsertAgent(RageAgents.RAGEVIRUS, 25);// заражение количество в единицах при выполнении условия
				}
				
				/*int chancerleg = Math.RandomInt(0,100);  // НЕ ИЗМЕНЯТЬ
				if(source.IsZombie() && (chancerleg <= 3))// Условие заражения первое - что бил зомби, второе - шанс заражения перелома при ударе в процентах
				{
					this.GetModifiersManager().ActivateModifier( eModifiers.MDF_BROKEN_LEGS );
					this.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftFoot");
					this.GetBleedingManagerServer().AttemptAddBleedingSource(Math.RandomInt(0, 100));// появление царапины на рандомной части тела при ударе
					this.InsertAgent(RageAgents.RAGEVIRUS, 50);// заражение количество в единицах при выполнении условия
				}*/
				
				
		}		
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		
	}
	
// override void EEKilled( Object killer )
	// {
		// if(HasRage==true)
		// {
		// GetGame().CreateObject( "ZmbM_DoctorFat", GetPosition(), false, true);
			////////////equipmentdrop////////////
			
		// }
		
		// super.EEKilled( killer );
	// }
	
	////////////////////////////RPC/////////////////////////////////
	
	// Called on each server and client tick
	/*override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		PlayerVirusCheck(deltaTime);
	}
	
	void PlayerVirusCheck(float deltaTime)
	{
		if (GetSingleAgentCount(RageAgents.RAGEVIRUS) <= 0)
			{
				return;
			}

			// This makes sure the virus infection amount shrinks if it's below Stage 1 infection.
			if (GetSingleAgentCountNormalized(RageAgents.RAGEVIRUS) < 120 && GetBleedingManagerServer() && GetBleedingManagerServer().m_BleedingSources.Count() <= 0)
			{
				InsertAgent(RageAgents.RAGEVIRUS, -0.5); // 
				if (GetSingleAgentCount(RageAgents.RAGEVIRUS) <= 0)
				{
					RemoveAgent(RageAgents.RAGEVIRUS);
				}
			}

			
	}	*/
	
}


