class BloodVomitZombie : EffectParticle
{
	void BloodVomitZombie()
	{
		
		SetParticleID(ParticleList.BLOODVOMITINFECTED);
	}
	override void Event_OnStarted()
	{
		// Uncomment this to spawn fake decal of vomit on ground.
		/*
		vector pos = Zomb.GetPosition();
		vector ori = Zomb.GetOrientation();
		vector playerdir = Zomb.GetDirection();
		vector offset = playerdir * 1.2;
		vector splashpos = pos + offset;

		
		Particle p = Particle.Play(ParticleList.BLOODVOMITSPLASH, splashpos);
		p.SetOrientation(ori);
		*/
	}
}