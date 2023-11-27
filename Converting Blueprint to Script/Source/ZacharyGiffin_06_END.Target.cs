// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ZacharyGiffin_06_ENDTarget : TargetRules
{
	public ZacharyGiffin_06_ENDTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ZacharyGiffin_06_END" } );
	}
}
