// cms2defaultsurfacecreator.h - PLACEHOLDER for CMS2DefaultSurfaceCreator (RTTI .?AVCMS2DefaultSurfaceCreator@@, base
// ecr::IDefaultSurfaceCreator): creates the game window's render context and surface for ecr::RenderService. NOT an
// original header; 8 bytes (the vptr). MS2 (ms2.h) owns one and deletes it on shutdown.
#pragma once

#include "ms2/ms2layout.h"
#include <ecr/IDefaultSurfaceCreator.h>

class CMS2DefaultSurfaceCreator : public ecr::IDefaultSurfaceCreator
{
public:
    CMS2DefaultSurfaceCreator();
    virtual bool CreateDefaultSurface(ecr::RenderService* pRenderService, const efd::ColorA& color);
    virtual ~CMS2DefaultSurfaceCreator();
};
MS2_CHECK_SIZE(CMS2DefaultSurfaceCreator, 8);
