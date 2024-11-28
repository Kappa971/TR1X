#pragma once

#include "global/types.h"

#include <libtrx/game/inject.h>

typedef struct {
    int32_t texture_page_count;
    int32_t texture_count;
    int32_t sprite_info_count;
    int32_t sprite_count;
    int32_t mesh_count;
    int32_t mesh_ptr_count;
    int32_t anim_change_count;
    int32_t anim_range_count;
    int32_t anim_cmd_count;
    int32_t anim_bone_count;
    int32_t anim_frame_data_count;
    int32_t anim_frame_count;
    int32_t anim_frame_mesh_rot_count;
    int32_t anim_count;
    int32_t object_count;
    int32_t sfx_count;
    int32_t sfx_data_size;
    int32_t sample_count;
    int32_t mesh_edit_count;
    int32_t texture_overwrite_count;
    int32_t floor_edit_count;
    int32_t room_mesh_meta_count;
    INJECTION_MESH_META *room_mesh_meta;
    int32_t room_mesh_edit_count;
    int32_t room_door_edit_count;
    int32_t anim_range_edit_count;
    int32_t item_position_count;
} INJECTION_INFO;

void Inject_Init(
    int32_t injection_count, char *filenames[], INJECTION_INFO *aggregate);
void Inject_AllInjections(LEVEL_INFO *level_info);
void Inject_Cleanup(void);
