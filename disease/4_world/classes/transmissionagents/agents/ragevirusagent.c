class RageVirusAgent extends AgentBase
{
override void Init()
	{
		m_Type 					= RageAgents.RAGEVIRUS;
		m_Invasibility 			= 0;//увеличивайте количество агентов на это число в секунду, если оно достаточно сильно, чтобы расти
		m_TransferabilityIn		= 1;//игроку
		m_TransferabilityOut	= 0;//от игрока
		m_AntibioticsResistance = 1;//[0..1], 0 означает полный эффект антибиотиков, 1 означает отсутствие эффекта
		m_MaxCount 				= 1000;
		m_TransferabilityAirOut = 0;
		m_AutoinfectProbability = 0;
		m_Potency = EStatLevels.CRITICAL;//расти, когда иммунная система игрока находится на этом уровне или ниже
		m_DieOffSpeed = 0;//как быстро агент умирает, когда недостаточно мощный, чтобы расти(в секунду)
	}
}