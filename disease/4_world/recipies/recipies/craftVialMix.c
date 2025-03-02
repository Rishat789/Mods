class CraftVialMix extends RecipeBase
{
	override void Init()
	{
		m_Name = "Смешать";
		m_IsInstaRecipe = false;
		m_AnimationLength = 0.5;
		m_Specialty = -0.02;
				
				
				
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;
		
		m_MinQuantityIngredient[0] = -1;
		m_MaxQuantityIngredient[0] = -1;
		
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;
		
		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;
				
				
				
				
				
		InsertIngredient(0,"BV");
		
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1; 
		m_IngredientAddQuantity[0] = -1;
		m_IngredientDestroy[0] = true;
		m_IngredientUseSoftSkills[0] = false;
		
		
		
		InsertIngredient(1,"BA");
		
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1; 
		m_IngredientAddQuantity[1] = -1;
		m_IngredientDestroy[1] = true;
		m_IngredientUseSoftSkills[1] = false;
			

			
		AddResult("BVA");

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -2;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)
	{
		Debug.Log("Recipe Do method called","recipes");
	}
};
