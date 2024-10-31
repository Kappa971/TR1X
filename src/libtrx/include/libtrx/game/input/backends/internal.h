#pragma once

#include "../common.h"
#include "base.h"

void Input_UpdateFromBackend(
    INPUT_STATE *result, INPUT_LAYOUT layout,
    const INPUT_BACKEND_IMPL *backend);

void Input_ConflictHelper(
    INPUT_LAYOUT layout,
    bool (*check_conflict_func)(
        INPUT_LAYOUT layout, INPUT_ROLE role1, INPUT_ROLE role2),
    void (*assign_conflict_func)(
        INPUT_LAYOUT layout, INPUT_ROLE role, bool conflict));
