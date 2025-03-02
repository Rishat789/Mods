modded class PluginRecipesManager extends PluginBase
{
    


    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        UnregisterRecipe("FillFilter");
        UnregisterRecipe("CraftLeatherSack");
        RegisterRecipe(new CraftVialMix);
        RegisterRecipe(new CraftRageCure);
		RegisterRecipe(new CraftPatogen);
		RegisterRecipe(new CraftAntibodies);
    }
}