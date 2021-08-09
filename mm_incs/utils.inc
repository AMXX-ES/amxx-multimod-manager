#if defined _mm_utils_included_
	#endinput
#endif
#define _mm_utils_included_

stock UTIL_GetCurrentMod(const szFilePath[PLATFORM_MAX_PATH], szOut[], const iLen)
{
	if(file_exists(szFilePath))
	{
		new iFile = fopen(szFilePath, "r");

		if(iFile)
		{
			new szLine[PLATFORM_MAX_PATH];
			fgets(iFile, szLine, charsmax(szLine));
			trim(szLine);

			replace_string(szLine, charsmax(szLine), ";Mod:", "");
			
			copy(szOut, iLen, szLine);

			fclose(iFile);
		}
	}
}

stock ChangeMap_e:UTIL_GetChangeMapType(const iMod)
{
	if(g_GlobalConfigs[Mods] == Invalid_Array || ArraySize(g_GlobalConfigs[Mods]) < 1)
		return CHANGEMAP_END_OF_ROUND;

	new aData[ArrayMods_e];
	ArrayGetArray(g_GlobalConfigs[Mods], iMod, aData);

	return aData[ChangeMapType];
}

stock UTIL_RegisterClientCommandAll(const command[], function[], flags = -1, const info[] = "", FlagManager = -1, bool:info_ml = false)
{
	new sFormatCommand[PLATFORM_MAX_PATH];

	formatex(sFormatCommand, charsmax(sFormatCommand), "say %s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);
	
	formatex(sFormatCommand, charsmax(sFormatCommand), "say /%s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);

	formatex(sFormatCommand, charsmax(sFormatCommand), "say !%s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);
	
	formatex(sFormatCommand, charsmax(sFormatCommand), "say .%s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);

	formatex(sFormatCommand, charsmax(sFormatCommand), "say_team %s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);
	
	formatex(sFormatCommand, charsmax(sFormatCommand), "say_team /%s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);

	formatex(sFormatCommand, charsmax(sFormatCommand), "say_team !%s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);
	
	formatex(sFormatCommand, charsmax(sFormatCommand), "say_team .%s", command);
	register_clcmd(sFormatCommand, function, flags, info, FlagManager, info_ml);
}

public UTIL_GetPercent(const iVotes, const iTotal)
{
	return (iTotal < 1) ? 0 : ((iVotes * 100) / iTotal);
}