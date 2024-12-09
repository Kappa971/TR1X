// This file is autogenerated. To update it, run tools/generate_funcs.

#pragma once

#include "global/types.h"
#include "inject_util.h"

// clang-format off
#define g_IID_IDirectDrawSurface3 (*(GUID*)0x00463150)
#define g_IID_IDirect3DTexture2 (*(GUID*)0x00463170)
#define g_PerspectiveDistance (*(uint32_t*)0x00464060) // = 0x3000000
#define g_PolyDrawRoutines (*((void(__cdecl  *(*)[9])(const int16_t *obj_ptr))0x00464068))
#define g_CineTrackID (*(int32_t*)0x004640B0) // = 1
#define g_CineTickRate (*(int32_t*)0x004640B8) // = 0x8000
#define g_FlipEffect (*(int32_t*)0x004640C4) // = -1
#define g_BoxLines (*(int32_t(*)[12][2])0x00464180)
#define g_AssaultBestTime (*(int32_t*)0x004641F0) // = -1
#define g_EffectRoutines (*((void(__cdecl  *(*)[32])(ITEM *item))0x004641F8))
#define g_GF_NumSecrets (*(int16_t*)0x004642E8) // = 3
#define g_GF_MusicTracks (*(int16_t(*)[16])0x004642F0)
#define g_CineTargetAngle (*(int16_t*)0x00464310) // = 0x4000
#define g_OverlayStatus (*(int32_t*)0x004644E0) // = 1
#define g_Inv_NFrames (*(int32_t*)0x004644F8)
#define g_Requester_BackgroundGour1 (*(const uint16_t(*)[])0x00464500)
#define g_Requester_BackgroundGour2 (*(const uint16_t(*)[])0x00464520)
#define g_Requester_MainGour1 (*(const uint16_t(*)[])0x00464538)
#define g_Requester_MainGour2 (*(const uint16_t(*)[])0x00464558)
#define g_Requester_SelectionGour2 (*(const uint16_t(*)[])0x00464590)
#define g_Requester_UnselectionGour1 (*(const uint16_t(*)[])0x004645A8)
#define g_Inv_Item_Stopwatch (*(INVENTORY_ITEM*)0x00464A90)
#define g_Inv_Item_Pistols (*(INVENTORY_ITEM*)0x00464AE0)
#define g_Inv_Item_Flare (*(INVENTORY_ITEM*)0x00464B30)
#define g_Inv_Item_Shotgun (*(INVENTORY_ITEM*)0x00464B80)
#define g_Inv_Item_Magnums (*(INVENTORY_ITEM*)0x00464BD0)
#define g_Inv_Item_Uzis (*(INVENTORY_ITEM*)0x00464C20)
#define g_Inv_Item_Harpoon (*(INVENTORY_ITEM*)0x00464C70)
#define g_Inv_Item_M16 (*(INVENTORY_ITEM*)0x00464CC0)
#define g_Inv_Item_Grenade (*(INVENTORY_ITEM*)0x00464D10)
#define g_Inv_Item_PistolAmmo (*(INVENTORY_ITEM*)0x00464D60)
#define g_Inv_Item_ShotgunAmmo (*(INVENTORY_ITEM*)0x00464DB0)
#define g_Inv_Item_MagnumAmmo (*(INVENTORY_ITEM*)0x00464E00)
#define g_Inv_Item_UziAmmo (*(INVENTORY_ITEM*)0x00464E50)
#define g_Inv_Item_HarpoonAmmo (*(INVENTORY_ITEM*)0x00464EA0)
#define g_Inv_Item_M16Ammo (*(INVENTORY_ITEM*)0x00464EF0)
#define g_Inv_Item_GrenadeAmmo (*(INVENTORY_ITEM*)0x00464F40)
#define g_Inv_Item_SmallMedi (*(INVENTORY_ITEM*)0x00464F90)
#define g_Inv_Item_LargeMedi (*(INVENTORY_ITEM*)0x00464FE0)
#define g_Inv_Item_Pickup1 (*(INVENTORY_ITEM*)0x00465030)
#define g_Inv_Item_Pickup2 (*(INVENTORY_ITEM*)0x00465080)
#define g_Inv_Item_Puzzle1 (*(INVENTORY_ITEM*)0x004650D0)
#define g_Inv_Item_Puzzle2 (*(INVENTORY_ITEM*)0x00465120)
#define g_Inv_Item_Puzzle3 (*(INVENTORY_ITEM*)0x00465170)
#define g_Inv_Item_Puzzle4 (*(INVENTORY_ITEM*)0x004651C0)
#define g_Inv_Item_Key1 (*(INVENTORY_ITEM*)0x00465210)
#define g_Inv_Item_Key2 (*(INVENTORY_ITEM*)0x00465260)
#define g_Inv_Item_Key3 (*(INVENTORY_ITEM*)0x004652B0)
#define g_Inv_Item_Key4 (*(INVENTORY_ITEM*)0x00465300)
#define g_Inv_Item_Passport (*(INVENTORY_ITEM*)0x00465350)
#define g_Inv_Item_Graphics (*(INVENTORY_ITEM*)0x004653A0)
#define g_Inv_Item_Sound (*(INVENTORY_ITEM*)0x004653F0)
#define g_Inv_Item_Controls (*(INVENTORY_ITEM*)0x00465440)
#define g_Inv_Item_Photo (*(INVENTORY_ITEM*)0x00465490)
#define g_Inv_MainObjectsCount (*(int16_t*)0x004654E0) // = 8
#define g_Inv_MainQtys (*(int16_t(*)[])0x004654E8)
#define g_Inv_MainList (*(INVENTORY_ITEM *(*)[])0x00465518)
#define g_Inv_KeysQtys (*(int16_t(*)[])0x00465578)
#define g_Inv_KeysList (*(INVENTORY_ITEM *(*)[])0x004655A8)
#define g_GymInvOpenEnabled (*(BOOL*)0x00465618) // = TRUE
#define g_LoadGameRequester (*(REQUEST_INFO*)0x00465620)
#define g_SaveGameRequester (*(REQUEST_INFO*)0x00465838)
#define g_Inv_Chosen (*(int16_t*)0x00465A50) // = -1
#define g_Inv_Mode (*(INVENTORY_MODE*)0x00465A54) // = INV_TITLE_MODE
#define g_JumpPermitted (*(int32_t*)0x00465AD4) // = 1
#define g_LaraOldSlideAngle (*(int16_t*)0x00465AD8) // = 1
#define g_Weapons (*(WEAPON_INFO(*)[])0x00465AE0)
#define g_LaraControlRoutines (*((void(__cdecl  *(*)[71])(ITEM *item, COLL_INFO *coll))0x00465CD0))
#define g_ExtraControlRoutines (*((void(__cdecl  *(*)[11])(ITEM *item, COLL_INFO *coll))0x00465DF0))
#define g_LaraCollisionRoutines (*((void(__cdecl  *(*)[71])(ITEM *item, COLL_INFO *coll))0x00465E20))
#define g_MovableBlockBounds (*(int16_t(*)[])0x00465F40)
#define g_ZiplineHandleBounds (*(int16_t(*)[])0x00465F58)
#define g_ZiplineHandlePosition (*(XYZ_32*)0x00465F70)
#define g_PickupBounds (*(int16_t(*)[])0x00465FF0)
#define g_PickupPosition (*(XYZ_32*)0x00466008)
#define g_GongBounds (*(int16_t(*)[])0x00466018)
#define g_PickupBoundsUW (*(int16_t(*)[])0x00466030)
#define g_PickupPositionUW (*(XYZ_32*)0x00466048)
#define g_SwitchBounds (*(int16_t(*)[])0x00466058)
#define g_SmallSwitchPosition (*(XYZ_32*)0x00466070)
#define g_PushSwitchPosition (*(XYZ_32*)0x00466080)
#define g_AirlockPosition (*(XYZ_32*)0x00466090)
#define g_SwitchBoundsUW (*(int16_t(*)[])0x004660A0)
#define g_SwitchUWPosition (*(XYZ_32*)0x004660B8)
#define g_KeyholeBounds (*(int16_t(*)[])0x004660C8)
#define g_KeyholePosition (*(XYZ_32*)0x004660E0)
#define g_PuzzleHoleBounds (*(int16_t(*)[])0x004660F0)
#define g_PuzzleHolePosition (*(XYZ_32*)0x00466108)
#define g_BGND_PaletteIndex (*(int32_t*)0x00466400) // = -1
#define g_FadeValue (*(int32_t*)0x00466490) // = 0x100000
#define g_FadeLimit (*(int32_t*)0x00466494) // = 0x100000
#define g_FadeAdder (*(int32_t*)0x00466498) // = 0x8000
#define g_ErrorMessages (*(const char *(*)[43])0x004664E8)
#define g_SavedLevels (*(int16_t(*)[24])0x00466B80)
#define g_MidSort (*(int32_t*)0x0046C300) // = 0
#define g_ViewportAspectRatio (*(float*)0x0046C304) // = 0.0f
#define g_XGenY1 (*(int32_t*)0x0046C308)
#define g_XGenY2 (*(int32_t*)0x0046C30C)
#define g_GouraudTable (*(GOURAUD_ENTRY(*)[256])0x0046C310)
#define g_PhdWinTop (*(int32_t*)0x0046E310)
#define g_PhdSprites (*(PHD_SPRITE(*)[512])0x0046E318)
#define g_LsAdder (*(int32_t*)0x00470318)
#define g_FltWinBottom (*(float*)0x0047031C)
#define g_FltResZBuf (*(float*)0x00470320)
#define g_FltResZ (*(float*)0x00470324)
#define g_PhdWinHeight (*(int32_t*)0x0047032C)
#define g_PhdWinCenterX (*(int32_t*)0x00470330)
#define g_PhdWinCenterY (*(int32_t*)0x00470334)
#define g_LsYaw (*(int16_t*)0x00470338)
#define g_FltWinTop (*(float*)0x00470340)
#define g_SortBuffer (*(SORT_ITEM(*)[4000])0x00470348)
#define g_FltWinLeft (*(float*)0x00478048)
#define g_PhdFarZ (*(int32_t*)0x00478058)
#define g_FltRhwOPersp (*(float*)0x0047805C)
#define g_PhdWinBottom (*(int32_t*)0x00478060)
#define g_PhdPersp (*(int32_t*)0x00478064)
#define g_PhdWinLeft (*(int32_t*)0x00478068)
#define g_Info3DBuffer (*(int16_t(*)[120000])0x00478070)
#define g_PhdWinMaxX (*(int32_t*)0x004B29F0)
#define g_PhdNearZ (*(int32_t*)0x004B29F4)
#define g_FltResZORhw (*(float*)0x004B29F8)
#define g_FltFarZ (*(float*)0x004B29FC)
#define g_FltWinCenterX (*(float*)0x004B2A00)
#define g_FltWinCenterY (*(float*)0x004B2A04)
#define g_FltPerspONearZ (*(float*)0x004B2A14)
#define g_FltRhwONearZ (*(float*)0x004B2A18)
#define g_PhdWinMaxY (*(int32_t*)0x004B2A1C)
#define g_FltNearZ (*(float*)0x004B2A24)
#define g_MatrixPtr (*(MATRIX **)0x004B2A28)
#define g_RandomTable (*(int32_t(*)[32])0x004B2A38)
#define g_FltPersp (*(float*)0x004B2AB8)
#define g_W2VMatrix (*(MATRIX*)0x004B2AC0)
#define g_Info3DPtr (*(int16_t **)0x004B2AF0)
#define g_PhdWinWidth (*(int32_t*)0x004B2AF4)
#define g_PhdViewDistance (*(int32_t*)0x004BCB00)
#define g_LsPitch (*(int16_t*)0x004BCB04)
#define g_ShadesTable (*(int16_t(*)[32])0x004BCB10)
#define g_MatrixStack (*(MATRIX(*)[])0x004BCB58)
#define g_DepthQTable (*(DEPTHQ_ENTRY(*)[32])0x004BD2D8)
#define g_DepthQIndex (*(uint8_t(*)[256])0x004BF2D8)
#define g_LsDivider (*(int32_t*)0x004BF3DC)
#define g_PhdVBuf (*(PHD_VBUF(*)[1500])0x004BF3E0)
#define g_TexturePageBuffer8 (*(uint8_t *(*)[32])0x004D6AE0)
#define g_FltWinRight (*(float*)0x004D6B60)
#define g_LsVectorView (*(XYZ_32*)0x004D6B68)
#define g_WibbleTable (*(float(*)[32])0x004D6B78)
#define g_PhdWinRight (*(int32_t*)0x004D6BF8)
#define g_SurfaceCount (*(int32_t*)0x004D6BFC)
#define g_Sort3DPtr (*(SORT_ITEM **)0x004D6C00)
#define g_WibbleOffset (*(int32_t*)0x004D6C0C)
#define g_IsWibbleEffect (*(int32_t*)0x004D6C10)
#define g_IsWaterEffect (*(int32_t*)0x004D6C14)
#define g_IsShadeEffect (*(int8_t*)0x004D6F78)
#define g_GamePalette16 (*(PALETTEENTRY(*)[256])0x004D7380)
#define g_CineFrameCurrent (*(int32_t*)0x004D7780)
#define g_CineTickCount (*(int32_t*)0x004D7784)
#define g_OriginalRoom (*(int32_t*)0x004D7788)
#define g_IsChunkyCamera (*(int32_t*)0x004D778C)
#define g_HeightType (*(int32_t*)0x004D7790)
#define g_NoInputCounter (*(int32_t*)0x004D7794)
#define g_FlipTimer (*(int32_t*)0x004D779C)
#define g_LOSNumRooms (*(int32_t*)0x004D77A0) // = 0
#define g_IsDemoLevelType (*(BOOL*)0x004D77AC)
#define g_IsDemoLoaded (*(BOOL*)0x004D77B0)
#define g_BoundStart (*(int32_t*)0x004D77C0)
#define g_BoundEnd (*(int32_t*)0x004D77C4)
#define g_IsAssaultTimerDisplay (*(int32_t*)0x004D77E0)
#define g_IsAssaultTimerActive (*(BOOL*)0x004D77E4)
#define g_IsMonkAngry (*(BOOL*)0x004D77E8)
#define g_GF_ScriptVersion (*(int32_t*)0x004D77EC)
#define g_GF_LaraStartAnim (*(int32_t*)0x004D77F0)
#define g_GF_SunsetEnabled (*(int16_t*)0x004D77F4)
#define g_GF_DeadlyWater (*(int16_t*)0x004D77F8)
#define g_GF_NoFloor (*(int16_t*)0x004D77FC)
#define g_GF_RemoveWeapons (*(int16_t*)0x004D7800)
#define g_GF_RemoveAmmo (*(int16_t*)0x004D7804)
#define g_GF_Kill2Complete (*(char*)0x004D7808)
#define g_GF_StartGame (*(int8_t*)0x004D780C)
#define g_GF_Description (*(char(*)[256])0x004D7818)
#define g_AmmoTextInfo (*(TEXTSTRING **)0x004D792C)
#define g_DisplayModeTextInfo (*(TEXTSTRING **)0x004D7930)
#define g_DisplayModeInfoTimer (*(DWORD*)0x004D7934)
#define g_Inv_MainCurrent (*(UINT16*)0x004D7938)
#define g_Inv_KeyObjectsCount (*(UINT16*)0x004D793C)
#define g_Inv_KeysCurrent (*(UINT16*)0x004D7940)
#define g_Inv_OptionCurrent (*(UINT16*)0x004D7944)
#define g_Inv_ItemText (*(TEXTSTRING *(*)[3])0x004D7948)
#define g_Inv_LevelText (*(TEXTSTRING **)0x004D7950)
#define g_Inv_RingText (*(TEXTSTRING**)0x004D7954)
#define g_Inv_TagText (*(TEXTSTRING **)0x004D7958)
#define g_Inv_UpArrow1 (*(TEXTSTRING**)0x004D795C)
#define g_Inv_UpArrow2 (*(TEXTSTRING**)0x004D7960)
#define g_Inv_DownArrow1 (*(TEXTSTRING**)0x004D7964)
#define g_Inv_DownArrow2 (*(TEXTSTRING**)0x004D7968)
#define g_Inv_IsActive (*(uint16_t*)0x004D7978)
#define g_Inv_ExtraData (*(int32_t(*)[8])0x004D7980)
#define g_Inv_DemoMode (*(BOOL*)0x004D79A0)
#define g_Inv_IsOptionsDelay (*(BOOL*)0x004D79B4)
#define g_Inv_OptionsDelayCounter (*(int32_t*)0x004D79B8)
#define g_SoundOptionLine (*(uint16_t*)0x004D79BC)
#define g_StatsRequester (*(REQUEST_INFO*)0x004D79C0)
#define g_Assault (*(ASSAULT_STATS*)0x004D7BD8)
#define g_LevelItemCount (*(int32_t*)0x004D7C38)
#define g_HealthBarTimer (*(int32_t*)0x004D7C3C)
#define g_SlotsUsed (*(int32_t*)0x004D7C50)
#define g_InteractPosition (*(XYZ_32*)0x004D7C58)
#define g_DetonatorPosition (*(XYZ_32*)0x004D7C68)
#define g_NumCameras (*(int32_t*)0x004D7C74)
#define g_SoundTrackIds (*(int32_t(*)[128])0x004D7C80)
#define g_DetonateAllMines (*(int32_t*)0x004D7E7C)
#define g_BGND_PictureIsReady (*(bool*)0x004D7E88)
#define g_BGND_TexturePageIndexes (*(int32_t(*)[5])0x004D7E90)
#define g_BGND_PageHandles (*(HWR_TEXTURE_HANDLE(*)[5])0x004D7EA8)
#define g_MinWindowClientHeight (*(int32_t*)0x004D7ED0)
#define g_MaxWindowHeight (*(int32_t*)0x004D7EDC)
#define g_MinWindowClientWidth (*(int32_t*)0x004D7EF0)
#define g_IsMinWindowSizeSet (*(bool*)0x004D7EF8)
#define g_MaxWindowClientWidth (*(int32_t*)0x004D7EFC)
#define g_GameWindowHandle (*(HWND*)0x004D7F10)
#define g_LockedBufferCount (*(uint32_t*)0x004D8338)
#define g_DisplayAdapterList (*(DISPLAY_ADAPTER_LIST*)0x004D8348)
#define g_MaxWindowClientHeight (*(int32_t*)0x004D8354)
#define g_MaxWindowWidth (*(int32_t*)0x004D835C)
#define g_IsMaxWindowSizeSet (*(bool*)0x004D8360)
#define g_AppResultCode (*(uint32_t*)0x004D8364)
#define g_IsGameToExit (*(uint8_t*)0x004D8378)
#define g_MinWindowWidth (*(int32_t*)0x004D8388)
#define g_MinWindowHeight (*(int32_t*)0x004D838C)
#define g_IsGameWindowActive (*(bool*)0x004D8390)
#define g_MessageLoopCounter (*(int32_t*)0x004D8394)
#define g_IsSoundEnabled (*(uint8_t*)0x004D8D80)
#define g_ColorBitMasks (*(COLOR_BIT_MASKS*)0x004D92E8)
#define g_TexturePageCount (*(int32_t*)0x004D9360)
#define g_LabTextureUVFlag (*(uint8_t(*)[2048])0x004D93F0)
#define g_LevelFilePalettesOffset (*(int32_t*)0x004D9BF4)
#define g_LevelFileTexPagesOffset (*(int32_t*)0x004D9BF8)
#define g_GF_LevelOffsets (*(int16_t(*)[200])0x004D9C00)
#define g_MeshBase (*(int16_t **)0x004D9D90)
#define g_Legacy_FloorData (*(int16_t **)0x004D9D94)
#define g_LevelFileName (*(char(*)[256])0x004D9D98)
#define g_TextureInfoCount (*(int32_t*)0x004D9E98)
#define g_IsFMVPlaying (*(int32_t*)0x004D9EAC)
#define g_MovieContext (*(void **)0x004D9EB0)
#define g_FmvContext (*(void **)0x004D9EB4)
#define g_FmvSoundContext (*(void **)0x004D9EB8)
#define g_SavedGames (*(int32_t*)0x004D9EBC)
#define g_CurrentLevel (*(int32_t*)0x004D9EC0)
#define g_LevelComplete (*(int32_t*)0x004D9EC4)
#define g_SaveCounter (*(int32_t*)0x004D9EC8)
#define g_GameMode (*(int32_t*)0x004D9ECC)
#define g_GameBuf_MemCap (*(size_t*)0x0051A000)
#define g_GameBuf_MemPtr (*(char **)0x0051A004)
#define g_GameBuf_MemUsed (*(size_t*)0x0051A008)
#define g_GameBuf_MemFree (*(size_t*)0x0051A00C)
#define g_GameBuf_MemBase (*(char **)0x0051A0CC)
#define g_DIKeys (*(uint8_t(*)[256])0x0051A108)
#define g_IsVidModeLock (*(int8_t*)0x0051A20C)
#define g_GameModule (*(HINSTANCE*)0x0051A238)
#define g_CmdLine (*(char **)0x0051A23C)
#define g_ScreenshotCounter (*(int32_t*)0x0051A240)
#define g_PasswordText1 (*(TEXTSTRING **)0x0051A2CC)
#define g_PassportMode (*(int32_t*)0x0051A2D0)
#define g_SoundText (*(TEXTSTRING *(*)[4])0x0051A2F0)
#define g_WaterPalette (*(RGB_888(*)[256])0x0051B308)
#define g_PicturePalette (*(RGB_888(*)[256])0x0051B608)
#define g_AnimTextureRanges (*(int16_t **)0x0051B92C)
#define g_GamePalette8 (*(RGB_888(*)[256])0x0051B930)
#define g_IsWet (*(int32_t*)0x0051BC38)
#define g_IsTitleLoaded (*(BOOL*)0x0051BDA0)
#define g_MciDeviceID (*(MCIDEVICEID*)0x0051BDAC)
#define g_CD_LoopTrack (*(int32_t*)0x0051BDB0)
#define g_TextureFormat (*(TEXTURE_FORMAT*)0x0051C1B8)
#define g_TexturesHaveCompatibleMasks (*(uint8_t*)0x0051C20D)
#define g_NumSampleInfos (*(int32_t*)0x0051E6C0)
#define g_SoundIsActive (*(int32_t*)0x0051E6C4)
#define g_SampleLUT (*(int16_t(*)[])0x0051E6E0)
#define g_SampleInfos (*(SAMPLE_INFO **)0x0051E9C4)
#define g_SavegameBufPtr (*(char **)0x0051E9C8)
#define g_SaveGame (*(SAVEGAME_INFO*)0x0051E9E0)
#define g_SavegameBufPos (*(int32_t*)0x005206A4)
#define g_FinalBossActive (*(int16_t*)0x005206A8)
#define g_FinalBossItem (*(int16_t(*)[5])0x005206B0)
#define g_FinalLevelCount (*(int16_t*)0x005206BA)
#define g_FinalBossCount (*(int16_t*)0x005206BC)
#define g_BaddieSlots (*(CREATURE **)0x005206C0)
#define g_Lara (*(LARA_INFO*)0x005206E0)
#define g_LaraItem (*(ITEM **)0x005207BC)
#define g_Effects (*(FX **)0x005207C0)
#define g_NextEffectFree (*(int16_t*)0x005207C4)
#define g_NextItemFree (*(int16_t*)0x005207C6)
#define g_NextItemActive (*(int16_t*)0x005207C8)
#define g_NextEffectActive (*(int16_t*)0x005207CA)
#define g_PrevItemActive (*(int16_t*)0x005207CC)
#define g_ValidLevelStrings1 (*(char(*)[])0x005207E0)
#define g_RequesterFlags2 (*(uint32_t(*)[24])0x00520CA0)
#define g_RequesterFlags1 (*(uint32_t(*)[24])0x00520D00)
#define g_InvColors (*(uint16_t(*)[17])0x005216E0)
#define g_ValidLevelStrings2 (*(char(*)[])0x00521720)
#define g_SaveGameReqFlags2 (*(uint32_t(*)[24])0x00521BE0)
#define g_SaveGameReqFlags1 (*(uint32_t(*)[24])0x00521C40)
#define g_Pickups (*(PICKUP_INFO(*)[12])0x00521CA0)
#define g_GF_Puzzle1Strings (*(char ***)0x00521DC0)
#define g_GF_CutsceneFileNames (*(char ***)0x00521DC4)
#define g_GameFlow (*(GAME_FLOW*)0x00521DE0)
#define g_GF_Puzzle4Strings (*(char ***)0x00521E60)
#define g_GF_Pickup1StringsBuf (*(char **)0x00521E64)
#define g_GF_FMVFilenamesBuf (*(char **)0x00521E68)
#define g_GF_Key1StringsBuf (*(char **)0x00521E6C)
#define g_GF_FrontendSequence (*(int16_t **)0x00521E70)
#define g_GF_Key2Strings (*(char ***)0x00521E74)
#define g_GF_CutsceneFileNamesBuf (*(char **)0x00521E78)
#define g_GF_Key4StringsBuf (*(char **)0x00521E7C)
#define g_GF_SequenceBuf (*(int16_t **)0x00521E80)
#define g_GF_Key2StringsBuf (*(char **)0x00521E84)
#define g_GF_Pickup2StringsBuf (*(char **)0x00521E88)
#define g_GF_PicFilenamesBuf (*(char **)0x00521E8C)
#define g_GF_Key4Strings (*(char ***)0x00521E90)
#define g_GF_Pickup1Strings (*(char ***)0x00521E94)
#define g_GF_Puzzle2Strings (*(char ***)0x00521E98)
#define g_GF_LevelFileNamesBuf (*(char **)0x00521E9C)
#define g_GF_PicFilenames (*(char ***)0x00521EA0)
#define g_GF_Key1Strings (*(char ***)0x00521EA4)
#define g_GF_Puzzle1StringsBuf (*(char **)0x00521EA8)
#define g_GF_LevelNamesBuf (*(char **)0x00521EAC)
#define g_GF_GameStrings (*(char ***)0x00521EB0)
#define g_GF_PCStringsBuf (*(char **)0x00521EB4)
#define g_GF_GameStringsBuf (*(char **)0x00521EB8)
#define g_GF_Key3Strings (*(char ***)0x00521EBC)
#define g_GF_Puzzle3Strings (*(char ***)0x00521EC0)
#define g_GF_LevelNames (*(char ***)0x00521EC4)
#define g_GF_ScriptTable (*(int16_t *(*)[24])0x00521EE0)
#define g_GF_Puzzle2StringsBuf (*(char **)0x00521F40)
#define g_GF_Pickup2Strings (*(char ***)0x00521F44)
#define g_GF_TitleFileNames (*(char ***)0x00521F48)
#define g_GF_TitleFileNamesBuf (*(char **)0x00521F4C)
#define g_GF_PCStrings (*(char ***)0x00521F50)
#define g_GF_LevelFileNames (*(char ***)0x00521F54)
#define g_GF_ValidDemos (*(int16_t(*)[24])0x00521F60)
#define g_GF_Puzzle4StringsBuf (*(char **)0x00521F90)
#define g_GF_FMVFilenames (*(char ***)0x00521F94)
#define g_GF_Puzzle3StringsBuf (*(char **)0x00521F98)
#define g_GF_Key3StringsBuf (*(char **)0x00521F9C)
#define g_GF_SecretInvItems (*(char(*)[27])0x00521FA0)
#define g_GF_Add2InvItems (*(char(*)[27])0x00521FC0)
#define g_SoundEffectCount (*(int32_t*)0x00521FDC)
#define g_SoundEffects (*(OBJECT_VECTOR **)0x00521FE0)
#define g_Objects (*(OBJECT(*)[265])0x00522000)
#define g_AnimFrames (*(FRAME_INFO **)0x005251B0)
#define g_Meshes (*(int16_t ***)0x005252B0)
#define g_Outside (*(int32_t*)0x005252B4)
#define g_IMMatrixStack (*(MATRIX(*)[256])0x005252C0)
#define g_DoorVBuf (*(PORTAL_VBUF(*)[4])0x005258C0)
#define g_IMFrac (*(int32_t*)0x005258F0)
#define g_Anims (*(ANIM **)0x005258F4)
#define g_BoundRooms (*(int32_t(*)[128])0x00525900)
#define g_OutsideBottom (*(int32_t*)0x00525B00)
#define g_AnimRanges (*(ANIM_RANGE **)0x00525B04)
#define g_AnimCommands (*(int16_t **)0x00525B08)
#define g_AnimBones (*(int32_t **)0x00525BE8)
#define g_DynamicLightCount (*(int32_t*)0x00525BEC)
#define g_StaticObjects (*(STATIC_INFO(*)[50])0x00525C00)
#define g_OutsideLeft (*(int32_t*)0x00526178)
#define g_AnimChanges (*(ANIM_CHANGE **)0x0052617C)
#define g_RoomCount (*(int32_t*)0x00526180)
#define g_IMRate (*(int32_t*)0x00526184)
#define g_IMMatrixPtr (*(MATRIX **)0x00526188)
#define g_Rooms (*(ROOM **)0x0052618C)
#define g_CameraUnderwater (*(BOOL*)0x00526190)
#define g_OutsideRight (*(int32_t*)0x00526198)
#define g_OutsideTop (*(int32_t*)0x005261AC)
#define g_DemoPtr (*(uint32_t **)0x005261B0)
#define g_DemoCount (*(int32_t*)0x005261B4)
#define g_MusicTrackFlags (*(uint16_t(*)[64])0x005261C0)
#define g_FlipStatus (*(int32_t*)0x00526240)
#define g_FlipMaps (*(int32_t(*)[10])0x00526260)
#define g_Legacy_TriggerIndex (*(int16_t **)0x00526288)
#define g_LOSRooms (*(int32_t(*)[20])0x005262A0)
#define g_Items (*(ITEM **)0x005262F0)
#define g_CineLoaded (*(int16_t*)0x005262F4)
#define g_NumCineFrames (*(int16_t*)0x005262F6)
#define g_CineData (*(CINE_FRAME **)0x005262F8) // = NULL
#define g_CinePos (*(PHD_3DPOS*)0x00526300)
#define g_CineFrameIdx (*(int16_t*)0x00526314)
#define g_Camera (*(CAMERA_INFO*)0x00526320)
#define g_GroundZone (*(int16_t *(*)[][2])0x005263A0)
#define g_FlyZone (*(int16_t *(*)[2])0x005263C0)
#define g_Overlap (*(uint16_t **)0x005263C8)
#define g_Boxes (*(BOX_INFO **)0x005263CC)
#define g_BoxCount (*(int32_t*)0x005263D0)

// clang-format on
