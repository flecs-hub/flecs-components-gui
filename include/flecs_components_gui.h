#ifndef FLECS_COMPONENTS_GUI_H
#define FLECS_COMPONENTS_GUI_H

/* This generated file contains includes for project dependencies */
#include "flecs-components-gui/bake_config.h"

#ifdef __cplusplus
extern "C" {
#endif

ECS_STRUCT(EcsWindow, {
    char *title;
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
});

ECS_STRUCT(EcsCanvas, {
    int32_t width;
    int32_t height;
    ecs_rgb_t background_color;
    ecs_entity_t camera;
});

typedef struct EcsCamera {
    vec3 position;
    vec3 lookat;
    vec3 up;
    float fov;
} EcsCamera;

typedef struct FlecsComponentsGui {
    ECS_DECLARE_COMPONENT(EcsWindow);
    ECS_DECLARE_COMPONENT(EcsCanvas);
    ECS_DECLARE_COMPONENT(EcsCamera);
} FlecsComponentsGui;

void FlecsComponentsGuiImport(
    ecs_world_t *world);

#define FlecsComponentsGuiImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsWindow);\
    ECS_IMPORT_COMPONENT(handles, EcsCanvas);\
    ECS_IMPORT_COMPONENT(handles, EcsCamera);

#ifdef __cplusplus
}
#endif

#endif
