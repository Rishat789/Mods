class Antidot: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
	
		AddAction(ActionInjectRageCureSelf);
	}
};
