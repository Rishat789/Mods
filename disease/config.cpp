class CfgPatches
{
	class Zdisease
	{
		units[]=
		{
			"BV",
			"BA",
			"BVA",
			"microscope",
			"InfectedSkin",
			"BrainZ",
			"joint_mung",
			"InfectedSteakMeat"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Medical",
			"DZ_Structures_Furniture",
			"DZ_Data",
			"DZ_Characters",
			"DZ_Scripts",
			"DZ_gear_food",
			"DZ_Gear_Consumables",
			"DZ_Data_Bliss",
			"DZ_Animals",
			"DZ_AI_Bliss",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Characters_Gloves",
			"DZ_Gear_Containers",
			"DZ_Characters_Headgear",
			"DZ_Characters_Masks",
			"DZ_Characters_Shoes",
			"DZ_Characters_Heads",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Magazines"
		};
	};
};
class CfgMods
{
	class Zdisease
	{
		dir="disease";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="VirusZ";
		credits="Lion";
		author="Lion";
		authorID="0";
		version=0.1;
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"disease/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"disease/4_world"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BV: Inventory_Base
	{
		scope=2;
		displayName="Патоген";
		descriptionShort="Флакон, содержащий возбудители вируса Z";
		model="\dz\gear\medical\InjectionVial.p3d";
		itemSize[]={2,2};
		weight=50;
		lootCategory="Medical";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"disease\data\BV.paa",
			"disease\data\BV.paa",
			"disease\data\BV.paa"
		};
	};
	class BA: Inventory_Base
	{
		scope=2;
		displayName="Антитела";
		descriptionShort="Флакон, содержащий антитела вируса Z";
		model="\dz\gear\medical\InjectionVial.p3d";
		itemSize[]={2,2};
		weight=50;
		lootCategory="Medical";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"disease\data\BA.paa",
			"disease\data\BA.paa",
			"disease\data\BA.paa"
		};
	};
	class BVA: Inventory_Base
	{
		scope=2;
		displayName="Смесь анти Z";
		descriptionShort="Флакон, содержащий смесь патогенов вируса Z и антител";
		model="\dz\gear\medical\InjectionVial.p3d";
		itemSize[]={2,2};
		weight=50;
		lootCategory="Medical";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"disease\data\BVA.paa",
			"disease\data\BVA.paa",
			"disease\data\BVA.paa"
		};
	};
	class microscope: Inventory_Base
	{
		scope=2;
		displayName="Микроскоп";
		descriptionShort="Микроскоп для исследования";
		model="\dz\structures\furniture\school_equipment\lab_microscope.p3d";
		weight=1;
		interactionWeight=1;
		itemSize[]={4,4};
		repairableWithKits[]={7};
		repairCosts[]={30};
		hiddenSelections[]=
		{
			"component1"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\structures\furniture\school_equipment\data\lab_set.rvmat",
			"DZ\structures\furniture\school_equipment\data\lab_set.rvmat",
			"DZ\structures\furniture\school_equipment\data\lab_set.rvmat"
		};
	};
	class PigPelt;
	class InfectedSkin: PigPelt
	{
		scope=2;
		displayName="Шкурка зомби";
		descriptionShort="Кожа снятая с зомби";
		model="\dz\gear\consumables\Pelt_Pig.p3d";
		peltGain=6;
		weight=420;
		itemSize[]={5,3};
	};
	class DZ_LightAI;
	class DayZInfected: DZ_LightAI
	{
	};
	class ZombieBase: DayZInfected
	{
		class Skinning
		{
			/*class clothing
			{
				item="InfectedSkin";
				count=1;
			};*/
			class Steaks
			{
				item="InfectedSteakMeat";
				count=3;
				quantityMinMaxCoef[]={0.5,1};
			};
			class Guts
			{
				item="Guts";
				count=1;
				quantityMinMaxCoef[]={0.5,1};
			};
			/*class Bones
			{
				item="Bone";
				count=2;
				quantityMinMaxCoef[]={0.75,1};
			};*/
			class Inventory_Base
			{
				item="BrainZ";
				count=1;
				quantityMinMaxCoef[]={0.050000001,1};
			};
		};
	};
	
	class Edible_Base;
	class SodaCan_ColorBase: Edible_Base
	{
	};
	class SodaCan_Cola: SodaCan_ColorBase
	{
	};
	class AdminCola: SodaCan_Cola
	{
	};
	class InfectedSteakMeat: Edible_Base
	{
		scope=2;
		displayName="Стейк из зомби";
		descriptionShort="Мясо зомби. !ВНИМАНИЕ! !ТОКСИЧНО! !ЯДОВИТО! !ЗАРАЗНО! Не годится в пищу.";
		model="\dz\gear\food\human_meat.p3d";
		weight=0;
		interactionWeight=1;
		quantityBar=1;
		absorbency=0.30000001;
		itemSize[]={1,3};
		varQuantityInit=150;
		varQuantityMin=0;
		varQuantityMax=150;
		inventorySlot="Ingredient";
		ContinuousActions[]={159,185};
		isMeleeWeapon=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFist";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFist_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFist_Heavy";
				range=2.8;
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\meat_steak_raw_CO.paa",
			"dz\gear\food\data\meat_steak_baked_CO.paa",
			"dz\gear\food\data\meat_steak_baked_CO.paa",
			"dz\gear\food\data\meat_steak_dried_CO.paa",
			"dz\gear\food\data\meat_steak_burned_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\meat_steak_rotten.rvmat",
			"dz\gear\food\data\meat_steak_baked.rvmat",
			"dz\gear\food\data\meat_steak_boiled.rvmat",
			"dz\gear\food\data\meat_steak_dried.rvmat",
			"dz\gear\food\data\meat_steak_burnt.rvmat",
			"dz\gear\food\data\meat_steak_rotten.rvmat"
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={2.5,100,30,1,50};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={2,97.5,35,1,100};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1.75,227.5,52.5,1,10};
					cooking_properties[]={70,45};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1.5,162.5,70,1,10};
					cooking_properties[]={70,55};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={0.75,130,7,1,10};
					cooking_properties[]={70,45,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={2,97.5,17.5,1,10};
					cooking_properties[]={100,30};
				};
			};
		};
		class NoiseImpact
		{
			strength=600;
			type="sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_Loop
				{
					soundSet="Eating_loop_Soundset";
					id=888;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_Fruit1
				{
					soundSet="Eating_Fruit_Soundset";
					id=890;
				};
				class Eating_Fruit2
				{
					soundSet="Eating_Fruit_Soundset";
					id=891;
				};
				class Eating_Fruit3
				{
					soundSet="Eating_Fruit_Soundset";
					id=892;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
};
class CfgSoundCurves
{
	class CfgSoundCurvesBloodVomit
	{
		points[]=
		{
			{0,1},
			{0.1,0.98000002},
			{0.2,0.92000002},
			{0.30000001,0.80000001},
			{0.40000001,0.64999998},
			{0.5,0.5},
			{0.60000002,0.34999999},
			{0.69999999,0.2},
			{0.80000001,0.079999998},
			{0.89999998,0.02},
			{1,0}
		};
	};
};
class CfgSound3DProcessors
{
	class default3DProcessingBloodVomit
	{
		type="emitter";
		innerRange=15;
		range=10;
		radius=5;
		volume=8;
	};
	class default3DProcessingTypeSpeech
	{
		type="emitter";
		innerRange=15;
		range=10;
		radius=5;
		volume=0.30118701;
	};
};
class CfgSoundShaders
{
	class base_SoundShaderBloodVomit
	{
		range=10;
		rangeCurve="CfgSoundCurvesBloodVomit";
		volume=8;
	};
	class base_SoundShaderPlayerInfected
	{
		range=10;
		rangeCurve="CfgSoundCurvesBloodVomit";
		volume=8;
	};
	class BloodVomit_SoundShader: base_SoundShaderBloodVomit
	{
		volume=8;
		range=10;
		rangeCurve="CfgSoundCurvesBloodVomit";
		samples[]=
		{
			
			{
				"disease\data\voice2.ogg",
				1
			},
			
			{
				"disease\data\voice4.ogg",
				1
			},
			
			{
				"disease\data\voice1.ogg",
				1
			},
			
			{
				"disease\data\voice5.ogg",
				1
			},
			
			{
				"disease\data\voice3.ogg",
				1
			}
		};
	};
	class PlayerInfected_SoundShader: base_SoundShaderPlayerInfected
	{
		volume=8;
		range=10;
		rangeCurve="CfgSoundCurvesBloodVomit";
		samples[]=
		{
			
			{
				"disease\data\zvoice1.ogg",
				1
			},
			
			{
				"disease\data\zvoice2.ogg",
				1
			},
			
			{
				"disease\data\zvoice3.ogg",
				1
			},
			
			{
				"disease\data\zvoice4.ogg",
				1
			}
		};
	};
};
class CfgSoundSets
{
	class base_SoundSet
	{
		sound3DProcessingType="default3DProcessingBloodVomit";
		spatial=1;
		doppler=0;
		loop=1;
	};
	class base_SoundSetSpeech
	{
		sound3DProcessingType="default3DProcessingTypeSpeech";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BloodVomit_SoundSet: base_SoundSet
	{
		soundShaders[]=
		{
			"BloodVomit_SoundShader"
		};
		volume=12;
	};
	class playerinfected_SoundSet: base_SoundSet
	{
		soundShaders[]=
		{
			"PlayerInfected_SoundShader"
		};
		volume=12;
	};
};
