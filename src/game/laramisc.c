#include "3dsystem/phd_math.h"
#include "game/control.h"
#include "game/data.h"
#include "game/effects.h"
#include "game/inv.h"
#include "game/lara.h"
#include "game/lot.h"
#include "game/misc.h"
#include "specific/sndpc.h"
#include "mod.h"
#include "util.h"

void __cdecl LaraControl(int16_t item_num)
{
    COLL_INFO coll = { 0 };

    ITEM_INFO* item = LaraItem;
    ROOM_INFO* r = &RoomInfo[item->room_number];
    int32_t room_submerged = r->flags & RF_UNDERWATER;

    if (Lara.water_status == LWS_ABOVEWATER && room_submerged) {
        Lara.water_status = LWS_UNDERWATER;
        Lara.air = LARA_AIR;
        item->pos.y += 100;
        item->gravity_status = 0;
        UpdateLaraRoom(item, 0);
        StopSoundEffect(30, 0);
        if (item->current_anim_state == AS_SWANDIVE) {
            item->goal_anim_state = AS_DIVE;
            item->pos.x_rot = -45 * ONE_DEGREE;
            AnimateLara(item);
            item->fall_speed *= 2;
        } else if (item->current_anim_state == AS_FASTDIVE) {
            item->goal_anim_state = AS_DIVE;
            item->pos.x_rot = -85 * ONE_DEGREE;
            AnimateLara(item);
            item->fall_speed *= 2;
        } else {
            item->current_anim_state = AS_DIVE;
            item->goal_anim_state = AS_SWIM;
            item->anim_number = AA_JUMPIN;
            item->frame_number = AF_JUMPIN;
            item->pos.x_rot = -45 * ONE_DEGREE;
            item->fall_speed = (item->fall_speed * 3) / 2;
        }
        Lara.head_x_rot = 0;
        Lara.head_y_rot = 0;
        Lara.torso_x_rot = 0;
        Lara.torso_y_rot = 0;
        Splash(item);
    } else if (Lara.water_status == LWS_UNDERWATER && !room_submerged) {
        int16_t wh = GetWaterHeight(
            item->pos.x, item->pos.y, item->pos.z, item->room_number);
        if (wh != NO_HEIGHT && ABS(wh - item->pos.y) < STEP_L) {
            Lara.water_status = LWS_SURFACE;
            Lara.dive_count = DIVE_COUNT + 1;
            item->current_anim_state = AS_SURFTREAD;
            item->goal_anim_state = AS_SURFTREAD;
            item->anim_number = AA_SURFTREAD;
            item->frame_number = AF_SURFTREAD;
            item->fall_speed = 0;
            item->pos.y = wh + 1;
            item->pos.x_rot = 0;
            item->pos.z_rot = 0;
            Lara.head_x_rot = 0;
            Lara.head_y_rot = 0;
            Lara.torso_x_rot = 0;
            Lara.torso_y_rot = 0;
            UpdateLaraRoom(item, -LARA_HITE / 2);
            SoundEffect(36, &item->pos, SFX_ALWAYS);
        } else {
            Lara.water_status = LWS_ABOVEWATER;
            Lara.gun_status = LGS_ARMLESS;
            item->current_anim_state = AS_FORWARDJUMP;
            item->goal_anim_state = AS_FORWARDJUMP;
            item->anim_number = AA_FALLDOWN;
            item->frame_number = AF_FALLDOWN;
            item->speed = item->fall_speed / 4;
            item->fall_speed = 0;
            item->gravity_status = 1;
            item->pos.x_rot = 0;
            item->pos.z_rot = 0;
            Lara.head_x_rot = 0;
            Lara.head_y_rot = 0;
            Lara.torso_x_rot = 0;
            Lara.torso_y_rot = 0;
        }
    } else if (Lara.water_status == LWS_SURFACE && !room_submerged) {
        Lara.water_status = LWS_ABOVEWATER;
        Lara.gun_status = LGS_ARMLESS;
        item->current_anim_state = AS_FORWARDJUMP;
        item->goal_anim_state = AS_FORWARDJUMP;
        item->anim_number = AA_FALLDOWN;
        item->frame_number = AF_FALLDOWN;
        item->speed = item->fall_speed / 4;
        item->fall_speed = 0;
        item->gravity_status = 1;
        item->pos.x_rot = 0;
        item->pos.z_rot = 0;
        Lara.head_x_rot = 0;
        Lara.head_y_rot = 0;
        Lara.torso_x_rot = 0;
        Lara.torso_y_rot = 0;
    }

    if (item->hit_points <= 0) {
        item->hit_points = -1;
        if (!Lara.death_count) {
            S_CDStop();
        }
        Lara.death_count++;
    }

    switch (Lara.water_status) {
    case LWS_ABOVEWATER:
        Lara.air = LARA_AIR;
        LaraAboveWater(item, &coll);
        break;

    case LWS_UNDERWATER:
        if (item->hit_points >= 0) {
            Lara.air--;
            if (Lara.air < 0) {
                Lara.air = -1;
                item->hit_points -= 5;
            }
        }
        LaraUnderWater(item, &coll);
        break;

    case LWS_SURFACE:
        if (item->hit_points >= 0) {
            Lara.air += 10;
            if (Lara.air > LARA_AIR) {
                Lara.air = LARA_AIR;
            }
        }
        LaraSurface(item, &coll);
        break;
    }
}

void __cdecl LaraSwapMeshExtra()
{
    if (!Objects[O_LARA_EXTRA].loaded) {
        return;
    }
    for (int i = 0; i < 15; i++) {
        Lara.mesh_ptrs[i] = Meshes[(&Objects[O_LARA_EXTRA])->mesh_index + i];
    }
}

void __cdecl AnimateLara(ITEM_INFO* item)
{
    int16_t* command;
    ANIM_STRUCT* anim;

    item->frame_number++;
    anim = &Anims[item->anim_number];
    if (anim->number_changes > 0 && GetChange(item, anim)) {
        anim = &Anims[item->anim_number];
        item->current_anim_state = anim->current_anim_state;
    }

    if (item->frame_number > anim->frame_end) {
        if (anim->number_commands > 0) {
            command = &AnimCommands[anim->command_index];
            for (int i = 0; i < anim->number_commands; i++) {
                switch (*command++) {
                case AC_MOVE_ORIGIN:
                    TranslateItem(item, command[0], command[1], command[2]);
                    command += 3;
                    break;

                case AC_JUMP_VELOCITY:
                    item->fall_speed = command[0];
                    item->speed = command[1];
                    command += 2;
                    item->gravity_status = 1;
                    if (Lara.calc_fallspeed) {
                        item->fall_speed = Lara.calc_fallspeed;
                        Lara.calc_fallspeed = 0;
                    }
                    break;

                case AC_ATTACK_READY:
                    Lara.gun_status = LGS_ARMLESS;
                    break;

                case AC_SOUND_FX:
                case AC_EFFECT:
                    command += 2;
                    break;
                }
            }
        }

        item->anim_number = anim->jump_anim_num;
        item->frame_number = anim->jump_frame_num;

        anim = &Anims[anim->jump_anim_num];
        item->current_anim_state = anim->current_anim_state;
    }

    if (anim->number_commands > 0) {
        command = &AnimCommands[anim->command_index];
        for (int i = 0; i < anim->number_commands; i++) {
            switch (*command++) {
            case AC_MOVE_ORIGIN:
                command += 3;
                break;

            case AC_JUMP_VELOCITY:
                command += 2;
                break;

            case AC_SOUND_FX:
                if (item->frame_number == command[0]) {
                    SoundEffect(command[1], &item->pos, SFX_ALWAYS);
                }
                command += 2;
                break;

            case AC_EFFECT:
                if (item->frame_number == command[0]) {
                    EffectRoutines[command[1]](item);
                }
                command += 2;
                break;
            }
        }
    }

    if (item->gravity_status) {
        int32_t speed = anim->velocity
            + anim->acceleration * (item->frame_number - anim->frame_base - 1);
        item->speed -= (int16_t)(speed >> 16);
        speed += anim->acceleration;
        item->speed += (int16_t)(speed >> 16);

        item->fall_speed += (item->fall_speed < FASTFALL_SPEED) ? GRAVITY : 1;
        item->pos.y += item->fall_speed;
    } else {
        int32_t speed = anim->velocity;
        if (anim->acceleration) {
            speed +=
                anim->acceleration * (item->frame_number - anim->frame_base);
        }
        item->speed = (int16_t)(speed >> 16);
    }

    item->pos.x += (phd_sin(Lara.move_angle) * item->speed) >> W2V_SHIFT;
    item->pos.z += (phd_cos(Lara.move_angle) * item->speed) >> W2V_SHIFT;
}

void __cdecl UseItem(int16_t object_num)
{
    TRACE("%d", object_num);
    switch (object_num) {
    case O_GUN_ITEM:
    case O_GUN_OPTION:
        Lara.request_gun_type = LGT_PISTOLS;
        if (Lara.gun_status == LGS_ARMLESS && Lara.gun_type == LGT_PISTOLS) {
            Lara.gun_type = LGT_UNARMED;
        }
        break;

    case O_SHOTGUN_ITEM:
    case O_SHOTGUN_OPTION:
        Lara.request_gun_type = LGT_SHOTGUN;
        if (Lara.gun_status == LGS_ARMLESS && Lara.gun_type == LGT_SHOTGUN) {
            Lara.gun_type = LGT_UNARMED;
        }
        break;

    case O_MAGNUM_ITEM:
    case O_MAGNUM_OPTION:
        Lara.request_gun_type = LGT_MAGNUMS;
        if (Lara.gun_status == LGS_ARMLESS && Lara.gun_type == LGT_MAGNUMS) {
            Lara.gun_type = LGT_UNARMED;
        }
        break;

    case O_UZI_ITEM:
    case O_UZI_OPTION:
        Lara.request_gun_type = LGT_UZIS;
        if (Lara.gun_status == LGS_ARMLESS && Lara.gun_type == LGT_UZIS) {
            Lara.gun_type = LGT_UNARMED;
        }
        break;

    case O_MEDI_ITEM:
    case O_MEDI_OPTION:
        if (LaraItem->hit_points <= 0
            || LaraItem->hit_points >= LARA_HITPOINTS) {
            return;
        }
        LaraItem->hit_points += LARA_HITPOINTS / 2;
        if (LaraItem->hit_points > LARA_HITPOINTS) {
            LaraItem->hit_points = LARA_HITPOINTS;
        }
        Inv_RemoveItem(O_MEDI_ITEM);
        SoundEffect(116, NULL, SFX_ALWAYS);
        break;

    case O_BIGMEDI_ITEM:
    case O_BIGMEDI_OPTION:
        if (LaraItem->hit_points <= 0
            || LaraItem->hit_points >= LARA_HITPOINTS) {
            return;
        }
        LaraItem->hit_points = LaraItem->hit_points + LARA_HITPOINTS;
        if (LaraItem->hit_points > LARA_HITPOINTS) {
            LaraItem->hit_points = LARA_HITPOINTS;
        }
        Inv_RemoveItem(O_BIGMEDI_ITEM);
        SoundEffect(116, NULL, SFX_ALWAYS);
        break;
    }
}

void __cdecl ControlLaraExtra(int16_t item_num)
{
    AnimateItem(&Items[item_num]);
}

void __cdecl InitialiseLaraLoad(int16_t item_num)
{
    Lara.item_number = item_num;
    LaraItem = &Items[item_num];
}

void __cdecl InitialiseLara()
{
    TRACE("");
    LaraItem->collidable = 0;
    LaraItem->data = &Lara;
    LaraItem->hit_points = Tomb1MConfig.disable_healing_between_levels
        ? Tomb1MData.stored_lara_health
        : LARA_HITPOINTS;

    Lara.air = LARA_AIR;
    Lara.torso_y_rot = 0;
    Lara.torso_x_rot = 0;
    Lara.torso_z_rot = 0;
    Lara.head_y_rot = 0;
    Lara.head_x_rot = 0;
    Lara.head_z_rot = 0;
    Lara.calc_fallspeed = 0;
    Lara.mesh_effects = 0;
    Lara.hit_frames = 0;
    Lara.hit_direction = 0;
    Lara.death_count = 0;
    Lara.target = 0;
    Lara.spaz_effect = 0;
    Lara.spaz_effect_count = 0;
    Lara.turn_rate = 0;
    Lara.move_angle = 0;
    Lara.right_arm.flash_gun = 0;
    Lara.left_arm.flash_gun = 0;
    Lara.right_arm.lock = 0;
    Lara.left_arm.lock = 0;

    if (RoomInfo[LaraItem->room_number].flags & 1) {
        Lara.water_status = LWS_UNDERWATER;
        LaraItem->fall_speed = 0;
        LaraItem->goal_anim_state = AS_TREAD;
        LaraItem->current_anim_state = AS_TREAD;
        LaraItem->anim_number = AA_TREAD;
        LaraItem->frame_number = AF_TREAD;
    } else {
        Lara.water_status = LWS_ABOVEWATER;
        LaraItem->goal_anim_state = AS_STOP;
        LaraItem->current_anim_state = AS_STOP;
        LaraItem->anim_number = AA_STOP;
        LaraItem->frame_number = AF_STOP;
    }

    Lara.current_active = 0;

    InitialiseLOT(&Lara.LOT);
    Lara.LOT.step = WALL_L * 20;
    Lara.LOT.drop = -WALL_L * 20;
    Lara.LOT.fly = STEP_L;

    InitialiseLaraInventory(CurrentLevel);
}

void (*LaraControlRoutines[])(ITEM_INFO* item, COLL_INFO* coll) = {
    LaraAsWalk,      LaraAsRun,       LaraAsStop,      LaraAsForwardJump,
    LaraAsPose,      LaraAsFastBack,  LaraAsTurnR,     LaraAsTurnL,
    LaraAsDeath,     LaraAsFastFall,  LaraAsHang,      LaraAsReach,
    LaraAsSplat,     LaraAsTread,     LaraAsLand,      LaraAsCompress,
    LaraAsBack,      LaraAsSwim,      LaraAsGlide,     LaraAsNull,
    LaraAsFastTurn,  LaraAsStepRight, LaraAsStepLeft,  LaraAsRoll2,
    LaraAsSlide,     LaraAsBackJump,  LaraAsRightJump, LaraAsLeftJump,
    LaraAsUpJump,    LaraAsFallBack,  LaraAsHangLeft,  LaraAsHangRight,
    LaraAsSlideBack, LaraAsSurfTread, LaraAsSurfSwim,  LaraAsDive,
    LaraAsPushBlock, LaraAsPullBlock, LaraAsPPReady,   LaraAsPickup,
    LaraAsSwitchOn,  LaraAsSwitchOff, LaraAsUseKey,    LaraAsUsePuzzle,
    LaraAsUWDeath,   LaraAsRoll,      LaraAsSpecial,   LaraAsSurfBack,
    LaraAsSurfLeft,  LaraAsSurfRight, LaraAsUseMidas,  LaraAsDieMidas,
    LaraAsSwanDive,  LaraAsFastDive,  LaraAsGymnast,   LaraAsWaterOut,
};

void (*LaraCollisionRoutines[])(ITEM_INFO* item, COLL_INFO* coll) = {
    LaraColWalk,      LaraColRun,       LaraColStop,      LaraColForwardJump,
    LaraColPose,      LaraColFastBack,  LaraColTurnR,     LaraColTurnL,
    LaraColDeath,     LaraColFastFall,  LaraColHang,      LaraColReach,
    LaraColSplat,     LaraColTread,     LaraColLand,      LaraColCompress,
    LaraColBack,      LaraColSwim,      LaraColGlide,     LaraColNull,
    LaraColFastTurn,  LaraColStepRight, LaraColStepLeft,  LaraColRoll2,
    LaraColSlide,     LaraColBackJump,  LaraColRightJump, LaraColLeftJump,
    LaraColUpJump,    LaraColFallBack,  LaraColHangLeft,  LaraColHangRight,
    LaraColSlideBack, LaraColSurfTread, LaraColSurfSwim,  LaraColDive,
    LaraColPushBlock, LaraColPullBlock, LaraColPPReady,   LaraColPickup,
    LaraColSwitchOn,  LaraColSwitchOff, LaraColUseKey,    LaraColUsePuzzle,
    LaraColUWDeath,   LaraColRoll,      LaraColSpecial,   LaraColSurfBack,
    LaraColSurfLeft,  LaraColSurfRight, LaraColUseMidas,  LaraColDieMidas,
    LaraColSwanDive,  LaraColFastDive,  LaraColGymnast,   LaraColWaterOut,
};

void Tomb1MInjectGameLaraMisc()
{
    INJECT(0x00427850, LaraControl);
    INJECT(0x00427BD0, LaraSwapMeshExtra);
    INJECT(0x00427C00, AnimateLara);
    INJECT(0x00427E80, UseItem);
    INJECT(0x00427FD0, ControlLaraExtra);
    INJECT(0x00427FF0, InitialiseLaraLoad);
    INJECT(0x00428020, InitialiseLara);
}
