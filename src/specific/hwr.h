#ifndef T1M_SPECIFIC_HWR_H
#define T1M_SPECIFIC_HWR_H

#include "specific/ati.h"

#include <windows.h>
#include <ddraw.h>
#include <stdint.h>

// TODO: function naming, Render vs. Draw vs. Insert
// TODO: port ATI3DCIF to actual D3D calls

// clang-format off
#define HWR_InitialiseHardware      ((void      (*)())0x00408005)
#define HWR_ShutdownHardware        ((void      (*)())0x00408323)
#define HWR_DownloadTextures        ((void      (*)(int16_t level_num))0x004084DE)
#define HWR_SetPalette              ((void      (*)())0x004087EA)
#define HWR_PrepareFMV              ((void      (*)())0x0040834C)
#define HWR_FMVDone                 ((void      (*)())0x00408368)
#define HWR_CopyPicture             ((void      (*)())0x00408B85)
#define HWR_DownloadPicture         ((void      (*)())0x00408C3A)
#define HWR_SwitchResolution        ((void      (*)())0x004089F4)
// clang-format on

void HWR_Error(HRESULT result);
void HWR_RenderBegin();
void HWR_RenderEnd();
void HWR_RenderToggle();
void HWR_DisableTextures();
void HWR_ClearSurface(LPDIRECTDRAWSURFACE surface);
void HWR_BlitSurface(LPDIRECTDRAWSURFACE target, LPDIRECTDRAWSURFACE source);
void HWR_RenderTriangleStrip(C3D_VTCF *vertices, int num);
void HWR_Draw2DLine(
    int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t z, int32_t color);
void HWR_DrawTranslucentQuad(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void HWR_DrawLightningSegment(
    int x1, int y1, int z1, int thickness1, int x2, int y2, int z2,
    int thickness2);

void T1MInjectSpecificHWR();

#endif
