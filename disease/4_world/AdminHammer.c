modded class Construction
{
	override bool CanBuildPart( string part_name, ItemBase tool, bool use_tool )
	{
		if (tool.GetType() == "adminHammer")
		{
			if ( !IsPartConstructed( part_name ) && !HasConflictPart( part_name ) )
			{
				return true;
			}
		}
			
		return super.CanBuildPart( part_name, tool, use_tool );
	}
};

modded class ActionBuildPart: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		super.ActionCondition( player, target, item );

        PlayerIdentity p_Identity = player.GetIdentity();

        if ( item.GetDisplayName() == "adminHammer" )
        {
			item.SetHealth("", "", 100);
			return true;
        }

		
		return super.ActionCondition( player, target, item );
	};
};