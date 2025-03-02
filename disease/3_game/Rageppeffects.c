modded class PPEffects
{	
	
	static void SetRageVignette(float intensity, float R, float G, float B)
	{
		Material matHDR = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/glow");

		float color[4];
		color[0] = R;
		color[1] = G;
		color[2] = B;
		color[3] = 0;

                matHDR.SetParam("Vignette", intensity);
                matHDR.SetParam("VignetteColor", color);
	}
}