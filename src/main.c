#include <stdio.h>
#include <windows.h>

#include "json_utils.h"
#include "mod.h"
#include "util.h"

#include "game/bat.h"
#include "game/bear.h"
#include "game/box.h"
#include "game/control.h"
#include "game/demo.h"
#include "game/draw.h"
#include "game/effects.h"
#include "game/game.h"
#include "game/health.h"
#include "game/items.h"
#include "game/lara.h"
#include "game/lot.h"
#include "game/option.h"
#include "game/setup.h"
#include "game/text.h"
#include "specific/file.h"
#include "specific/init.h"
#include "specific/input.h"
#include "specific/output.h"

HINSTANCE hInstance = NULL;

static void Tomb1MInject()
{
    Tomb1MInjectGameBat();
    Tomb1MInjectGameBear();
    Tomb1MInjectGameBox();
    Tomb1MInjectGameControl();
    Tomb1MInjectGameDemo();
    Tomb1MInjectGameDraw();
    Tomb1MInjectGameEffects();
    Tomb1MInjectGameHealth();
    Tomb1MInjectGameItems();
    Tomb1MInjectGameLOT();
    Tomb1MInjectGameLara();
    Tomb1MInjectGameLaraFire();
    Tomb1MInjectGameLaraGun1();
    Tomb1MInjectGameLaraGun2();
    Tomb1MInjectGameLaraMisc();
    Tomb1MInjectGameLaraSurf();
    Tomb1MInjectGameLaraSwim();
    Tomb1MInjectGameOption();
    Tomb1MInjectGameSetup();
    Tomb1MInjectGameText();
    Tomb1MInjectSpecificFile();
    Tomb1MInjectSpecificGame();
    Tomb1MInjectSpecificInit();
    Tomb1MInjectSpecificInput();
    Tomb1MInjectSpecificOutput();
}

static int8_t Tomb1MReadHealthbarLocationConfig(
    json_value* root, const char* name, int8_t default_value)
{
    const char* value_str = tr1m_json_get_string_value(root, name);
    if (!value_str) {
        return default_value;
    }
    if (!strcmp(value_str, "top-left")) {
        return Tomb1M_BL_VTOP | Tomb1M_BL_HLEFT;
    } else if (!strcmp(value_str, "top-center")) {
        return Tomb1M_BL_VTOP | Tomb1M_BL_HCENTER;
    } else if (!strcmp(value_str, "top-right")) {
        return Tomb1M_BL_VTOP | Tomb1M_BL_HRIGHT;
    } else if (!strcmp(value_str, "bottom-left")) {
        return Tomb1M_BL_VBOTTOM | Tomb1M_BL_HLEFT;
    } else if (!strcmp(value_str, "bottom-center")) {
        return Tomb1M_BL_VBOTTOM | Tomb1M_BL_HCENTER;
    } else if (!strcmp(value_str, "bottom-right")) {
        return Tomb1M_BL_VBOTTOM | Tomb1M_BL_HRIGHT;
    }
    return default_value;
}

static int Tomb1MReadConfig()
{
    FILE* fp = fopen("Tomb1Main.json", "rb");
    if (!fp) {
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    int cfg_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* cfg_data = malloc(cfg_size);
    if (!cfg_data) {
        fclose(fp);
        return 0;
    }
    fread(cfg_data, 1, cfg_size, fp);
    fclose(fp);

    json_value* json = json_parse((const json_char*)cfg_data, cfg_size);

    T1MConfig.disable_healing_between_levels =
        tr1m_json_get_boolean_value(json, "disable_healing_between_levels");
    T1MConfig.disable_medpacks =
        tr1m_json_get_boolean_value(json, "disable_medpacks");
    T1MConfig.disable_magnums =
        tr1m_json_get_boolean_value(json, "disable_magnums");
    T1MConfig.disable_uzis = tr1m_json_get_boolean_value(json, "disable_uzis");
    T1MConfig.disable_shotgun =
        tr1m_json_get_boolean_value(json, "disable_shotgun");
    T1MConfig.enable_red_healthbar =
        tr1m_json_get_boolean_value(json, "enable_red_healthbar");
    T1MConfig.enable_enemy_healthbar =
        tr1m_json_get_boolean_value(json, "enable_enemy_healthbar");
    T1MConfig.enable_enhanced_look =
        tr1m_json_get_boolean_value(json, "enable_enhanced_look");
    T1MConfig.enable_enhanced_ui =
        tr1m_json_get_boolean_value(json, "enable_enhanced_ui");
    T1MConfig.enable_shotgun_flash =
        tr1m_json_get_boolean_value(json, "enable_shotgun_flash");
    T1MConfig.enable_cheats =
        tr1m_json_get_boolean_value(json, "enable_cheats");

    const char* healthbar_showing_mode =
        tr1m_json_get_string_value(json, "healthbar_showing_mode");
    T1MConfig.healthbar_showing_mode = Tomb1M_BSM_DEFAULT;
    if (healthbar_showing_mode) {
        if (!strcmp(healthbar_showing_mode, "flashing")) {
            T1MConfig.healthbar_showing_mode = Tomb1M_BSM_FLASHING;
        } else if (!strcmp(healthbar_showing_mode, "always")) {
            T1MConfig.healthbar_showing_mode = Tomb1M_BSM_ALWAYS;
        }
    }

    T1MConfig.healthbar_location = Tomb1MReadHealthbarLocationConfig(
        json, "healthbar_location", Tomb1M_BL_VTOP | Tomb1M_BL_HLEFT);
    T1MConfig.airbar_location = Tomb1MReadHealthbarLocationConfig(
        json, "airbar_location", Tomb1M_BL_VTOP | Tomb1M_BL_HRIGHT);
    T1MConfig.enemy_healthbar_location = Tomb1MReadHealthbarLocationConfig(
        json, "enemy_healthbar_location", Tomb1M_BL_VBOTTOM | Tomb1M_BL_HLEFT);

    T1MConfig.enable_numeric_keys =
        tr1m_json_get_boolean_value(json, "enable_numeric_keys");
    T1MConfig.fix_end_of_level_freeze =
        tr1m_json_get_boolean_value(json, "fix_end_of_level_freeze");
    T1MConfig.fix_tihocan_secret_sound =
        tr1m_json_get_boolean_value(json, "fix_tihocan_secret_sound");
    T1MConfig.fix_pyramid_secret_trigger =
        tr1m_json_get_boolean_value(json, "fix_pyramid_secret_trigger");
    T1MConfig.fix_hardcoded_secret_counts =
        tr1m_json_get_boolean_value(json, "fix_hardcoded_secret_counts");

    json_value_free(json);
    free(cfg_data);
    return 1;
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        freopen("./Tomb1Main.log", "w", stdout);
        Tomb1MReadConfig();
        TRACE("Attached");
        hInstance = hinstDLL;
        Tomb1MInject();
        break;

    case DLL_PROCESS_DETACH:
        TRACE("Detached");
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;
    }

    return TRUE;
}
