class BloodVomit : EffectParticle
{
	void BloodVomit()
	{
		SetParticleID(ParticleList.BLOODVOMIT);
	}
	override void Event_OnStarted()
	{
		// Раскомментируйте это, чтобы породить поддельную наклейку
		/* vector pos = this.GetPosition();
		
		
		
		
		
		
		Particle p = Particle.Play(ParticleList.BLOODVOMITSPLASH, pos); */
		
		
	}
}